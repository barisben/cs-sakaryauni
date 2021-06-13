/**
* @file Node.cpp
* @description Node sınıfındaki metotların oluşturulduğu dosya
* @course 2/B
* @assignment 1. ödev
* @date 29.11.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "Node.hpp"

Node::Node(const int& data, Node *nx, Node *pr){
	this->data = data;
	this->next = nx;
	this->prev = pr;
}