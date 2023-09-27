#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node{
	public:
		int item;
		Node *next;
		Node(const int& item=int(), Node *nx=NULL);
};

#endif
