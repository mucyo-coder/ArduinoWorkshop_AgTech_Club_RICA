// Project 26 – LED Stopwatch 
#include "LedControl.h" //  need the library
LedControl lc = LedControl(12, 11, 10, 1);
unsigned long starting, finished, elapsed;
void setup()
{
  pinMode(2, INPUT); // the start button
  pinMode(3, INPUT); // the stop button
  lc.shutdown(0, false);  // enable display
  lc.setIntensity(0, 3);  // sets brightness
  lc.clearDisplay(0);     // clear screen
  starting = millis();
}

void displayResultLED()
{
  float h, m, s, ms;
  int m1, m2, s1, s2, ms1, ms2, ms3;
  unsigned long over;
  finished = millis();
  elapsed = finished - starting;

  h = int(elapsed / 3600000);
  over = elapsed % 3600000;
  m = int(over / 60000);
  over = over % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  
  // display hours
  lc.setDigit(0, 7, h, true);
  
  // display minutes
  m1 = m / 10;
  m2 = int(m) % 10;
  lc.setDigit(0, 6, m1, false);
  lc.setDigit(0, 5, m2, true);
  
  // display seconds
  s1 = s / 10;
  s2 = int(s) % 10;
  lc.setDigit(0, 4, s1, false);
  lc.setDigit(0, 3, s2, true);
  
  // display milliseconds (1/100 s)
  ms1 = int(ms / 100);
  ms2 = (int((ms / 10)) % 10);
  ms3 = int(ms) % 10;
  lc.setDigit(0, 2, ms1, false);
  lc.setDigit(0, 1, ms2, false);
  lc.setDigit(0, 0, ms2, false);
}

void loop()
{
  if (digitalRead(2) == HIGH)  // reset count
  {
    starting = millis();
    delay(200); // for debounce

  }
  if (digitalRead(3) == HIGH) // display count for five seconds then resume
  {
    finished = millis();
    delay(5000); // for debounce
  }
  displayResultLED();
}
