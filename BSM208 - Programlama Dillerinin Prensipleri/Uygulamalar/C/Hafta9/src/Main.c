#include "Mean.h"
#include "Order.h"

int main(){
	int notlar[]={18,63,97,100,52,27,35};
	Mean m=MeanOlustur(notlar,7);
	m->yazdir(m);
	m->meanYokEt(m);
	
	Order o1=OrderOlustur(notlar,7);
	Order o2=OrderOlustur(notlar,7);
	if(o1->equals(o1,o2))	printf("Esittir!");
	else printf("Esit degil!");
	
	o1->orderYokEt(o1);
	o2->orderYokEt(o2);
	
	return 0;
}