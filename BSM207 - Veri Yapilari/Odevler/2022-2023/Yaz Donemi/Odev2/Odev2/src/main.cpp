/**
* @file main.cpp
* @description odevde istenen islemleri yapar
* @course 1/A
* @assignment 2. Odev
* @date 02.08.2023
* @author Ahmet Faruk Sezgenç - faruksezgenc@gmail.com
*/

#include "BST.hpp"
#include "Stack.hpp"

#include <fstream>
#include <sstream>
#include <windows.h>

int main()
{
	ifstream dosya;
	string satir;
	int sayi;
	
	dosya.open("./Sayilar.txt");
	while(getline(dosya, satir)){
		if (satir.empty()) continue;
		
		int stackSayisi=1, oncekiSayi=0, i=0;
		
		istringstream in(satir);
		while(in >> sayi){
			if(sayi>oncekiSayi && sayi%2==0 && i!=0) stackSayisi++;
			oncekiSayi=sayi;
			i++;
		}
		
		Stack **stacks=new Stack *[stackSayisi];
		i=0;
		oncekiSayi=0;
		stackSayisi=1;

		istringstream in2(satir);
		stacks[stackSayisi-1]=new Stack();
		while(in2 >> sayi){
			if(sayi>oncekiSayi && sayi%2==0 && i!=0){
				stackSayisi++;
				stacks[stackSayisi-1]=new Stack();
				stacks[stackSayisi-1]->push(sayi);
			}
			else	stacks[stackSayisi-1]->push(sayi);
			
			oncekiSayi=sayi;
			i++;
		}
		
		BST **lists=new BST *[stackSayisi];
		int highestIndex=0, highestHeight=0;
		
		for (int i=0;i<stackSayisi;i++)
		{
			lists[i]=new BST();
			stacks[i]->bst=lists[i];
			delete stacks[i];
			int height=lists[i]->Height();
			if(highestHeight<height){
				highestIndex=i;
				highestHeight=height;
			}
			else if(highestHeight==height){
				if(lists[highestIndex]->TotalValue()<lists[i]->TotalValue()) highestIndex=i;
			}
		}
		delete[] stacks;
		
		lists[highestIndex]->postorder();
		cout<<endl;
		Sleep(10);
		
		for (int i=0;i<stackSayisi;i++)
		{
			delete lists[i];
		}
		delete[] lists;
	}
	dosya.close();
	
	return 0;
}
