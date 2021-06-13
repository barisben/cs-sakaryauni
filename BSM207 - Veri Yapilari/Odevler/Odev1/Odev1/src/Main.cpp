/**
* @file Main.cpp
* @description istenilen işlemleri yapan ana dosya
* @course 2/B
* @assignment 1. ödev
* @date 29.11.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "CircularDoublyLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	ifstream dosya;
	string satir;
	int sayi;
	dosya.open("./Sayilar.txt"); 
	while(getline(dosya, satir)){
		int sayac=0;
		istringstream in(satir);
		while(in >> sayi){
			if(sayi<1){
				cout<<"\n1 veya 1'den fazla negatif sayi veya 0 bulundugundan dolayi program kapatiliyor.\n"<<endl;
				exit(0);
			}
			sayac++;
		}
		if(sayac%2==0 || sayac<3){
			cout<<"\n1 veya 1'den fazla satirda cift sayi adedince sayi veya 3'den az sayi bulundugundan dolayi program kapatiliyor.\n"<<endl;
			exit(0);
		}
	}
	dosya.close();
	
	int satirSayisi=0;
	dosya.open("./Sayilar.txt");
	while(getline(dosya, satir)) 
		satirSayisi++;
	dosya.close();
	CircularDoublyLinkedList **listeler = new CircularDoublyLinkedList *[satirSayisi];
	int sayac=0;
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
		listeler[sayac]=new CircularDoublyLinkedList();
		listeler[sayac]->add(satirdakiSayilarDizisi,satirdakiSayiSayisi);
		sayac++;
		delete[] satirdakiSayilarDizisi;
	}
	dosya.close();
	
	int minIndex=listeler[0]->minIndexBul(listeler, satirSayisi);
	int maksIndex=listeler[0]->maksIndexBul(listeler, satirSayisi);
	listeler[0]->caprazlama(listeler, maksIndex, minIndex);
	cout<<"\nEn buyuk liste orta dugum adres: "<<listeler[maksIndex]->listeOrtaAdres(listeler)<<endl;
	cout<<"En buyuk liste degerler:\n";
	cout<<*listeler[maksIndex]<<endl;
	cout<<"En kucuk liste orta dugum adres: "<<listeler[minIndex]->listeOrtaAdres(listeler)<<endl;
	cout<<"En kucuk liste degerler:\n";
	cout<<*listeler[minIndex]<<endl;
	
	for (int i=0;i<satirSayisi;i++)
    {
        delete listeler[i];
    }
	delete[] listeler;
	
	return 0;
}