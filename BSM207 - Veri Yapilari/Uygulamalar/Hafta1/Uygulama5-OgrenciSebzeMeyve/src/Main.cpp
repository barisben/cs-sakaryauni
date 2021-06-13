#include <iostream>
#include "Ogrenci.hpp"
#include "Sebze.hpp"
#include "Meyve.hpp"
using namespace std;

int main(){
	Ogrenci o1(10,140, 53);
	cout<<o1<<endl;
	Sebze fasulye(1200);
	Meyve muz(800);
	o1.YemekYe<Sebze>(fasulye);
	o1.YemekYe<Meyve>(muz);
	cout<<o1<<endl;
	return 0;
}