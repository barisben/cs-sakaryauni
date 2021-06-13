#ifndef DOSYA_H
#define DOSYA_H

#include "setjmp.h"

#include "cJSON.h"
#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"

struct DOSYA{
	cJSON *root;
	Hisse* hisseler;
	Portfoy* portfoyler;
	Emir* emirler;
	
	int objSayisi;
	int emirSatisSayisi;
	char *yol;
	char *data;
	jmp_buf jumper;
	
	void (*oku)(struct DOSYA*);
	void (*hisseParse)(struct DOSYA*);
	void (*portfoyParse)(struct DOSYA*);
	void (*emirParse)(struct DOSYA*);
	void (*yokEt)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur(char*);
void Oku(const Dosya);
void HisseParseEt(const Dosya);
void PortfoyParseEt(const Dosya);
void EmirParseEt(const Dosya);
void DosyaYokEt(Dosya);
#endif