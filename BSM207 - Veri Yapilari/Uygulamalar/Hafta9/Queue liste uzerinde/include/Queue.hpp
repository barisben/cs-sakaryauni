#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename Object>

class Node{
	public:
		Object item;//dügümün verisi
		Node<Object> *next;
		
		Node(Object itm, Node<Object> *nxt=NULL){
			item=itm;
			next=nxt;
		}
};

template <typename Object>

class Queue{
	private:
		Node<Object> *front;//ilk elemanın düğümü
		Node<Object> *back;//sondaki elemanın dugumu
		int lenght;
	public:
		Queue(){
			front=back=NULL;//front ve back null baslangicta
			lenght=0;
		}
		bool isEmpty()const{//lenght 0 ise bos oldugu kabul edilir
			return lenght==0;
		}
		int count()const{//kuyruktaki eleman sayısını veren metot
			return lenght;
		}
		void enqueue(const Object& item){//kuyruga eleman ekleme
			Node<Object> *last=new Node<Object>(item);//sona yeni bir eleman ekleme
			if(isEmpty())//eğer liste bossa ve yeni eleman ekleniyorsa front da back de bu dugume esitleniyor
				front=back=last;
			else{//listede eleman varsa back'in yeniden ayarlanması
				back->next=last;
				back=last;
			}
			lenght++;
		}
		const Object& peek()const{
			if(isEmpty()) throw "Hata";
			return front->item;
		}
		void dequeue(){//kuyrugun basindan elemani silme
			if(isEmpty()) throw "Hata";
			Node<Object> *del=front;//gecici dugum, front silinecegi icin
			front=front->next;
			delete del;
			lenght--;
		}
		void clear(){//kuyruktaki dugumlerin temizlenmesi
			while(!isEmpty())//bos olmadigi surece dequeu calistiriliyor
				dequeue();
		}
		~Queue(){//yikici metotta clear cagiriliyor ve tum dugumler siliniyor
			clear();
		}
};

#endif