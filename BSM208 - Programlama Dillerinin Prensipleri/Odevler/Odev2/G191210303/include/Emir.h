#ifndef EMIR_H
#define EMIR_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct EMIR{
	char *sembol;
	char *islem;
	int adet;
	int satisSayisi;
	
	void (*yokEt)(struct EMIR*);
};

typedef struct EMIR* Emir;

Emir EmirOlustur(char*, char*, int);
void EmirYokEt(Emir);

#endif