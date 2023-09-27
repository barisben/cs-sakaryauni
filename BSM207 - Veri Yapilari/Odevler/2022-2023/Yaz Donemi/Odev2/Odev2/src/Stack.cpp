/**
* @file Stack.cpp
* @description Stack ile ilgili işlemlerin fonksiyonlarını içerir
* @course 1/A
* @assignment 2. Odev
* @date 02.08.2023
* @author Ahmet Faruk Sezgenç - faruksezgenc@gmail.com
*/

#include "Stack.hpp"

Stack::Stack(){
	topOfStack=NULL;
	bst=NULL;
}
bool Stack::isEmpty()const{
	return topOfStack == NULL;
}
void Stack::push(const int& item){
	topOfStack	= new StackNode(item,topOfStack);
}
void Stack::pop(){
	if(isEmpty()) throw "Stack is Empty";
	StackNode *tmp = topOfStack;
	bst->Add(topOfStack->item);
	topOfStack = topOfStack->next;
	delete tmp;
}
const int& Stack::top()const{
	if(isEmpty()) throw "Stack is Empty";
	return topOfStack->item;
}
void Stack::makeEmpty(){
	while(!isEmpty()) pop();
}
Stack::~Stack(){
	makeEmpty();
}