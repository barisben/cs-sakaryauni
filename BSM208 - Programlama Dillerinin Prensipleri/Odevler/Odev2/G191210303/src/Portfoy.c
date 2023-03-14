#include "Portfoy.h"

char* PortfoySifirsizDondur(const Portfoy this, float sayi){
	char tmp[1];
	int count = snprintf(tmp, sizeof tmp, "%f", sayi);
	
	if(this->sifirsizSayi!=NULL)	this->sifirsizSayi=realloc(this->sifirsizSayi, sizeof(char)*count);
	else	this->sifirsizSayi=malloc(sizeof(char)*count);
	sprintf(this->sifirsizSayi, "%.2f", sayi);
	int i;
	for(i=0; i<count; i++){
		if(this->sifirsizSayi[i]=='.'){
			if(this->sifirsizSayi[i+2]=='0' && this->sifirsizSayi[i+1]=='0')
				this->sifirsizSayi[i]='\0';
			else if(this->sifirsizSayi[i+2]=='0' && this->sifirsizSayi[i+1]!='0')
				this->sifirsizSayi[i+2]='\0';
			break;
		}	
	}
	return this->sifirsizSayi;
}

Portfoy PortfoyOlustur(char* sembol, float maliyet, int adet){
	Portfoy this;
	this=(Portfoy)malloc(sizeof(struct PORTFOY));
	this->sembol=malloc(sizeof(char)*strlen(sembol));
	strcpy(this->sembol, sembol);
	this->maliyet=maliyet;
	this->adet=adet;
	this->sifirsizSayi=NULL;
	this->toString=&PortfoyToString;
	this->yokEt=&PortfoyYokEt;
	return this;
}
void PortfoyToString(const Portfoy this){
	int i;
	if(this->adet!=0){
		printf("Hisse: %s\n", this->sembol);
		printf("Adet: %d\n", this->adet);
		printf("Maliyet: %s TL\n", PortfoySifirsizDondur(this, this->maliyet));
		printf("-------------------\n");
	}
}
void PortfoyYokEt(Portfoy this){
	if(this==NULL)	return;
	if(this->sifirsizSayi!=NULL)	free(this->sifirsizSayi);
	if(this->sembol != NULL)	free(this->sembol);
	free(this);
}