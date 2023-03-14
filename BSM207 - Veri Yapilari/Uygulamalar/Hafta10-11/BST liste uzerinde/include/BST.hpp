#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename Object>

class Dugum{
	public:
		Object veri;
		Dugum<Object> *sol;
		Dugum<Object> *sag;
		
		Dugum(const Object& veri, Dugum<Object> *sol=NULL, Dugum<Object> *sag=NULL){
			this->veri=veri;
			this->sol=sol;
			this->sag=sag;
		}
};

template <typename Object>

class BST{
	private:
		Dugum<Object> *kok;
		
		//altDugumlerde *& çünkü sağ ve sol kollarını gerçekten yakalayabilmek için refli
		void AraveEkle(Dugum<Object> *&altDugum, const Object& yeni){//bos yeri arayarak ekliyor, ana ekleme islemini yapan yer
			if(altDugum==NULL)//gonderilen alt dugumun oldugu yer bos ise oraya yeni bir dugum olusturuluyor
				altDugum=new Dugum<Object>(yeni);
			else if(yeni < altDugum->veri)//yeni veri kucukse soldan ilerliyor
				AraveEkle(altDugum->sol, yeni);
			else if(yeni > altDugum->veri)//yeni veri buyukse sagdan ilerliyor
				AraveEkle(altDugum->sag, yeni);
			else return;//veri eşitse eklenmiyor
		}
		
		bool AraveSil(Dugum<Object> *&altDugum, const Object& veri){//gonderilen dugumun olup olmadıgının kontrolü
			if(altDugum==NULL)
				return false;
			if(altDugum->veri == veri)//aranan dugum esitse yani bulunduysa silmek icin DugumSil'e gonderilir
				return DugumSil(altDugum);
			else if(veri < altDugum->veri)
				return AraveSil(altDugum->sol, veri);
			else
				return AraveSil(altDugum->sag, veri);
		}
		
		bool DugumSil(Dugum<Object> *&altDugum){
			Dugum<Object> *del=altDugum;
			if(altDugum->sag==NULL)//yalnızca sol cocugu varsa
				altDugum=altDugum->sol;
			else if(altDugum->sol==NULL)//yalnızca sag cocugu varsa
				altDugum=altDugum->sag;
			else{//ya sol tarafın en sagı ya da sag tarafın en soluyla degisim yapılır, burada solun en sagı seklinde gidiyoruz
				del=altDugum->sol;
				Dugum<Object> *ebeveynDugum=altDugum;//delin bi üstünde kalan ebeveyn düğümü de tutuyoruz
				while(del->sag != NULL){//solun en sagına ilerliyoruz
					ebeveynDugum=del;//sil sağ tarafa geçeceği için onun ebeveynini bilmek gerekir, onu da burada tutuyoruz
					del=del->sag;
				}
				altDugum->veri=del->veri;//silinecek dugumun verisi ile yapılanan yeni ağaçta yer alacak yeni düğümün verisini silinecek düğümün verisi ile değiştiriyoruz
				if(altDugum == ebeveynDugum)//solun hiç sağı olmadığı durumun kontrolü, burası yalnızca sağı veya solu varsa çalışır
					altDugum->sol=del->sol;
				else//burası sağ ve solu varsa çalışır, sağını sileceğimiz için sildiğimizin solunu sağına bağlar
					ebeveynDugum->sag=del->sol;
			}
			delete del;//del'i siliyoruz çünkü del her halükarda ya gerçekten verinin oldugu düğüm ya da solun en sağındaki düğümdür
			return true;
		}
		//yalnızca arayacağımız için, yani sağ ve sol bir değişiklik yapmayacağımız için *& yani refli yerine *  yani yalnızca pointer olarak çağırmak yetiyor
		bool Arama(Dugum<Object> *altDugum, const Object& veri){//böyle bir düğümün bulunup bulunmadığının kontrolü
			if(altDugum==NULL)
				return false;
			if(altDugum->veri == veri)
				return true;
			else if(veri < altDugum->veri)
				return Arama(altDugum->sol, veri);
			else
				return Arama(altDugum->sag, veri);
		}
		
		int Yukseklik(Dugum<Object> *altDugum){
			if(altDugum==NULL)//null ise yüksekliği -1 döndürüyor
				return -1;
			return max(Yukseklik(altDugum->sol), Yukseklik(altDugum->sag))+1;//max 2 parametreden büyüğünü döndürür, sonrasında +1 ekler ve yükseklik gönderilen parametre için odur
		}
		
		void SeviyeYazdir(Dugum<Object> *altDugum, int seviye){//bulunulan seviyedeki değerleri soldan sağa yazdıran fonk
			if(altDugum==NULL)
				return;
			if(seviye==0)
				cout<<altDugum->veri<<" ";
			else{
				SeviyeYazdir(altDugum->sol, seviye-1);
				SeviyeYazdir(altDugum->sag, seviye-1);
			}
		}
		
		void inorder(Dugum<Object> *altDugum){
			if(altDugum!=NULL){
				inorder(altDugum->sol);
				cout<<altDugum->veri<<" ";
				inorder(altDugum->sag);
			}
		}
		void preorder(Dugum<Object> *altDugum){
			if(altDugum!=NULL){
				cout<<altDugum->veri<<" ";
				preorder(altDugum->sol);
				preorder(altDugum->sag);
			}
		}
		void postorder(Dugum<Object> *altDugum){
			if(altDugum!=NULL){
				postorder(altDugum->sol);
				postorder(altDugum->sag);
				cout<<altDugum->veri<<" ";
			}
		}
	public:
		BST(){
			kok=NULL;
		}
		bool isEmpty(){
			return kok==NULL;//kok null ise bos yani true dondurur
		}
		void Ekle(const Object& veri){
			AraveEkle(kok, veri);
		}
		void Sil(const Object& veri){
			if(AraveSil(kok, veri) == false) throw "Eleman Yok";
		}
		bool Arama(const Object& veri){
			return Arama(kok, veri);
		}
		int Yukseklik(){
			return Yukseklik(kok);
		}
		void inorder(){
			inorder(kok);
		}
		void preorder(){
			preorder(kok);
		}
		void postorder(){
			postorder(kok);
		}
		void levelorder(){
			int h=Yukseklik();//öncelikle kökün yüksekliği alınıyor
			for(int seviye=0; seviye<=h; seviye++){//burada da o yüksekliğin değerine kadar ağaç geziliyor, buradaki seviye counter
				SeviyeYazdir(kok, seviye);//bulunulan seviyedeki değerleri soldan sağa yazdıran fonk
			}
		}
		void Temizle(){
			while(!isEmpty())
				DugumSil(kok);//sürekli kökü silerek tüm liste temizleniyor
		}
		~BST(){
			Temizle();
		}
};

#endif