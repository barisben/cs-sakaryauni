#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename Object>

class Queue{
	private:
		Object* items;//diziyi tutan pointer
		int capacity;
		int front;//öndeki indeksi
		int back;//arkadaki indeksi
		int lenght;//dizinin boyutu
		void reserve(int newCapacity){
			Object *tmp=new Object[newCapacity];//yeni dizi olusturuluyor
			for(int i=front, j=0; j<lenght; j++){//yeni dizinin indekslerine kopyalamalar yapılıyor
				tmp[j]=items[i];
				i=(i+1)%capacity;//kapasiteyi baz alarak i'yi 1 arttırma
			}
			capacity=newCapacity;
			delete [] items;
			items=tmp;
			front=0;
			back=lenght-1;
		}
	public:
		Queue(){
			capacity=100;//kapasite ilk durumda 100 olarak olusturuluyor
			front=0;//ilk durumda 0 olarak baslatiliyor
			back=-1;//ilk durumda bos olarak baslatiliyor
			lenght=0;//ilk durumda eleman sayısı 0
			items=new Object[capacity];//100 elemanlı dizi olusturuluyor
		}
		bool isEmpty()const{//lenght 0 ise bos oldugu kabul edilir
			return lenght==0;
		}
		int count()const{//kuyruktaki eleman sayısını veren metot
			return lenght;
		}
		void enqueue(const Object& item){//kuyruga eleman ekleme
			if(lenght==capacity)//eğer doluluk kapasiteye esitse reserve fonknunda kapasitenin 2 katı kadar kapasiteyle yeni bir dizi olusturularak queue oraya aktarılır
				reserve(2*capacity);
			back=(back+1)%capacity;
			items[back]=item;
			lenght++;
		}
		const Object& peek()const{//kuyrugun basindaki elemanı gonderir
			if(isEmpty()) throw "Hata";
			return items[front];
		}
		void dequeue(){//kuyrugun basindan elemani silme
			if(isEmpty()) throw "Hata";
			front=(front+1)%capacity;
			lenght--;
		}
		void clear(){//kuyruktaki elemanlarin temizlenmesi, baslangic durumuna aliniyor
			front=0;
			back=-1;
			lenght=0;
		}
		~Queue(){//yikici metotta items siliniyor
			delete[] items;
		}
};

#endif