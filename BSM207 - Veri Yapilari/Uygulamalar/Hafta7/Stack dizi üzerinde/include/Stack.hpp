#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Stack{
	private:
		Object *items;//dizinin ilk elemanını gösteren pointer
		int topOfStack;//son elemanını indexinin kac oldugunu gösterir, yani 5 eleman varsa 4 değerini tutar
		//lenght olmasa idi topOfStack+1 ile de eleman sayısı bulunabilirdi
		int capacity;//kapasitesi
		int lenght;//eleman sayısı
		
		void reserve(int newCapacity){//kapasite dolduysa yeni bir dizi olusturup capacity*2 yaparak eski dizidekilerini de yeni diziye aktarıyor
			Object *tmp=new Object[newCapacity];//önce yeni 1 dizi olusturuluyor.
			for(int i=0;i<lenght;i++)
				tmp[i]=items[i];
			delete[] items;//eski items dizisini heapten silip daha sonra publicteki itemsı tmpye eşitliyoruz
			items=tmp;
			capacity=newCapacity;
		}
	public:
		Stack(){
			capacity=100;
			items=new Object[capacity];//100 uzunluğunda bir dizi tanımlanıyor.
			lenght=0;//başlangıçta hiç eleman olmayacağı için 0
			topOfStack=-1;//başta hiç eleman olmadığı için hiçbir şeyi göstermemesi gerektiği için olmayan bir değer
		}
		bool isEmpty()const{//içi boş mu dolu mu
			return lenght==0;
		}
		void push(const Object& item){//push eleman ekleme metodu
			if(lenght==capacity)//eğer yer dolduysa reserve metoduyla kapasite 2 katına çıkarılıyor
				reserve(2*capacity);
			//buraya gelindiyse artık eleman eklemek için yer var demektir
			topOfStack++;//örneğin 5 eleman varsa topOfStack 4'ü gösterir, +1 diyerek 5.indekse yeni eleman eklenir
			items[topOfStack]=item;
			lenght++;//eleman sayısı da 1 arttırılır ve bu sekilde eleman eklenmis olur
		}
		const Object& top()const{//yani son elemanı gösteren fonk
			//if (isEmpty()) throw hata //eleman yoksa bu metot çağırılamaz demek
			return items[topOfStack];//son elemanı da topOfStack'in değerindeki index demek oluyor
		}
		void pop(){//yığıttan eleman silme metodu, en son giren elemanı çıkarma, o da top metodundan döndürülen topOfStack'in yerindeki item
			//if(isEmpty()) throw hata //yığıt boşsa çağırılamaz
			topOfStack--;//eleman silindiği için bu ve lenght 1 eksiliyor
			lenght--;
		}
		void makeEmpty(){//yığıtı boşaltma metodu fakat diziyi silmiyor, yalnızca elemanlar siliniyor
			//tüm eleman kadar dönüp değerleri silmek yerine bu şekilde yapıp bundan sonra dizinin üzerine elemanllar
			//eklenirse zaten eski değerlerin üzerine yazacağı için otomatik olarak silinmiş gibi olacak
			topOfStack=-1;
			lenght=0;
		}
		~Stack(){//diziyi silmek yığıtı temizlemek için yeterli
			delete[] items;
		}
};
#endif