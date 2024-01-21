// listing 8-1
#include "LedControl.h" //  need the library
LedControl lc = LedControl(12, 11, 10, 1);
void setup()
{
  lc.shutdown(0, false);  // enable display
  lc.setIntensity(0, 3);  // sets brightness
  lc.clearDisplay(0);     // clear screen
}

void loop()
{
  // numbers with decimal point
  for (int a = 0; a < 8; a++)
  {
    lc.setDigit(0, a, a, true);
    delay(500);
    lc.clearDisplay(0);// clear screen
  }
  // dashes
  for (int a = 0; a < 8; a++)
  {
    lc.setChar(0, a, '-', false);
    delay(500);
    lc.clearDisplay(0);// clear screen
  }
  // numbers without decimal point
  for (int a = 0; a < 8; a++)
  {
    lc.setDigit(0, a, a, false);
    delay(500);
    lc.clearDisplay(0);// clear screen
  }
  // display "abcdef"
  lc.setDigit(0, 5, 10, false);
  lc.setDigit(0, 4, 11, false);
  lc.setDigit(0, 3, 12, false);
  lc.setDigit(0, 2, 13, false);
  lc.setDigit(0, 1, 14, false);
  lc.setDigit(0, 0, 15, false);
  delay(500);
  lc.clearDisplay(0);// clear screen
}
