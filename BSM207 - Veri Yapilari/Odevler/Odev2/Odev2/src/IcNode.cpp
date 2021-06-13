/**
* @file IcNode.cpp
* @description IcNode sınıfındaki metotların oluşturulduğu dosya
* @course 2/B
* @assignment 2. ödev
* @date 27.12.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "IcNode.hpp"

IcNode::IcNode(const int& veri, string isim, int yil, IcNode* sol, IcNode* sag)
{
	this->veri=veri;
	this->sol=sol;
	this->sag=sag;
	this->isim=isim;
	this->yil=yil;
	yukseklik=0;
}