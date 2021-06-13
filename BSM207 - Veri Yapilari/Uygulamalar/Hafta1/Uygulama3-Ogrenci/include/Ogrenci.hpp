#ifndef OGRENCI_HPP
#define OGRENCI_HPP

class Ogrenci{
	private:
		int yas;
		double boy;
	public:
		Ogrenci(int, double);
		Ogrenci();
		void YasIlerle(int);
		void BoyUza(double);
		int getYas();
		int getBoy();
		~Ogrenci();
};

#endif