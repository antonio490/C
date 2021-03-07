#include <iostream>
#include <string>

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

using namespace std

int main(void)
{
    cout << "Initializing libs";
    Serial.begin(9600);
    
    cout << "DHT";
    dht.begin();
    readDHT();

    return (0);

}

void readDHT()
{

    AdaSensor tempS = new Sensor();
    tempS.setId(1);
    tempS.setName("AdaFruit_DHT11");
 
    tempS.setTemperature(dht.readTemperature());    
    tempS.setHumidity(dht.readHumidity());

    Serial.print(F("Humidity: "));
    Serial.print(tempS.getHumidity());
    Serial.print(F("%  Temperature: "));
    Serial.print(tempS.getTemperature());
}