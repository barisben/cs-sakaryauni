#include "CircularDoublyLinkedList.hpp"

int main() {
	CircularDoublyLinkedList<string> *isimler = new CircularDoublyLinkedList<string>();
	int secim = 0;
	string isim;
	int konum;
	do {
		system("CLS");
		cout << "1. isim ekle" << endl;
		cout << "2. isim sil" << endl;
		cout << "3. konumdan isim sil" << endl;
		cout << "4. konuma isim ekle" << endl;
		cout << "5. konum bul" << endl;
		cout << "6. isim sayisi" << endl;
		cout << "7. ilk isim" << endl;
		cout << "8. son isim" << endl;
		cout << "9. isimleri listele" << endl;
		cout << "10. isimleri temizle" << endl;
		cout << "11. isim ara" << endl;
		cout << "12. isimleri verilen konumdan bütün listeyi tersten yazdir" << endl;
		cout << "13. isimleri tersten listele" << endl;
		cout << "14. cikis" << endl;
		cout << "secim:" << endl;
		cin >> secim;
		system("CLS");
		switch (secim) {
		case 1:
			cout << "isim:";
			cin.ignore();
			getline(cin, isim);
			isimler->add(isim);
			break;
		case 2:
			cout << "isim:";
			cin.ignore();
			getline(cin, isim);
			isimler->remove(isim);
			break;
		case 3:
			cout << "konum:";
			cin >> konum;
			isimler->removeAt(konum);
			break;
		case 4:
			cout << "konum:";
			cin >> konum;
			cout << "isim:";
			cin.ignore();
			getline(cin, isim);
			isimler->insert(konum, isim);
			break;
		case 5:
			cout << "isim:";
			cin.ignore();
			getline(cin, isim);
			cout << "konum:" << isimler->indexOf(isim);
			cin.ignore();
			cin.get();
			break;
		case 6:
			cout << "isim sayisi:" << isimler->Count() << endl;
			cin.ignore();
			cin.get();
			break;
		case 7:
			cout << "ilk isim:" << isimler->first() << endl;
			cin.ignore();
			cin.get();
			break;
		case 8:
			cout << "son isim:" << isimler->last() << endl;
			cin.ignore();
			cin.get();
			break;
		case 9:
			cout << "isimler:" << endl;
			cout << *isimler << endl;
			cin.ignore();
			cin.get();
			break;
		case 10:
			isimler->clear();
			cout << endl << "isimler silindi." << endl;
			cin.ignore();
			cin.get();
			break;
		case 11:
			cout << "isim:";
			cin.ignore();
			getline(cin, isim);
			if(isimler->find(isim)) cout<<"isim var"<<endl;
			else cout<<"isim yok"<<endl;
			cin.ignore();
			cin.get();
			break;
		case 12:
			cout << "konum:";
			cin >> konum;
			isimler->printAllNodesPositionReverseOrder(konum);
			cin.ignore();
			cin.get();
			break;
		case 13:
			isimler->printReverseOrder();
			cin.ignore();
			cin.get();
			break;
		case 14:
			cout << "cikiliyor..";
			cin.ignore();
			cin.get();
			break;	
		default:
			cout << endl << "hatali giris!" << endl;
			cin.ignore();
			cin.get();
			break;
		}
		system("CLS");
	} while (secim != 14);
	delete isimler;
	return 0;
}