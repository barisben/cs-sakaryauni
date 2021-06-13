#include "stdio.h"

int main(){
	//ornek1
	int sayi,toplam=0;
	printf("Sayi: ");
	scanf("%d",&sayi);
	while(sayi!=0){
		toplam+=sayi;
		sayi--;
	}
	printf("Toplam: %d",toplam);
	
	//ornek2 iç içe döngü çarpan etkisi
	printf("\n 		Carpim Tablosu\n");
	printf("-----------------------------------------\n");
	printf("# | ");
	for(int i=1;i<=9;i++){
		printf("   %d",i);
	}
	printf("\n-----------------------------------------\n");
	for(int i=1;i<=9;i++){//satir
		printf("%d | ",i);
		for(int j=1;j<=9;j++){//sütun
			if(i*j<10) printf("   %d",i*j);//sonuc tek haneyse daha cok bosluk
			else printf("  %d",i*j);
		}
		printf("\n");
	}
	printf("\n");
	
	//ornek3 break'in tüm döngüye etki etmesi
	printf("\n 		Carpim Tablosu\n");
	printf("-----------------------------------------\n");
	printf("# | ");
	for(int i=1;i<=9;i++){
		printf("   %d",i);
	}
	printf("\n-----------------------------------------\n");
	for(int i=1;i<=9;i++){//satir
		printf("%d | ",i);
		for(int j=1;j<=9;j++){//sütun
			if(i*j<10) printf("   %d",i*j);//sonuc tek haneyse daha cok bosluk
			else goto outer;
		}
		printf("\n");
	}
	outer:
	return 0;
}