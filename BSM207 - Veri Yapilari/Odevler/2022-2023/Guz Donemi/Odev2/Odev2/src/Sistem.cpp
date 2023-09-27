/**
 * @file Sistem.cpp
 * @description	Sistemleri ve ona ait organları tutan ve sistemlerle ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Sistem.hpp"

Sistem::Sistem(){
    this->organlar=new Organ *[100];
    this->organAdet=100;
}
Organ *Sistem::GetOrgan(int index){
    return organlar[index];
}
void Sistem::OrganEkle(Organ* organ, int index){
    organlar[index]=organ;
}
int Sistem::GetOrganAdet(){
    return organAdet;
}
Sistem::~Sistem(){
    for (int i=0;i<100;i++)
    {
        delete organlar[i];
    }
	delete[] organlar;
}