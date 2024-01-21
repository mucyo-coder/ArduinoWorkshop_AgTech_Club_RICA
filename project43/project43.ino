// Project 43 - GPS receiver with LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#include <TinyGPS.h>
#include <SoftwareSerial.h>

// GPS RX to D3, GPS TX to D2
SoftwareSerial Serial2(2, 3);

TinyGPS gps;
void getgps(TinyGPS &gps);

byte gpsData;

void getgps(TinyGPS &gps)
// The getgps function will display the required data on the LCD
{
  float latitude, longitude;
  //decode and display position data
  gps.f_get_position(&latitude, &longitude);
  lcd.setCursor(0, 0);
  lcd.print("Lat:");
  lcd.print(latitude, 5);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("Long:");
  lcd.print(longitude, 5);
  lcd.print(" ");
  delay(3000); // wait for 3 seconds
  lcd.clear();
}

void setup()
{
  Serial2.begin(9600);
}

void loop()
{
  while (Serial2.available() > 0)
  {
    // get the byte data from the GPS
    gpsData = Serial2.read();
    if (gps.encode(gpsData))
    {
      getgps(gps);
    }
  }
}
