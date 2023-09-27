/**
* @file DisAVLTree.cpp
* @description DisAVLTree sınıfındaki fonksiyonların ve metotların oluşturulduğu dosya
* @course 2/B
* @assignment 2. ödev
* @date 27.12.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "DisNode.hpp"
#include "DisAVLTree.hpp"
#include "IcAVLTree.hpp"

DisNode* DisAVLTree::DegistirSol(DisNode* altDugum)
{
	DisNode* tmp = altDugum->sol;
	altDugum->sol = tmp->sag;
	tmp->sag = altDugum;
	altDugum->yukseklik = Yukseklik(altDugum);
	tmp->yukseklik = max(Yukseklik(tmp->sol), altDugum->yukseklik) + 1;
	return tmp;
}

DisNode* DisAVLTree::DegistirSag(DisNode* altDugum)
{
	DisNode* tmp = altDugum->sag;
	altDugum->sag = tmp->sol;
	tmp->sol = altDugum;
	altDugum->yukseklik = Yukseklik(altDugum);
	tmp->yukseklik = max(Yukseklik(tmp->sag), altDugum->yukseklik) + 1;
	return tmp;
}

DisNode* DisAVLTree::AraveEkle(DisNode* altDugum, const int& yeni, string isYeri, string isim, int yil)
{
	DisNode* tmpDugum=AgacAra(altDugum, yeni, isYeri, isim, yil, tmpDugum);

	if(tmpDugum==NULL){
		tmpDugum = new DisNode(isYeri);
		tmpDugum->icAVL->Ekle(yeni, isim, yil);
        altDugum=YeniEkle(altDugum, tmpDugum);
    }
	else{
        altDugum=DisBuNodeSil(altDugum, tmpDugum->veri, isYeri);
        tmpDugum->veri+=1;
        altDugum=YeniEkle(altDugum, tmpDugum);
        delete tmpDugum;
    }
	
    return altDugum;
}

DisNode* DisAVLTree::YeniEkle(DisNode* altDugum, DisNode* tmpDugum){
	if (altDugum == NULL)
	{
		DisNode* yeniDugum=new DisNode(tmpDugum->isYeri);
		yeniDugum->veri=tmpDugum->veri;
		yeniDugum->icAVL=tmpDugum->icAVL;
		return yeniDugum;
	}
	
	else if (tmpDugum->veri <= altDugum->veri)
	{
		altDugum->sol = YeniEkle(altDugum->sol, tmpDugum);
		if (Yukseklik(altDugum->sol) - Yukseklik(altDugum->sag) == 2)
		{
			if (tmpDugum->veri <= altDugum->sol->veri)
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
	else if (tmpDugum->veri > altDugum->veri)
	{
		altDugum->sag = YeniEkle(altDugum->sag, tmpDugum);
		if (Yukseklik(altDugum->sag) - Yukseklik(altDugum->sol) == 2)
		{
			if (tmpDugum->veri > altDugum->sag->veri)
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

DisAVLTree::DisAVLTree() 
{
	kok=NULL;
}

void DisAVLTree::Ekle(const int& yeni, string isYeri, string isim, int yil)
{
	kok = AraveEkle(kok, yeni, isYeri, isim, yil);
}

DisNode* DisAVLTree::AgacAra(DisNode* altDugum, const int& yeni, string isYeri, string isim, int yil, DisNode* tmpDugum){
	if(altDugum != NULL){
        if(altDugum->isYeri == isYeri){
			altDugum->icAVL->Ekle(yeni, isim, yil);
			DisNode* yeniDugum=new DisNode(isYeri);
			yeniDugum->veri=altDugum->veri;
			yeniDugum->icAVL=altDugum->icAVL;
			tmpDugum=yeniDugum;
			
			return tmpDugum;
        }
		else{
            DisNode* tmp = AgacAra(altDugum->sol, yeni, isYeri, isim, yil, tmpDugum);
            if(tmp == NULL){
                tmp = AgacAra(altDugum->sag, yeni, isYeri, isim, yil, tmpDugum);
            }
            return tmp;
        }
    }
	return NULL;
}

void DisAVLTree::Postorder(DisNode* altDugum)const
{
	if (altDugum != NULL)
	{
		Postorder(altDugum->sol);
		Postorder(altDugum->sag);
		cout<<altDugum->isYeri<<endl;
		altDugum->icAVL->Postorder(altDugum->icAVL->kok);
		cout<<endl;
	}
}

int DisAVLTree::Yukseklik(DisNode* altDugum)const
{
	if (altDugum == NULL)
		return -1;
	return 1 + max(Yukseklik(altDugum->sol), Yukseklik(altDugum->sag));
}

DisNode* DisAVLTree::MinBul(DisNode* altDugum)
{
	while(altDugum->sol != NULL)	altDugum = altDugum->sol;
	return altDugum;
}

DisNode* DisAVLTree::DisBuNodeSil(DisNode* altDugum, int veri, string isYeri)
{
	if(altDugum == NULL) return altDugum; 
	if(altDugum->isYeri != isYeri){
		
        if (veri < altDugum->veri)	altDugum->sol = DisBuNodeSil(altDugum->sol, veri, isYeri);
        else if (veri > altDugum->veri)	altDugum->sag = DisBuNodeSil(altDugum->sag, veri, isYeri);
        else{
			
            altDugum->sol = DisBuNodeSil(altDugum->sol, veri, isYeri);
            altDugum->sag = DisBuNodeSil(altDugum->sag, veri, isYeri);
        }
        altDugum->yukseklik = Yukseklik(altDugum);
        return altDugum;
    }
	else 
	{
		if(altDugum->sol == NULL || altDugum->sag == NULL) 
		{ 
			DisNode* temp = altDugum->sol ? altDugum->sol : altDugum->sag;
  
            if (temp == NULL)  
            {  
                temp = altDugum;  
                altDugum = NULL;
            }  
            else	*altDugum = *temp; 
            
            delete temp;
		} 
		else
		{
			DisNode* temp = MinBul(altDugum->sag);
			altDugum->veri=temp->veri;
			altDugum->isYeri=temp->isYeri;
			altDugum->icAVL=temp->icAVL;
			
			altDugum->sag = DisBuNodeSil(altDugum->sag, temp->veri, temp->isYeri);
		}
	}
  
    if (altDugum == NULL)	return altDugum;

    altDugum->yukseklik = Yukseklik(altDugum);
	
	int balance = Yukseklik(altDugum->sol) - Yukseklik(altDugum->sag);

	if (balance > 1 && Yukseklik(altDugum->sol->sol) - Yukseklik(altDugum->sol->sag) >= 0)
	{
		return DegistirSol(altDugum);
	}
	if (balance > 1 && Yukseklik(altDugum->sol->sol) - Yukseklik(altDugum->sol->sag) < 0)
	{
		altDugum->sol = DegistirSag(altDugum->sol);
		return DegistirSol(altDugum);
	}
	if (balance < -1 && Yukseklik(altDugum->sag->sol) - Yukseklik(altDugum->sag->sag) <= 0)
	{
		return DegistirSag(altDugum);
	}
	if (balance < -1 && Yukseklik(altDugum->sag->sol) - Yukseklik(altDugum->sag->sag) > 0)
	{
		altDugum->sag = DegistirSol(altDugum->sag);
		return DegistirSag(altDugum);
	}
	
    return altDugum;
}

bool DisAVLTree::DisNodeSil(DisNode*& altDugum)
{
	DisNode* bunuSil = altDugum;
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
		DisNode* parent = altDugum;
		while (bunuSil->sag != NULL) 
		{
			parent = bunuSil;
			bunuSil = bunuSil->sag;
		}
		altDugum->veri=bunuSil->veri;
		altDugum->isYeri=bunuSil->isYeri;
		altDugum->icAVL=bunuSil->icAVL;
		if (parent == altDugum)
			altDugum->sol = bunuSil->sol;
		else
			parent->sag = bunuSil->sol;
	}
	delete bunuSil;
	return true;
}
	
void DisAVLTree::Temizle()
{
	while (kok!=NULL)
	{
		delete kok->icAVL;
		DisNodeSil(kok);
	}
}
	
DisAVLTree::~DisAVLTree()
{
	Temizle();
}