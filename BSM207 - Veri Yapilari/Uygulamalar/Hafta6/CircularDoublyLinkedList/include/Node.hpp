#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template<typename Object>
class Node{
	public:
		Object data;
		Node<Object> *next;
		Node<Object> *prev;
		
		Node(const Object data,Node<Object> *nx=NULL,Node<Object> *pr=NULL){
			this->data=data;
			next=nx;
			prev=pr;
		}
};

#endif