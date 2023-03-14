#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID "TDU"
#define WLAN_PASS "AA11BB22C1"

#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883
#define AIO_USERNAME "Raydric"
#define AIO_KEY "aio_mYHv71ynGSU53LY0xk6AsWmtEBnF"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Publish feed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/sau.saumqtt");

Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff");

void MQTT_connect();
void setup()
{
 Serial.begin(115200);
 delay(10);
 Serial.println(F("Adafruit MQTT demo"));
 // Connect to WiFi access point.
 Serial.println(); Serial.println();
 Serial.print("Connecting to ");
 Serial.println(WLAN_SSID);
 WiFi.begin(WLAN_SSID, WLAN_PASS);
 while (WiFi.status() != WL_CONNECTED)
 {
 delay(500);
 Serial.print(".");
 }
 Serial.println();
 Serial.println("WiFi connected");
 Serial.println("IP address: "); Serial.println(WiFi.localIP());
 mqtt.subscribe(&onoffbutton);
}
uint32_t x = 0;
void loop()
{
 MQTT_connect();
 Adafruit_MQTT_Subscribe* subscription;
 while ((subscription = mqtt.readSubscription(5000)))
 {
 if (subscription == &onoffbutton)
 {
 Serial.print(F("Got: "));
 Serial.println((char*)onoffbutton.lastread);
 }
 }
 Serial.print(F("\nSending feed val "));
 Serial.print(x);
 Serial.print("...");
 if (!feed.publish(x++))
 {
 Serial.println(F("Failed"));
 }
 else
 {
 Serial.println(F("OK!"));
 }
}

void MQTT_connect()
{
 int8_t ret;
 if (mqtt.connected())
 {
 return;
 }
 Serial.print("Connecting to MQTT... ");
 uint8_t retries = 3;
 while ((ret = mqtt.connect()) != 0)
 {
 Serial.println(mqtt.connectErrorString(ret));
 Serial.println("Retrying MQTT connection in 5 seconds...");
 mqtt.disconnect();
 delay(5000);
 retries--;
 if (retries == 0)
 {
 while (1) ;
 }
 }
 Serial.println("MQTT Connected!");
}
