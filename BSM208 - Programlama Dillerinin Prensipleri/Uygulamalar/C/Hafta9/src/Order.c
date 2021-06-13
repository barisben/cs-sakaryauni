#include "Order.h"

Order OrderOlustur(int sayilar[], int uzunluk){
	Order this;
	this=(Order)malloc(sizeof(struct ORDER));
	this->sayilar=malloc(sizeof(int)*uzunluk);//dışarıdan gelen diziyi kullanmıyoruz
	this->uzunluk=uzunluk;
	this->sirala=&Sirala;//bir pointer oldugu için Sirala fonksiyonunun adresini göster diyoruz, mantık bu
	this->toString=&ToString;
	this->equals=&Equals;
	this->orderYokEt=&OrderYokEt;
	
	int i;
	for(i=0; i<uzunluk; i++){//diziye kopyalama işlemi
		this->sayilar[i]=sayilar[i];
	}
	
	return this;//normalde bu nesne yönelimlilerde otomatik return eder
}
int* Sirala(const Order this){
	int i;
	for(i=0; i<this->uzunluk-1; i++) {
		int j;
		for(j=1; j<this->uzunluk-i; j++) {
			if(this->sayilar[j] < this->sayilar[j-1]) {
				int tmp=this->sayilar[j-1];
				this->sayilar[j-1]=this->sayilar[j];
				this->sayilar[j]=tmp;
			}
		}
	}
	//heapte yeni bir dizi olusturmuyoruz cünkü dışarıda zaten parametre olarak gelen heapten silinecek	
	return this->sayilar;
}
void ToString(const Order this){
	this->sirala(this);
	int i;
	for(i=0;i<this->uzunluk;i++){
		printf("%d ",this->sayilar[i]);
	}
	printf("\n");
}
bool Equals(const Order lhs, const Order rhs){
	if(lhs==NULL || rhs==NULL)	return false;
	return lhs->uzunluk==rhs->uzunluk;
}
void OrderYokEt(Order this){
	if(this==NULL)	return;
	//önce sayıları yok ediyoruz ki structı yok edip gösterdikleri yerleri kaybetmeyelim
	free(this->sayilar);
	free(this);
}