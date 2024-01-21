// Listing 4-3
#define LED 3
#define BUTTON 7

void setup()
{
  pinMode(LED, OUTPUT); // output for the LED
  pinMode(BUTTON, INPUT); // input for the button
}

void loop()
{
  if ( digitalRead(BUTTON) == HIGH )
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}
