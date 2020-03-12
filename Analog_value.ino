#include <ArduinoJson.h>
#define pot A0
int poten,i,n;


void setup()
{
  Serial.begin(9600);
  while(!Serial) continue;
  pinMode( pot, INPUT);
//  DynamicJsonDocument<200> doc;
}

void loop()
{
  poten=analogRead(pot);
  StaticJsonDocument<200> doc;
  //JsonObject root
  doc["Sensor"]="Potentiometer";
  n=poten;
  doc["Data"]=n;
  serializeJsonPretty( doc, Serial);
  
  
}
