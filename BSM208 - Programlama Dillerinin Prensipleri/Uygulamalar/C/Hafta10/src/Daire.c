#include "Daire.h"

Daire DaireOlustur(char* renk, double yariCap){
	Daire this;
	this=(Daire)malloc(sizeof(struct DAIRE));
	this->super=GeometrikSekilOlustur(renk);
	this->yariCap=yariCap;
	
	this->super->Alan=&Alan;
	this->super->Cevre=&Cevre;
	this->yokEt=&DaireYoket;
	return this;
}
double Alan(const Daire this){
	return M_PI*pow(this->yariCap, 2);
}
double Cevre(const Daire this){
	return 2*M_PI*this->yariCap;
}
void DaireYoket(Daire this){
	if(this==NULL)	return;
	this->super->yokEt(this->super);//burada fonksiyon göstericisi yardımıyla geometriksekil'in yıkıcısını çağırmak önemli!!!!
	free(this);
}