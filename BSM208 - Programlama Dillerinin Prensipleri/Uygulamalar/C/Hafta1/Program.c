#include "stdio.h"

int main(){
	int sayi;
	do{
		printf("4 basamakli sayi:" );
		scanf("%d",&sayi);
	}while(sayi<=1000 || sayi>=9999);
	
	short birler,onlar,yuzler,binler;
	binler=sayi/1000;
	yuzler=(sayi%1000)/100;
	onlar=(sayi%100)/10;
	birler=sayi%10;
	
	printf("\nBinler: %d\n",binler);
	printf("\nYuzler: %d\n",yuzler);
	printf("\nOnlar: %d\n",onlar);
	printf("\nBirler: %d\n",birler);
	getchar();
	return 0;
}