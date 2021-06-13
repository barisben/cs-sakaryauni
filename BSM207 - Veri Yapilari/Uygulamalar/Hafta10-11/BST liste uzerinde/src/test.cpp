#include "BST.hpp"

int main(){
	BST<int> *agac=new BST<int>();
	agac->Ekle(62);
	agac->Ekle(88);
	agac->Ekle(25);
	agac->Ekle(68);
	agac->Ekle(94);
	agac->Ekle(37);
	agac->Ekle(63);
	cout<<endl<<"Preorder:"<<endl;
	agac->preorder();
	cout<<endl<<"Postorder:"<<endl;
	agac->postorder();
	cout<<endl<<"Levelorder:"<<endl;
	agac->levelorder();
	delete agac;
	return 0;
}