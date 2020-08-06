#include <SoftwareSerial>

int laserSenso = 4;
int laserModule = 5;
unsigned long timer
SoftwareSerial BT(2,3);
void setup(){
  BT.begin(9600);
  pinMode(laserSensor, INPUT);
  pinMode(laserModule, OUTPUT);
  digitalWrite(laserModule, HIGH);
}

void main(){
  BT.print(String(getVCC()));
  BT.println(String(getRPM()));
}

int getRPM{
  preTimer = millis();
  int repeatVal = 0;
  while(timer - preTimer < 60000){
    repeatVal++;
    while(!digitalRead(laserSensor));
    timer = millis();
    while(digitalRead(laserSensor));
  }
  return repeatVal/5;
}

int getVCC() {                              // Returns ADC value on the power pin
  ADCSRA |= _BV(ADSC); // Convert           // alowes to get the battery voltage
  while (bit_is_set(ADCSRA, ADSC));         //without using any additional pin
  byte low = ADCL;
  unsigned int val = (ADCH << 8) | low;
  //discard previous result
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA, ADSC));
  low = ADCL;
  val = (ADCH << 8) | low;
  //return val;
  return ((long)1024 * 1100) / val;      // return value in mV (don't need this)
}
