/**
* @file StackNode.cpp
* @description Stack içerisindeki düğümlerle ilgili işlemlerin fonksiyonlarını içerir
* @course 1/A
* @assignment 2. Odev
* @date 02.08.2023
* @author Ahmet Faruk Sezgenç - faruksezgenc@gmail.com
*/

#include "StackNode.hpp"

StackNode::StackNode(const int& item,StackNode *next){
	this->item = item;
	this->next = next;
}
