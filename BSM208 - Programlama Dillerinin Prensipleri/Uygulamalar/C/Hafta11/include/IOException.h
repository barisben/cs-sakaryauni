#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "Exception.h"

struct IOEXCEPTION{
	Exception super;
	char *mesaj;
	
	char* (*getMessage)(struct IOEXCEPTION*);
	void (*Yoket)(struct IOEXCEPTION*);
};
typedef struct IOEXCEPTION* IOException;

IOException IOExceptionOlustur(char*);
char* IOGetMessage(const IOException);
void throw(const IOException);
void IOExceptionYoket(IOException);

#endif