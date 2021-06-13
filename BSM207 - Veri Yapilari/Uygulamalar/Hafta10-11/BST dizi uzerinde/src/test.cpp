#include "BST.hpp"

int main(){
	BST<int> *agac=new BST<int>();
	agac->Ekle(50);
	agac->Ekle(40);
	agac->Ekle(80);
	agac->Ekle(30);
	agac->Ekle(45);
	agac->Ekle(60);
	agac->Ekle(90);
	agac->Ekle(36);
	cout<<endl<<"Inorder:"<<endl;
	agac->inorder();
	cout<<endl<<"Preorder:"<<endl;
	agac->preorder();
	cout<<endl<<"Postorder:"<<endl;
	agac->postorder();
	cout<<endl<<"Levelorder:"<<endl;
	agac->levelorder();
	cout<<endl<<"Yukseklik: "<<agac->Yukseklik()<<endl;
	agac->sil(50);
	cout<<endl<<"50'yi sildikten sonra Preorder:"<<endl;
	agac->preorder();
	delete agac;
	return 0;
}