#include "Ogrenci.hpp"

using namespace std;

Ogrenci::Ogrenci(int ysi, double byu){
yas=ysi;
boy=byu;
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
int Ogrenci::getYas(){
return yas;
}
int Ogrenci::getBoy(){
return boy;
}
Ogrenci::~Ogrenci(){
}