#ifndef PORTFOY_H
#define PORTFOY_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct PORTFOY{
	char *sembol;
	float maliyet;
	int adet;
	char *sifirsizSayi;
	
	void (*toString)(struct PORTFOY*);
	void (*yokEt)(struct PORTFOY*);
};

typedef struct PORTFOY* Portfoy;

Portfoy PortfoyOlustur(char*, float, int);
void PortfoyToString(const Portfoy);
void PortfoyYokEt(Portfoy);

#endif