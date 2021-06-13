#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Dugum{
	public:
		char karakter;
		int frekans;
		string kod;
		
		Dugum *sol;
		Dugum *sag;
		
		Dugum(char karakter, int frekans, Dugum *sol=NULL, Dugum *sag=NULL){
			this->karakter=karakter;
			this->frekans=frekans;
			this->sol=sol;
			this->sag=sag;
			kod="";
		}
		
		bool YaprakMi()const{
			return sol==NULL && sag==NULL;//sağı ve solu null ise yapraktır
		}
		
		bool operator==(Dugum& sagDugum){//"==" operatör kullanımında yapacağı işlem
			return this->karakter==sagDugum.karakter;//karakterin sağ düğümün karakterine eşitliğini kontrol eder, eşitse true
		}
		
		bool operator!=(Dugum& sagDugum){//"!=" operatör kullanımında yapacağı işlem
			return this->karakter!=sagDugum.karakter;//karakterin sağ düğümün karakterine eşitliğini kontrol eder, eşit değilse true
		}
		
		bool operator>(Dugum& sagDugum){//">" operatör kullanımında yapacağı işlem
			return this->frekans>sagDugum.frekans;//frekansın sağ düğümün frekansından büyük olup olmadığını kontrol eder, eşitse true
		}
};

class Huffman{
	private:
		Dugum *kok;
		int harfler;//asci karşılıkları olduğu için int 256 karaktere kadar
		string girdi;
		
		Dugum *AgacOlustur(int frekans[]){
			Dugum *agaclar[harfler];
			for(int i=0; i<harfler; i++){
				if(frekans[i]>0)//yani bu karakterden var ise
					agaclar[i]=new Dugum((char)i, frekans[i]);
				else//yani i'deki bu karakter ilk defa geldiyse
					agaclar[i]=NULL;
			}
			while(true){//kac agac oldugunu bilmedigimiz icin sonsuz döngü, tek 1 ağaç kalana dek dönmeye devam ediyor
				int ilkIndeks=MinDugumIndeks(agaclar);//2'li kombinasyonlar için en küçüğü aldık
				Dugum *min1=agaclar[ilkIndeks];//kombinasyon için 2. en küçüğü bulmak için önce ilk en küçük olan en küçüğü yedek alıp null a eşitliyoruz ki dizide en küçük diye yine 1'i vermesin
				agaclar[ilkIndeks]=NULL;
				int ikinciIndeks=MinDugumIndeks(agaclar);
				if(ikinciIndeks==-1)//eğer 2.bir indeks yoksa aslında ilkIndeksteki düğüm/ağaç aslında ağacın kendisidir, bu durumda min1 ile ilkIndeksteki ağacın kendisini döndürüp whiledan çıkarız
					return min1;//bu durumda bu dönen şey aslında kök oluyor, onu da Kodla fonksiyonunda bu fonksiyonu çağırırken köke eşitlettik
				Dugum *min2=agaclar[ikinciIndeks];//aynı işlemle ikinci en küçüğü tutup null yapıyoruz
				agaclar[ikinciIndeks]=NULL;
				//buradan sonra 2sini çocuklar yapacağımız yeni t düğümünü ilk veya ikinciIndeksin bos oldugunu bildigimiz icin bunlardan birinin yerine olusturuyoruz
				agaclar[ilkIndeks]=new Dugum(0, min1->frekans+min2->frekans, min1, min2);//yeni düğümde karaktere 0 girdik çünkü ara düğüm olan tlerde karakter/acsinin bir önemi yoktur, küçük olan min1 oldugu icin sol cocuk min1 yani ilkIndeksteki
			}
		}
		
		void KodOlustur(Dugum *altDugum, string kod){//ağaçlar olusturulduktan sonraki son halinde kodlamaya dökecek asıl yer
			if(!altDugum->YaprakMi()){//yaprak değilse işlemleri yapacak
				KodOlustur(altDugum->sol, kod+'0');//sol tarafta ağaçta 0 sağda 1 oldugundan sola gittiğinde stringe 0 ekliyor
				KodOlustur(altDugum->sag, kod+'1');//sol tarafta ağaçta 0 sağda 1 oldugundan sağa gittiğinde stringe 1 ekliyor
				//bu şekilde harflerin kodlaması yaprağa gelene kadar ilerlediğinden oluşmuş oluyor
			}
			else//yaprağa geldik
				altDugum->kod=kod;//düğümün yani yaprak düğümün kodunu burada oluşan koda eşitleyerek kodunu oluşturmuş oluyoruz
		}
		
