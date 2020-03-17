#include <ThingSpeak.h>
#include <ArduinoJson.h>
#include <WiFiEsp.h>
#include<SoftwareSerial.h>
//#include "secrets.h"

char* ssid="Morphedo -2.4GHz";
char* pass="82$morph";

WiFiEspClient client;

#define pot A0
int poten,i,n;


unsigned long channelNumber=1018374;
const char* APIkey="O1QWXH2KHSICUJ9L";


void setup()
{
  Serial.begin(9600);
  while(!Serial) continue;
  pinMode( pot, INPUT);
//  setEspbaudrate(ESP_BAUDRATE);
  WiFi.init(&Serial);
 
 ThingSpeak.begin(client);
}


void loop()
{
    if(WiFi.status() != WL_CONNECTED)
    {
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);  
      Serial.print(".");
      delay(5000);     
    } 

  poten=analogRead(pot);
  StaticJsonDocument<200> doc;
  //JsonObject root
  doc["Sensor"]="Potentiometer";
  n=poten;
  doc["Data"]=n;
  serializeJsonPretty( doc, Serial);
  
    }
}
