#include "stdio.h"

double Topla(double, double);

//adres ile cagirma
void degistir(int *dizi){
	//dizi[5]=100; p[5] 100 yazdırır
	dizi=NULL; //p[5] 60 yazdırır
}

int main(){
	//ornek1
	//printf("%lf", Topla(5.8,9.17)); 
	
	//ornek2 adres ile çağırma
	int p[]={10,20,30,40,50,60,70};
	degistir(p);
	printf("%d",p[5]);
	
	return 0;
}

double Topla(double x, double y){
	return x+y;
}