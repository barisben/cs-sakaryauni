#ifndef DISAVLTREE_HPP
#define DISAVLTREE_HPP

#include <algorithm>
#include <string>
#include "DisNode.hpp"
#include "IcAVLTree.hpp"

using namespace std;

class DisAVLTree{
	private:
		DisNode* DegistirSol(DisNode*);
		DisNode* DegistirSag(DisNode*);
		DisNode* AraveEkle(DisNode*, const int&, string, string, int);
		DisNode* YeniEkle(DisNode*, DisNode*);
		DisNode* DisBuNodeSil(DisNode*, int, string);
		DisNode* AgacAra(DisNode*, const int&, string, string, int, DisNode*);
		DisNode* MinBul(DisNode*);
		int Yukseklik(DisNode*)const;
	public:
		DisNode* kok;
		DisAVLTree();
		void Ekle(const int&, string, string, int);
		void Postorder(DisNode*)const;
		bool DisNodeSil(DisNode*&);
		void Temizle();
		~DisAVLTree();
};

#endif