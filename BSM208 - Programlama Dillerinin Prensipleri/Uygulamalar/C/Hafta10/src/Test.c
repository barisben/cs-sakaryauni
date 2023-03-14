#include "Daire.h"
#include "Kare.h"

typedef void* Object;//Java Object örneği için

int main(){
	Daire daire=DaireOlustur("Mavi", 12);
	daire->super->toString(daire->super, daire);//kalıtım alınan geometriksekil'in toString'i
	Kare kare=KareOlustur("Yesil", 54);
	kare->super->toString(kare->super, kare);
	daire->yokEt(daire);
	kare->yokEt(kare);
	
	//Java Object örneği
	Object obj=DaireOlustur("Sari", 12);
	((Daire)obj)->super->toString(((Daire)obj)->super, (Daire)obj);
	((Daire)obj)->yokEt((Daire)obj);
	obj=KareOlustur("Pembe", 54);
	((Kare)obj)->super->toString(((Kare)obj)->super, (Kare)obj);
	((Kare)obj)->yokEt((Kare)obj);
	return 0;
}