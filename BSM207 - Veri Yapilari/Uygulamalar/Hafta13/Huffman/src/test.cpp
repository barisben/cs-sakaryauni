#include "Huffman.hpp"

int main(){
	system("CLS");
	Huffman *agac=new Huffman("Dosya.txt");
	agac->Kodla();
	cout<<*agac<<endl;	
	delete agac;
	return 0;
}