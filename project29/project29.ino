// Project 29 - Text on TFT LCD
#include <TFT.h>  // Arduino TFT LCD library
#include <SPI.h>  // SPI bus library
TFT TFTscreen = TFT(10, 9, 8); // allocate digital pins to LCD

char analogZero[4];

void setup()
{
  TFTscreen.begin(); // activate LCD
  TFTscreen.background(0, 0, 0); // set display to black
}

void loop()
{
  TFTscreen.stroke(255, 255, 255); // white text
  TFTscreen.setTextSize(1);
  TFTscreen.text("Size One", 0, 0);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Size Two", 0, 10);
  TFTscreen.setTextSize(3);
  TFTscreen.text("Size 3", 0, 30);
  TFTscreen.setTextSize(4);
  TFTscreen.text("Size 4", 0, 55);
  delay(2000);
  TFTscreen.background(0, 0, 0); // set display to black
  TFTscreen.setTextSize(5);
  TFTscreen.text("Five", 0, 0);
  delay(2000);
  TFTscreen.background(0, 0, 0); // set display to black
  TFTscreen.stroke(255, 255, 255); // white text
  TFTscreen.setTextSize(1);
  TFTscreen.text("Sensor Value :\n ", 0, 0);
  TFTscreen.setTextSize(3);
  String sensorVal = String(analogRead(A0));
  // convert the reading to a char array
  sensorVal.toCharArray(analogZero, 4);
  TFTscreen.text(analogZero, 0, 20);
  delay(2000);
  TFTscreen.background(0, 0, 0); // set display to black
}
