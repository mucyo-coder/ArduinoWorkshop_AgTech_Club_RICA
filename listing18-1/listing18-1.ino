// Listing 18-1
#include <SoftwareSerial.h>
SoftwareSerial Serial2(2, 3); 
int data1 = 0;

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() 
{
  if (Serial2.available() > 0) {
    data1 = Serial2.read();
    // display incoming number
    Serial.print(" ");
    Serial.print(data1, DEC);
  }
}
