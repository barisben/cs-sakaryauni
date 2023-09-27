#ifndef KONTROL_HPP
#define KONTROL_HPP
#include <iostream>
#include "Sistem.hpp"
using namespace std;

class Kontrol{
	private:
        Sistem **sistemler;
		int sistemAdet;
	public:
		Kontrol(Sistem**, int);
		void KokKontrol();
};
#endif