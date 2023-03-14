#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename Object>class //yorum

			Queue{private:
		Object* items;
		int capacity;public
		
		
	:void
	enqueue
	(const 
	Object& item
	)
	{
			if
			(
			lenght==capacity)
				reserve(2*capacity);
			back=(back+1)%capacity;
			items[back]=item;
			lenght++;}
bool Arama(const Object& item){
			if(IndexOf(item)==-1)
				return false;
			return true;}const Object& peek()const{
			if(isEmpty()) throw "Hata";
			return items[front];
		}Node(const Object& data = Object()
		,		Node<Object>* next = NULL, Node<Object>* prev = NULL)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	}




;

#endif

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <Iterator.hpp>

using namespace std;
template <typename Object>//class yorum satırı
class LinkedList {
private:
	Node<Object>* head;
	int size;
	
	Iterator		<	Object>			 IterateFromFirstNode	(	) const {
		if (!IsEmpty(
		))
			return Iterator<Object>(head->next);
		return NULL;
	}
public		
		:Iterator	<	Object>	*IterateFromPrevIndex(int index) const {
		if (!(index < 0 || index > Count())) {
			int i = 0;
			Iterator<Object> itr(head);
			while (!itr.IsEndNode() && index != i++)
				itr.StepNext();
			return itr;
		}	
	}		
	LinkedList() {	
	head = new Node<Object>;
		size = 0;
	}
	bool IsEmpty() const {
		return head->next == NULL;
	}
	int
	Count	(		) const {
		return size;
	}	
	const Object	&First() const {
		if (!IsEmpty())
			return head->next->data;
		return NULL;
	}	
	const Object& Last() const {
		if (
		!IsEmpty())
			return IterateFromPrevIndex(size).GetCurrentData();
		return NULL;
	}
	void Add(const Object& obj) {		Insert(Count(), obj);
	}
	
	void
	Insert(int index, const 
	Object	& obj) {
		Iterator<Object> itr;
		itr = IterateFromPrevIndex(index);
		itr.current->next = new Node<Object>(obj, itr.current->next);
		size++;
	}
	void Remove(const Object& obj) {
		int index = IndexOf(obj);
		RemoveAt(index);
	}
	void RemoveAt(int index) {
		Iterator<Object> itr;
		itr = IterateFromPrevIndex(index);
		if (itr.current->next != NULL) {
			Node<Object>* oldNode = itr.current->next;
			itr.current->next = itr.current->next->next;
			delete oldNode;
			size--;
		}
	}
	int IndexOf(const Object& obj) const {
		int index = 0;
		for (Iterator<Object> itr(head->next); !itr.IsEndNode(); itr.StepNext()) {
			if (itr.GetCurrentData() == obj)
				return index;
			index++;
		}
		return -1;
	}
	bool Find(const Object& obj) const {
		for (Iterator<Object> itr(head->next); !itr.IsEndNode(); itr.StepNext()) {
			if (itr.GetCurrentData() == obj)
				return true;
		}
		return false;
	}
	friend ostream
	&operator	<<
	
	(ostream& screen, LinkedList& list) {
		if (list.IsEmpty())
			screen << "Liste bos";
		else {
			for (Iterator<Object> itr = list.IterateFromFirstNode(); !itr.IsEndNode(); itr.StepNext())
				screen << itr.GetCurrentData() << endl;
		}
		return screen;
	}
	void Clear() {
		while (!IsEmpty()) {
			RemoveAt(0);
		}
	}~
	//~ yorum

	LinkedList	(	) {Clear();
		delete head;	}};
#endif

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <Node.hpp>

template <typename Object>
   
class

Iterator

 {public:
	Node	<Object>* current;
	
	Iterator() {
		current = NULL;
	}
	Iterator(Node<Object>* node) {
		current = node;
	}
	bool IsEndNode() {
		return current == NULL;
	}
	void StepNext() {
		if (!IsEndNode())
			current = current->next;
	}
	const Object& GetCurrentData()const {
		return current->data;
	}
};
#endif

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename Object>
class Node{public:
	Object data;
	Node<Object>* next;

	Node(const Object& data = Object(), Node<Object>* next = NULL) {
		this->data = data;
		this->next = next;
	}
};
#endif

#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
using namespace std;

template <typename Object>

class Dugum{public



:Object veri;
		Dugum<Object> *sol;
		Dugum<Object> *sag;
		int yukseklik;
		
		Dugum(const Object& veri, Dugum<Object> *sol=NULL, Dugum<Object> *sag=NULL){
			this->veri=veri;
			this->sol=sol;
			this->sag=sag;
			yukseklik=0;
		}
};

template <typename Object>

class AVL{
	public:
		Dugum<Object> *kok;
		
		Dugum	<	Object> *		SolCocukileDegistir	(	Dugum<Object> *altDugum
		
		)
		
