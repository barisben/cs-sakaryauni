#include "stdio.h"
#include "stdlib.h"

int main(){
	int *p=malloc(sizeof(int));
	*p=100;
	printf("%d\n",*p);
	printf("%x\n",p);
	printf("%x\n",&p);
	free(p);
	return 0;
}