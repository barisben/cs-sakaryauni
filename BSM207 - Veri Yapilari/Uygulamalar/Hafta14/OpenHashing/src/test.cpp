#include "OpenHashing.hpp"

int main(){
	system("CLS");
	OpenHashing *openHashing=new OpenHashing();
	openHashing->Ekle(85);
	openHashing->Ekle(186);
	openHashing->Ekle(2);
	openHashing->Ekle(103);
	openHashing->Ekle(50);
	openHashing->Ekle(151);
	openHashing->Ekle(252);
	openHashing->Yaz();
	if(openHashing->Arama(151))
		cout<<"Sayi bulundu!"<<endl;
	else
		cout<<"Sayi bulunamadi!"<<endl;
	delete openHashing;
	return 0;
}