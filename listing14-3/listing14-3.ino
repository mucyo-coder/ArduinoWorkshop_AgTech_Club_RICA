// Listing 14-3
float sensor = 0;
int cm = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  u sensor = analogRead(0);
  v if (sensor<=90)
  {
    Serial.println("Infinite distance!");
  } 
else if (sensor<100) // 80cm
{
  cm = 80;
} 
else if (sensor<110) // 70 cm
{
  cm = 70;
} 
else if (sensor<118) // 60cm
{
  cm = 60;
} 
else if (sensor<147) // 50cm
{
  cm = 50;
} 
else if (sensor<188) // 40 cm
{
  cm = 40;
} 
else if (sensor<230) // 30cm
{
  cm = 30;
} 
else if (sensor<302) // 25 cm
{
  cm = 25;
} 
else if (sensor<360) // 20cm
{
  cm = 20;
} 
else if (sensor<505) // 15cm
{
  cm = 15;
} 
else if (sensor<510) // 10 cm
{
  cm = 10;
} 
else if (sensor>=510) // too close!
{
  Serial.println("Too close!");
}
Serial.print("Distance: ");
Serial.print(cm);
Serial.println(" cm");
delay(250);
}
