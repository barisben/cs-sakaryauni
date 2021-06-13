#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
using namespace std;

template <typename Object>

class Dugum{
	public:
		Object veri;
		Dugum<Object> *sol;
		Dugum<Object> *sag;
		int yukseklik;
		
		Dugum(const Object& veri, Dugum<Object> *sol=NULL, Dugum<Object> *sag=NULL){
			this->veri=veri;
			this->sol=sol;
			this->sag=sag;
			yukseklik=0;//en alta eklenen dugumun yuksekliği varsayılan olarak 0'dır
		}
};

template <typename Object>

class AVL{
	private:
		Dugum<Object> *kok;
		
		Dugum<Object> *SolCocukileDegistir(Dugum<Object> *altDugum){
			Dugum<Object> *tmp=altDugum->sol;
			altDugum->sol=tmp->sag;
			tmp->sag=altDugum;
			altDugum->yukseklik=Yukseklik(altDugum);
			tmp->yukseklik=max(Yukseklik(tmp->sol), altDugum->yukseklik)+1;
			return tmp;
		}
		
		Dugum<Object> *SagCocukileDegistir(Dugum<Object> *altDugum){
			Dugum<Object> *tmp=altDugum->sag;
			altDugum->sag=tmp->sol;
			tmp->sol=altDugum;
			altDugum->yukseklik=Yukseklik(altDugum);
			tmp->yukseklik=max(Yukseklik(tmp->sag), altDugum->yukseklik)+1;
			return tmp;
		}
		
		Dugum<Object> *AraveEkle(Dugum<Object> *altDugum, const Object& yeni){//bos yeri arayarak ekliyor, ana ekleme islemini yapan yer
			if(altDugum==NULL)//gonderilen alt dugumun oldugu yer bos ise oraya yeni bir dugum olusturuluyor
				altDugum=new Dugum<Object>(yeni);
			else if(yeni < altDugum->veri){//yeni veri kucukse soldan ilerliyor
				altDugum->sol=AraveEkle(altDugum->sol, yeni);//bstde referanslı çağırdığımız için eşitleme yapmıyorduk, burada refsiz oldugu için eşitliyoruz
				if(Yukseklik(altDugum->sol)-Yukseklik(altDugum->sag) == 2){//denge kontrolü, sol taraf dengesizse
					if(yeni < altDugum->sol->veri)//sol-sol durumu
						altDugum=SolCocukileDegistir(altDugum);
					else{//sol-sag durumu
						altDugum->sol=SagCocukileDegistir(altDugum->sol);
						altDugum=SolCocukileDegistir(altDugum);
					}
				}
			}
			else if(yeni > altDugum->veri){//yeni veri buyukse sagdan ilerliyor
				altDugum->sag=AraveEkle(altDugum->sag, yeni);//bstde referanslı çağırdığımız için eşitleme yapmıyorduk, burada refsiz oldugu için eşitliyoruz
				if(Yukseklik(altDugum->sag)-Yukseklik(altDugum->sol) == 2){//denge kontrolü, sag taraf dengesizse
					if(yeni > altDugum->sag->veri)//sag-sag durumu
						altDugum=SagCocukileDegistir(altDugum);
					else{//sag-sol durumu
						altDugum->sag=SolCocukileDegistir(altDugum->sag);
						altDugum=SagCocukileDegistir(altDugum);
					}
				}
			}
			//veri eşitse bir şey olmuyor
			altDugum->yukseklik=Yukseklik(altDugum);
			return altDugum;
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
		AVL(){
			kok=NULL;
		}
		bool isEmpty(){
			return kok==NULL;//kok null ise bos yani true dondurur
		}
		void Ekle(const Object& veri){
			kok=AraveEkle(kok, veri);//refsiz oldugu icin kok'e esitliyoruz
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
		~AVL(){
			Temizle();
		}
};

#endif