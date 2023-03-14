#include "HeapTree.hpp"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));
	HeapTree *agac=new HeapTree(100);
	int *dizi=new int[25];
	cout<<"Dizinin ilk hali: "<<endl;
	for(int i=0; i<25; i++){
		dizi[i]=rand()%100+1;//1 ila 100 arasında rastgele değer üretip dizinin indekslerine yolluyoruz
		agac->Ekle(dizi[i]);
		cout<<dizi[i]<<" ";
	}
	
	int indeks=0;
	while(!agac->isEmpty()){
		dizi[indeks]=agac->EnKucuguCikar();//sürekli olarak kökü oluşturduğumuz diziye yolluyarak sıralıyoruz
		indeks++;
	}
	
	cout<<"\nDizinin siralanmis hali: "<<endl;
	for(int i=0; i<25; i++)
		cout<<dizi[i]<<" ";
		
	delete[] dizi;
	delete agac;
	return 0;
}