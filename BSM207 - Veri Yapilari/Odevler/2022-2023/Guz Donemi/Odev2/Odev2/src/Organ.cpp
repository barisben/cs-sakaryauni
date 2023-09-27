/**
 * @file Organ.cpp
 * @description	Organları ve ona ait dokuları BST'de tutan ve organlarla ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Organ.hpp"

Organ::Organ(){
    this->dokular=new BST();
}
void Organ::DokuEkle(Doku* doku){
    dokular->Ekle(doku);
}
bool Organ::DengeKontrol(){
    return dokular->DengeliMi();
}
void Organ::OrganMutasyon(){
    dokular->MutasyonKontrol();
}
Organ::~Organ(){
    delete dokular;
}