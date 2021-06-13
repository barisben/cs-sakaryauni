#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

using namespace std;

template <typename Object>

//Bu Class aslında c# gibi dillerde otomatik bulunan bir class. fakat c++'da olmadığı için bu şekilde implemente ettik.
class ArrayList{
	private:
		Object* items;
		int lenght;
		int capacity;
		void Reserve(int newCapacity){
			if(capacity>=newCapacity)
				return;
			Object* temp=new Object[newCapacity];
			for(int i=0;i<lenght;i++){
				temp[i]=items[i];
			}
			if(items!=NULL)
				delete[] items;
			items=temp;
			capacity=newCapacity;
		}
	public:
		ArrayList(){
			lenght=0;
			capacity=0;
			items=NULL;
		}
		int Size()const{//const yalnızca okuma işlemi
			return lenght;
		}
		int IsEmpty()const{
			return Size()==0;
		}
		int IndexOf(const Object& item){
			for(int i=0;i<lenght;i++){
				if(items[i]==item)
					return i;
			}
			return -1;
		}
		const Object& ElementAt(int i){
			if(i<0 || i>lenght)
				return NULL;
			return items[i];
		}
		void Remove(const Object& item){
			RemoveAt(IndexOf(item));
			return;
		}
		void RemoveAt(int i){
			if(i<0 || i>lenght)
				return;
			for(int j=i+1;j<lenght;j++)
				items[j-1]=items[j];
			lenght--;
		}
		void Add(const Object& yeni){
			Insert(lenght, yeni);
		}
		void Insert(int i, const Object& yeni){
			if(i<0 || i>lenght)
				return;
			if(lenght>=capacity)
				Reserve(max(1,2*capacity));
			for(int j=lenght-1; j>=i; j--){
				items[j+1]=items[j];
			}
			items[i]=yeni;
			lenght++;
		}
		const Object& First(){
			if(lenght==0)
				return NULL;
			return items[0];
		}
		const Object& Last(){
			if(lenght==0)
				return NULL;
			return items[lenght-1];
		}
		void Clear(){
			lenght=0;
		}
		friend ostream& operator<<(ostream& screen, ArrayList<Object>& right){//operatör overlloading
			screen<<endl;
			for(int i=0;i<right.lenght;i++){
				screen<<right.items[i];
				if(i+1!=right.lenght)
					screen<<" ||";
			}
			return screen;
		}
		~ArrayList(){
			if(items!=NULL)
				delete[] items;
		}
};

#endif