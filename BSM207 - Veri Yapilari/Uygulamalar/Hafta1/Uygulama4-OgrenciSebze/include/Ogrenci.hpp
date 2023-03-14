#ifndef OGRENCI_HPP
#define OGRENCI_HPP
#include "Sebze.hpp"

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
		void YemekYe(Sebze);
		int getYas();
		double getBoy();
		double getKilo();
		~Ogrenci();
};

#endif