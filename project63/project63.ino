// Project 63 - Building an Arduino Dialer
#include <SoftwareSerial.h> // Virtual serial port
SoftwareSerial cell(2,3);
char incoming_char = 0;
void setup()
{
  pinMode(7, INPUT); // for button
  pinMode(8, OUTPUT); // shield power control
  //Initialize serial ports for communication.
  Serial.begin(9600);
  cell.begin(4800);
}
void callSomeone()
{
  // turn shield on
  Serial.println("Turning shield power on...");
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  delay(10000);
  cell.println("ATD0422556544"); // dial the phone number xxxxxxxxxx
  // change xxxxxxxxxx to your desired phone number (with area code)
  Serial.println("Calling ...");
  delay(20000); // wait 20 seconds.
  cell.println("ATH"); // end call
  Serial.println("Ending call, shield power off.");  
  // turn shield off to conserve power
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
}
void loop()
{
  if (digitalRead(7) == HIGH)
  {
    callSomeone();
  }
}
