#ifndef ORDER_H
#define ORDER_H

#include "stdio.h"
#include "stdlib.h"

typedef enum BOOL{false, true}bool;//bool tanımlama

struct ORDER{
	int *sayilar;
	int uzunluk;//C  dilinde dizi uzunlugunu bulamadigimiz icin
	
	//bu fonk göstericisi yardımıyla Order sözde benzetimli class'ı içerisinden fonksiyonları çağırabileceğiz
	//yani aslında bunlar dışarıda o aşağıda tanımladığımız Sirala vs. fonksiyonları gösteriyor.
	int* (*sirala)(struct ORDER*);//fonksiyon göstericisi, Sirala fonk ile aynı imzaya sahip
	//int* kısmı Sirala'nın int* döndürdüğünü belirtir, (*sirala)'da ise parantez içerisine yazılmış
	//olması bunun bir fonksiyon göstericisi olduğu anlamına gelir. Ayrıca fonk adının başına da * konulur.
	void (*toString)(struct ORDER*);
	bool (*equals)(struct ORDER*, struct ORDER*);//Java equals benzetimi, normalde tek parametre fakat burada 2 tipi de aynı anda vermemiz gerek
	void (*orderYokEt)(struct ORDER*);
	
	//zaten kurucuyu başta kendimiz mecbur çağıracağımız için onun için göstericiye gerek yok
};

typedef struct ORDER* Order;

Order OrderOlustur(int sayilar[], int);
int *Sirala(const Order);
void ToString(const Order);
bool Equals(const Order, const Order);
void OrderYokEt(Order);

#endif