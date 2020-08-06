#include <SoftwareSerial>

SoftwareSerial BT(2,3);

void setup(){
  BT.begin(9600);
  Serial.begin(9600);
}

void main(){
  while(Serial.available()) Serial.print(BT.read());
  Serial.println("\n");
}
