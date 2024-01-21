// Listing 6-2

byte a;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for ( int count = 0 ; count < 256 ; count++ )
  {
    a = count;
    Serial.print("Base-10 = ");
    Serial.print(a, DEC);
    Serial.print(" Binary = ");
    Serial.println(a, BIN);
    delay(1000);
  }
}
