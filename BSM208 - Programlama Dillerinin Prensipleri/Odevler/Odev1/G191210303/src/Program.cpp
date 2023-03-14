#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

enum MALZEME{
	Ahsap, Aluminyum, Fiberglas, Plastik
};

class Kisi{
	private:
		string isim;
		int dogumYili;
		double kilo;
	public:
		Kisi(string isim,int dogumYili,double kilo){
			this->isim = isim;
			this->dogumYili = dogumYili;
			this->kilo = kilo;
		}
		Kisi(){
			this->isim = " ";
			this->dogumYili = 1880;
			this->kilo = 55;
		}
		string getIsim()const{
			return isim;
		}
		int getDogumYili()const{
			return dogumYili;
		}
		double getKilo()const{
			return kilo;
		}
		void YemekYe(double kalori){
			this->kilo += (kalori/1000);
		}
		void Kos(double metre){
			this->kilo -= (metre/1000);
		}
};

class Arac{
	protected:
		Kisi *surucu;
		double benzinLitre;
	public:
		Arac(string isim,int dogumYili,double kilo,double benzinLitre){
			this->surucu = new Kisi(isim,dogumYili,kilo);
			this->benzinLitre = benzinLitre;
		}
		Arac(){
			this->surucu = new Kisi();
			this->benzinLitre = 60;
		}
		void Sur(double km){
			benzinLitre -= ((km/100)*7);
			surucu->Kos(km/100);
		}
		~Arac(){
			delete surucu;
		}
};
class Tekne : public Arac{
	private:
		MALZEME malzeme;
	public:
		Tekne(Kisi* kaptan,double depo,MALZEME malzeme):Arac(kaptan->getIsim(),kaptan->getDogumYili(),kaptan->getKilo(), depo)
		{
			this->malzeme = malzeme;
		}
		Tekne():Arac(){
			surucu = new Kisi();
			benzinLitre = 80;
			malzeme = Ahsap;
		}
		string MalzemeToString(){
			switch(malzeme){
				case Ahsap:
				return "Ahsap";
				case Aluminyum:
				return "Aluminyum";
				case Fiberglas:
				return "Fiberglas";
				case Plastik:
				return "Plastik";
				default:
				return "";
			}
		}
		friend ostream& operator<<(ostream& ekran,Tekne& sag){
			ekran<<"Malzeme: "<<sag.MalzemeToString()<<endl;
			ekran<<"Depo: "<<sag.benzinLitre<<endl;
			ekran<<"Kaptan: "<<sag.surucu->getIsim()<<endl;
			return ekran;
		}
};
int main(){
	Tekne **tekneler = new Tekne*[3];
	tekneler[0] = new Tekne();
	Kisi *ahmetKaptan = new Kisi("Ahmet",1974,85);
	Kisi *mehmetKaptan = new Kisi("Mehmet",1965,81);
	tekneler[1] = new Tekne(ahmetKaptan,75,Fiberglas);
	tekneler[2] = new Tekne(mehmetKaptan,80,Aluminyum);
	cout<<*tekneler[1]<<endl;
	for(int i=0;i<3;i++) delete tekneler[i];
	delete [] tekneler;
	return 0;
}