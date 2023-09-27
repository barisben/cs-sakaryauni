#include "Kontrol.hpp"

Kontrol::Kontrol(Sistem** sistemler, int sistemAdet){
    this->sistemler=sistemler;
    this->sistemAdet=sistemAdet;
}
void Kontrol::KokKontrol(){
    for (int i=0;i<sistemAdet;i++)
    {
        for(int j=0; j<sistemler[i]->GetOrganAdet(); j++){
            sistemler[i]->GetOrgan(j)->OrganMutasyon();
        }
    }
}