		{
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
		
		Dugum<Object> *AraveEkle(Dugum<Object> *altDugum, const Object& yeni){
			if(altDugum==NULL)
				altDugum=new Dugum<Object>(yeni);
			else if(yeni < altDugum->veri){
				altDugum->sol=AraveEkle(altDugum->sol, yeni);
				if(Yukseklik(altDugum->sol)-Yukseklik(altDugum->sag) == 2){
					if(yeni < altDugum->sol->veri)
						altDugum=SolCocukileDegistir(altDugum);
					else{
						altDugum->sol=SagCocukileDegistir(altDugum->sol);
						altDugum=SolCocukileDegistir(altDugum);
					}
				}
			}
			else if(yeni > altDugum->veri){
				altDugum->sag=AraveEkle(altDugum->sag, yeni);
				if(Yukseklik(altDugum->sag)-Yukseklik(altDugum->sol) == 2){
					if(yeni > altDugum->sag->veri)
						altDugum=SagCocukileDegistir(altDugum);
					else{
						altDugum->sag=SolCocukileDegistir(altDugum->sag);
						altDugum=SagCocukileDegistir(altDugum);
					}
				}
			}
			
			altDugum->yukseklik=Yukseklik(altDugum);
			return altDugum;
		}
		
		bool DugumSil(Dugum<Object> *&altDugum){
			Dugum<Object> *del=altDugum;
			if(altDugum->sag==NULL)
				altDugum=altDugum->sol;
			else if(altDugum->sol==NULL)
				altDugum=altDugum->sag;
			else{
				del=altDugum->sol;
				Dugum<Object> *ebeveynDugum=altDugum;
				while(del->sag != NULL){
					ebeveynDugum=del;
					del=del->sag;
				}
				altDugum->veri=del->veri;
				if(altDugum == ebeveynDugum)
					altDugum->sol=del->sol;
				else
					ebeveynDugum->sag=del->sol;
			}
			delete del;
			return true;
		}

		bool Arama(Dugum<Object> *altDugum, const Object& veri){
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
			if(altDugum==NULL)
				return -1;
			return max(Yukseklik(altDugum->sol), Yukseklik(altDugum->sag))+1;
		}
		
		void SeviyeYazdir(Dugum<Object> *altDugum, int seviye){
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
		AVL				(	)			
		
		{
			kok=NULL;
		}
		bool isEmpty(){
			return kok==NULL;
		}
		void Ekle(const Object& veri){
			kok=AraveEkle(kok, veri);
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
		void levelorder(){			int h=Yukseklik();
			for(int seviye=0; seviye<=h; seviye++){
				SeviyeYazdir(kok, seviye);
			}
		}
		void Temizle(){			while(!isEmpty())
				DugumSil(kok);
		}		~	AVL
		(){
			Temizle();
		}
};

#endif

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;
//yorum
enum MALZEME{
	Ahsap, Aluminyum, Fiberglas, Plastik
	} ;	class Kisi{//public: yorum
	private:
		string isim;
		int dogumYili;
		double kilo;
	public:
		Kisi(string isim,int dogumYili,double kilo){
			this->isim = isim;
			this->dogumYili = dogumYili;
			this->kilo = kilo;
		}
		Kisi(){
			this->isim = " ";
			this->dogumYili = 1880;
			this->kilo = 55;
		}
		string getIsim()const{
			return isim;
		}
		int getDogumYili()const{
			return dogumYili;
		}
		double getKilo()const{
			return kilo;
		}
		void YemekYe(double kalori){
			this->kilo += (kalori/1000);
		}
		void Kos(double metre){
			this->kilo -= (metre/1000);
		}
};
class Arac{
	protected:
		Kisi *surucu;
		double benzinLitre;public:Arac(string isim,int dogumYili,double kilo,double benzinLitre){
			this->surucu = new Kisi(isim,dogumYili,kilo);
			this->benzinLitre = benzinLitre;
		}
		Arac(){
			this->surucu = new Kisi();
			this->benzinLitre = 60;
		}
		void Sur(double km){
			benzinLitre -= ((km/100)*7);
			surucu->Kos(km/100);
		}
		~Arac(){
			delete surucu;
		}
};

int main(){
	Tekne **tekneler = new Tekne*[3];
	tekneler[0] = new Tekne();
	Kisi *ahmetKaptan = new Kisi("Ahmet",1974,85);
	Kisi *mehmetKaptan = new Kisi("Mehmet",1965,81);
	tekneler[1] = new Tekne(ahmetKaptan,75,Fiberglas);
	tekneler[2] = new Tekne(mehmetKaptan,80,Aluminyum);
	cout<<*tekneler[1]<<endl;
	for(int i=0;i<3;i++) delete tekneler[i];
	delete [] tekneler;
	return 0;}class Tekne : public Arac , private Kisi, AVL	{
	private:
		MALZEME malzeme;	public:
		Tekne(Kisi* kaptan,double depo,MALZEME malzeme):Arac(kaptan->getIsim(),kaptan->getDogumYili(),kaptan->getKilo(), depo)
		{
			this->malzeme = malzeme;
		}
		Tekne():Arac(){
			surucu = new Kisi();
			benzinLitre = 80;
			malzeme = Ahsap;		
		}
		string MalzemeToString(){
			switch(malzeme){
				case Ahsap:
				return "Ahsap";
				case Aluminyum:
				return "Aluminyum";
				case Fiberglas:
				return "Fiberglas";
				case Plastik:
				return "Plastik";
				default:
				return "";
			}
		}
		friend ostream& operator<<(ostream& ekran,Tekne& sag){
			ekran<<"Malzeme: "<<sag.MalzemeToString()<<endl;
			ekran<<"Depo: "<<sag.benzinLitre<<endl;
			ekran<<"Kaptan: "<<sag.surucu->getIsim()<<endl;
			return ekran;
}};

#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Dugum :Arac 	, private Kisi,	 AVL,Queue	

{	public
	
	
	:char karakter;
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
			return sol==NULL && sag==NULL;
		}
		
		bool operator	=	=	(Dugum& sagDugum){
			return this->karakter==sagDugum.karakter;
		}
		
		bool operator	!	=	(Dugum& sagDugum){
			return this->karakter!=sagDugum.karakter;
		}
		
		bool operator	>	(Dugum	& sagDugum)	{
			return this->frekans>sagDugum.frekans;
		}		}	;		class Huffman:Queue{
	public:
		Dugum *kok;
		int harfler;
		string girdi;
		
		Dugum *AgacOlustur(int frekans[]){
			Dugum *agaclar[harfler];
			for(int i=0; i<harfler; i++){
				if(frekans[i]>0)
					agaclar[i]=new Dugum((char)i, frekans[i]);
				else
					agaclar[i]=NULL;
			}
			while(true){
				int ilkIndeks=MinDugumIndeks(agaclar);
				Dugum *min1=agaclar[ilkIndeks];
				agaclar[ilkIndeks]=NULL;
				int ikinciIndeks=MinDugumIndeks(agaclar);
				if(ikinciIndeks==-1)
					return min1;
				Dugum *min2=agaclar[ikinciIndeks];
				agaclar[ikinciIndeks]=NULL;
	
				agaclar[ilkIndeks]=new Dugum(0, min1->frekans+min2->frekans, min1, min2);
			}
		}
		
		void KodOlustur(Dugum *altDugum, string kod){
			if(!altDugum->YaprakMi()){
				KodOlustur(altDugum->sol, kod+'0'); 
				KodOlustur(altDugum->sag, kod+'1'); 
				
			}
			else
				altDugum->kod=kod;
		}
		
		int MinDugumIndeks(Dugum *agaclar[]){
			Dugum *min;
			int minIndeks=-1;
			for(int i=0; i<harfler; i++){
				if(agaclar[i]!=NULL){
					min=agaclar[i];
					minIndeks=i;
					break;
				}
			}
			for(int i=0; i<harfler; i++){
				if(agaclar[i]==NULL)
					continue;
				if(*min>*agaclar[i]){
					
					min=agaclar[i];
					minIndeks=i;
				}
			}
			return minIndeks;
		}
		
		void DosyaOku(string dosyaYolu){
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
		
		void inorder(Dugum *altDugum){			if(altDugum!=NULL){
				inorder(altDugum->sol);
				if(altDugum->YaprakMi())
					cout<<altDugum->karakter<<" : "<<altDugum->kod<<endl;
				inorder(altDugum->sag);
			}
		}
		
		void  SilDugum  (Dugum*&   altDugum)  {
			if(altDugum==NULL)
				return;
			SilDugum(altDugum->sol);
			SilDugum(altDugum->sag);
			delete altDugum;
			altDugum=NULL;
		}
		Huffman(string dosyaYolu){			harfler=256;
			girdi="";
			DosyaOku(dosyaYolu);
			kok=NULL;
}
void Kodla(){			char karakterler[girdi.size()-1];
			strcpy(karakterler, girdi.c_str());
			int frekans[harfler];
			
			for(int i=0; i<harfler; i++)
				frekans[i]=0;
			for(int i=0; i<girdi.size()-1; i++)
				frekans[karakterler[i]]++;
			kok=AgacOlustur(frekans);	
			KodOlustur(kok, "");
		}
		
		friend ostream& operator<<(ostream& ekran, Huffman& sag){
			ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
			sag.inorder(sag.kok);
			return ekran;		}~Huffman			(){			SilDugum(kok);
		}
		
};

#endif