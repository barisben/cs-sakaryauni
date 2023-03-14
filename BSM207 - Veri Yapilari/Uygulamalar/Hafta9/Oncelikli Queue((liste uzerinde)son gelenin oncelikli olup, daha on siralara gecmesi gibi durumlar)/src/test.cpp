#include "Queue.hpp"

class Kisi{
	private:
		string isim;
		int yas;
	public:
		Kisi(){
			isim="";
			yas=0;
		}
		Kisi(string isim, int yas){
			this->isim=isim;
			this->yas=yas;
		}
		friend ostream& operator<<(ostream& screen, Kisi& r){
			screen<<r.isim<<" "<<r.yas<<endl;
			return screen;
		}
		bool operator>(Kisi& r){//">" neyi ifade edeceginin tanimlanmasi(max karsilastirmasinda yas icin)
		return this->yas>r.yas;	
		}
};

int main(){
	Queue<Kisi> *kisiler=new Queue<Kisi>();
	Kisi *murat=new Kisi("Murat", 15);
	Kisi *leyla=new Kisi("Leyla", 10);
	Kisi *asli=new Kisi("Asli", 18);
	kisiler->enqueue(*murat);
	kisiler->enqueue(*leyla);
	kisiler->enqueue(*asli);
	kisiler->dequeue();
	cout<<kisiler->peekMax();
	delete murat;
	delete leyla;
	delete asli;
	delete kisiler;
	return 0;
}