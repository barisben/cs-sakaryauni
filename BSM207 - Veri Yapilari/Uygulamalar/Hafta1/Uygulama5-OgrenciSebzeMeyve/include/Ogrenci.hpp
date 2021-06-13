#ifndef OGRENCI_HPP
#define OGRENCI_HPP
#include "Sebze.hpp"
#include "Meyve.hpp"
#include <iostream>
using namespace std;
class Ogrenci{
	private:
		int yas;
		double boy;
		double kilo;
	public:
		Ogrenci(int, double, double);
		Ogrenci();
		void YasIlerle(int);
		void BoyUza(double);
		template <typename YIYECEK>
		void YemekYe(YIYECEK yiyecek){
			kilo+=yiyecek.getKalori()/1000;
		}
		int getYas();
		double getBoy();
		double getKilo();
		friend ostream& operator<<(ostream&, Ogrenci&);
		~Ogrenci();
};

#endif