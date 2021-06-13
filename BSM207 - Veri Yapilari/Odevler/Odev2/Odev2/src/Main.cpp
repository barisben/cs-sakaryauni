/**
* @file Main.cpp
* @description istenilen işlemleri yürütecek olan ana dosya
* @course 2/B
* @assignment 2. ödev
* @date 27.12.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "DisAVLTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

int main(){
	SetConsoleOutputCP(65001);
	system("CLS");
	DisAVLTree* avl=new DisAVLTree();
	string satir, yil, isYeri, isim;
	ifstream dosya;
	dosya.open("./Veri.txt");
	while (getline(dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, isYeri, '#');
		getline(ss, isim, '#');
		getline(ss, yil, '#');
		avl->Ekle(2020-stoi(yil), isYeri, isim, stoi(yil));
	}
	dosya.close();
	avl->Postorder(avl->kok);
	avl->Temizle();
	return 0;
}