#ifndef BANKA_H
#define BANKA_H

#include "Dosya.h"

typedef enum BOOL{false, true}bool;

struct BANKA{
	Dosya hisseObj;
	Dosya portfoyObj;
	Dosya emirObj;
	
	char **satisSemboller;
	float *satisKarZararlar;
	int satisSayisi;
	char *sifirsizSayi;
	
	void (*alimSatim)(struct BANKA*, struct DOSYA*, struct DOSYA*, struct DOSYA*);
	void (*toString)(struct BANKA*);
	void (*yokEt)(struct BANKA*);
};

typedef struct BANKA* Banka;

Banka BankaOlustur();
void BankaAlimSatim(const Banka, const Dosya, const Dosya, const Dosya);
void BankaToString(const Banka);
void BankaYokEt(Banka);

#endif