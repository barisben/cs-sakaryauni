#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include <cmath>

class BST{
	private:	
		BSTNode *root;
		int totalValue;
		
		void SearchAndAdd(BSTNode *&subNode,const int& newItem);
		bool SearchAndDelete(BSTNode *&subNode,const int& data);
		bool DeleteNode(BSTNode *&subNode);
		void inorder(BSTNode *subNode);
		void preorder(BSTNode *subNode);
		void postorder(BSTNode *subNode);
		int Height(BSTNode *subNode);
		void PrintLevel(BSTNode *subNode,int level);
		bool Search(BSTNode *subNode,const int& item);
	public:
		BST();
		int TotalValue();
		bool isEmpty()const;
		void Add(const int& newItem);
		void Delete(const int& data);
		void postorder();
		int Height();
		bool Search(const int& item);
		void Clear();
		~BST();
};

#endif