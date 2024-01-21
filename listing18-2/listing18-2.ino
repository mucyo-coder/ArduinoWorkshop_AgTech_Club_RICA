// Listing 18-2
#include <EEPROM.h>
int zz;
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop()
{
  Serial.println("Writing random numbers...");
  for (int i = 0; i < 1024; i++)
  {
    zz = random(255);
    EEPROM.write(i, zz);
  }
  Serial.println();
  for (int a = 0; a < 1024; a++)
  {
    zz = EEPROM.read(a);
    Serial.print("EEPROM position: ");
    Serial.print(a);
    Serial.print(" contains ");
    Serial.println(zz);
    delay(25);
  }
}
