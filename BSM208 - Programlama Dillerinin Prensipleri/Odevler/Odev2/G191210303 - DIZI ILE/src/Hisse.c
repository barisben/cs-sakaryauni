#include "Hisse.h"

Hisse HisseOlustur(){
	Hisse this;
	this=(Hisse)malloc(sizeof(struct HISSE));
	this->semboller=NULL;
	this->fiyatlar=NULL;
	this->hisseSayisi=0;
	this->root=NULL;
	this->oku=&HisseOku;
	this->yokEt=&HisseYokEt;
	return this;
}
void HisseOku(const Hisse this, char* data){
	this->root = cJSON_Parse(data);
	cJSON *hisseler = cJSON_GetObjectItem(this->root, "Hisseler");
    int hisseSayisi = cJSON_GetArraySize(hisseler);
	int i;
	
	this->semboller=malloc(sizeof(char*)*hisseSayisi);
	this->fiyatlar=malloc(sizeof(float)*hisseSayisi);
	this->hisseSayisi=hisseSayisi;
	
    for (i=0; i<hisseSayisi; i++){
        cJSON *hisse = cJSON_GetArrayItem(hisseler, i);
		char *sembol = cJSON_GetObjectItem(hisse, "Sembol")->valuestring;
		float fiyat = cJSON_GetObjectItem(hisse, "Fiyat")->valuedouble;
		this->semboller[i]=malloc(sizeof(char)*strlen(sembol));
		strcpy(this->semboller[i], sembol);
		this->fiyatlar[i]=fiyat;
    }
	cJSON_Delete(this->root);
}
void HisseYokEt(Hisse this){
	//printf("\nHISSE YIKICI CAGIRILDI\n");
	if(this==NULL)	return;
	if(this->semboller != NULL){
		int i;
		for(i=0; i<this->hisseSayisi; i++){
			free(this->semboller[i]);
			this->semboller[i]=NULL;
		}
		free(this->semboller);
		free(this->fiyatlar);
	}
	free(this);
}