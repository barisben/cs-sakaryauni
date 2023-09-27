/**
* @file BST.cpp
* @description BST ile ilgili işlemlerin fonksiyonlarını içerir
* @course 1/A
* @assignment 2. Odev
* @date 02.08.2023
* @author Ahmet Faruk Sezgenç - faruksezgenc@gmail.com
*/

#include "BST.hpp"

void BST::SearchAndAdd(BSTNode *&subNode,const int& newItem){
	if(subNode == NULL){
		subNode = new BSTNode(newItem);
		totalValue+=newItem;
	}
	else if(newItem < subNode->data)
		SearchAndAdd(subNode->left,newItem);
	else if(newItem > subNode->data)
		SearchAndAdd(subNode->right,newItem);
	else return;
}
bool BST::SearchAndDelete(BSTNode *&subNode,const int& data){
	if(subNode == NULL) return false;
	if(subNode->data == data) return DeleteNode(subNode);
	else if(data < subNode->data) return SearchAndDelete(subNode->left,data);
	else return SearchAndDelete(subNode->right,data);
}
bool BST::DeleteNode(BSTNode *&subNode){
	BSTNode *DelNode = subNode;
	
	if(subNode->right == NULL) subNode = subNode->left;
	else if(subNode->left == NULL) subNode = subNode->right;
	else{
		DelNode = subNode->left;
		BSTNode *parent = subNode;
		while(DelNode->right != NULL){
			parent = DelNode;
			DelNode = DelNode->right;
		}
		subNode->data = DelNode->data;
		if(parent == subNode) subNode->left = DelNode->left;
		else parent->right = DelNode->left;
	}
	delete DelNode;
	return true;
}
void BST::postorder(BSTNode *subNode){
	if(subNode != NULL){
		postorder(subNode->left);
		postorder(subNode->right);
		cout<<char(subNode->data)<<" ";
	}
}
int BST::Height(BSTNode *subNode){
	if(subNode == NULL) return -1;
	return 1+max(Height(subNode->left),Height(subNode->right));
}
void BST::PrintLevel(BSTNode *subNode,int level){
	if(subNode == NULL) return;
	if(level == 0) cout<<subNode->data<<" ";
	else{
		PrintLevel(subNode->left,level-1);
		PrintLevel(subNode->right,level-1);
	}
}
bool BST::Search(BSTNode *subNode,const int& item){
	if(subNode == NULL) return false;
	if(subNode->data == item) return true;
	if(item < subNode->data) return Search(subNode->left,item);
	else return Search(subNode->right,item);
}

BST::BST(){
	root = NULL;
	totalValue=0;
}
int BST::TotalValue(){
	return totalValue;
}
bool BST::isEmpty()const{
	return root == NULL;
}
void BST::Add(const int& newItem){
	SearchAndAdd(root,newItem);
}
void BST::Delete(const int& data){
	if(SearchAndDelete(root,data) == false) throw "Item not found.";
}
void BST::postorder(){
	postorder(root);
}
int BST::Height(){
	return Height(root);
}
bool BST::Search(const int& item){
	return Search(root,item);
}
void BST::Clear(){
	while(!isEmpty()) DeleteNode(root);
}
BST::~BST(){
	Clear();
}