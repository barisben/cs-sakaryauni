#ifndef CIRCULARDOUBLYLINKEDLIST_HPP
#define CIRCULARDOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class CircularDoublyLinkedList{
	private:
		Node *listeOrta;
		int size;
		Node *FindPreviousNode(int, int);
		Node *FindNextNode(int);
	public:
		CircularDoublyLinkedList();
		void add(int*, int);
		void reverseOrder();
		void caprazlama(CircularDoublyLinkedList**, int, int);
		Node *listeOrtaAdres(CircularDoublyLinkedList**);
		int minIndexBul(CircularDoublyLinkedList**, int);
		int maksIndexBul(CircularDoublyLinkedList**, int);
		friend ostream& operator<<(ostream&, CircularDoublyLinkedList&);
		void clear();
		~CircularDoublyLinkedList();
};

#endif