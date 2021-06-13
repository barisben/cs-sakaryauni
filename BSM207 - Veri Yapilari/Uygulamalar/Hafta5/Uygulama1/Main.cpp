#include <iostream>
#include <string>
using namespace std;

int main(){
	int sayilar[]={1,2,3};//stackte oluşturulmuştur çünkü NEW anahtar kelimesi yok!! NEW olsa DELETE gerekir!
	cout<<sayilar<<endl;//diziler aynı zamanda pointerdır, yani 0. indisin adresini gösterecek
	cout<<&sayilar[1]<<endl;//1. indisin adresini gösterecek
	cout<<*sayilar+1<<endl;//1. indisin değerini gösterir
	return 0;
}