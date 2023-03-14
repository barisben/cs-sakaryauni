#include <iostream>
using namespace std;

class Sayi{
	private:
		int* pdeger;
	public:
		Sayi(int deger){
			this->pdeger=new int(deger);// this, sınıfın kendisini gösteren pointerdır. yani this->deger privatetaki deger demek
		}
		Sayi(){
			this->pdeger=new int(0);
		}
		friend ostream& operator<<(ostream& ekran, Sayi& sayi){
			ekran<<*sayi.pdeger<<endl;
			return ekran;
		}
		~Sayi(){
			cout<<"Yikici metot calisti"<<endl;
			delete pdeger;//kurucular içerisinde oluşturduğumuz heaplerden dolayı... önemli!
		}
};//Yani her new için delete de gerekli!!!

int main(){
	Sayi* s1 = NULL;//hiçbir şey göstermemesi istenirse NULL olmalı.
	cout<<s1;
	delete s1;//oluşturulan heapteki nesne bu komut kullanılmazsa silinmez, bu komut sayesinde yıkıcı metot çalışır.
	return 0;
}