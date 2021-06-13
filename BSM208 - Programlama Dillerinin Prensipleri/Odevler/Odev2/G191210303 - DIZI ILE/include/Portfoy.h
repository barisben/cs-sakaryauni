#ifndef PORTFOY_H
#define PORTFOY_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#include "cJSON.h"

struct PORTFOY{
	cJSON *root;
	
	char **semboller;
	float *maliyetler;
	int *adetler;
	int portfoySayisi;
	
	void (*oku)(struct PORTFOY*, char*);
	void (*toString)(struct PORTFOY*);
	void (*yokEt)(struct PORTFOY*);
};

typedef struct PORTFOY* Portfoy;

Portfoy PortfoyOlustur();
void PortfoyOku(const Portfoy, char*);
void PortfoyToString(const Portfoy);
void PortfoyYokEt(Portfoy);

#endif