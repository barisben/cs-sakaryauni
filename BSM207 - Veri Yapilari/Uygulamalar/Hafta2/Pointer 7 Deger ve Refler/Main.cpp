#include <iostream>
using namespace std;

/*void Degistir(int a){//burada x'i değil x'in değeri 200ü gönderdiği için main scopeta değişiklik olmuyor. pointer kullanılmalıydı.
	a=100;//bu kısım değer ile çağırma
}*/
/*void Degistir(int &a){//fakat böyle olur, bu kısım ref ile çağırma
	a=100;
}*/

/*void Degistir(int* p){
	*p=100;
}*/

void Degistir(int*& p){
	*p=100;
}

int main(){
	int x=200;
	int* r=&x;
	Degistir(r);
	cout<<x;
	return 0;
}