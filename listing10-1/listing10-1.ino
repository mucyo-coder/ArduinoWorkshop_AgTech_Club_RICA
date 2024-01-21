void setup() {
  pinMode(13, OUTPUT); // using onboard LED
}

void blinkSlow()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
}

void blinkFast()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    delay(250);
  }
}


void loop()
{
  blinkSlow();
  delay(1000);
  blinkFast();
  delay(1000);
}
