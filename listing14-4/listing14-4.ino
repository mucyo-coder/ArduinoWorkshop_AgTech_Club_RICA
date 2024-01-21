// Listing 14-4 - testing ultrasonic distance sensor
#include <HCSR04.h>

UltraSonicDistanceSensor HCSR04(2, 13); // trig - D2, echo - D13

float distance;

void setup () 
{
  Serial.begin(9600);
}

void loop () 
{
  distance = HCSR04.measureDistanceCm();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
