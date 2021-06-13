#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;
#define SIZE 100

template <typename Object>

class BST{
	private:
		Object *items;
		int indeksDoluluk[SIZE];//indekste ağaç olup olmadığının kontrolü, 0 ise boş 1 ise dolu
		
		int IndexOf(const Object& item, int index=0){//index kok oluyor çünkü 0'a eşitledik
			while(true){
				if(index==SIZE || indeksDoluluk[index]==0)//eleman olmadıgı durum indeksDoluluk[index]==0 eleman yoksa demek
					return -1;
				if(items[index]==item && indeksDoluluk[index]==1)
					return index;
				else if(item<items[index])
					index=2*index+1;
				else if(item>items[index])
					index=2*index+2;
			}
		}
		bool ikininKatiMi(int x){
			while((x%2==0) && x>1)
				x/2;
			return x==1;
		}
		int EnKucukDeger(int i=0){
			if(2*i+1 > SIZE)
				return i;
			else if(indeksDoluluk[2*i+1]==0)
				return i;
			else
				return EnKucukDeger(2*i+1);
		}
	public:
		BST(){
			items=new Object[SIZE];
			clear();//dizinin icindeki anlamsız indeksleri temizliyoruz
		}
		void clear(){
			for(int i=0; i<SIZE; i++)
				indeksDoluluk[i]=0;
		}
		void Ekle(const Object& item){
			int currentIndex=0;
			while(true){//bos yer bulana kadar dolasiliyor
				if(indeksDoluluk[currentIndex]==0){//ilk eleman eklenme durumu yani kok
					items[currentIndex]=item;
					indeksDoluluk[currentIndex]=1;
					break;
				}
				else if(item < items[currentIndex])//sol tarafa ekleme
					currentIndex=2*currentIndex+1;
				else if(item > items[currentIndex])
					currentIndex=2*currentIndex+2;
				else return;//eşitlik durumunda bst'ye veri eklenmez!, while'dan cikilir
			}
		}
		bool Arama(const Object& item){
			if(IndexOf(item)==-1)//aranan eleman yoksa
				return false;
			return true;
		}
		int Yukseklik(int index=0){//index kok oluyor çünkü 0'a eşitledik
			if(indeksDoluluk[index]==0)//boş yere geldiysek
				return -1;
			return 1+max(Yukseklik(2*index+1), Yukseklik(2*index+2));//sol ve sag cocukların yukseklikleri alındı
		}
		void inorder(int index=0){
			if(index < SIZE && indeksDoluluk[index]!=0){
				inorder(2*index+1);
				cout<<items[index]<< " ";
				inorder(2*index+2);
			}
		}
		void preorder(int index=0){
			if(index < SIZE && indeksDoluluk[index]!=0){
				cout<<items[index]<< " ";
				preorder(2*index+1);	
				preorder(2*index+2);
			}
		}
		void postorder(int index=0){
			if(index < SIZE && indeksDoluluk[index]!=0){
				postorder(2*index+1);
				postorder(2*index+2);
				cout<<items[index]<< " ";
			}
		}
		void levelorder(){
			for(int i=0; i<SIZE; i++){
				if(indeksDoluluk[i]==1)
					cout<<items[i]<<" ";
			}
		}
		void sil(const Object& item, int index=0){
			int i=IndexOf(item, index);
			if(i==-1) throw "HATA";//eğer eleman yoksa hata fırlatır
			indeksDoluluk[i]=0;
			if(indeksDoluluk[2*i+2]==0){//sag cocugu yoksa silinecek agacın
				if(indeksDoluluk[2*i+1]==1){//sadece sol cocugu oldugu durum
					int k=2*i+1;
					int yedek[SIZE];
					for(int iter=0; iter<SIZE; iter++)
						yedek[iter]=0;
					yedek[0]=k;
					int index=0;
					//BFS Algoritmasi, bir seviye yukarı kaydırma islemleri icin
					for(int iter=0; iter<SIZE && yedek[iter] != 0; iter++){
						for(int x=0; x<SIZE; x++){
							if(ikininKatiMi(yedek[iter]+1-x)){
								items[(yedek[iter]+x-1)/2]=items[yedek[iter]];
								indeksDoluluk[(yedek[iter]+x-1)/2]=1;
								indeksDoluluk[yedek[iter]]=0;
								break;
							}
						}
						if(indeksDoluluk[2*yedek[iter]+1] != 0)
							yedek[++index]=2*yedek[iter]+1;
						if(indeksDoluluk[2*yedek[iter]+2] != 0)
							yedek[++index]=2*yedek[iter]+2;
					}
				}
			}
			else{
				if(indeksDoluluk[2*i+1]==0){//sadece sag cocuk oldugu durum
					int k=2*i+2;
					int yedek[SIZE];
					for(int iter=0; iter<SIZE; iter++)
						yedek[iter]=0;
					yedek[0]=k;
					int index=0;
					//BFS Algoritmasi, bir seviye yukarı kaydırma islemleri icin
					for(int iter=0; iter<SIZE && yedek[iter] != 0; iter++){
						for(int x=0; x<SIZE; x++){
							if(ikininKatiMi((yedek[iter]+x)/2+1)){
								items[(yedek[iter]-2-x)/2]=items[yedek[iter]];
								indeksDoluluk[(yedek[iter]-2-x)/2]=1;
								break;
							}
						}
						indeksDoluluk[yedek[iter]]=0;
						if(indeksDoluluk[2*yedek[iter]+1] != 0)
							yedek[++index]=2*yedek[iter]+1;
						if(indeksDoluluk[2*yedek[iter]+2] != 0)
							yedek[++index]=2*yedek[iter]+2;
					}
				}
				else{//iki cocugunun oldugu durum
					int x=EnKucukDeger(2*i+2);//en kucuk degerin indeksini aldik
					Object tmp=items[x];
					indeksDoluluk[i]=indeksDoluluk[x];
					items[i]=items[x];
					sil(tmp, x);
				}

			}
		}
		~BST(){
			delete[] items;
		}
};

#endif