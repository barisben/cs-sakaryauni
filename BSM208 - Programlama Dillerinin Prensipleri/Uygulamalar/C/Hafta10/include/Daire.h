#ifndef DAIRE_H
#define DAIRE_H

#include "GeometrikSekil.h"
#include "Math.h"

struct DAIRE{
	GeometrikSekil super;
	double yariCap;
	
	void (*yokEt)(struct DAIRE*);
	//görüleceği üzere Alan ve Cevre fonksiyonları için fonksiyon göstericisi tanımlamıyoruz
	//çünkü Daire kurucusu içerinde GeometrikSekil'in gösterdiği Alan ve Cevre'nin burada tanımladıklarımız olduğunu söyleyeceğiz
};

typedef struct DAIRE* Daire;

Daire DaireOlustur(char*, double);
double Alan(const Daire);
double Cevre(const Daire);
void DaireYoket(Daire);

#endif