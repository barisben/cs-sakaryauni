#ifndef BST_HPP
#define BST_HPP

#include "Doku.hpp"
#include <iostream>
using namespace std;

class Dugum{
	public:
		Doku *doku;
		Dugum *sol;
		Dugum *sag;
		int veri;
		int yukseklik;
		
		Dugum(Doku*, Dugum *sol=NULL, Dugum *sag=NULL);
};

class BST{
	private:
		Dugum *kok;
		Doku **yeniDokular;
		bool yikiciMi;
		bool DengeliMi(Dugum*);
		void AraveEkle(Dugum*&, Doku*);
		void DokulariMutasyonaUgrat(Dugum*, int&);
		void AgaciYenidenOlustur();
	public:
		BST();
		void Ekle(Doku*);
		bool DugumSil(Dugum*&, bool);
		int Yukseklik(Dugum*);
		bool DengeliMi();
		void MutasyonKontrol();
		bool isEmpty();
		void Temizle(bool yikiciMi=true);
		~BST();
};

#endif