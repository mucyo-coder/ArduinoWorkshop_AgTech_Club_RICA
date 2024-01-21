// Project 48 transmitter

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

void takeAction(int packetSize)
// things to do when data received over LoRa wireless
{
  char incoming[4] = "";
  int k, n;
  for (int i = 0; i < packetSize; i++)
  {
    k = i;
    if (k > 6)
    {
      k = 18; //make sure we don't write past end of string
    }
    incoming[k] = (char)LoRa.read();
  }
  // check the three character code sent from transmitter is correct
  if (incoming[0] != 'D')
  {
    return; // if not 'D', stop function and go back to void loop()
  }
  if (incoming[1] != 'E')
  {
    return; // if not 'E', stop function and go back to void loop()
  }
  if (incoming[2] != 'F')
  {
    return; // if not 'F', stop function and go back to void loop()
  }
  // if made it this far, the correct code has been received from transmitter. Now to do something
  if (incoming[3] == '1')
  {
    digitalWrite(6, HIGH);
    // receiver has turned the output on and has sent a signal confirming this
  }
  if (incoming[3] == '0')
  {
    digitalWrite(6, LOW);
    // receiver has turned the output off and has sent a signal confirming this
  }
}

void setup()
{
  pinMode(4, INPUT); // on button
  pinMode(3, INPUT); // off button
  pinMode(6, OUTPUT); // status LED
  LoRa.begin(LORAFREQ); // start up LoRa at specified frequency
  LoRa.onReceive(takeAction); // call function "takeAction" when data received over LoRa wireless
}

void loop()
{
  // check for button presses to control receiver
  if (digitalRead(4) == HIGH)
  {
    loraSend(1); // '1' is code for turn receiver digital pin 7 HIGH
    delay(500); // button debounce
  }
  if (digitalRead(3) == HIGH)
  {
    loraSend(0); // '0' is code for turn receiver digital pin 7 LOW
    delay(500); // button debounce
  }
}
