#include "Mean.h"

Mean MeanOlustur(int sayilar[], int uzunluk){
	Mean this;
	this=(Mean)malloc(sizeof(struct MEAN));
	this->super=OrderOlustur(sayilar, uzunluk);//Kalıtım aldığımız Order sınıfının kurucusunu çağırdık ve super'e atadık.
	
	this->ortalama=&Ortalama;
	this->yazdir=&Yazdir;
	this->meanYokEt=&MeanYokEt;
	return this;
}
double Ortalama(const Mean this){
	double toplam=0;
	int i;
	for(i=0; i<this->super->uzunluk; i++) {
		toplam+=this->super->sayilar[i];
	}
	return toplam/this->super->uzunluk;
}
void Yazdir(const Mean this){
	this->super->toString(this->super);
	printf("\nOrtalama: %.2lf\n", this->ortalama(this));
}
void MeanYokEt(Mean this){
	if(this==NULL)	return;
	this->super->orderYokEt(this->super);//önce base sınıfın yıkıcısını çağırıyoruz
	free(this);
}