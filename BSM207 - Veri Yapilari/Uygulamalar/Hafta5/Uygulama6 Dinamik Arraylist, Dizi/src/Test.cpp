#include<iostream>
#include "ArrayList.hpp"

using namespace std;

int main()
{
	ArrayList<string> *isimler = new ArrayList<string>();
	int sec=0;
	string isim;
	do{
		system("CLS");
		cout<<"1.Isim Ekle"<<endl;
		cout<<"2.Isim Sil"<<endl;
		cout<<"3.Konumdan Isim Sil"<<endl;
		cout<<"4.Konuma Isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.Isim Sayisi"<<endl;
		cout<<"7.Ilk Isim"<<endl;
		cout<<"8.Son Isim"<<endl;
		cout<<"9.Isimleri Listele"<<endl;
		cout<<"10.Isimleri Temizle"<<endl;
		cout<<"11.Cikis"<<endl;
		cout<<"Secim:";
		cin>>sec;
		system("CLS");
		switch(sec){
			case 1:{
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->Add(isim);
			}break;
			case 2:{
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->Remove(isim);	
				cin.get();
			}break;
			case 3:{
				int konum;
				cout<<"Konum:";
				cin>>konum;
				isimler->RemoveAt(konum);	
				cin.get();
			}break;
			case 4:{
				string isim;
				int konum;
				cout<<"Konum:";
				cin>>konum;
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->Insert(konum,isim);
				cin.get();
			}break;
			case 5:{
				string isim;
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				cout<<"Konum:"<<isimler->IndexOf(isim);
				cin.get();
			}break;
			case 6:{		
				cout<<"Isim Sayisi:"<<isimler->Size()<<endl;
				cin.ignore();
				cin.get();
			}break;	
			case 7:{
				cout<<"Ilk Isim:"<<isimler->First()<<endl;
				cin.ignore();
				cin.get();
			}break;	
			case 8:{
				cout<<"Son Isim:"<<isimler->Last()<<endl;
				cin.ignore();
				cin.get();
			}break;	
			case 9:{	
				cout<<"ISIMLER";
				cout<<*isimler<<endl;
				cin.ignore();
				cin.get();
			}break;	
			case 10:{
				isimler->Clear();
				cout<<endl<<"Tum isimler silindi."<<endl;
				cin.ignore();
				cin.get();
			}break;
			case 11:
			break;
			default:{
				cout<<endl<<"Yanlis tercih!"<<endl;
				cin.ignore();
				cin.get();
			}break;
		}
		system("CLS");
	}while(sec != 11);
	delete isimler;
}