		int MinDugumIndeks(Dugum *agaclar[]){//en kücük frekanslıları bulmak için
			Dugum *min;
			int minIndeks=-1;//-1 döndürse dizide ağaç kalmamış demektir, varsayılan -1 ayarlıyoruz
			for(int i=0; i<harfler; i++){
				if(agaclar[i]!=NULL){//ilk null olmayan ağacı diğerleriyle karşılaştırmak amacıyla tuttuk ve sonraki forda gerçekten min olup olmadıgını netleyeceğiz
					min=agaclar[i];
					minIndeks=i;
					break;
				}
			}
			for(int i=0; i<harfler; i++){//burada gerçekten min olup olmadıgını netliyoruz, diğer ağaçlarla karşılaştırarak
				if(agaclar[i]==NULL)
					continue;
				if(*min>*agaclar[i]){//operator ">" fonk sayesinde frekansları karşılaştırıyor
					
					min=agaclar[i];
					minIndeks=i;
				}
			}
			return minIndeks;
		}
		
		void DosyaOku(string dosyaYolu){//dosyayı okuma islemi
			string satir;
			ifstream dosya(dosyaYolu.c_str());
			if(dosya.is_open()){
				while(getline(dosya, satir)){
					girdi+=satir;
					girdi+='\n';
				}
				dosya.close();
			}
		}
		
		void inorder(Dugum *altDugum){//ağacı yazdırmak için gezdirme yöntemi, tercihen inorder seçildi
			if(altDugum!=NULL){
				inorder(altDugum->sol);
				if(altDugum->YaprakMi())//ara düğümleri yani t'leri atlamak için yapraksa yazdırıyoruz
					cout<<altDugum->karakter<<" : "<<altDugum->kod<<endl;
				inorder(altDugum->sag);
			}
		}
		
		void SilDugum(Dugum *&altDugum){//postorder usulü düğüm silen fonk
			if(altDugum==NULL)
				return;
			SilDugum(altDugum->sol);
			SilDugum(altDugum->sag);
			delete altDugum;
			altDugum=NULL;//referanslı "*&" çağırdığımız için null eşitliyoruz
		}
	public:
		Huffman(string dosyaYolu){
			harfler=256;//asci
			girdi="";
			DosyaOku(dosyaYolu);
			kok=NULL;
		}
		
		void Kodla(){//sıkıştırma işleminin yapılacağı yer
			char karakterler[girdi.size()-1];
			strcpy(karakterler, girdi.c_str());//karakterler dizisine girdiyi kopyalıyoruz
			int frekans[harfler];
			//yani a asci karsılıgı 97 ise frekans[97]=10 dersek a'dan 10 tane oldugu anlamına gelir
			for(int i=0; i<harfler; i++)//tüm indekslere 0 değerini veriyoruz baslangicta
				frekans[i]=0;
			for(int i=0; i<girdi.size()-1; i++)
				frekans[karakterler[i]]++;//bu sekilde her karakterden yani örneğin a'dan kaç tane oldugunu öğrenmis oluyoruz		
			kok=AgacOlustur(frekans);	
			KodOlustur(kok, "");//bos string gönderdik çünkü kökten inerken kendisi boşluğu doldurarak kodlarını oluşturacak, yaprağa kadar ilerleyerek yaprağa geldiğinde string yani kodlama olusmus olacak(yaprak sağ ve sol cocugunun olmaması demek)
		}
		
		friend ostream& operator<<(ostream& ekran, Huffman& sag){//kodları görmemizi sağlayan fonk
			ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
			sag.inorder(sag.kok);
			return ekran;
		}
		
		~Huffman(){
			SilDugum(kok);//kökten başlayarak tüm düğümleri silerek ağacı yok etmiş oluyoruz
		}
		
};

#endif