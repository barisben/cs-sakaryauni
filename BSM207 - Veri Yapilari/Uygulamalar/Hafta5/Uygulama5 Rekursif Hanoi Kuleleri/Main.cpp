#include <iostream>
#include <string>
using namespace std;

void Hanoi(int diskSayisi, char kaynak, char yedek, char hedef){//A, B, C
	if(diskSayisi==1){
		cout<<"Diski "<<kaynak<<" ve "<<hedef<<" arasi tasi. (cift yonlu)"<<endl;
	}
	else{
		Hanoi(diskSayisi-1,kaynak,hedef,yedek);//yani hedefle yedeği yer değiştir diyoruz
		Hanoi(1,kaynak,yedek,hedef);//Kalanı kaynaktan hedefe
		Hanoi(diskSayisi-1, yedek, kaynak, hedef);
	}
}

int main(){
	int diskSayisi;
	cout<<"Hanoi Kulleleri"<<endl;
	cout<<"Disk sayisini giriniz:";
	cin>>diskSayisi;
	Hanoi(diskSayisi,'A','B','C');
	return 0;
}