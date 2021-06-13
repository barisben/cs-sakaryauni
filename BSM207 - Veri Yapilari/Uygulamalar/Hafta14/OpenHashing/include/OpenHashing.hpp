#ifndef OPENHASHING_HPP
#define OPENHASHING_HPP

#include <iostream>
#define MAX 101
using namespace std;

class Dugum{
	public:
		int veri;
		Dugum *ileri;
	
		Dugum(int veri, Dugum *ileri=NULL){
			this->veri=veri;
			this->ileri=ileri;
		}
};

class OpenHashing{
	private:
		Dugum *Dizi[MAX];
	public:
		OpenHashing(){
			for(int i=0; i<MAX; i++)
				Dizi[i]=NULL;//adres dizisi oldugundan 0 yerine null'a eşitliyoruz baslangıcta varsayılan
		}
		int HashKodu(int sayi){
			return sayi%MAX;
		}
		void Ekle(int sayi){
			if(Arama(sayi))//eğer sayı zaten varsa eklemiyor
				return;
			int indeks=HashKodu(sayi);
			Dizi[indeks]=new Dugum(sayi, Dizi[indeks]);//dizi indeksinin indeksinin başına düğümü ekleme
		}
		bool Cikar(int sayi){
			int indeks=HashKodu(sayi);
			Dugum *tmp=Dizi[indeks];
			if(Dizi[indeks]==NULL)//null exception kontrolü
				return false;
			if(Dizi[indeks]->veri == sayi){//ilk düğümdeyse
				Dugum *sil=Dizi[indeks];
				Dizi[indeks]=Dizi[indeks]->ileri;
				delete sil;
				return true;
			}
			//arada ve sondaysa
			Dugum *onceki=Dizi[indeks];
			while(onceki->ileri!=NULL){//arıyoruz
				if(onceki->ileri->veri == sayi){
					Dugum *sil=onceki->ileri;
					onceki->ileri=sil->ileri;
					delete sil;
					return true;
				}
				onceki=onceki->ileri;
			}
			return false;
		}
		void Temizle(){
			for(int i=0; i<MAX; i++){
				Dugum *tmp=Dizi[i];
				while(tmp!=NULL){
					Dugum *sil=tmp;
					tmp=tmp->ileri;
					delete sil;
				}
				Dizi[i]=NULL;
			}
		}
		bool Arama(int sayi){
			int indeks=HashKodu(sayi);//sayının bulundugu indeksi alıyoruz
			Dugum *tmp=Dizi[indeks];//adresi tmpye attık
			while(tmp!=NULL){//null olana dek sayı var mı yok mu arıyoruz
				if(tmp->veri == sayi)
					return true;
				tmp=tmp->ileri;
			}
			return false;
		}
		bool BosMu()const{
			for(int i=0; i<MAX; i++){
				if(Dizi[i]!=NULL)
					return false;
			}
			return true;
		}
		void Yaz()const{
			for(int i=0; i<MAX; i++){
				if(Dizi[i] != NULL){
					cout<<"Tablo["<<i<<"]->";
					for(Dugum *tmp=Dizi[i]; tmp!=NULL; tmp=tmp->ileri)
						cout<<tmp->veri<<"->";
					cout<<"NULL"<<endl;
				}
			}
		}
		~OpenHashing(){
			Temizle();
		}
};

#endif