#include "Banka.h"

Banka BankaOlustur(){
	Banka this;
	this=(Banka)malloc(sizeof(struct BANKA));
	this->hisseObj=NULL;
	this->portfoyObj=NULL;
	this->emirObj=NULL;
	this->satisSemboller=NULL;
	this->satisKarZararlar=NULL;
	this->satisSayisi=0;
	this->alimSatim=&BankaAlimSatim;
	this->toString=&BankaToString;
	this->yokEt=&BankaYokEt;
	return this;
}
void BankaAlimSatim(const Banka this, const Hisse h, const Portfoy p, const Emir e){
	this->hisseObj=h;
	this->portfoyObj=p;
	this->emirObj=e;
	this->satisSayisi=this->emirObj->satisSayisi;
	
	int i, j, satisIndeks=0;
	float guncelFiyat, maliyet, yeniBirimMaliyet, karZarar;
	
	bool satilabilirMi=true, portfoyVarMi=false, portfoydeVarMi=false, alinabilirMi=false;
	
	this->satisSemboller=malloc(sizeof(char*)*this->satisSayisi);
	this->satisKarZararlar=malloc(sizeof(float)*this->satisSayisi);
	
	for(i=0; i<this->emirObj->emirSayisi; i++){
		if(strcmp(this->emirObj->islemler[i], "SATIS")==0){
			for(j=0; j<this->portfoyObj->portfoySayisi; j++){
				if(strcmp(this->emirObj->semboller[i], this->portfoyObj->semboller[j])==0){
					if(this->portfoyObj->adetler[j]<this->emirObj->adetler[i]){
						satilabilirMi=false;
						break;
					}
					maliyet=this->portfoyObj->maliyetler[j]*this->emirObj->adetler[i];
					this->portfoyObj->adetler[j]-=this->emirObj->adetler[i];
					portfoydeVarMi=true;
					break;
				}
			}
			if(!satilabilirMi){
				printf("Satis emri verilen %s hisse sayisi portfoyde bulunan hisse sayisindan fazla oldugundan satisa izin verilmedi!\n", this->emirObj->semboller[i]);
				satilabilirMi=true;
				continue;
			}
			else if(!portfoydeVarMi){
				printf("Satis emri verilen %s portfoyde bulunamadigindan satisa izin verilmedi!\n", this->emirObj->semboller[i]);
				portfoydeVarMi=false;
				continue;
			}
			for(j=0; j<this->hisseObj->hisseSayisi; j++){
				if(strcmp(this->emirObj->semboller[i], this->hisseObj->semboller[j])==0){
					guncelFiyat=this->hisseObj->fiyatlar[j]*this->emirObj->adetler[i];
					break;
				}
			}
			this->satisSemboller[satisIndeks]=malloc(sizeof(char)*strlen(this->emirObj->semboller[i]));
			strcpy(this->satisSemboller[satisIndeks], this->emirObj->semboller[i]);
			karZarar=guncelFiyat-maliyet;
			this->satisKarZararlar[satisIndeks]=karZarar;
			satisIndeks+=1;
		}
		else if(strcmp(this->emirObj->islemler[i], "ALIS")==0){
			for(j=0; j<this->hisseObj->hisseSayisi; j++){
				if(strcmp(this->emirObj->semboller[i], this->hisseObj->semboller[j])==0){
					guncelFiyat=this->hisseObj->fiyatlar[j]*this->emirObj->adetler[i];
					alinabilirMi=true;
					break;
				}
			}
			if(!alinabilirMi){
				printf("Alis emri verilen %s hisselerde bulunamadigindan alisa izin verilmedi!\n", this->emirObj->semboller[i]);
				alinabilirMi=false;
				continue;
			}
			for(j=0; j<this->portfoyObj->portfoySayisi; j++){
				if(strcmp(this->emirObj->semboller[i], this->portfoyObj->semboller[j])==0){
					yeniBirimMaliyet=(this->portfoyObj->maliyetler[j]*this->portfoyObj->adetler[j]+guncelFiyat)/(this->portfoyObj->adetler[j]+this->emirObj->adetler[i]);
					this->portfoyObj->adetler[j]+=this->emirObj->adetler[i];
					this->portfoyObj->maliyetler[j]=yeniBirimMaliyet;
					portfoyVarMi=true;
					break;
				}
			}
			if(!portfoyVarMi){
				this->portfoyObj->portfoySayisi+=1;
				this->portfoyObj->semboller=realloc(this->portfoyObj->semboller, sizeof(char*)*this->portfoyObj->portfoySayisi);
				this->portfoyObj->semboller[this->portfoyObj->portfoySayisi-1]=malloc(sizeof(char)*strlen(this->emirObj->semboller[i]));
				this->portfoyObj->maliyetler=realloc(this->portfoyObj->maliyetler, sizeof(float)*this->portfoyObj->portfoySayisi);
				this->portfoyObj->adetler=realloc(this->portfoyObj->adetler, sizeof(int)*this->portfoyObj->portfoySayisi);
				strcpy(this->portfoyObj->semboller[this->portfoyObj->portfoySayisi-1], this->emirObj->semboller[i]);
				this->portfoyObj->adetler[this->portfoyObj->portfoySayisi-1]=this->emirObj->adetler[i];
				this->portfoyObj->maliyetler[this->portfoyObj->portfoySayisi-1]=guncelFiyat/this->emirObj->adetler[i];
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
			printf("%s: %.2f TL Zarar\n",this->satisSemboller[i], tmpZarar);
		}	
		else
			printf("%s: %.2f TL Kar\n",this->satisSemboller[i], this->satisKarZararlar[i]);
		toplamKarZarar+=this->satisKarZararlar[i];
	}
	if(toplamKarZarar>=0)
		printf("Toplam Kar/Zarar: %+.2f TL\n\n", toplamKarZarar);
	else
		printf("Toplam Kar/Zarar: %.2f TL\n\n", toplamKarZarar);
}
void BankaYokEt(Banka this){
	//printf("BANKA YIKICI CAGIRILDI\n");
	if(this==NULL)	return;
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