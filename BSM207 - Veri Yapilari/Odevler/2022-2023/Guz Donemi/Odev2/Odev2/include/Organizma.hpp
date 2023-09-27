#ifndef ORGANIZMA_HPP
#define ORGANIZMA_HPP
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Sistem.hpp"
using namespace std;

class Organizma{
	private:
        Sistem **sistemler;
		int sistemAdet;
	public:
		Organizma(int);
		void SistemEkle(Sistem*, int);
		void OrganizmaYazdir(bool);
		~Organizma();
};
#endif