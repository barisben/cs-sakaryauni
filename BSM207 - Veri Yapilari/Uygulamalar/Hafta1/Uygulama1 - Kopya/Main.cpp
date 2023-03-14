#include <iostream>

using namespace std;

int main(){
	int x=2;
	x = (x < 3 ? x*3+2 : x);
	cout<<x;
	return 0;
}