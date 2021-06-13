#ifndef DOUBLEHASHING_HPP
#define DOUBLEHASHING_HPP

#include <iostream>
#define MAX 101
#define R 97
using namespace std;

class DoubleHashing{
	private:
		int *tablo;
		int elemanSayisi;
	public:
		DoubleHashing(){
			tablo=new int[MAX];
			Temizle();
		}
		int hash1(int sayi){
			return sayi%MAX;
		}
		int hash2(int sayi){
			return R-(sayi%R);
		}
		bool DoluMu()const{
			return elemanSayisi==MAX;
		}
		void Ekle(int sayi){
			if(DoluMu()) throw "Yer yok!";
			int indeks=hash1(sayi);
			if(tablo[indeks]!=-1){//-1 değilse çarpışma vardır yani indeks doludur
				int adimSayisi=hash2(sayi);
				int i=1;
				while(true){//adımsayısı kadar atlama yaparak boş yeri bulana kadar arıyoruz
					int yeniIndeks=(indeks+i*adimSayisi)%MAX;
					if(tablo[yeniIndeks]==-1){//bos yer bulundu demektir, ekliyoruz
						tablo[yeniIndeks]=sayi;
						break;
					}
					i++;
				}
			}
			else//çarpışma yoktur yani direkt olarak eklenebilir
				tablo[indeks]=sayi;
			elemanSayisi++;
		}
		bool Arama(int sayi){
			if(elemanSayisi==0)
				return false;
			int indeks=hash1(sayi);
			if(tablo[indeks]==sayi)
				return true;
			int adimSayisi=hash2(sayi);
			int i=1;
			while(i<=elemanSayisi){
				int yeniIndeks=(indeks+i*adimSayisi)%MAX;
				if(tablo[yeniIndeks]==sayi)
					return true;
				i++;
			}
			return false;
		}
		void Cikar(int sayi){
			if(elemanSayisi==0) throw "Eleman yok!";
			int indeks=hash1(sayi);
			if(tablo[indeks]==sayi){
				tablo[indeks]=-1;
				elemanSayisi--;
				return;
			}
			int adimSayisi=hash2(sayi);
			int i=1;
			while(i<=elemanSayisi){
				int yeniIndeks=(indeks+i*adimSayisi)%MAX;
				if(tablo[yeniIndeks]==sayi){
					tablo[yeniIndeks]=-1;
					elemanSayisi--;
					return;
				}
				i++;
			}
			throw "Eleman yok!";
		}
		void Temizle(){
			for(int i=0; i<MAX; i++)//dizide tüm sayıların pozitif oldugunu varsayıyoruz, yani negatifse dizinin o indeksi dolu değildir diyeceğiz. bu yüzden varsayılan olarak önce tüm indekslere negatif sayı atıyoruz
				tablo[i]=-1;
			elemanSayisi=0;
		}
		void Yaz(){
			for(int i=0; i<MAX; i++){
				if(tablo[i]!=-1)
					cout<<"["<<i<<"]: "<<tablo[i]<<endl;
				else
					cout<<"["<<i<<"]: "<<endl;
			}
		}
		~DoubleHashing(){
			delete[] tablo;
		}
};

#endif