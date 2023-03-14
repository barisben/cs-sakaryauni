#include <iostream>
using namespace std;

int main(){
	int a=10, b=10;
	int* p;
	int* r;
	p=&a;
	r=&b;
	if(p==r)
		cout<<"Esit";
	else
		cout<<"Esit degil";
	return 0;
}