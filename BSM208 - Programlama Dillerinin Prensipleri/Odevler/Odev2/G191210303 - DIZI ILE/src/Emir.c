#include "Emir.h"

Emir EmirOlustur(){
	Emir this;
	this=(Emir)malloc(sizeof(struct EMIR));
	this->semboller=NULL;
	this->islemler=NULL;
	this->adetler=NULL;
	this->emirSayisi=0;
	this->satisSayisi=0;
	this->root=NULL;
	this->oku=&EmirOku;
	this->yokEt=&EmirYokEt;
	return this;
}
void EmirOku(const Emir this, char* data){
	this->root = cJSON_Parse(data);
	cJSON *emirler = cJSON_GetObjectItem(this->root, "Emirler");
    int emirSayisi = cJSON_GetArraySize(emirler);
	int i, satisSayisi=0;

	this->semboller=malloc(sizeof(char*)*emirSayisi);
	this->islemler=malloc(sizeof(char*)*emirSayisi);
	this->adetler=malloc(sizeof(int)*emirSayisi);
	this->emirSayisi=emirSayisi;
	
	for (i=0; i<emirSayisi; i++){
        cJSON *emir = cJSON_GetArrayItem(emirler, i);
		char *sembol = cJSON_GetObjectItem(emir, "Sembol")->valuestring;
		char *islem = cJSON_GetObjectItem(emir, "Islem")->valuestring;
		int adet = cJSON_GetObjectItem(emir, "Adet")->valueint;
		this->semboller[i]=malloc(sizeof(char)*strlen(sembol));
		this->islemler[i]=malloc(sizeof(char)*strlen(islem));
		strcpy(this->semboller[i], sembol);
		strcpy(this->islemler[i], islem);
		this->adetler[i]=adet;
		if(strcmp(islem, "SATIS")==0)	satisSayisi+=1;
    }
	this->satisSayisi=satisSayisi;
	cJSON_Delete(this->root);
}
void EmirYokEt(Emir this){
	//printf("EMIR YIKICI CAGIRILDI\n");
	if(this==NULL)	return;
	if(this->semboller != NULL){
		int i;
		for(i=0; i<this->emirSayisi; i++){
			free(this->semboller[i]);
			free(this->islemler[i]);
			this->semboller[i]=NULL;
			this->islemler[i]=NULL;
		}
		free(this->semboller);
		free(this->islemler);
		free(this->adetler);
	}
	free(this);
}