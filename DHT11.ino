#include <dht.h>
#define dht_dpin A2
dht DHT;
void setup()
{
    Serial.begin(9600);
}

void loop()
{   
   DHT.read11(dht_dpin);
   
   float h = DHT.humidity;
   float t = DHT.temperature;
   Serial.print("Temperature : ");
   Serial.println(t);
   Serial.print("Hygrometrie : ");
   Serial.print(h);
   Serial.println("\%");
   delay(1000);
 }
