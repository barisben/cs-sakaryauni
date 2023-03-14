#include <iostream>
#include <string>
using namespace std;

class Kisi{
	private:
		string isim;
	public:
		Kisi(string isim){
			this->isim=isim;
		}
		friend ostream& operator<<(ostream& ekran, Kisi& sag){
			ekran<<sag.isim<<endl;
			return ekran;
		}
};

void Yazdir(Kisi** kisiDizi, int kisiSayisi){
	for(int i=0;i<kisiSayisi;i++){
		cout<<*kisiDizi[i];
	}
}

void Yoket(Kisi** kisiDizi, int kisiSayisi){
	for(int i=0;i<kisiSayisi;i++){
		delete kisiDizi[i];
	}
}

int main(){
	Kisi** kisiler=new Kisi*[3];//normalde öğrenci sınıfı olsa 1'er 1'er o1 gibi öğrenci olustururduk ama burada 1'den fazla oldugu icin ** kullanılıyor
	kisiler[0]=new Kisi("ahmet");
	kisiler[1]=new Kisi("mehmet");
	kisiler[2]=new Kisi("ayse");
	Yazdir(kisiler, 3);
	Yoket(kisiler, 3);
	delete[] kisiler;//heapten diziyi silme
	return 0;
}