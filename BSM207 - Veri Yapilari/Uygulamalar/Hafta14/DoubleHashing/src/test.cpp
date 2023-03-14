#include "DoubleHashing.hpp"

int main(){
	system("CLS");
	DoubleHashing *doubleHashing=new DoubleHashing();
	int dizi[]={15,9,62,34,59,37,85,42,102,1,135};
	for(int i=0; i<11; i++)
		doubleHashing->Ekle(dizi[i]);
	if(doubleHashing->Arama(85))
		cout<<"Sayi bulundu!"<<endl;
	else
		cout<<"Sayi bulunamadi!"<<endl;
	doubleHashing->Cikar(85);
	if(doubleHashing->Arama(85))
		cout<<"Sayi bulundu!"<<endl;
	else
		cout<<"Sayi bulunamadi!"<<endl;
	doubleHashing->Yaz();
	delete doubleHashing;
	return 0;
}