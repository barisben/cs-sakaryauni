#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename Object>
class Node {
public:
	Object data;
	Node<Object>* next;

	Node(const Object& data = Object(), Node<Object>* next = NULL) {
		this->data = data;
		this->next = next;
	}
};
#endif