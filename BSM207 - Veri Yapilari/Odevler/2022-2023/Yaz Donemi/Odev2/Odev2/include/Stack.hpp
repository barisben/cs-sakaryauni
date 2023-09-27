#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"
#include "BST.hpp"

class Stack{
	private:
		StackNode *topOfStack;
	public:
		BST *bst;
		Stack();
		bool isEmpty()const;
		void push(const int& item);
		void pop();
		const int& top()const;
		void makeEmpty();
		~Stack();
};

#endif