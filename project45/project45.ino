// Project 45 - recording position of moving object over time

#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <SD.h>

// GPS RX to D3, GPS TX to D2
SoftwareSerial Serial2(2, 3);

TinyGPS gps;
void getgps(TinyGPS &gps);

byte gpsData;

void getgps(TinyGPS &gps)
{
  float latitude, longitude;
  int year;
  byte month, day, hour, minute, second, hundredths;

  // create/open and append the file for writing
  File dataFile = SD.open("DATA.TXT", FILE_WRITE);
  // if the file is ready, write to it:
  if (dataFile)
  {
    gps.f_get_position(&latitude, &longitude);
    dataFile.print("Lat: ");
    dataFile.print(latitude, 5);
    dataFile.print(" ");
    dataFile.print("Long: ");
    dataFile.print(longitude, 5);
    dataFile.print(" ");
    // decode and display time data
    gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths);
    // correct for your time zone as in Project 45
    hour = hour + 10;
    if (hour > 23)
    {
      hour = hour - 24;
    }
    if (hour < 10)
    {
      dataFile.print("0");
    }
    dataFile.print(hour, DEC);
    dataFile.print(":");
    if (minute < 10)
    {
      dataFile.print("0");
    }
    dataFile.print(minute, DEC);
    dataFile.print(":");
    if (second < 10)
    {
      dataFile.print("0");
    }
    dataFile.print(second, DEC);
    dataFile.print(" ");
    dataFile.print(gps.f_speed_kmph());
    dataFile.println("km/h");
    dataFile.close();
    delay(15000); // record a measurement around every 15 seconds
  }
  // if the file isn't ready, show an error:
  else
  {
    Serial.println("error opening DATA.TXT");
  }
}

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println("Initializing SD card...");
  pinMode(10, OUTPUT);
  // check that the memory card exists and is usable
  if (!SD.begin(10))
  {
    Serial.println("Card failed, or not present");
    // stop sketch
    return;
  }
  Serial.println("memory card is ready");
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
