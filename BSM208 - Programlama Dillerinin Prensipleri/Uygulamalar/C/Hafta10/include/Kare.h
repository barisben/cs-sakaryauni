#ifndef KARE_H
#define KARE_H

#include "GeometrikSekil.h"
#include "Math.h"

struct KARE{
	GeometrikSekil super;
	int kenar;
	
	void (*yokEt)(struct KARE*);
	//görüleceği üzere Alan ve Cevre fonksiyonları için fonksiyon göstericisi tanımlamıyoruz
	//çünkü Kare kurucusu içerinde GeometrikSekil'in gösterdiği Alan ve Cevre'nin burada tanımladıklarımız olduğunu söyleyeceğiz
};

typedef struct KARE* Kare;

Kare KareOlustur(char*, int);
//C'de her ne kadar Alan ve Cevre'nin parametreleri farklı olsa da function overloading olmadığından dolayı program çalıştığında yani derlenme aşamasında 
//fonksiyonların hiçbirisi aynı isimde olmamalıdır.(fonksiyon göstericileri olabilir) Bundan dolayı öncelikle Daire'de Alan ve Cevre adında fonksiyon tanımladığımızdan,
//burada fonksiyon adlarını farklı bir şey yapıyoruz, zaten geometriksekil'de fonksiyon göstericisi yardımı ile çağıracağımızdan bu görünmeyecektir
double alan(const Kare);
double cevre(const Kare);
void KareYoket(Kare);

#endif