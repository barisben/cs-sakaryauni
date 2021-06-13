#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include "setjmp.h"

struct DOSYA{
	char *yol;
	char *data;
	jmp_buf jumper;
	
	char*(*oku)(struct DOSYA*);
	void (*yokEt)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur(char*);
char* Oku(const Dosya);
void DosyaYokEt(Dosya);
#endif