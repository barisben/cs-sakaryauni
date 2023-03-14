#include <iostream>
using namespace std;

int main(){
	int a=10;
	int* p;
	int* r;
	p=&a;
	r=p;
	*r=50;
	++a;
	cout<<a<<endl;
	cout<<&a<<endl;
	cout<<r<<endl;
	cout<<*r<<endl;
	cout<<&r<<endl;
	cout<<p<<endl;
	cout<<*p<<endl;
	cout<<&p<<endl;
	return 0;
}