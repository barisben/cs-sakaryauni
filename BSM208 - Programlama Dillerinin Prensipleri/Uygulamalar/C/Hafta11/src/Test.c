#include "Dosya.h"

int main(){
	Dosya dosya=DosyaOlustur("./doc/den2eme.txt");
	
	//EXCEPTION KUTUPHANESI OLMASAYDI, ORNEK 1
	/*
	if(setjmp(dosya->jumper) == 0)
		printf("%s", dosya->Oku(dosya));
	else{
		printf("Dosya okuma hatasi!");
	}
	*/
	
	//EXCEPTION KUTUPHANESI OLDUGU ICIN, ORNEK 2
	if(setjmp(dosya->exception->super->jumper) == 0){
		char *str=dosya->Oku(dosya);
		printf("%s\n",str);
	}
	else{
		printf("%s", dosya->exception->getMessage(dosya->exception));
	}
	
	
	dosya->Yoket(dosya);
	return 0;
}