/*  Kütüphane Dosyaları */
#include  <ESP8266WiFi.h>
#include  "ThingSpeak.h"
/*  Kablosuz  Bağlantı  Bilgileri */
#define WLAN_SSID   "TDU"       
#define WLAN_PASSWORD   "AA11BB22C1"         
/*  ThingSpeak  Kurulumu */
unsigned long channelID =1210813;
unsigned  int field_no=1;
const char* writeAPIKey = "7382ECMI1P6Q48VS";     //  Thingspeak  write API Key
const char* readAPIKey  = "2ZQDP697NWXOZY9V";     //  Thingspeak  read  API Key
/*    Pin Tanımları */
int sicaklikSensor=A0;      //  LM35  Data  ucu A0  pinine  bağlanacak
float sicaklikDegeri;     //  Analog  değeri  dönüştüreceğimiz  sıcaklık  değeri
float olculenDeger;        // Ölçeceğimiz analog  değer
WiFiClient  client;
/*  ESP8266 WiFi  Kurulum Fonksiyonu  */
void  wifiSetup (){
  delay(10);
  Serial.println();  Serial.println(WLAN_SSID);
  Serial.println(F("Kablosuz  Agina Baglaniyor"));
  WiFi.begin(WLAN_SSID,  WLAN_PASSWORD);
  //  WiFi  durum kontrolü
  while (WiFi.status()  !=  WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print(WLAN_SSID);  Serial.println("Kablosuz  Aga Baglandi");
  Serial.println("IP  adresi: "); Serial.println(WiFi.localIP());
}

void  setup() {
  Serial.begin(9600);  
  wifiSetup();  
  ThingSpeak.begin(client);
  pinMode  (A0,  INPUT); 
  Serial.println(F("Kurulum  Hazır"));
}

void  loop()  {
  delay(500);
  sicaklik();
}

void  sicaklik (){
  olculenDeger  = analogRead  (sicaklikSensor);
  olculenDeger  = (olculenDeger/1024)*5000;
  sicaklikDegeri  = olculenDeger  /12,0;
  sicaklikDegeri  = sicaklikDegeri-10;
  Serial.print("ThingSpeak  Gonderilen  Sicaklik  Değeri: "); Serial.println(sicaklikDegeri);
  ThingSpeak.writeField  (channelID, field_no, sicaklikDegeri, writeAPIKey);
  ThingSpeak.setField  (1, sicaklikDegeri);
  ThingSpeak.writeFields(channelID,  writeAPIKey);
  Serial.println("\n");
  delay(20000);
  float  oku = ThingSpeak.readFloatField(channelID,  field_no, readAPIKey);
  Serial.print("ThingSpeak’ten  Okunan  Sicaklik  Değeri: "); Serial.println(oku);
}
