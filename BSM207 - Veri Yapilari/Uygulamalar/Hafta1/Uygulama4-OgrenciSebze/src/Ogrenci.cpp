#include "Ogrenci.hpp"

using namespace std;

Ogrenci::Ogrenci(int ysi, double byu, double kl){
yas=ysi;
boy=byu;
kilo=kl;
}
Ogrenci::Ogrenci(){
yas=0;
boy=30;
}
void Ogrenci::YasIlerle(int ys){
yas+=ys;
}
void Ogrenci::BoyUza(double by){
boy+=by;
}
void Ogrenci::YemekYe(Sebze yemek){
kilo+=yemek.getKalori()/1000;
}
int Ogrenci::getYas(){
return yas;
}
double Ogrenci::getBoy(){
return boy;
}
double Ogrenci::getKilo(){
return kilo;
}
Ogrenci::~Ogrenci(){
}