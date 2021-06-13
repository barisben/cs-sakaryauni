#include "stdio.h"
#include "stdlib.h"

int main(){
	int x=100;
	double a=18.24;
	void *obj;
	obj=&x;
	printf("%d\n",*(int*)obj);
	obj=&a;
	printf("%lf",*(double*)obj);
	return 0;
}