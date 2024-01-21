// Listing 4-2
if (digitalRead(BUTTON) == HIGH)
{
  digitalWrite(LED, HIGH); // turn on the LED
  delay(500); // wait for 0.5 seconds
  digitalWrite(LED, LOW); // turn off the LED
}
