// Project 47 transmitter

#define LORAFREQ (915000000L)
#include <SPI.h>
#include <LoRa.h>

void loraSend(int controlCode)
{
  LoRa.beginPacket(); // start sending data
  LoRa.print("ABC"); // "ABC" is our three character code for the receiver. Needs to be matched on RX
  LoRa.print(controlCode); // send our instructions (controlcode codes)
  LoRa.endPacket(); // finished sending data
  LoRa.receive();   // start listening
}

void setup()
{
  pinMode(4, INPUT); // on button
  pinMode(3, INPUT); // off button
  LoRa.begin(LORAFREQ); // start up LoRa at specified frequency
}

void loop()
{
  // check for button presses to control receiver
  if (digitalRead(4) == HIGH)
  {
    loraSend(1); // '1' is code for turn receiver digital pin 5 HIGH
    delay(500); // allow time to send
  }
  if (digitalRead(3) == HIGH)
  {
    loraSend(0); // '0' is code for turn receiver digital pin 5 LOW
    delay(500); // allow time to send
  }
}
