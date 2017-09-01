/* How to use the DHT-11 sensor with Arduino uno
   Temperature and humidity sensor
   Wiring Information: https://youtu.be/sWiThXeOAVQ
   Please subscribe to IntroAutomation Channel on YouTube
   More info: https://www.youtube.com/introautomation
   
    */
#include <dht.h>

dht DHT;

#define DHT11_PIN 2

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
