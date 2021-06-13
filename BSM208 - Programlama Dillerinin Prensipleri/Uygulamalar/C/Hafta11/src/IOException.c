#include "IOException.h"

IOException IOExceptionOlustur(char* mesaj){
	IOException this;
	this=(IOException)malloc(sizeof(struct IOEXCEPTION));
	this->super=ExceptionOlustur(mesaj);
	this->mesaj=mesaj;
	this->getMessage=&IOGetMessage;
	this->Yoket=&IOExceptionYoket;
	return this;
}
char* IOGetMessage(const IOException this){
	return this->super->getMessage(this->super);
}
void throw(const IOException this){
	longjmp(this->super->jumper, -3);
}
void IOExceptionYoket(IOException this){
	if(this==NULL)	return;
	this->super->Yoket(this->super);
	free(this);
}