#ifndef ICNODE_HPP
#define ICNODE_HPP

#include <iostream>

using namespace std;

class IcNode{
	public:
		int veri;
		int yukseklik;
		int yil;
		string isim;
		IcNode* sol;
		IcNode* sag;
		IcNode(const int& veri, string isim, int yil, IcNode* sol=NULL, IcNode* sag=NULL);
};

#endif