#include <iostream>
#include <string>
using namespace std;

int* DiziOlustur(int uzunluk){
	int* sayilar=new int[uzunluk];//heapte dizi oluşturuldu
	for(int i=0;i<uzunluk;i++){
		sayilar[i]=i;
	}
	return sayilar;
}
//Pointerlar genelde, yani temel amacı heapte adresi göstermek için kullanılır. Bu uygulamada heapte dizi oluşturuluyor!
int main(){
	int uzunluk;
	cout<<"Dizi uzunlugu: "<<endl;
	cin>>uzunluk;
	int *p = DiziOlustur(uzunluk);//pointera dizi atanabiliyor..
	cout<<p[3];//burada örneğin dizi uzunlugu 3 girilirse 3.indisi olmayacağı için rastgele bir sayı üretir
	//c++ tehlikesi burada, kontrolü sana bırakıyor.
	delete p;
	return 0;
}