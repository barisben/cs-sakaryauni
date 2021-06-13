#ifndef HISSE_H
#define HISSE_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#include "cJSON.h"

struct HISSE{
	cJSON *root;
	
	char **semboller;
	float *fiyatlar;
	int hisseSayisi;
	
	void (*oku)(struct HISSE*, char*);
	void (*yokEt)(struct HISSE*);
};

typedef struct HISSE* Hisse;

Hisse HisseOlustur();
void HisseOku(const Hisse, char*);
void HisseYokEt(Hisse);

#endif