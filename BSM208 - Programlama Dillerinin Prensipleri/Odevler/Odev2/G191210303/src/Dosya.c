#include "Dosya.h"

Dosya DosyaOlustur(char* yol){
	Dosya this;
	this=(Dosya)malloc(sizeof(struct DOSYA));
	this->root=NULL;
	this->hisseler=NULL;
	this->portfoyler=NULL;
	this->emirler=NULL;
	this->objSayisi=0;
	this->emirSatisSayisi=0;
	this->yol=yol;
	this->data=NULL;
	this->oku=&Oku;
	this->hisseParse=&HisseParseEt;
	this->portfoyParse=&PortfoyParseEt;
	this->emirParse=&EmirParseEt;
	this->yokEt=&DosyaYokEt;
	return this;
}
void Oku(const Dosya this){
	FILE *dosya;
    long len;
    char *data;
    dosya=fopen(this->yol, "rb");
	
	if(!dosya)	longjmp(this->jumper,-3);
	
    fseek(dosya,0,SEEK_END);
    len=ftell(dosya);
    fseek(dosya,0,SEEK_SET);
    data=(char*)malloc(len+1);
    fread(data,1,len,dosya);
    fclose(dosya);
	this->data=data;
}
void HisseParseEt(const Dosya this){
	this->root = cJSON_Parse(this->data);
	
	if(!this->root)		longjmp(this->jumper,-4);
	
	cJSON *hisseler = cJSON_GetObjectItem(this->root, "Hisseler");
    int hisseSayisi = cJSON_GetArraySize(hisseler);
	int i;
	
	this->hisseler=malloc(sizeof(struct HISSE*)*hisseSayisi);
	
    for (i=0; i<hisseSayisi; i++){
        cJSON *hisse = cJSON_GetArrayItem(hisseler, i);
		char *sembol = cJSON_GetObjectItem(hisse, "Sembol")->valuestring;
		float fiyat = cJSON_GetObjectItem(hisse, "Fiyat")->valuedouble;
		this->hisseler[i]=HisseOlustur(sembol, fiyat);
    }
	this->objSayisi=hisseSayisi;
}
void PortfoyParseEt(const Dosya this){
	this->root = cJSON_Parse(this->data);
	
	if(!this->root)		longjmp(this->jumper,-4);
	
	cJSON *portfoyler = cJSON_GetObjectItem(this->root, "Portfoy");
    int portfoySayisi = cJSON_GetArraySize(portfoyler);
	int i;
	
	this->portfoyler=malloc(sizeof(struct PORTFOY*)*portfoySayisi);
	
	for (i=0; i<portfoySayisi; i++){
        cJSON *portfoy = cJSON_GetArrayItem(portfoyler, i);
		char *sembol = cJSON_GetObjectItem(portfoy, "Sembol")->valuestring;
		float maliyet = cJSON_GetObjectItem(portfoy, "Maliyet")->valuedouble;
		int adet = cJSON_GetObjectItem(portfoy, "Adet")->valueint;
		this->portfoyler[i]=PortfoyOlustur(sembol, maliyet, adet);
    }
	this->objSayisi=portfoySayisi;
}
void EmirParseEt(const Dosya this){
	this->root = cJSON_Parse(this->data);
	
	if(!this->root)		longjmp(this->jumper,-4);
	
	cJSON *emirler = cJSON_GetObjectItem(this->root, "Emirler");
    int emirSayisi = cJSON_GetArraySize(emirler);
	int i, satisSayisi=0;

	this->emirler=malloc(sizeof(struct EMIR*)*emirSayisi);
	
	for (i=0; i<emirSayisi; i++){
        cJSON *emir = cJSON_GetArrayItem(emirler, i);
		char *sembol = cJSON_GetObjectItem(emir, "Sembol")->valuestring;
		char *islem = cJSON_GetObjectItem(emir, "Islem")->valuestring;
		int adet = cJSON_GetObjectItem(emir, "Adet")->valueint;
		this->emirler[i]=EmirOlustur(sembol, islem, adet);
		if(strcmp(islem, "SATIS")==0)	satisSayisi+=1;
    }
	this->emirSatisSayisi=satisSayisi;
	this->objSayisi=emirSayisi;
}
void DosyaYokEt(Dosya this){
	if(this==NULL)	return;
	cJSON_Delete(this->root);
	if(this->data!=NULL)	free(this->data);
	if(this->hisseler != NULL){
		int i;
		for(i=0; i<this->objSayisi; i++){
			this->hisseler[i]->yokEt(this->hisseler[i]);
		}
	}
	else if(this->portfoyler != NULL){
		int i;
		for(i=0; i<this->objSayisi; i++){
			this->portfoyler[i]->yokEt(this->portfoyler[i]);
		}
	}
	else if(this->emirler != NULL){
		int i;
		for(i=0; i<this->objSayisi; i++){
			this->emirler[i]->yokEt(this->emirler[i]);
		}
	}
	free(this);
}