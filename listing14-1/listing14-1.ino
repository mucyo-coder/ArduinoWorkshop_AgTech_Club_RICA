// Listing 14-1
#include <Servo.h>
Servo myservo;
void setup()
{
  myservo.attach(4);
}
void loop()
{
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}
