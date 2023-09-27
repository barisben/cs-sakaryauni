/**
* @file main.cpp
* @description odevde istenen islemleri yapar
* @course 1/A
* @assignment 1. Odev
* @date 23.07.2023
* @author faruksezgenc@gmail.com
*/

#include <cmath>
#include "LinkedList.hpp"

int main()
{
	ifstream dosya;
	string satir;
	int sayi, listeSayisi=0;
	
	dosya.open("./Sayilar.txt");
	while(getline(dosya, satir)) 
		listeSayisi++;
	dosya.close();
	LinkedList **onlarBasamagiListeler = new LinkedList *[listeSayisi];
	LinkedList **birlerBasamagiListeler = new LinkedList *[listeSayisi];
	
	int sayac=0, maxSayiAdedi=0;
	dosya.open("./Sayilar.txt");  
	while(getline(dosya, satir)){
		int satirdakiSayiSayisi=0, i=0;
		istringstream in2(satir);
		while(in2 >> sayi)
			satirdakiSayiSayisi++;
		int *satirdakiSayilarDizisi = new int[satirdakiSayiSayisi];
		istringstream in3(satir);
		while(in3 >> sayi){
			satirdakiSayilarDizisi[i]=sayi;
			i++;
		}
		onlarBasamagiListeler[sayac]=new LinkedList();
		birlerBasamagiListeler[sayac]=new LinkedList();
		
		for(int j=0; j<satirdakiSayiSayisi; j++){
			onlarBasamagiListeler[sayac]->add((satirdakiSayilarDizisi[j]/10)%10);
			birlerBasamagiListeler[sayac]->add(satirdakiSayilarDizisi[j]%10);
		}
		
		if(maxSayiAdedi<satirdakiSayiSayisi) maxSayiAdedi=satirdakiSayiSayisi;
		
		sayac++;
		delete[] satirdakiSayilarDizisi;
	}
	dosya.close();
	
	int konumA, konumB;
    cout << "Konum A: ";
    cin >> konumA;
	if(konumA>=listeSayisi || konumA<0){
		cout<<"OUT OF INDEX"<<endl;
		exit(0);
	}
    cout << "Konum B: ";
    cin >> konumB;
	if(konumB>=listeSayisi || konumB<0){
		cout<<"OUT OF INDEX"<<endl;
		exit(0);
	}
	
	LinkedList *tmp=onlarBasamagiListeler[konumA];
	onlarBasamagiListeler[konumA]=birlerBasamagiListeler[konumB];
	birlerBasamagiListeler[konumB]=tmp;
	
	int onlarAdet=0, birlerAdet=0;
	double onlarToplam=0, birlerToplam=0;
	for (int i=1;i<=maxSayiAdedi;i++)
    {
		int result_int=0, result_decimal=0;
		double onlar=0, birler=0;
		for(int j=0;j<listeSayisi;j++){
			if(onlarBasamagiListeler[j]->Count()>=i){
				onlar+=onlarBasamagiListeler[j]->FindPrevByPosition(i)->item;
				onlarAdet++;
			}
			if(birlerBasamagiListeler[j]->Count()>=i){
				birler+=birlerBasamagiListeler[j]->FindPrevByPosition(i)->item;
				birlerAdet++;
			}
		}
		
		if(birlerAdet>0)	birlerToplam+=birler/birlerAdet;
		if(onlarAdet>0)		onlarToplam+=onlar/onlarAdet;
		
		onlarAdet=0;
		birlerAdet=0;
    }
	
	cout<<"Ust: "<<onlarToplam<<endl;
	cout<<"Alt: "<<birlerToplam<<endl;

	for (int i=0;i<listeSayisi;i++)
    {
        delete onlarBasamagiListeler[i];
		delete birlerBasamagiListeler[i];
    }
	delete[] onlarBasamagiListeler;
	delete[] birlerBasamagiListeler;

	return 0;
}
