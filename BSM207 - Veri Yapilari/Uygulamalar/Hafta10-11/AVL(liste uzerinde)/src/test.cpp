#include "AVL.hpp"

int main(){
	AVL<int> *agac=new AVL<int>();
	agac->Ekle(1);
	agac->Ekle(2);
	agac->Ekle(3);
	agac->Ekle(4);
	agac->Ekle(5);
	agac->Ekle(6);
	agac->Ekle(7);
	agac->Ekle(8);
	cout<<endl<<"Yukseklik: "<<agac->Yukseklik()<<endl;
	cout<<endl<<"Inorder:"<<endl;
	agac->inorder();
	cout<<endl<<"Preorder:"<<endl;
	agac->preorder();
	cout<<endl<<"Postorder:"<<endl;
	agac->postorder();
	cout<<endl<<"Levelorder:"<<endl;
	agac->levelorder();
	delete agac;
	return 0;
}