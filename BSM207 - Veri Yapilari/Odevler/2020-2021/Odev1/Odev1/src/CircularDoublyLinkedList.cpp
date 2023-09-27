/**
* @file CircularDoublyLinkedList.cpp
* @description CircularDoublyLinkedList sınıfındaki fonksiyonların ve metotların oluşturulduğu dosya
* @course 2/B
* @assignment 1. ödev
* @date 29.11.2020
* @author Barış Yılmaz baris.yilmaz5@ogr.sakarya.edu.tr
*/

#include "CircularDoublyLinkedList.hpp"

Node* CircularDoublyLinkedList::FindPreviousNode(int index, int lenght){
	Node *prev=listeOrta;
	int i=lenght/2+1;
	for(Node *itr=listeOrta;i!=index;itr=itr->next,i++)
		prev=prev->next;
	return prev;
}
Node* CircularDoublyLinkedList::FindNextNode(int index){
	Node *next=listeOrta;
	int i=size;
	for(Node *itr=listeOrta;i!=index;itr=itr->prev, i--)
		next=next->prev;
	return next;
}
CircularDoublyLinkedList::CircularDoublyLinkedList(){
	listeOrta=NULL;
	size=0;
}
void CircularDoublyLinkedList::add(int *dizi, int lenght){
	listeOrta=new Node(dizi[0]);
	listeOrta->next=listeOrta->prev=listeOrta;
	size++;
	for(int i=1;i<(lenght+1)/2;i++){
		Node *nxt=FindNextNode(1);
		nxt->prev=new Node(dizi[i],nxt,listeOrta);
		nxt->prev->prev->next=nxt->prev;
		size++;
	}
	for(int i=(lenght+1)/2;i<lenght;i++){
		Node *prv=FindPreviousNode(i,lenght);
		prv->next=new Node(dizi[i],prv->next,prv);
		prv->next->next->prev=prv->next;
		size++;
	}
}
void CircularDoublyLinkedList::reverseOrder(){
	int *sayiTut = new int[(size-1)/2];
	int ind=(size-1)/2;
	int i=0;
	for(Node *itr=FindPreviousNode(size, size);ind<size-1;itr=itr->prev, ind++){
		sayiTut[i]=itr->data;
		i++;
		if(ind==size-2){
			itr=listeOrta;
			for(int j=0;j<(size-1)/2;itr=itr->next, j++)
				itr->next->data=sayiTut[j];
		}
	}
	ind=(size-1)/2;
	i=0;
	for(Node *itr=FindPreviousNode(size+1, size);ind<size-1;itr=itr->next, ind++){
		sayiTut[i]=itr->data;
		i++;
		if(ind==size-2){
			itr=listeOrta;
			for(int j=0;j<(size-1)/2;itr=itr->prev, j++)
				itr->prev->data=sayiTut[j];
		}
	}
	delete[] sayiTut;
}
void CircularDoublyLinkedList::caprazlama(CircularDoublyLinkedList **liste, int maksIndex, int minIndex){
	liste[maksIndex]->reverseOrder();
	liste[minIndex]->reverseOrder();
	int i=(liste[maksIndex]->size+1)/2;
	Node *itr=liste[maksIndex]->listeOrta;
	for(itr;i!=liste[maksIndex]->size;itr=itr->next, i++){}
	itr->next=liste[minIndex]->listeOrta;
	i=(liste[maksIndex]->size+1)/2;
	Node *itr2=liste[maksIndex]->listeOrta;
	for(itr2;i!=liste[maksIndex]->size;itr2=itr2->prev, i++){}
	itr2->prev=liste[minIndex]->listeOrta;
	liste[maksIndex]->listeOrta->next->prev=liste[maksIndex]->listeOrta->prev;
	liste[maksIndex]->listeOrta->prev->next=liste[maksIndex]->listeOrta->next;
	i=(liste[minIndex]->size+1)/2;
	Node *itr3=liste[minIndex]->listeOrta;
	for(itr3;i!=liste[minIndex]->size;itr3=itr3->next, i++){}
	itr3->next=liste[maksIndex]->listeOrta;
	i=(liste[minIndex]->size+1)/2;
	Node *itr4=liste[minIndex]->listeOrta;
	for(itr4;i!=liste[minIndex]->size;itr4=itr4->prev, i++){}
	itr4->prev=liste[maksIndex]->listeOrta;
	liste[minIndex]->listeOrta->next->prev=liste[minIndex]->listeOrta->prev;
	liste[minIndex]->listeOrta->prev->next=liste[minIndex]->listeOrta->next;
	liste[maksIndex]->listeOrta->prev=itr3;
	liste[maksIndex]->listeOrta->next=itr4;
	liste[minIndex]->listeOrta->prev=itr;
	liste[minIndex]->listeOrta->next=itr2;
	int tempSize=liste[minIndex]->size;
	liste[minIndex]->size=liste[maksIndex]->size;
	liste[maksIndex]->size=tempSize;
}
Node* CircularDoublyLinkedList::listeOrtaAdres(CircularDoublyLinkedList **liste){
	return listeOrta;
}
int CircularDoublyLinkedList::minIndexBul(CircularDoublyLinkedList **liste, int lenght){
	int minSayi=liste[0]->listeOrta->data;
	int minIndex;
	for(int i=0;i<lenght;i++){
		if(liste[i]->listeOrta->data<minSayi){
			minSayi=liste[i]->listeOrta->data;
			minIndex=i;
		}
	}
	return minIndex;
}
int CircularDoublyLinkedList::maksIndexBul(CircularDoublyLinkedList **liste, int lenght){
	int maksSayi=liste[0]->listeOrta->data;
	int maksIndex;
	for(int i=0;i<lenght;i++){
		if(liste[i]->listeOrta->data>maksSayi){
			maksSayi=liste[i]->listeOrta->data;
			maksIndex=i;
		}
	}
	return maksIndex;
}
ostream& operator<<(ostream& screen, CircularDoublyLinkedList& right){
	int index=0;
	Node *itr=right.listeOrta;
	for(itr;index<(right.size-1)/2;itr=itr->prev, index++){}
	index=0;
	for(itr;index<right.size;itr=itr->next, index++)
		screen<<itr->data<<" ";
	screen<<endl;
	return screen;
}
void CircularDoublyLinkedList::clear(){
	Node *del;
	while(size!=1){
		del=listeOrta;
		listeOrta=listeOrta->next;
		listeOrta->prev=del->prev;
		del->prev->next=listeOrta;
		size--;
	}
	listeOrta=listeOrta->next=listeOrta->prev=NULL;
	size--;
	delete del;
}
CircularDoublyLinkedList::~CircularDoublyLinkedList(){
	clear();
	delete listeOrta;
}