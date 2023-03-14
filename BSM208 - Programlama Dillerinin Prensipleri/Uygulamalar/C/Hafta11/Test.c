#include "stdio.h"
#include "setjmp.h"

jmp_buf jumper;

int Bolme(int x, int y){
	if(y==0)	longjmp(jumper, -3);
	return x/y;
}

int main(){
	int a=10, b=0;
	if(setjmp(jumper)==0)
		printf("%d", Bolme(a,b));
	else
		printf("Sifira bolunme hatasi!");
	
	return 0;
}