#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

class Queue{
	private:
		int front;
		int back;
		int capacity;
		int length;
		int *items;
		
		void reserve(int);
	public:
		Queue();
		void clear();
		int count() const;
		bool isEmpty() const;
		/// Kuyrukta en öndeki elemanı getirir
		const int& peek();
		void enqueue(const int&);
		void dequeue();
		~Queue();
};
#endif
