// Project 64 - Building an Arduino Texter
#include <SerialGSM.h>
#include <SoftwareSerial.h> // Virtual serial port
SerialGSM cell(2, 3);

void sendSMS()
{
  cell.Message("The button has been pressed!");
  cell.SendSMS();
}

void setup()
{
  pinMode(7, INPUT); // for button
  pinMode(8, OUTPUT); // shield power control
  // turn shield on
  Serial.println("Turning shield power on...");
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  //Initialize serial ports for communication.
  Serial.begin(9600);
  cell.begin(4800);
  cell.Verbose(true);
  cell.Boot();
  cell.FwdSMS2Serial();
  cell.Rcpt("0422556544");
  delay(10000);
}

void loop()
{
  if (digitalRead(7) == HIGH)
  {
    sendSMS();
  }
}
