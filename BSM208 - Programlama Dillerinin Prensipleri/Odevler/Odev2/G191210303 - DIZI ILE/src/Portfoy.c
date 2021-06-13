#include "Portfoy.h"

Portfoy PortfoyOlustur(){
	Portfoy this;
	this=(Portfoy)malloc(sizeof(struct PORTFOY));
	this->semboller=NULL;
	this->maliyetler=NULL;
	this->adetler=NULL;
	this->portfoySayisi=0;
	this->root=NULL;
	this->oku=&PortfoyOku;
	this->toString=&PortfoyToString;
	this->yokEt=&PortfoyYokEt;
	return this;
}
void PortfoyOku(const Portfoy this, char* data){
	this->root = cJSON_Parse(data);
	cJSON *portfoyler = cJSON_GetObjectItem(this->root, "Portfoy");
    int portfoySayisi = cJSON_GetArraySize(portfoyler);
	int i;
	
	this->semboller=malloc(sizeof(char*)*portfoySayisi);
	this->maliyetler=malloc(sizeof(float)*portfoySayisi);
	this->adetler=malloc(sizeof(int)*portfoySayisi);
	this->portfoySayisi=portfoySayisi;
	
	for (i=0; i<portfoySayisi; i++){
        cJSON *portfoy = cJSON_GetArrayItem(portfoyler, i);
		char *sembol = cJSON_GetObjectItem(portfoy, "Sembol")->valuestring;
		float maliyet = cJSON_GetObjectItem(portfoy, "Maliyet")->valuedouble;
		int adet = cJSON_GetObjectItem(portfoy, "Adet")->valueint;
		this->semboller[i]=malloc(sizeof(char)*strlen(sembol));
		strcpy(this->semboller[i], sembol);
		this->maliyetler[i]=maliyet;
		this->adetler[i]=adet;
    }
	cJSON_Delete(this->root);
}
void PortfoyToString(const Portfoy this){
	printf("Guncel Portfoy:\n");
	int i;
	for(i=0; i<this->portfoySayisi; i++){
		if(this->adetler[i]!=0){
			printf("Hisse: %s\n",this->semboller[i]);
			printf("Adet: %d\n", this->adetler[i]);
			printf("Maliyet: %.2f TL\n",this->maliyetler[i]);
			if(i!=this->portfoySayisi-1)	printf("-------------------\n");
		}
	}
}
void PortfoyYokEt(Portfoy this){
	//printf("PORTFOY YIKICI CAGIRILDI\n");
	if(this==NULL)	return;
	if(this->semboller != NULL){
		int i;
		for(i=0; i<this->portfoySayisi; i++){
			free(this->semboller[i]);
			this->semboller[i]=NULL;
		}
		free(this->semboller);
		free(this->maliyetler);
		free(this->adetler);
	}
	free(this);
}