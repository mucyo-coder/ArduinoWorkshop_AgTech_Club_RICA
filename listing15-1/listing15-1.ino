// Listing 15-1 - testing GPS receiver
#include <SoftwareSerial.h>

// GPS RX to D3, GPS TX to D2
SoftwareSerial Serial2(2, 3);

byte gpsData;

void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() 
{
  while (Serial2.available() > 0)
  {
    // get the byte data from the GPS
    gpsData = Serial2.read();
    Serial.write(gpsData);
  }
}
