/**
 * @file Hucre.cpp
 * @description	Hucreleri tutan ve hucrelerle ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Hucre.hpp"

Hucre::Hucre(int dnaUzunlugu){
    this->dnaUzunlugu=dnaUzunlugu;
}
void Hucre::SetDnaUzunlugu(int dnaUzunlugu){
    this->dnaUzunlugu=dnaUzunlugu;
}
int Hucre::GetDnaUzunlugu(){
    return dnaUzunlugu;
}