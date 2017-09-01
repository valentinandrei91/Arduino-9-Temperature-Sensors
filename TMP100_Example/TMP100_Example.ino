/* How to use the TMP100 sensor with Arduino uno
   Wiring Information: https://youtu.be/sWiThXeOAVQ
   Please subscribe to IntroAutomation Channel on YouTube
   More info: https://www.youtube.com/introautomation
    */
 
// Set the TMP Address and Resolution here
int tmpAddress = B1001011;
int ResolutionBits = 10;
 
#include <Wire.h>
 
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  SetResolution();
}
 
void loop(){
  getTemperature();
  delay(200);
}
 
float getTemperature(){
  Wire.requestFrom(tmpAddress,2);
  byte MSB = Wire.read();
  byte LSB = Wire.read();
 
  int TemperatureSum = ((MSB << 8) | LSB) >> 4;
 
  float celsius = TemperatureSum*0.0625;
  float fahrenheit = (1.8 * celsius) + 32;
 
  Serial.print("Celsius: ");
  Serial.println(celsius);
  Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);
}
 
void SetResolution(){
  if (ResolutionBits < 9 || ResolutionBits > 12) exit;
  Wire.beginTransmission(tmpAddress);
  Wire.write(B00000001); //addresses the configuration register
  Wire.write((ResolutionBits-9) << 5); //writes the resolution bits
  Wire.endTransmission();
 
  Wire.beginTransmission(tmpAddress); //resets to reading the temperature
  Wire.write((byte)0x00);
  Wire.endTransmission();
}
