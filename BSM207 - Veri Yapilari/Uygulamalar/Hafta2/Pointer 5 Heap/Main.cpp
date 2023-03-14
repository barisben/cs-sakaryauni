#include <iostream>
using namespace std;

class Sayi{
	private:
		int deger;
	public:
		Sayi(int deger){
			this->deger=deger;// this, sınıfın kendisini gösteren pointerdır. yani this->deger privatetaki deger demek
		}
		Sayi(){
			deger=0;
		}
		friend ostream& operator<<(ostream& ekran, Sayi& sayi){
			ekran<<sayi.deger<<endl;
			return ekran;
		}
		~Sayi(){
			cout<<"Yikici metot calisti"<<endl;
		}
};

int main(){
	Sayi* s1 = new Sayi(100);//new Sayi heapte alan oluşturulmasını sağlıyor
	Sayi* s2=s1;
	cout<<*s2;
	delete s1;//oluşturulan heapteki nesne bu komut kullanılmazsa silinmez, bu komut sayesinde yıkıcı metot çalışır.
	cout<<*s2;
	return 0;
}