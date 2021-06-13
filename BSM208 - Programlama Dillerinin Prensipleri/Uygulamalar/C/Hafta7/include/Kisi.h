#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"

struct KISI{
	char *isim;
	float boy;
	float kilo;
	int yas;
};

typedef struct KISI* Kisi;

Kisi KisiOlustur(char* isim, float, float);
void YasIlerle(const Kisi, int);
void YemekYe(const Kisi, float);
void toString(const Kisi);
void KisiYokEt(Kisi);

#endif