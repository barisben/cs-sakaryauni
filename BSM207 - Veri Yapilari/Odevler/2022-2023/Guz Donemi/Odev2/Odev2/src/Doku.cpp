/**
 * @file Doku.cpp
 * @description	Dokuları ve ona ait hücreleri tutan ve dokularla ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Doku.hpp"

Doku::Doku(Hucre** hucreler, int hucreAdet, int ortancaHucre){
    this->hucreler=hucreler;
    this->hucreAdet=hucreAdet;
    this->ortancaHucre=ortancaHucre;
}
int Doku::GetOrtancaHucre(){
    return ortancaHucre;
}
void Doku::HucreleriMutasyonaUgrat(){
    for(int i=0; i<hucreAdet; i++){
        if(hucreler[i]->GetDnaUzunlugu()%2==0)   hucreler[i]->SetDnaUzunlugu(hucreler[i]->GetDnaUzunlugu()/2);
    }
}
void Doku::YenidenSirala(){
    int* hucreDizi=new int[hucreAdet];
    for(int i=0; i<hucreAdet; i++)  hucreDizi[i]=hucreler[i]->GetDnaUzunlugu();
    Radix *radix = new Radix(hucreDizi,hucreAdet);
    int *hucreSirali = radix->Sort();
    int ortadakiSayi=hucreSirali[(hucreAdet-1)/2];
    ortancaHucre=ortadakiSayi;

    delete [] hucreDizi;
    delete [] hucreSirali;
    delete radix;
}
Doku::~Doku(){
    for (int i=0;i<hucreAdet;i++)
    {
        delete hucreler[i];
    }
	delete[] hucreler;
}