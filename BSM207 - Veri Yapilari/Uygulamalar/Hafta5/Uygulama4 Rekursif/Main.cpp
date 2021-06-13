#include <iostream>
#include <string>
using namespace std;

//Özyineleme yani rekürsiyon, bir fonksiyonun kendi kendisini çağırmasıdır!! Ayrıca kod da kısaltır.

int FaktoriyelRekursif(int sayi){
	if(sayi<=1)
		return 1;
	return sayi*FaktoriyelRekursif(sayi-1);
}


/*int FaktoriyelIteratif(int sayi){//Normal çözüm. Yani diğer adı iteratif oluyor.
	int sonuc=1;
	for(int i=2;i<=sayi;i++){
		sonuc*=i;
	}
	return sonuc;
}*/

int main(){
	//Rekursif uygulanması
	int sayi;
	cout<<"Sayi: "<<endl;
	cin>>sayi;
	cout<<sayi<<"! = "<<FaktoriyelRekursif(sayi)<<endl;
	
	
	/*Iteratifin uygulanması
	int sayi;
	cout<<"Sayi: "<<endl;
	cin>>sayi;
	cout<<sayi<<"! = "<<FaktoriyelIteratif(sayi)<<endl;;,
	*/
	return 0;
}