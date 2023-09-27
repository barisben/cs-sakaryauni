/**
* @file BSTNode.cpp
* @description BST içerisindeki düğümlerle ilgili işlemlerin fonksiyonlarını içerir
* @course 1/A
* @assignment 2. Odev
* @date 02.08.2023
* @author Ahmet Faruk Sezgenç - faruksezgenc@gmail.com
*/

#include "BSTNode.hpp"

BSTNode::BSTNode(const int& dt,BSTNode *lf,BSTNode *rg){
	data = dt;
	left = lf;
	right = rg;
}