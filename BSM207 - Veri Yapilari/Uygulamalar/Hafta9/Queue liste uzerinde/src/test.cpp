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
};

int main(){
	Queue<Kisi*> *kisiler=new Queue<Kisi*>();
	kisiler->enqueue(new Kisi("Murat", 45));
	kisiler->enqueue(new Kisi("Leyla", 25));
	kisiler->enqueue(new Kisi("Asli", 18));
	delete kisiler->peek();//önce adresten siliyoruz
	kisiler->dequeue();//sonrasinda adresten kurtuluyoruz
	cout<<*kisiler->peek();
	delete kisiler;
	return 0;
}