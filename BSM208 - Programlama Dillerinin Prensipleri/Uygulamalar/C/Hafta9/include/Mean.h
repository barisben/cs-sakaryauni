#ifndef MEAN_H
#define MEAN_H

#include "stdio.h"
#include "stdlib.h"

#include "Order.h"//kalıtım icin

struct MEAN{
	Order super;//Mean kurucusu cagırıldıgında Order'ın da kurucusunun cagırılması icin, yani kalıtım
	double (*ortalama)(struct MEAN*);
	void (*yazdir)(struct MEAN*);
	void (*meanYokEt)(struct MEAN*);
};

typedef struct MEAN* Mean;

Mean MeanOlustur(int sayilar[], int);
double Ortalama(const Mean);
void Yazdir(const Mean);
void MeanYokEt(Mean);

#endif