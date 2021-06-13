#ifndef GEOMETRIKSEKIL_H
#define GEOMETRIKSEKIL_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct GEOMETRIKSEKIL{
	char *renk;
	char *olusturulmaTarihi;
	
	char* (*getOlusturulmaTarihi)(struct GEOMETRIKSEKIL*);
	void (*yokEt)(struct GEOMETRIKSEKIL*);
	void (*toString)(struct GEOMETRIKSEKIL*, void*);
	//abstract fonksiyonlar, kare mi daire mi çağıracağımız belli olmadığı için parametresiz
	double (*Alan)();
	double (*Cevre)();
};

typedef struct GEOMETRIKSEKIL* GeometrikSekil;

GeometrikSekil GeometrikSekilOlustur(char*);
char* OlusturulmaTarihi(const GeometrikSekil);
//yazdir metodunda alan ve çevre bilgisi de yazdırılacağı için ve hangisini yazdıracağımızı bilmediğimizden(birinde Daire, birinde Kare türünden olacak) 2. parametre olarak void* alıyoruz
void Yazdir(const GeometrikSekil, void*);//void*, aslında geometriksekil de pointer olmalı fakat zaten kendisi struct geometriksekil*'ı ifade ediyor. struct içinde de fonksiyon göstericisinde belli
void GeometrikSekilYokEt(GeometrikSekil);

#endif