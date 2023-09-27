/**
* @file LinkedList.cpp
* @description LinkedList sınıfının fonksiyonlarını içerir
* @course 1/A
* @assignment 1. Odev
* @date 23.07.2023
* @author faruksezgenc@gmail.com
*/

#include "LinkedList.hpp"

Node* LinkedList::FindPrevByPosition(int position){
	if(position < 0 || position > size) throw "Index out of range";
	int index=1;
	
	for(Node *itr=head;itr!=NULL;itr=itr->next,index++){
		if(position == index) return itr;
	}
	return NULL;
}	

LinkedList::LinkedList(){
	head = NULL;	
	size=0;
}

bool LinkedList::isEmpty() const{
	return head == NULL;
}

int LinkedList::Count() const{
	return size;
}

void LinkedList::add(const int& item){
	insert(size,item);
}

void LinkedList::insert(int index,const int& item){
	if(index == 0) head = new Node(item, head);
	else{
		Node *prev = FindPrevByPosition(index);
		prev->next = new Node(item,prev->next);
	}						
	size++;
}

void LinkedList::removeAt(int index){
	if(size == 0) throw "Empty list";
	Node *del;
	if(index == 0){
		del = head;
		head = head->next;
	}
	else{
		Node *prev = FindPrevByPosition(index);
		del = prev->next;
		prev->next = prev->next->next;
	}
	delete del;
	size--;
}

ostream& operator<<(ostream& screen, LinkedList &right){
	if(right.isEmpty()) screen<<"Empty list";
	else{
		for(Node *itr=right.head;itr!=NULL;itr=itr->next){
			screen<<itr->item<<" ";
		}
	}
	return screen;
}

void LinkedList::clear(){
	while(!isEmpty())
		removeAt(0);			
}

LinkedList::~LinkedList(){
	clear();
}