#ifndef SISTEM_HPP
#define SISTEM_HPP
#include <iostream>
#include "Organ.hpp"
using namespace std;

class Sistem{
	private:
        Organ **organlar;
		int organAdet;		
	public:
		Sistem();
		Organ *GetOrgan(int);
		void OrganEkle(Organ*, int);
		int GetOrganAdet();
		~Sistem();
};
#endif