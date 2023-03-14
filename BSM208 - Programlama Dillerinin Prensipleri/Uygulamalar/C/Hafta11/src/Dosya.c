#include "Dosya.h"

Dosya DosyaOlustur(char* yol){
	Dosya this;
	this=(Dosya)malloc(sizeof(struct DOSYA));
	this->yol=yol;
	this->icerik=NULL;
	
	//Exception kütüphanesi olduğu için yazılan kısım
	this->exception=IOExceptionOlustur("Dosya okuma hatasi");
	
	this->Oku=&oku;
	this->Yoket=&DosyaYoket;
	return this;
}
char* oku(const Dosya this){
	char *icerik=NULL;
	int boyut=0;
	FILE *fp;
	fp=fopen(this->yol, "r");
	
	//exception handling, Exception kütüphanesi yazılmamış olsaydı
	//if(!fp)	longjmp(this->jumper,-3);
	
	//exception handling, Exception kütüphanesi yazıldığı için
	if(!fp)	throw(this->exception);
	
	fseek(fp, 0, SEEK_END);
	boyut=ftell(fp);
	rewind(fp);
	icerik=(char*)malloc(sizeof(char)*boyut);
	fread(icerik, 1, boyut, fp);
	fclose(fp);
	this->icerik=icerik;
	return icerik;
}
void DosyaYoket(Dosya this){
	if(this==NULL)	return;
	if(this->icerik != NULL)	free(this->icerik);
	free(this);
}