#include "stdio.h"

const char* SehirDondur(){
	const char* str="Sakarya";
	return str;
}

char* SehirDondur2(){
	char str[]="Ankara";
	return str;
}

void f(){
	static int h=10;
}

int main(){
	//diziler ornek1
	/*int x[5];
	int y[3][5];
	printf("%d\n",x[0]);
	printf("%d\n",y[2][3]);*/
	
	//string ornek2
	char *isim="Baris";
	printf("%c\n",*isim);
	printf("%s\n",isim);
	
	//string ve normal dizi char fonk ornek3
	printf("%s\n",SehirDondur());
	printf("%s\n",SehirDondur2());
	
	//C ve Java farkı ornek4
	int x=100,y=50;
	int *p=&x;
	int *r=&y;
	int *tmp=p;
	p=r;
	r=tmp;
	printf("%d\n",*p);
	printf("%d\n",*r);
	
	//ornek5 bool
	int n=4,m=3;
	printf("%d",n>m);
	
	return 0;
}