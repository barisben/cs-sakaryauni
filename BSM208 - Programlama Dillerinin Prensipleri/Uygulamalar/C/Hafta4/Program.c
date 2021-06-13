#include "stdio.h"
#include "stdlib.h"

int main(){
	//ornek1
	int x;
	printf("Bir sayi giriniz: ");
	scanf("%d",&x);
	if(x%2==0)
		if(x<100)
			if(x>10)
				printf("Girilen sayi 10'dan buyuk, 100'den kucuk ve cift!\n");
	else
		printf("elsedeyim\n");
	
	//ornek2 Uclu Operatör
	int sayi;
	printf("Bir sayi giriniz: ");
	scanf("%d",&sayi);
	char* sonuc;
	sonuc=(sayi%2==0 ? "Sayi Cifttir\n" : "Sayi Tektir\n");
	printf("%s",sonuc);
	
	//ornek3 heap bellekte 10 elemanlı dizi olusturma
	int *dizi=malloc(10*sizeof(int));
	dizi[2]=100;
	printf("%d",dizi[2]);
	free(dizi);
	return 0;
}