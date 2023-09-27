/**
 * @file Organizma.cpp
 * @description	Organizmayı ve ona ait sistemleri tutan ve organizmayla ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Organizma.hpp"

Organizma::Organizma(int sistemAdet){
    this->sistemler=new Sistem *[sistemAdet];
    this->sistemAdet=sistemAdet;
}
void Organizma::SistemEkle(Sistem* sistem, int index){
    sistemler[index]=sistem;
}
void Organizma::OrganizmaYazdir(bool mutasyonluMu){
	SetConsoleOutputCP(65001);
	system("CLS");
    if(!mutasyonluMu)   cout<<setw(28)<<"ORGANIZMA"<<endl<<endl;
    else    cout<<setw(40)<<"ORGANIZMA (MUTASYONA UGRADI)"<<endl<<endl;
    
    for (int i=0;i<sistemAdet;i++)
    {
        for(int j=0; j<sistemler[i]->GetOrganAdet(); j++){
            bool dengeliMi=sistemler[i]->GetOrgan(j)->DengeKontrol();
            if(!dengeliMi)  cout<<"#";
            else    cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
Organizma::~Organizma(){
    for (int i=0;i<sistemAdet;i++)
    {
        delete sistemler[i];
    }
	delete[] sistemler;
}