/**
 * @file Queue.cpp
 * @description	Queue ile ilgili işlemleri yapan kaynak dosyası
 * @course	2. Öğretim A Grubu
 * @assignment	2. Ödev
 * @date	21.12.2022
 * @author	cemalss_1999@outlook.com
 */

#include "Queue.hpp"

void Queue::reserve(int newCapacity){
	int *temp = new int[newCapacity];
	for(int i=front,j=0;j<length; j++){
		temp[j] = items[i]; 
		i = (i + 1) % capacity;
	}
	capacity = newCapacity;
	delete[] items;
	items = temp;
	front = 0;
	back = length - 1;
}

Queue::Queue(){
	capacity=1;
	front=0;
	back=-1;
	length=0;			
	items=new int[capacity];
}

void Queue::clear(){			
	front=0;
	back=-1;
	length=0;
}
int Queue::count() const{
	return length;
}
bool Queue::isEmpty() const {
	if(length == 0) return true;
	return false;
}
/// Kuyrukta en öndeki elemanı getirir
const int& Queue::peek(){
	if(isEmpty()) throw "Empty List";
	return items[front];
}
void Queue::enqueue(const int& item){
	if(length == capacity) reserve(2*capacity);
	back = (back + 1) % capacity;
	items[back] = item;
	length++;
}
void Queue::dequeue(){
	if(isEmpty()) throw "Empty List";			
	front = (front + 1) % capacity;
	length--;
}
Queue::~Queue(){
	delete[] items;
}