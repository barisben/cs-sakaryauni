#ifndef CIRCULARDOUBLYLINKEDLIST_HPP
#define CIRCULARDOUBLYLINKEDLIST_HPP

#include "Node.hpp"

template <typename Object>
class CircularDoublyLinkedList{
	private:
		Node<Object> *head;//ilk oluşturulan dügüm
		int size;//boyutu
		Node<Object>* FindPreviousNode(int index){//Bir önceki düğümü bulma
			Node<Object> *prev=head;
			int i=1;
			for(Node<Object> *itr=head;i!=index;itr=itr->next,i++){//itr nextin ilerisini kontrol etmeye gerek yok çünkü başı gösterecek
				prev=prev->next;
			}
			return prev;
		}
	public:
		CircularDoublyLinkedList(){//içi boşsa başta değerler
			head=NULL;
			size=0;
		}
		int Count()const{//eleman sayısını döndüren fonk
			return size;
		}
		bool isEmpty()const{//listenin bos olup olmadigi kontrolü
			return size==0;
		}
		void add(const Object& item){//sona eleman ekleme
			insert(size,item);
		}
		void insert(int index,const Object& item){//araya eleman ekleme, index konumu
			//if(index<0 || index>=size) böyleyse hatalı islem olur, "throw hata veya throw "Hatali islem";"
			if(index==0){//head yerine ekleniyorsa yeni head olması için kontrol, yani liste başı
				if(size==0){//ilk kez mi dügüm ekleniyor kontrolü
					head=new Node<Object>(item);
					head->next=head->prev=head;//ilk düğümse previ de nexti de kendisini gösteriyor
				}
				else{//düğüm varsa
					head=new Node<Object>(item,head,head->prev);//"head->prev" bu kısımdan dolayı previ headin previni yani sonu gösterecek
					head->next->prev=head;//eski headin previnin yeni heade bağlanması
					head->prev->next=head;//son dügümün nextinin yeni heade bağlanması
				}
			}
			else{//araya veya sona eleman ekleme
				Node<Object> *prv=FindPreviousNode(index);
				prv->next=new Node<Object>(item,prv->next,prv);
				prv->next->next->prev=prv->next;
			}
			size++;
		}
		const Object& first()const{//listenin ilk elemanının döndürülmesi
			//if(isEmpty())//boşsa hata döndürür
			return head->data;
		}
		const Object& last(){//listenin son elemanının döndürülmesi
			//if(isEmpty())//boşsa hata döndürür
			return head->prev->data;
		}
		int indexOf(const Object& item)const{//verdiği elemanın indexini döndürme
			int index=0;
			for(Node<Object> *itr=head;index<size;itr=itr->next){
				if(itr->data==item) return index;//datası verilen iteme eşitse indexi döndürür
				index++;//değilse indexi 1 arttır, bulana dek
			}
			throw "Eleman yok";//olmayan bir eleman girilirse
		}
		const Object& elementAt(int index)const{//verilen indexin elemanını döndürme
			//if(index<0 || index>=size) böyleyse hatalı islem olur, "throw hata veya throw "Hatali islem";"
			if(index==0) return first();//index 0 ise head i döndürür
			return FindPreviousNode(index+1)->data;//+1 yaptık, 1 öncesi istediğimiz yer oluyor ve datasını alıyoruz
		}
		void remove(const Object& item){//indexini bulup elemanı silme
			int index=indexOf(item);
			removeAt(index);
		}
		void removeAt(int index){//indexten eleman silme
			//if(index<0 || index>=size) böyleyse hatalı islem olur, "throw hata veya throw "Hatali islem";"
			Node<Object> *del;//bastaki elemani kaybetmemek icin
			if(index==0){//ilk eleman mı siliniyor kontrolü, yani head
				del=head;
				if(size==1){//listenin boyutu 1 ise tek düğüm vardır ve son düğüm siliniyor demektir
					head=head->next=head->prev=NULL;//eğer öyleyse tümünü NULL yapıyoruz
				}
				else{//listenin boyutu 1'den fazlaysa
					head=head->next;
					head->prev=del->prev;
					del->prev->next=head;
				}			
			}
			else{//aradan veya sondan silme durumu
				Node<Object> *prv=FindPreviousNode(index);
				del=prv->next;
				prv->next=del->next;
				del->next->prev=prv;
			}
			delete del;//del new ile olusturuldugu icin ram e iade
			size--;//eleman sayısını 1 eksiltiyoruz
		}
		bool find(const Object& item)const{//verdiği elemanın olup olmadığının kontrolü
			int index=0;//"index<size" için yazıldı çünkü içerisi boşsa bir şey bulamaz direkt false döndürür
			for(Node<Object> *itr=head;index<size;itr=itr->next,index++){
				if(itr->data==item) return true;//datası verilen iteme eşitse true döndürür
			}
			return false;
		}
		void clear(){//liste temizleme
			while(!isEmpty()){//liste boşalana dek sürekli ilk indexi silme
				removeAt(0);
			}
		}
		friend ostream& operator<<(ostream& screen,CircularDoublyLinkedList& right){//elemanları ekrana yazdırma
			int index=0;
			for(Node<Object> *itr=right.head;index<right.size;itr=itr->next){
				screen<<itr->data<<" ";
				index++;
			}
			screen<<endl;
			return screen;
		}
		void printAllNodesPositionReverseOrder(int index){//verilen indexten itibaren geriye yazdırma, örneğin 2. index girilirse 2-1-0 olarak yazdırılacak
			//if(index<0 || index>=size) böyleyse hatalı islem olur, "throw hata veya throw "Hatali islem";"
			int ind=0;
			for(Node<Object> *itr=FindPreviousNode(index+1);ind<size;itr=itr->prev){//index deseydik örneğin 2.indeks desek 1.yi verirdi, şimdi direkt isteneni veriyor
				cout<<itr->data<<" ";
				ind++;
			}
			cout<<endl;
		}
		void printReverseOrder(){//tüm listeyi tersinden yazdırma
			printAllNodesPositionReverseOrder(size-1);//eleman sayısı 4 ise index 3ten 0'a gittiği için -1
		}
		~CircularDoublyLinkedList(){
			clear();//bu fonksiyonda zaten tüm düğümler siliniyor
			delete head;//privateda oluşturulan düğüm
		}
};

#endif