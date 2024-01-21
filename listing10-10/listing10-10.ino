float temperature;

float readC()
{
  float tempC;
  tempC = analogRead(0);
  tempC = tempC = (tempC * 5000) / 1024;
  tempC = tempC - 500;
  tempC = tempC / 10;
  return tempC;
}

float readF()
{
  float tempC;
  float tempF;
  tempC = analogRead(0);
  tempC = tempC = (tempC * 5000) / 1024;
  tempC = tempC - 500;
  tempC = tempC / 10;
  tempF = (tempC * 1.8) + 32;
  return tempF;
}
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Temperature in Celsius is: ");
  temperature = readC();
  Serial.println(temperature);
  Serial.print("Temperature in Fahrenheit is: ");
  temperature = readF();
  Serial.println(temperature);
  delay(1000);
}
