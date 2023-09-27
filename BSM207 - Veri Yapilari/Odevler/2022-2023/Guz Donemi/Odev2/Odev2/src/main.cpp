/**
 * @file main.cpp
 * @description	Ana işlemlerin yapıldığı cpp dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Organizma.hpp"
#include "Kontrol.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
	ifstream dosya;
	string satir;
	int sayi=0, hucreAdet=0, dokuIndex=0, organIndex=0, sistemIndex=0, ortadakiSayi=0, satirSayisi=0, i=0;
	bool organEkle=true;

	dosya.open("./Veri.txt");
	while(getline(dosya,satir))	satirSayisi++;
	dosya.close();

	Doku **dokular = new Doku *[satirSayisi];
	Organ **organlar = new Organ *[satirSayisi/20];
	Sistem **sistemler = new Sistem *[satirSayisi/100];

	dosya.open("./Veri.txt");
	while(getline(dosya, satir)){
		istringstream in(satir);
		while (in >> sayi)	hucreAdet++;
		int* hucreDizi=new int[hucreAdet];
		istringstream in1(satir);
		Hucre **hucreler = new Hucre *[hucreAdet];
		while(in1 >> sayi){
			hucreler[i]=new Hucre(sayi);
			hucreDizi[i]=sayi;
			i++;
		}

		Radix *radix = new Radix(hucreDizi,hucreAdet);
		int *hucreSirali = radix->Sort();
		ortadakiSayi=hucreSirali[(hucreAdet-1)/2];

		delete [] hucreDizi;
		delete [] hucreSirali;
		delete radix;

		dokular[dokuIndex]=new Doku(hucreler, hucreAdet, ortadakiSayi);

		if((dokuIndex+1)%20==0){
			organlar[organIndex]=new Organ();
			for(int i=dokuIndex-19; i<dokuIndex+1; i++)		organlar[organIndex]->DokuEkle(dokular[i]);	
			organIndex++;
			organEkle=true;
		}
		if((organIndex)%100==0 && organEkle==true && organIndex!=0){
			int j=0;
			sistemler[sistemIndex]=new Sistem();
			for(int i=organIndex-100; i<organIndex; i++){
				sistemler[sistemIndex]->OrganEkle(organlar[i], j);
				j++;
			}
			sistemIndex++;
			organEkle=false;
		}

		i=0;
		hucreAdet=0;
		dokuIndex++;
	}
	dosya.close();

	Organizma *organizma=new Organizma(sistemIndex);
	for(int i=0; i<sistemIndex; i++)		organizma->SistemEkle(sistemler[i], i);
	organizma->OrganizmaYazdir(false);

	Kontrol *organizmaKontrol=new Kontrol(sistemler, sistemIndex);
    organizmaKontrol->KokKontrol();
    delete organizmaKontrol;

	string input;
	getline(cin, input);
    if(input.length()==0)		organizma->OrganizmaYazdir(true);
	

	delete organizma;
	delete [] dokular;
	delete [] organlar;
	delete [] sistemler;
	
	return 0;
}