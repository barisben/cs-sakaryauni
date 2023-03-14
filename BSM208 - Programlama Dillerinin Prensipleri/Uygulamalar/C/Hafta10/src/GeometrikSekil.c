#include "GeometrikSekil.h"

//bu private fonksiyona bir benzetimdir çünkü h dosyasında struct içerisinde bu fonksiyonun fonksiyon göstericisini tanımlamadık. bu fonksiyonun dışarıdan erişilmesini istemiyoruz
char* ZamanGetir(){
	char* buff=malloc(sizeof(char)*100);//tarih için yeterli bir alan
	time_t simdi=time(0);//zamanı aldık
	strftime(buff, 100, "%d %m %H:%M %Y", localtime(&simdi));//javada çıktı verdiği formatta strftime fonksiyonu aracılığıyla tanımladık, buff içerisine bunu kopyaladı, 100 yazan parametre buff'ın size'ı
	return buff;//bu buff yıkıcı metotta iade edilmeli çünkü heapte oluşturuldu, bunu da bu fonksiyonu çağıran olusturulmaTarihi degiskenini iade ederek yapacağız
}

GeometrikSekil GeometrikSekilOlustur(char* renk){
	GeometrikSekil this;
	this=(GeometrikSekil)malloc(sizeof(struct GEOMETRIKSEKIL));
	this->renk=renk;
	this->olusturulmaTarihi=ZamanGetir();
	
	this->getOlusturulmaTarihi=&OlusturulmaTarihi;
	this->toString=&Yazdir;
	this->yokEt=&GeometrikSekilYokEt;
	return this;
}
char* OlusturulmaTarihi(const GeometrikSekil this){
	return this->olusturulmaTarihi;
}
void Yazdir(const GeometrikSekil this, void* p){
	printf("\n\nTarih: %s", this->olusturulmaTarihi);
	printf("\nRenk: %s", this->renk);
	//burada void* olmasının sebebi ortaya çıkıyor, gelen şey daire de olabilir kare de. gelecek tür belirsiz olduğu için
	//ve void* gelen herhangi bir türe dönüşebileceği için void* alıyoruz ve bu aldığımızı Alan fonksiyonuna gönderiyoruz
	printf("\nAlan: %lf", this->Alan(p));
	printf("\nCevre: %lf", this->Cevre(p));
}
void GeometrikSekilYokEt(GeometrikSekil this){
	if(this==NULL)	return;
	free(this->olusturulmaTarihi);
	free(this);
}