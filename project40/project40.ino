// Project 40 – Detecting Robot Vehicle Collisions with a Microswitch
#include <AFMotor.h>

AF_DCMotor motor1(1); // set-up instances of each motor
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

boolean crash = false;

void goBackward(int speed, int duration)
{
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(duration);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void backOut()
{
  crash = true;
}

void goForward(int duration, int speed)
{
  long a, b;
  boolean move = true;
  a = millis();
  do
  {
    if (crash == false)
    {
      motor1.setSpeed(speed);
      motor2.setSpeed(speed);
      motor3.setSpeed(speed);
      motor4.setSpeed(speed);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }
    if (crash == true)
    {
      goBackward(200, 2000);
      crash = false;
    }
    b = millis() - a;
    if (b >= duration)
    {
      move = false;
    }
  }
  while (move != false);
  // stop motors
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void setup()
{
  attachInterrupt(0, backOut, RISING);
  delay(5000);
}

void loop()
{
  goForward(5000, 127);
  delay(2000);
}
