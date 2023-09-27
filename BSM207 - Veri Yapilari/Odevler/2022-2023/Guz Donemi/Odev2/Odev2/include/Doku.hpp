#ifndef DOKU_HPP
#define DOKU_HPP
#include <iostream>
#include "Radix.hpp"
#include "Hucre.hpp"
using namespace std;

class Doku{
	private:
        Hucre **hucreler;
		int hucreAdet;
		int ortancaHucre;
	public:
		Doku(Hucre**, int, int);
		int GetOrtancaHucre();
		void YenidenSirala();
		void HucreleriMutasyonaUgrat();
		~Doku();
};
#endif