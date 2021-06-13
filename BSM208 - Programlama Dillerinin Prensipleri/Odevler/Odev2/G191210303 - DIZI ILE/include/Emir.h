#ifndef EMIR_H
#define EMIR_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#include "cJSON.h"

struct EMIR{
	cJSON *root;
	
	char **semboller;
	char **islemler;
	int *adetler;
	int emirSayisi;
	int satisSayisi;
	
	void (*oku)(struct EMIR*, char*);
	void (*yokEt)(struct EMIR*);
};

typedef struct EMIR* Emir;

Emir EmirOlustur();
void EmirOku(const Emir, char*);
void EmirYokEt(Emir);

#endif