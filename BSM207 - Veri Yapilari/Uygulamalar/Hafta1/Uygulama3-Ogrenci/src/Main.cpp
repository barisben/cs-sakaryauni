#include <iostream>
#include "Ogrenci.hpp"

using namespace std;

int main(){
	Ogrenci o1(10,140),o2(5, 135);
	cout<<"Ogrenci 1\n";
	cout<<"Yas: "<<o1.getYas()<<endl;;
	cout<<"Boy: "<<o1.getBoy()<<endl;;
	cout<<"Ogrenci 2\n";
	cout<<"Yas: "<<o2.getYas()<<endl;
	cout<<"Boy: "<<o2.getBoy()<<endl;
	o1.YasIlerle(15);
	o2.BoyUza(25);
	cout<<"-------------------------------------\n";
	cout<<"Ogrenci 1\n";
	cout<<"Yas: "<<o1.getYas()<<endl;;
	cout<<"Boy: "<<o1.getBoy()<<endl;;
	cout<<"Ogrenci 2\n";
	cout<<"Yas: "<<o2.getYas()<<endl;
	cout<<"Boy: "<<o2.getBoy()<<endl;
	return 0;
}