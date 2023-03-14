#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "stdio.h"
#include "stdlib.h"
#include "setjmp.h"

struct EXCEPTION{
	char *mesaj;
	jmp_buf jumper;
	
	char*(*getMessage)(struct EXCEPTION*);
	void (*Yoket)(struct EXCEPTION*);
};
typedef struct EXCEPTION* Exception;

Exception ExceptionOlustur(char*);
char* GetMessage(const Exception);
void ExceptionYoket(Exception);


#endif