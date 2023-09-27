/**
* @file Node.cpp
* @description Node sınıfının fonksiyonlarını içerir
* @course 1/A
* @assignment 1. Odev
* @date 23.07.2023
* @author faruksezgenc@gmail.com
*/

#include "Node.hpp"
	
Node::Node(const int& item,Node *nx){
	this->item=item;
	next=nx;
}