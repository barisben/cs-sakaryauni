#include <iostream>
using namespace std;

int main(){
	int a=50;
	int* p=&a;
	int** pp=&p;
	cout<<"a: "<<a<<endl;//1
	cout<<"&a: "<<&a<<endl;//2
	
	cout<<"p: "<<p<<endl;//2
	cout<<"*p: "<<*p<<endl;//1
	cout<<"&p: "<<&p<<endl;//3
	
	cout<<"pp: "<<pp<<endl;//3
	cout<<"*pp: "<<*pp<<endl;//2
	cout<<"&pp: "<<&pp<<endl;//4
	
	cout<<"**pp: "<<**pp<<endl;//1
	return 0;
}