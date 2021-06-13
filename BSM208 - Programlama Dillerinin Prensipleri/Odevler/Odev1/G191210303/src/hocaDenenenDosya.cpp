#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
#include <string>
using namespace std;

class Insan{
	private:
		string tcKimlikNo;
		string isim;
		int yas;
		
	protected:
		string DoubletoString(double num){
			ostringstream str;
			str<<num;
			return str.str();
		}

	public:
		Insan(string tcKimlikNo, string isim,int yas){
			this->tcKimlikNo = tcKimlikNo;
			this->isim = isim;
			this->yas = yas;
		}
		string TCKimlikNo(){
			return tcKimlikNo;
		}
		string toString(){
			return tcKimlikNo+"\t"+isim+"\t"+DoubletoString(yas);
		}
};

class Calisan : public Insan
{
	private:
		double maas;
		int tecrubeYil;
		bool emeklimi;
		
	public:
		Calisan(string tcKimlikNo,string isim,int yas,double maas,int tecrubeYil,bool emeklimi) : Insan(tcKimlikNo,isim,yas) {
			this->maas = maas;
			this->tecrubeYil = tecrubeYil;
			this->emeklimi = emeklimi;
		}
		double IkramiyeHesapla(){
			return (tecrubeYil*maas) / 2020;
		}
		double KatSayiHesapla(double *donemselMaaslar,int uzunluk){
			int katSayi=1;
			
			for(int ind=0;ind<uzunluk;ind++){
				katSayi += donemselMaaslar[ind]/30;
				for(int i=0;i<7;i++){
					if(katSayi%15 == 3) break;
					katSayi++;
				}
			}
			return katSayi;
		}
		bool mutlumu(){
			int r = rand() % 100;
			if(r > 5) return true;
			else return false;
		}
		string toString(){
			return Insan::toString()+
			"\nCalisan Bilgileri: "+DoubletoString(maas)+" "+DoubletoString(tecrubeYil);
		}
};

class Doktor : public Calisan{
	private:
		double gunlukVisitSaati;
	public:
		Doktor(string tcKimlikNo,string isim,int yas,double maas,int tecrubeYil,bool emeklimi,double gunlukVisitSaati): 
		Calisan(tcKimlikNo, isim,yas,maas,tecrubeYil,emeklimi){
			this->gunlukVisitSaati = gunlukVisitSaati;
		}
		double KatSayiHesapla(double *donemselMaaslar,int uzunluk)
		{
			return 100*Calisan::KatSayiHesapla(donemselMaaslar, uzunluk);
		}
		bool operator==(Doktor& sag){
			return this->TCKimlikNo() == sag.TCKimlikNo();
		}
		string toString(){
			return Calisan::toString()+"\nDoktor Gunluk Visit Sayisi: "+DoubletoString(gunlukVisitSaati);
		}
};

int main(){
	Doktor *d = new Doktor("5462315613","Ahmet",52,25000,20,false,15);
	cout<<d->toString()<<endl;
	delete d;
	return 0;
}

