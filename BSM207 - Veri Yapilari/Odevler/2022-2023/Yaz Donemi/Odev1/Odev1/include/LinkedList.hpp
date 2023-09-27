#ifndef LinkedList_HPP
#define LinkedList_HPP

#include "Node.hpp"
#include <fstream>
#include <sstream>

class LinkedList{
	private:
		Node *head;
		int size;
	public:
		Node* FindPrevByPosition(int);
		LinkedList();
		bool isEmpty() const;
		int Count() const;
		void add(const int&);
		void insert(int, const int&);
		void removeAt(int);
		friend ostream& operator<<(ostream&, LinkedList&);
		void clear();
		~LinkedList();
};

#endif
