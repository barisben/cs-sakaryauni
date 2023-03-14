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
};

int main(){
	Sayi* s1;
	Sayi* s2;
	Sayi s3(15);
	s1=&s3;
	s2=&s3;
	cout<<*s1;
	cout<<*s2;
	cout<<s3;
	cout<<s1<<endl;//endl kendimiz attık çünkü friendde değer bekliyo ama biz adres gönderiyoruz
	cout<<s2<<endl;
	cout<<&s3;
	return 0;
}