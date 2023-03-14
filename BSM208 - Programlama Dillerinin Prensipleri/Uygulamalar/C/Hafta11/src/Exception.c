#include "Exception.h"

Exception ExceptionOlustur(char* mesaj){
	Exception this;
	this=(Exception)malloc(sizeof(struct EXCEPTION));
	this->mesaj=mesaj;
	this->getMessage=&GetMessage;
	this->Yoket=&ExceptionYoket;
	return this;
}
char* GetMessage(const Exception this){
	return this->mesaj;
}
void ExceptionYoket(Exception this){
	if(this==NULL)	return;
	free(this);
}