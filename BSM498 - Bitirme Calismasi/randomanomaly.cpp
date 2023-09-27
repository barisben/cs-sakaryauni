#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  string x[] = {"Point - Birkaç saat boyunca beklenen sıcaklık değerlerinin çok altında kaldı.",
                "Point - Normal çalışma koşullarına rağmen beklenmedik bir yükseklik seviyesi tespit etti.",
                "Point - Belirtilen zaman dilimi boyunca beklenen bir su seviyesinin altına düştü.",
                "Point - Beklenenden daha düşük bir voltaj tespit etti ve birkaç dakika boyunca bu seviyede kaldı.",
				"Contextual - Beklenen yüksek sıcaklık değerlerinin görüldüğü yaz aylarında normal çalışma koşullarının dışında kaldı.",
				"Contextual - Beklenen yüksek nem oranının olduğu bir günde anormal bir yükseklik tespit etti.",
				"Contextual - Özel bir etkinlik nedeniyle belirtilen tarihte beklenenden daha yüksek bir su seviyesi tespit etti.",
				"Contextual - Belirtilen tarihte planlanan bir bakım çalışması sırasında beklenmeyen bir voltaj düşüklüğü tespit etti.",
				"Collective - Cihazlar belirli bir tarihte beklenenden daha düşük bir enerji tüketimi gösterdi.",
				"Collective - Cihazlar beklenenden daha yüksek bir sıcaklık seviyesi tespit edildiği bir zamanda normalin dışında kaldı.",
				"Collective - Cihazlar beklenenden daha yüksek bir nem oranı tespit edildiği bir zamanda beklenmeyen bir şekilde çalıştı.",
				"Collective - Cihazlar beklenenden daha yüksek bir su seviyesi tespit edildiği bir zamanda anormal bir davranış gösterdi."};
				
	string y[] = {"7UT85", "6MD85"};

  int x_size = sizeof(x)/sizeof(x[0]); // x dizisinin boyutunu hesapla
  int y_size = sizeof(y)/sizeof(y[0]);

  srand(time(NULL)); // rastgele sayı üretmek için zamanı kullan

  // rastgele bir tarih ve x dizisinden bir string seç
  for (int i = 0; i < 399; i++) {
    int day = rand() % 29 + 1;
	string day_st = day < 10 ? "0" + to_string(day) : to_string(day);
    int month = rand() % 12 + 1;
	string month_st = month < 10 ? "0" + to_string(month) : to_string(month);
    int year = 2022 + rand() % 2;
    int hour = rand() % 24;
	string hour_st = hour < 10 ? "0" + to_string(hour) : to_string(hour);
    int minute = rand() % 60;
	string minute_st = minute < 10 ? "0" + to_string(minute) : to_string(minute);
    int second = rand() % 60;
	string second_st = second < 10 ? "0" + to_string(second) : to_string(second);
    string selected_x = x[rand() % x_size];
	string selected_y = y[rand() % y_size];
	int rand_val = rand() % 100 + 1;

    ofstream myfile("randanomalylog.txt", ios::app);
    if (myfile.is_open()) {
      myfile << year << "-" << month_st << "-" << day_st << " " << hour_st << ":" << minute_st << ":" << second_st << " - " << selected_y << " - " << rand_val << " - " << selected_x << endl;
      myfile.close();
    } else {
      cout << "Dosya acilamadi." << endl;
      return 1;
    }
  }

  cout << "Dosyaya yazildi." << endl;


  return 0;
}
