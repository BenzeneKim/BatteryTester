#include <SoftwareSerial.h>

SoftwareSerial btSerial(2,3);

void setup()
{
  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop()
{
    if(Serial.available())
    {
      delay(5); 
      while(Serial.available())
      {
        btSerial.write(Serial.read());
      }
    }
    if(btSerial.available())
    {
      delay(5); 
      while(btSerial.available())
      {
        Serial.write(btSerial.read());
      }
    }
}
