#ifndef ORGAN_HPP
#define ORGAN_HPP
#include <iostream>
#include "BST.hpp"
#include "Doku.hpp"
using namespace std;

class Organ{
	private:
        BST *dokular;
	public:
		Organ();
		void DokuEkle(Doku*);
		bool DengeKontrol();
		void OrganMutasyon();
		~Organ();
};
#endif