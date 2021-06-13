#include "Kare.h"

Kare KareOlustur(char* renk, int kenar){
	Kare this;
	this=(Kare)malloc(sizeof(struct KARE));
	this->super=GeometrikSekilOlustur(renk);
	this->kenar=kenar;
	
	this->super->Alan=&alan;
	this->super->Cevre=&cevre;
	this->yokEt=&KareYoket;
	return this;
}
double alan(const Kare this){
	return pow(this->kenar, 2);
}
double cevre(const Kare this){
	return 4*this->kenar;
}
void KareYoket(Kare this){
	if(this==NULL)	return;
	this->super->yokEt(this->super);//burada fonksiyon göstericisi yardımıyla geometriksekil'in yıkıcısını çağırmak önemli!!!!
	free(this);
}