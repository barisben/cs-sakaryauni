#include "stdio.h"

int main(){
	//ornek1
	float x=10;
	double a=10;
	float y=3;
	double b=3;
	float z=x/y;
	double c=a/b;
	
	if(z==c) printf("Esit");
	else printf("Esit degil!");
	
	//ornek2
	double pi=3.14;
	int q=pi;
	printf("%d\n",q);
	
	//ornek3
	/* buna izin vermez const yani sabit oldugu icin
	const double yercekim;
	yercekim=10;
	*/
	//boyle olmali yani tanımlandıgı yerde atama yapılmalı
	const double yercekim=10;
	double kutle=100;
	printf("Kuvvet: %lf",yercekim*kutle);
	
	return 0;
}