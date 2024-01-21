// Listing 6-1
int r = 0;

void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Random number between zero and 1000 is: ");
  r = random(0, 1001);
  Serial.println(r);
  Serial.print("Random number between ten and fifty is: ");
  r = random(10, 51);
  Serial.println(r);
  delay(1000);
}
