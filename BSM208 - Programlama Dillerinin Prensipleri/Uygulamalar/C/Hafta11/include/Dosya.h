#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include "setjmp.h"

#include "IOException.h"

struct DOSYA{
	char *yol;
	char *icerik;
	//jmp_buf jumper; //Exception kütüphanesi yazılmamış olsaydı
	IOException exception; //Exception kütüphanesi yazıldığı için
	
	char*(*Oku)(struct DOSYA*);
	void (*Yoket)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur(char*);
char* oku(const Dosya);
void DosyaYoket(Dosya);
#endif