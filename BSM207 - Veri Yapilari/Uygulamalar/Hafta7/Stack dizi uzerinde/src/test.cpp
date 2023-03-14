#include "Stack.hpp"

int main(){
	Stack<int> *yigit=new Stack<int>();
	yigit->push(100);
	yigit->push(200);
	yigit->push(300);
	yigit->push(400);
	yigit->pop();
	yigit->push(500);
	yigit->pop();
	yigit->pop();
	cout<<yigit->top();
	delete yigit;
	return 0;
}