/**
* @file IcAVLTree.cpp
* @description IcAVLTree sınıfındaki fonksiyonların ve metotların oluşturulduğu dosya
* @course 2/B
* @assignment 2. ödev
* @date 27.12.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "IcNode.hpp"
#include "IcAVLTree.hpp"

IcNode* IcAVLTree::DegistirSol(IcNode* altDugum)
{
	IcNode* tmp = altDugum->sol;
	altDugum->sol = tmp->sag;
	tmp->sag = altDugum;
	altDugum->yukseklik = Yukseklik(altDugum);
	tmp->yukseklik = max(Yukseklik(tmp->sol), altDugum->yukseklik) + 1;
	return tmp;
}

IcNode* IcAVLTree::DegistirSag(IcNode* altDugum)
{
	IcNode* tmp = altDugum->sag;
	altDugum->sag = tmp->sol;
	tmp->sol = altDugum;
	altDugum->yukseklik = Yukseklik(altDugum);
	tmp->yukseklik = max(Yukseklik(tmp->sag), altDugum->yukseklik) + 1;
	return tmp;
}

IcNode* IcAVLTree::YeniEkle(IcNode* altDugum, const int& yeni, string isim, int yil)
{
	if (altDugum == NULL)
	{
		altDugum = new IcNode(yeni, isim, yil);
	}
	else if (yeni <= altDugum->veri)
	{
		altDugum->sol = YeniEkle(altDugum->sol, yeni, isim, yil);
		if (Yukseklik(altDugum->sol) - Yukseklik(altDugum->sag) == 2)
		{
			if (yeni <= altDugum->sol->veri)
			{
				altDugum = DegistirSol(altDugum);
			}
			else
			{
				altDugum->sol = DegistirSag(altDugum->sol);
				altDugum = DegistirSol(altDugum);
			}
		}
	}
	else if (yeni > altDugum->veri)
	{
		altDugum->sag = YeniEkle(altDugum->sag, yeni, isim, yil);
		if (Yukseklik(altDugum->sag) - Yukseklik(altDugum->sol) == 2)
		{
			if (yeni >= altDugum->sag->veri)
			{
				altDugum = DegistirSag(altDugum);
			}
			else
			{
				altDugum->sag = DegistirSol(altDugum->sag);
				altDugum = DegistirSag(altDugum);
			}
		}
	}
	altDugum->yukseklik = Yukseklik(altDugum);
	return altDugum;
}

IcAVLTree::IcAVLTree(){
	kok=NULL;
}

void IcAVLTree::Ekle(const int& yeni, string isim, int yil)
{
	kok = YeniEkle(kok, yeni, isim, yil);
}

void IcAVLTree::Postorder(IcNode* altDugum)const
{
	if (altDugum != NULL)
	{
		Postorder(altDugum->sol);
		Postorder(altDugum->sag);
		cout<< altDugum->isim << " - " << altDugum->yil;
		if(altDugum != kok)		cout<< " | ";
	}
}

int IcAVLTree::Yukseklik(IcNode* altDugum)const
{
	if (altDugum == NULL)
		return -1;
	return 1 + max(Yukseklik(altDugum->sol), Yukseklik(altDugum->sag));
}

bool IcAVLTree::IcNodeSil(IcNode*& altDugum)
{
	IcNode* bunuSil = altDugum;
	if (altDugum->sag == NULL)
	{
		altDugum = altDugum->sol;
	}
	else if (altDugum->sol == NULL)
	{
		altDugum = altDugum->sag;
	}
	else
	{
		bunuSil = altDugum->sol;
		IcNode* parent = altDugum;
		while (bunuSil->sag != NULL) 
		{
			parent = bunuSil;
			bunuSil = bunuSil->sag;
		}
		altDugum->veri = bunuSil->veri;
		altDugum->isim = bunuSil->isim;
		altDugum->yil = bunuSil->yil;
		if (parent == altDugum)
			altDugum->sol = bunuSil->sol;
		else
			parent->sag = bunuSil->sol;
	}
	delete bunuSil;
	return true;
}
	
void IcAVLTree::Temizle()
{
	while (kok!=NULL)
	{
		IcNodeSil(kok);
	}
}
	
IcAVLTree::~IcAVLTree()
{
	Temizle();
}