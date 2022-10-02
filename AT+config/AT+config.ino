#include <SoftwareSerial.h>

//Declares the bluetooth Receive pin an Transmision pin (Board, not component)
SoftwareSerial BTP(0, 1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("On");
  BTP.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTP.available()) Serial.write(BTP.read());
  if(Serial.available()) BTP.write(Serial.read());
}
