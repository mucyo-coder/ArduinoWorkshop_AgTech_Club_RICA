// Project 51 - Creating an IR Remote Control Tank
int receiverpin = 2; // pin 1 of IR receiver to Arduino digital pin 11
#include <IRremote.h>
IRrecv irrecv(receiverpin); // create instance of 'irrecv'
decode_results results;
#include <AFMotor.h>
AF_DCMotor motor1(1); // set-up instances of each motor
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void goForward(int speed, int duration)
{
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(duration);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

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

void rotateLeft(int speed, int duration)
{
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(duration);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void rotateRight(int speed, int duration)
{
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(duration);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// translateIR takes action based on IR code received, uses Sony IR codes
void translateIR()
{
  switch (results.value)
  {
    case 0x810:
      goForward(255, 250);
      break; // 2
    case 0xC10:
      rotateLeft(255, 250);
      break; // 4
    case 0xA10:
      rotateRight(255, 250);
      break; // 6
    case 0xE10:
      goBackward(255, 250);
      break; // 8
  }
}

void setup()
{
  delay(5000);
  irrecv.enableIRIn(); // start IR receiver
}

void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    for (int z = 0 ; z < 2 ; z++) // ignore the repeated codes
    {
      irrecv.resume(); // receive the next value
    }
  }
}
