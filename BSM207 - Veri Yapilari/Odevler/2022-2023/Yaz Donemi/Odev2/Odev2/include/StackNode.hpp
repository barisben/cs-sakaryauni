#ifndef STACKNODE_HPP
#define STACKNODE_HPP

#include <iostream>
using namespace std;

class StackNode{
	public:
		int item;
		StackNode *next;
		StackNode(const int& item,StackNode *next=NULL);
};

#endif