#include "Emir.h"

Emir EmirOlustur(char* sembol, char* islem, int adet){
	Emir this;
	this=(Emir)malloc(sizeof(struct EMIR));
	this->sembol=malloc(sizeof(char)*strlen(sembol));
	this->islem=malloc(sizeof(char)*strlen(islem));
	strcpy(this->sembol, sembol);
	strcpy(this->islem, islem);
	this->adet=adet;
	this->satisSayisi=0;
	this->yokEt=&EmirYokEt;
	return this;
}
void EmirYokEt(Emir this){
	if(this==NULL)	return;
	if(this->sembol != NULL)	free(this->sembol);
	if(this->islem != NULL)		free(this->islem);
	free(this);
}