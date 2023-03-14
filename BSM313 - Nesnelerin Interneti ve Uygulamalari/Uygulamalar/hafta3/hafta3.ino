#define  BLYNK_PRINT Serial
#include  <ESP8266WiFi.h>
#include  <BlynkSimpleEsp8266.h>
char  auth[]  = "cOJs7WujdgqA2bXlnv4-VYtLcacRChtJ"; // Blynk  uygulaması  tarafından  , mailinize gelen token key 
char  ssid[]  = "TDU"; // Bağlantı  yapacağınız wifi  adı 
char  pass[]  = "AA11BB22C1"; // Wifi  şifreniz
void  setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}
void  loop()
{
    Blynk.run();
}
