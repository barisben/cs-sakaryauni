#include "Dosya.h"
#include "Hisse.h"
#include "Emir.h"
#include "Portfoy.h"
#include "Banka.h"

int main(){
	Dosya hisseDosya=DosyaOlustur("./doc/hisseler.json");
	Dosya portfoyDosya=DosyaOlustur("./doc/portfoy.json");
	Dosya emirDosya=DosyaOlustur("./doc/emirler.json");
	Hisse hisse=HisseOlustur();
	Portfoy portfoy=PortfoyOlustur();
	Emir emir=EmirOlustur();
	Banka banka=BankaOlustur();
	
	if(setjmp(hisseDosya->jumper)==0 && setjmp(portfoyDosya->jumper)==0 && setjmp(emirDosya->jumper)==0){
		char *hisseData=hisseDosya->oku(hisseDosya);
		hisse->oku(hisse, hisseData);
		char *portfoyData=portfoyDosya->oku(portfoyDosya);
		portfoy->oku(portfoy, portfoyData);
		char *emirData=emirDosya->oku(emirDosya);
		emir->oku(emir, emirData);
		banka->alimSatim(banka, hisse, portfoy, emir);
		banka->toString(banka);
		portfoy->toString(portfoy);
	}
	else{
		printf("Dosya okuma hatasi: Dosya bulunamadi!");
	}
	
	hisseDosya->yokEt(hisseDosya);
	portfoyDosya->yokEt(portfoyDosya);
	emirDosya->yokEt(emirDosya);
	hisse->yokEt(hisse);
	portfoy->yokEt(portfoy);
	emir->yokEt(emir);
	banka->yokEt(banka);
	return 0;
}