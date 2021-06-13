#ifndef BANKA_H
#define BANKA_H

#include "Emir.h"
#include "Hisse.h"
#include "Portfoy.h"

typedef enum BOOL{false, true}bool;

struct BANKA{
	Hisse hisseObj;
	Portfoy portfoyObj;
	Emir emirObj;
	
	char **satisSemboller;
	float *satisKarZararlar;
	int satisSayisi;
	
	void (*alimSatim)(struct BANKA*, struct HISSE*, struct PORTFOY*, struct EMIR*);
	void (*toString)(struct BANKA*);
	void (*yokEt)(struct BANKA*);
};

typedef struct BANKA* Banka;

Banka BankaOlustur();
void BankaAlimSatim(const Banka, const Hisse, const Portfoy, const Emir);
void BankaToString(const Banka);
void BankaYokEt(Banka);

#endif