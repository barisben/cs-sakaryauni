#include "Kisi.h"

int main(){
	Kisi k=KisiOlustur("Ahmet", 35, 5);
	YemekYe(k,1200);
	toString(k);
	KisiYokEt(k);
	return 0;
}