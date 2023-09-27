#ifndef DISNODE_HPP
#define DISNODE_HPP

#include "IcAVLTree.hpp"

class DisNode{
	public:
		int veri;
		int yukseklik;
		string isYeri;
		DisNode* sol;
		DisNode* sag;
		IcAVLTree* icAVL;
		DisNode(string isYeri, DisNode* sol=NULL, DisNode* sag=NULL);
};

#endif