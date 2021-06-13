#include "Hisse.h"

Hisse HisseOlustur(char* sembol, float fiyat){
	Hisse this;
	this=(Hisse)malloc(sizeof(struct HISSE));
	this->sembol=malloc(sizeof(char)*strlen(sembol));
	strcpy(this->sembol, sembol);
	this->fiyat=fiyat;
	this->yokEt=&HisseYokEt;
	return this;
}
void HisseYokEt(Hisse this){
	if(this==NULL)	return;
	if(this->sembol != NULL)	free(this->sembol);
	free(this);
}