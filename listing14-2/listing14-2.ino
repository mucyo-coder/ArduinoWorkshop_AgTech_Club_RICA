// Listing 14-2 - testing stepper motor
#include <CheapStepper.h>
CheapStepper stepper (8, 9, 10, 11);
boolean clockwise = true;
boolean cclockwise = false;

void setup()
{
  stepper.setRpm(20);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("stepper.moveTo (Clockwise, 0)");
  stepper.moveTo (clockwise, 0);
  delay(1000);

  Serial.println("stepper.moveTo (Clockwise, 1024)");
  stepper.moveTo (clockwise, 1024);
  delay(1000);

  Serial.println("stepper.moveTo (Clockwise, 2048)");
  stepper.moveTo (clockwise, 2048);
  delay(1000);

  Serial.println("stepper.moveTo (Clockwise, 3072)");
  stepper.moveTo (clockwise, 3072);
  delay(1000);

  Serial.println("stepper.moveTo (CClockwise, 512)");
  stepper.moveTo (cclockwise, 512);
  delay(1000);

  Serial.println("stepper.moveTo (CClockwise, 1536)");
  stepper.moveTo (cclockwise, 1536);
  delay(1000);

  Serial.println("stepper.moveTo (CClockwise, 2560)");
  stepper.moveTo (cclockwise, 2560);
  delay(1000);

  Serial.println("stepper.moveTo (CClockwise, 3584)");
  stepper.moveTo (cclockwise, 3584);
  delay(1000);
}
