/**
* @file DisNode.cpp
* @description DisNode sınıfındaki metotların oluşturulduğu dosya
* @course 2/B
* @assignment 2. ödev
* @date 27.12.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "DisNode.hpp"

DisNode::DisNode(string isYeri, DisNode* sol, DisNode* sag)
{
	this->sol=sol;
	this->sag=sag;
	this->isYeri=isYeri;
	icAVL=new IcAVLTree;
	veri=1;
	yukseklik=0;
}