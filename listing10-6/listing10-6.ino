void setup() {
  pinMode(13, OUTPUT); // use onboard LED
}

void blinkType(int blinks, int duration)
// blinks is the number of times to blink the LED
// duration is the length of time in ms for each on and off cycle
{
  for (int i = 0; i < blinks; i++)
  {
    digitalWrite(13, HIGH);
    delay(duration);
    digitalWrite(13, LOW);
    delay(duration);
  }
}

void loop()
{
  // blink LED ten times, with 250ms duration
  blinkType(10, 250);
  delay(1000);
  // blink LED three times, with one second duration
  blinkType(3, 1000);
  delay(1000);
}
