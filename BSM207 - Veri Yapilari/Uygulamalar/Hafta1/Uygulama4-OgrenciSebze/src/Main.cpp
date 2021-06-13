#include <iostream>
#include "Ogrenci.hpp"
#include "Sebze.hpp"
using namespace std;

int main(){
	Ogrenci o1(10,140, 53);
	cout<<"Ogrenci 1\n";
	cout<<"Yas: "<<o1.getYas()<<endl;;
	cout<<"Boy: "<<o1.getBoy()<<endl;;
	cout<<"Kilo: "<<o1.getKilo()<<endl;
	Sebze fasulye(2000);
	o1.YemekYe(fasulye);
	cout<<"-------------------------------------\n";
	cout<<"Ogrenci 1\n";
	cout<<"Yas: "<<o1.getYas()<<endl;;
	cout<<"Boy: "<<o1.getBoy()<<endl;;
	cout<<"Kilo: "<<o1.getKilo()<<endl;
	return 0;
}