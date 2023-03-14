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
	Sayi* s1 = new Sayi(100);//new Sayi heapte alan oluşturulmasını sağlıyor
	Sayi* s2 = new Sayi(70);
	
	cout<<*s1;
	cout<<*s2;
	
	Sayi* syedek;
	syedek=s1;
	s1=s2;
	s2=syedek;
	
	cout<<*s1;
	cout<<*s2;
	
	delete s1;//oluşturulan heapteki nesne bu komut kullanılmazsa silinmez, bu komut sayesinde yıkıcı metot çalışır.
	delete s2;
	return 0;
}