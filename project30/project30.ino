// Project 30 - Graphics on TFT LCD

#include <TFT.h>  // Arduino TFT LCD library
#include <SPI.h>  // SPI bus library
TFT TFTscreen = TFT(10, 9, 8); // allocate digital pins to LCD

int a;

void setup()
{
  TFTscreen.begin(); // activate LCD
  TFTscreen.background(0, 0, 0); // set display to black
  randomSeed(analogRead(0)); // for random numbers
}

void loop()
{
  // random dots
  for (a = 0; a < 100; a++)
  {
    TFTscreen.stroke(random(256), random(256), random(256));
    TFTscreen.point(random(160), random(120));
    delay(10);
  }
  delay(1000);
  TFTscreen.background(0, 0, 0); // set display to black

  // random lines
  for (a = 0; a < 100; a++)
  {
    TFTscreen.stroke(random(256), random(256), random(256));
    TFTscreen.line(random(160), random(120), random(160), random(120));
    delay(10);
  }
  delay(1000);
  TFTscreen.background(0, 0, 0); // set display to black

  // random circles
  for (a = 0; a < 50; a++)
  {
    TFTscreen.stroke(random(256), random(256), random(256));
    TFTscreen.circle(random(160), random(120), random(50));
    delay(10);
  }
  delay(1000);
  TFTscreen.background(0, 0, 0); // set display to black

  // random filled circles
  for (a = 0; a < 50; a++)
  {
    TFTscreen.fill(random(256), random(256), random(256));
    TFTscreen.stroke(random(256), random(256), random(256));
    TFTscreen.circle(random(160), random(120), random(50));
    delay(10);
  }
  delay(1000);
  TFTscreen.background(0, 0, 0); // set display to black

  // random rectangles
  TFTscreen.noFill();
  for (a = 0; a < 50; a++)
  {
    TFTscreen.stroke(random(256), random(256), random(256));
    TFTscreen.rect(random(160), random(120), random(160), random(120));
    delay(10);
  }
  delay(1000);
  TFTscreen.background(0, 0, 0); // set display to black

  // random filled rectangles
  TFTscreen.noFill();
  for (a = 0; a < 50; a++)
  {
    TFTscreen.fill(random(256), random(256), random(256));
    TFTscreen.stroke(random(256), random(256), random(256));
    TFTscreen.rect(random(160), random(120), random(160), random(120));
    delay(10);
  }
  delay(1000);
  TFTscreen.background(0, 0, 0); // set display to black
}
