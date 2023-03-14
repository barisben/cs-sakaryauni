#include "Dosya.h"
#include "Banka.h"

int main(){
	Dosya hisseDosya=DosyaOlustur("./doc/hisseler.json");
	Dosya portfoyDosya=DosyaOlustur("./doc/portfoy.json");
	Dosya emirDosya=DosyaOlustur("./doc/emirler.json");
	Banka banka=BankaOlustur();
	
	if(setjmp(hisseDosya->jumper)==0 && setjmp(portfoyDosya->jumper)==0 && setjmp(emirDosya->jumper)==0){
		hisseDosya->oku(hisseDosya);
		portfoyDosya->oku(portfoyDosya);
		emirDosya->oku(emirDosya);
		banka->alimSatim(banka, hisseDosya, portfoyDosya, emirDosya);
		banka->toString(banka);
		printf("Guncel Portfoy:\n");
		int i;
		for(i=0; i<portfoyDosya->objSayisi; i++){
			portfoyDosya->portfoyler[i]->toString(portfoyDosya->portfoyler[i]);
		}
	}
	else{
		printf("Dosya okuma hatasi: Dosya hatali veya bulunamadi!");
	}
	
	hisseDosya->yokEt(hisseDosya);
	portfoyDosya->yokEt(portfoyDosya);
	emirDosya->yokEt(emirDosya);
	banka->yokEt(banka);
	return 0;
}