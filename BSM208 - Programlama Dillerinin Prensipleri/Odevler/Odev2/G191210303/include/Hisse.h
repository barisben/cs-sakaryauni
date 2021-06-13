#ifndef HISSE_H
#define HISSE_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct HISSE{
	char *sembol;
	float fiyat;
	
	void (*yokEt)(struct HISSE*);
};

typedef struct HISSE* Hisse;

Hisse HisseOlustur(char*, float);
void HisseYokEt(Hisse);

#endif