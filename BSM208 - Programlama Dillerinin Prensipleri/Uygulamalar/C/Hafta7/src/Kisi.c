#include "Kisi.h"

Kisi KisiOlustur(char* isim, float boy, float kilo){
	Kisi this;
	this=(Kisi)malloc(sizeof(struct KISI));
	this->isim=isim;
	this->boy=boy;
	this->kilo=kilo;
	this->yas=0;
	return this;//normalde bu nesne yönelimlilerde otomatik return eder
}
void YasIlerle(const Kisi this, int yil){
	this->yas+=yil;
	if(this->yas<18)	this->boy+=1;
}
void YemekYe(const Kisi this, float kalori){
	this->kilo+=(kalori/1000);
}
void toString(const Kisi this){
	printf("%s %d %f %f",this->isim, this->yas, this->boy, this->kilo);
}
void KisiYokEt(Kisi this){
	if(this!=NULL)	free(this);
}