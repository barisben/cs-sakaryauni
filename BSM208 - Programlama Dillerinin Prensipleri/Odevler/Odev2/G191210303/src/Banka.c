#include "Banka.h"

char* BankaSifirsizDondur(const Banka this, float sayi){
	char tmp[1];
	int count = snprintf(tmp, sizeof tmp, "%f", sayi);
	
	if(this->sifirsizSayi!=NULL)	this->sifirsizSayi=realloc(this->sifirsizSayi, sizeof(char)*count);
	else	this->sifirsizSayi=malloc(sizeof(char)*count);
	sprintf(this->sifirsizSayi, "%.2f", sayi);
	int i;
	for(i=0; i<count; i++){
		if(this->sifirsizSayi[i]=='.'){
			if(this->sifirsizSayi[i+2]=='0' && this->sifirsizSayi[i+1]=='0')
				this->sifirsizSayi[i]='\0';
			else if(this->sifirsizSayi[i+2]=='0' && this->sifirsizSayi[i+1]!='0')
				this->sifirsizSayi[i+2]='\0';
			break;
		}	
	}
	return this->sifirsizSayi;
}

Banka BankaOlustur(){
	Banka this;
	this=(Banka)malloc(sizeof(struct BANKA));
	this->hisseObj=NULL;
	this->portfoyObj=NULL;
	this->emirObj=NULL;
	this->satisSemboller=NULL;
	this->satisKarZararlar=NULL;
	this->satisSayisi=0;
	this->sifirsizSayi=NULL;
	this->alimSatim=&BankaAlimSatim;
	this->toString=&BankaToString;
	this->yokEt=&BankaYokEt;
	return this;
}
void BankaAlimSatim(const Banka this, const Dosya hisse, const Dosya portfoy, const Dosya emir){
	this->hisseObj=hisse;
	this->portfoyObj=portfoy;
	this->emirObj=emir;
	
	this->hisseObj->hisseParse(this->hisseObj);
	this->portfoyObj->portfoyParse(this->portfoyObj);
	this->emirObj->emirParse(this->emirObj);
	
	this->satisSayisi=this->emirObj->emirSatisSayisi;	
	
	int i, j, satisIndeks=0;
	float guncelFiyat, maliyet, yeniBirimMaliyet, karZarar;
	
	bool satilabilirMi=true, portfoyVarMi=false, portfoydeVarMi=false, alinabilirMi=false;
	
	this->satisSemboller=malloc(sizeof(char*)*this->satisSayisi);
	this->satisKarZararlar=malloc(sizeof(float)*this->satisSayisi);
	
	for(i=0; i<this->emirObj->objSayisi; i++){
		if(strcmp(this->emirObj->emirler[i]->islem, "SATIS")==0){
			for(j=0; j<this->portfoyObj->objSayisi; j++){
				if(strcmp(this->emirObj->emirler[i]->sembol, this->portfoyObj->portfoyler[j]->sembol)==0){
					if(this->portfoyObj->portfoyler[j]->adet<this->emirObj->emirler[i]->adet || this->emirObj->emirler[i]->adet<=0){
						satilabilirMi=false;
						break;
					}
					maliyet=this->portfoyObj->portfoyler[j]->maliyet*this->emirObj->emirler[i]->adet;
					this->portfoyObj->portfoyler[j]->adet-=this->emirObj->emirler[i]->adet;
					portfoydeVarMi=true;
					break;
				}
			}
			if(!satilabilirMi){
				printf("%s hisse sayisi portfoyde bulunan hisse sayisindan fazla veya adet 0'dan kucuk oldugu icin satisa izin verilmedi!\n", this->emirObj->emirler[i]->sembol);
				satilabilirMi=true;
				continue;
			}
			else if(!portfoydeVarMi){
				printf("%s portfoyde bulunamadigindan satisa izin verilmedi!\n", this->emirObj->emirler[i]->sembol);
				portfoydeVarMi=false;
				continue;
			}
			for(j=0; j<this->hisseObj->objSayisi; j++){
				if(strcmp(this->emirObj->emirler[i]->sembol, this->hisseObj->hisseler[j]->sembol)==0){
					guncelFiyat=this->hisseObj->hisseler[j]->fiyat*this->emirObj->emirler[i]->adet;
					break;
				}
			}
			this->satisSemboller[satisIndeks]=malloc(sizeof(char)*strlen(this->emirObj->emirler[i]->sembol));
			strcpy(this->satisSemboller[satisIndeks], this->emirObj->emirler[i]->sembol);
			karZarar=guncelFiyat-maliyet;
			this->satisKarZararlar[satisIndeks]=karZarar;
			satisIndeks+=1;
		}
		else if(strcmp(this->emirObj->emirler[i]->islem, "ALIS")==0){
			for(j=0; j<this->hisseObj->objSayisi; j++){
				if(strcmp(this->emirObj->emirler[i]->sembol, this->hisseObj->hisseler[j]->sembol)==0){
					guncelFiyat=this->hisseObj->hisseler[j]->fiyat*this->emirObj->emirler[i]->adet;
					alinabilirMi=true;
					break;
				}
			}
			if(!alinabilirMi){
				printf("%s hisselerde bulunamadigindan alisa izin verilmedi!\n", this->emirObj->emirler[i]->sembol);
				alinabilirMi=false;
				continue;
			}
			for(j=0; j<this->portfoyObj->objSayisi; j++){
				if(strcmp(this->emirObj->emirler[i]->sembol, this->portfoyObj->portfoyler[j]->sembol)==0){
					yeniBirimMaliyet=(this->portfoyObj->portfoyler[j]->maliyet*this->portfoyObj->portfoyler[j]->adet+guncelFiyat)/(this->portfoyObj->portfoyler[j]->adet+this->emirObj->emirler[i]->adet);
					this->portfoyObj->portfoyler[j]->adet+=this->emirObj->emirler[i]->adet;
					this->portfoyObj->portfoyler[j]->maliyet=yeniBirimMaliyet;
					portfoyVarMi=true;
					break;
				}
			}
			if(!portfoyVarMi){
				this->portfoyObj->objSayisi+=1;
				this->portfoyObj->portfoyler=realloc(this->portfoyObj->portfoyler, sizeof(struct PORTFOY*)*this->portfoyObj->objSayisi);
				float maliyet=guncelFiyat/this->emirObj->emirler[i]->adet;
				this->portfoyObj->portfoyler[this->portfoyObj->objSayisi-1]=PortfoyOlustur(this->emirObj->emirler[i]->sembol, maliyet, this->emirObj->emirler[i]->adet);
			}
		}
		satilabilirMi=true;
		portfoyVarMi=false;
		portfoydeVarMi=false;
		alinabilirMi=false;
	}
	if(this->satisSayisi!=satisIndeks){
		this->satisSayisi=satisIndeks;
		this->satisSemboller=realloc(this->satisSemboller, sizeof(char*)*this->satisSayisi);
		this->satisKarZararlar=realloc(this->satisKarZararlar, sizeof(float)*this->satisSayisi);
	}
}
void BankaToString(const Banka this){
	float tmpZarar, toplamKarZarar=0;
	int i;
	printf("Satislar Kar/Zarar:\n");
	for(i=0; i<this->satisSayisi; i++){
		if(this->satisKarZararlar[i]<0){
			tmpZarar=this->satisKarZararlar[i]*-1;
			printf("%s: %s TL Zarar\n",this->satisSemboller[i], BankaSifirsizDondur(this, tmpZarar));
		}
		else
			printf("%s: %s TL Kar\n",this->satisSemboller[i], BankaSifirsizDondur(this, this->satisKarZararlar[i]));
		toplamKarZarar+=this->satisKarZararlar[i];
	}
	if(toplamKarZarar>=0)
		printf("Toplam Kar/Zarar: +%s TL\n\n", BankaSifirsizDondur(this, toplamKarZarar));
	else
		printf("Toplam Kar/Zarar: %s TL\n\n", BankaSifirsizDondur(this, toplamKarZarar));
}
void BankaYokEt(Banka this){
	if(this==NULL)	return;
	if(this->sifirsizSayi!=NULL)	free(this->sifirsizSayi);
	if(this->satisSemboller != NULL){
		int i;
		for(i=0; i<this->satisSayisi; i++){
			free(this->satisSemboller[i]);
			this->satisSemboller[i]=NULL;
		}
		free(this->satisSemboller);
		free(this->satisKarZararlar);
	}
	free(this);
}