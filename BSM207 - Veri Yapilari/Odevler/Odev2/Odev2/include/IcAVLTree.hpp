#ifndef ICAVLTREE_HPP
#define ICAVLTREE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include "IcNode.hpp"

class IcAVLTree{
	private:
		IcNode* DegistirSol(IcNode*);
		IcNode* DegistirSag(IcNode*);
		IcNode* YeniEkle(IcNode*, const int&, string, int);
		int Yukseklik(IcNode*)const;
	public:
		IcNode* kok;
		IcAVLTree();
		void Ekle(const int&, string, int);
		void Postorder(IcNode*)const;
		bool IcNodeSil(IcNode*&);
		void Temizle();
		~IcAVLTree();
};

#endif