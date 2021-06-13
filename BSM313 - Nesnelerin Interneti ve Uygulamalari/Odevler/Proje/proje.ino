#include  <ESP8266WiFi.h>
#include  <DNSServer.h>
#include  <ESP8266WebServer.h>
#include  <WiFiManager.h>
#include <LiquidCrystal_I2C.h>
#include <CayenneMQTTESP8266.h>

#define giris D6
#define cikis D5

char username[] = "9121bde0-2150-11eb-a2e4-b32ea624e442";
char password[] = "bc23f7fa76e2780f09c1c82dc6420dc0be5ed87f";
char clientID[] = "ef50ead0-2150-11eb-8779-7d56e82df461";

LiquidCrystal_I2C lcd(0x27, 16, 2);
int yolcuSayisi=0;

void wiFi()
{
  WiFiManager wifiManager;
  wifiManager.autoConnect ("AnlikYolcuAP");
}

void setup()
{
  wiFi();
  Cayenne.begin(username, password, clientID);
  lcd.begin();
  lcd.print("Anlik Yolcu");
  lcd.setCursor(0,1);
  lcd.print("Sayisi Projesi");
  delay(500);
  pinMode(giris, INPUT);
  pinMode(cikis, INPUT);
}

CAYENNE_OUT(0)
{
  Cayenne.virtualWrite(0, yolcuSayisi);
}

void GirisFonk()
{
  yolcuSayisi++;
  lcd.clear();
  if(yolcuSayisi <= 24)
  {
    lcd.print("Anlik Yolcu:");
    lcd.setCursor(0,1);
    lcd.print(yolcuSayisi);
  }
  else
  {
    lcd.print("MAKS YOLCU!");
    lcd.setCursor(0,1);
    lcd.print(yolcuSayisi);
  }
  delay(75);
}

void CikisFonk()
{
  if(yolcuSayisi > 0)
  {
    yolcuSayisi--;
    lcd.clear();
    if(yolcuSayisi != 0 && yolcuSayisi <=24)
    {
      lcd.print("Anlik Yolcu:");
      lcd.setCursor(0,1);
      lcd.print(yolcuSayisi);
    }
    else if (yolcuSayisi >= 25)
    {
      lcd.print("MAKS YOLCU!");
      lcd.setCursor(0,1);
      lcd.print(yolcuSayisi);
    }
    else
    {
      lcd.clear();
      lcd.print("Yolcu yok!");
    }
  }
  else
  {
    lcd.clear();
    lcd.print("Yolcu yok!");
  }
  delay(75);
}


void loop()
{
  int girisDeger = digitalRead(giris);
  int cikisDeger = digitalRead(cikis);
  
  if(girisDeger == LOW)
  {
    GirisFonk();
  }
  if(cikisDeger == LOW)
  {
    CikisFonk();
  }

  Cayenne.loop();
}
