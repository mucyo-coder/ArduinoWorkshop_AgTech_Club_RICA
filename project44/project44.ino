// Project 44 - GPS Clock with LCD
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
{
  int year,a,t;
  byte month, day, hour, minute, second, hundredths;
  gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
  hour=hour+10; // correct for your time zone
  if (hour>23)
  {
    hour=hour-24;
  }
  lcd.setCursor(0,0); // print the date and time
  lcd.print("Current time: ");
  lcd.setCursor(4,1);
  if (hour<10)
  {
    lcd.print("0");
  }
  lcd.print(hour, DEC);
  lcd.print(":");
  if (minute<10)
  {
    lcd.print("0");
  }
  lcd.print(minute, DEC);
  lcd.print(":");
  if (second<10)
  {
    lcd.print("0");
  }
  lcd.print(second, DEC);
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
