#include "Dosya.h"

Dosya DosyaOlustur(char* yol){
	Dosya this;
	this=(Dosya)malloc(sizeof(struct DOSYA));
	this->yol=yol;
	this->data=NULL;
	this->oku=&Oku;
	this->yokEt=&DosyaYokEt;
	return this;
}
char* Oku(const Dosya this){
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
	return data;
}
void DosyaYokEt(Dosya this){
	//printf("DOSYA YIKICI CAGIRILDI\n");
	if(this==NULL)	return;
	if(this->data!=NULL)	free(this->data);
	free(this);
}