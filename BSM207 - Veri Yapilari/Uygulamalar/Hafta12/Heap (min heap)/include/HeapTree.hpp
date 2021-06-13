#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP

#include <iostream>
using namespace std;

class HeapTree{
	private:
		int *elemanlar;
		int elemanSayisi;
		int kapasite;
		
		int SolCocukIndeks(int indeks){//sol çocuğun indeksini verir
			return 2*indeks+1;
		}
		
		int SagCocukIndeks(int indeks){//sağ çocuğun indeksini verir
			return 2*indeks+2;
		}
		
		int EbeveynDugumIndeks(int indeks){
			return (indeks-1)/2;//"(indeks-1)/2" ebeveyn düğümü verir
		}
		
		void HeapYukari(int indeks){
			int ebeveynIndeks;
			if(indeks!=0){//0'a eşit değilse kökte değildir, yani hala yukarı çıkma ihtimali vardır
				ebeveynIndeks=EbeveynDugumIndeks(indeks);
				if(elemanlar[ebeveynIndeks] > elemanlar[indeks]){//ebeveyn daha büyükse aşağı inmesi gerekiyor
					Degistir(elemanlar[ebeveynIndeks], elemanlar[indeks]);//ebeveyn büyükse çocuktan, yer değiştiriyor
					HeapYukari(ebeveynIndeks);
				}
			}
			
		}
		
		void HeapAsagi(int indeks){
			int solCocukIndeks, sagCocukIndeks, enKucukIndeks;
			solCocukIndeks=SolCocukIndeks(indeks);
			sagCocukIndeks=SagCocukIndeks(indeks);
			if(sagCocukIndeks >= elemanSayisi){//en küçük değerin sol çocukta mı sağ çocukta mı oldugunu bulma
				if(solCocukIndeks >= elemanSayisi)//bu kosulla beraber ne sag ne de sol cocuk olmadıgı anlasılır
					return;
				else
					enKucukIndeks=solCocukIndeks;
			}
			else{//hem sağ hem de sol çocuğunun olduğu anlaşılmış olur
				if(elemanlar[solCocukIndeks] <= elemanlar[sagCocukIndeks])
					enKucukIndeks=solCocukIndeks;
				else
					enKucukIndeks=sagCocukIndeks;
			}
			if(elemanlar[indeks] > elemanlar[enKucukIndeks]){//eğer böyle bir durum varsa demekki ebeveynde daha büyük bir sayı vardır
				Degistir(elemanlar[enKucukIndeks], elemanlar[indeks]);
				HeapAsagi(enKucukIndeks);//degistirdikten sonra hala ihtiyaç olabileceği için çağırılıyor
			}
		}
		
		void Degistir(int &sol, int &sag){//sag ve solu yer değiştirir
			int tmp=sol;
			sol=sag;
			sag=tmp;
		}
	public:
		HeapTree(int kapasite){
			elemanlar=new int[kapasite];
			elemanSayisi=0;
			this->kapasite=kapasite;
		}
		bool isEmpty(){
			return elemanSayisi==0;
		}
		void Ekle(int sayi){
			if(elemanSayisi==kapasite) throw "Hata";
			elemanlar[elemanSayisi]=sayi;
			elemanSayisi++;
			HeapYukari(elemanSayisi-1);
			
		}
		int EnKucuguCikar(){//kökteki en küçük oldugundan dolayı, kökü çıkarıp yeniden ağacın düzenlemesini için gerekli şeyleri yapar
			if(isEmpty()) throw "Hata";
			int enKucuk=elemanlar[0];//0. indeksi kök
			elemanlar[0]=elemanlar[elemanSayisi-1];//kökü en aşağıdaki en sağdaki veri yapıyoruz
			elemanSayisi--;
			if(elemanSayisi>0)//son indeks değilse ve yani hala indeksler doluysa ağacın yeniden yapılandırılması gerekebileceği için heapasagi çağırılır
				HeapAsagi(0);
			return enKucuk;
		}
		~HeapTree(){
			delete[] elemanlar;
		}
	
};

#endif