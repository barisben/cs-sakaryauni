/**
 * @file BST.cpp
 * @description	BST ile ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "BST.hpp"

Dugum::Dugum(Doku* doku, Dugum *sol, Dugum *sag){
    this->doku=doku;
    this->sol=sol;
    this->sag=sag;
    this->veri=doku->GetOrtancaHucre();
    this->yukseklik=0;
}

BST::BST(){
    this->kok=NULL;
    this->yikiciMi=true;
    this->yeniDokular=NULL;
}        

void BST::AraveEkle(Dugum *&altDugum, Doku* doku){
    if(altDugum==NULL){
        altDugum=new Dugum(doku);
        altDugum->yukseklik=Yukseklik(altDugum);
    }
    else if(doku->GetOrtancaHucre() <= altDugum->veri)
        AraveEkle(altDugum->sol, doku);
    else if(doku->GetOrtancaHucre() > altDugum->veri)
        AraveEkle(altDugum->sag, doku);
}

void BST::Ekle(Doku* doku){
    AraveEkle(kok, doku);
}

bool BST::DugumSil(Dugum *&altDugum, bool yikiciMi){
    Dugum *del=altDugum;
    if(altDugum->sag==NULL)
        altDugum=altDugum->sol;
    else if(altDugum->sol==NULL)
        altDugum=altDugum->sag;
    else{
        del=altDugum->sol;
        Dugum *ebeveynDugum=altDugum;
        while(del->sag != NULL){
            ebeveynDugum=del;
            del=del->sag;
        }
        altDugum->veri=del->veri;
        if(altDugum == ebeveynDugum)
            altDugum->sol=del->sol;
        else
            ebeveynDugum->sag=del->sol;
    }
    if(yikiciMi)    delete del->doku;
    delete del;
    return true;
}
int BST::Yukseklik(Dugum *altDugum){
    if(altDugum==NULL)
        return -1;
    return max(Yukseklik(altDugum->sol), Yukseklik(altDugum->sag))+1;
}
bool BST::DengeliMi(Dugum *altDugum){
    if(altDugum==NULL)  return true;
    
    int sol=Yukseklik(altDugum->sol);
    int sag=Yukseklik(altDugum->sag);
    if (abs(sol - sag) <= 1 && DengeliMi(altDugum->sol) && DengeliMi(altDugum->sag))    return true;
    return false;
}
bool BST::DengeliMi(){
    return DengeliMi(kok);
}
void BST::DokulariMutasyonaUgrat(Dugum *altDugum, int &i){
    if(altDugum!=NULL){
        DokulariMutasyonaUgrat(altDugum->sol, i);
        DokulariMutasyonaUgrat(altDugum->sag, i);
        altDugum->doku->HucreleriMutasyonaUgrat();
        yeniDokular[i]=altDugum->doku;
        i++;
    }
}
void BST::AgaciYenidenOlustur(){
    Temizle(false);
    for(int i=0; i<20; i++){
        yeniDokular[i]->YenidenSirala();
        Ekle(yeniDokular[i]);
    }
}
void BST::MutasyonKontrol(){
    if(kok->veri%50==0){
        int i=0;
        yeniDokular=new Doku*[20];
        DokulariMutasyonaUgrat(kok, i);
        AgaciYenidenOlustur();
        
        delete [] yeniDokular;
    }
}
bool BST::isEmpty(){
    return kok==NULL;
}
void BST::Temizle(bool yikiciMi){
    while(!isEmpty())
        DugumSil(kok, yikiciMi);
}
BST::~BST(){
    Temizle();
}