#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <Iterator.hpp>

using namespace std;

template <typename Object>
class LinkedList {
private:
	Node<Object>* head;
	int size;
	Iterator<Object> IterateFromPrevIndex(int index) const {
		if (!(index < 0 || index > Count())) {
			int i = 0;
			Iterator<Object> itr(head);
			while (!itr.IsEndNode() && index != i++)
				itr.StepNext();
			return itr;
		}
		return NULL;
	}
	Iterator<Object> IterateFromFirstNode() const {
		if (!IsEmpty())
			return Iterator<Object>(head->next);
		return NULL;
	}
public:
	LinkedList() {
		head = new Node<Object>();
		size = 0;
	}
	bool IsEmpty() const {
		return head->next == NULL;
	}
	int Count() const {
		return size;
	}
	const Object& First() const {
		if (!IsEmpty())
			return head->next->data;
		return NULL;
	}
	const Object& Last() const {
		if (!IsEmpty())
			return IterateFromPrevIndex(size).GetCurrentData();
		return NULL;
	}
	void Add(const Object& obj) {
		Insert(Count(), obj);
	}
	void Insert(int index, const Object& obj) {
		Iterator<Object> itr;
		itr = IterateFromPrevIndex(index);
		itr.current->next = new Node<Object>(obj, itr.current->next);
		size++;
	}
	void Remove(const Object& obj) {
		int index = IndexOf(obj);
		RemoveAt(index);
	}
	void RemoveAt(int index) {
		Iterator<Object> itr;
		itr = IterateFromPrevIndex(index);
		if (itr.current->next != NULL) {
			Node<Object>* oldNode = itr.current->next;
			itr.current->next = itr.current->next->next;
			delete oldNode;
			size--;
		}
	}
	int IndexOf(const Object& obj) const {
		int index = 0;
		for (Iterator<Object> itr(head->next); !itr.IsEndNode(); itr.StepNext()) {
			if (itr.GetCurrentData() == obj)
				return index;
			index++;
		}
		return -1;
	}
	bool Find(const Object& obj) const {
		for (Iterator<Object> itr(head->next); !itr.IsEndNode(); itr.StepNext()) {
			if (itr.GetCurrentData() == obj)
				return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& screen, LinkedList& list) {
		if (list.IsEmpty())
			screen << "Liste bos";
		else {
			for (Iterator<Object> itr = list.IterateFromFirstNode(); !itr.IsEndNode(); itr.StepNext())
				screen << itr.GetCurrentData() << endl;
		}
		return screen;
	}
	void Clear() {
		while (!IsEmpty()) {
			RemoveAt(0);
		}
	}
	~LinkedList() {
		Clear();
		delete head;
	}
};
#endif