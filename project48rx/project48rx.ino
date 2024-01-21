// Project 48 receiver

#define LORAFREQ (915000000L)
#include <SPI.h>
#include <LoRa.h>

void loraSend(int controlCode)
{
  LoRa.beginPacket(); // start sending data
  LoRa.print("DEF"); // "DEF" is our three character code for the transmitter.
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
  if (incoming[0] != 'A')
  {
    return; // if not 'A', stop function and go back to void loop()
  }
  if (incoming[1] != 'B')
  {
    return; // if not 'B', stop function and go back to void loop()
  }
  if (incoming[2] != 'C')
  {
    return; // if not 'C', stop function and go back to void loop()
  }
  // if made it this far, the correct code has been received from transmitter. Now to do something
  if (incoming[3] == '1')
  {
    digitalWrite(7, HIGH);
    loraSend(1); // tell the transmitter that the output has been turned on
  }
  if (incoming[3] == '0')
  {
    digitalWrite(7, LOW);
    loraSend(0); // tell the transmitter that the output has been turned off
  }
}

void setup()
{
  pinMode(7, OUTPUT);
  LoRa.begin(LORAFREQ); // start up LoRa at specified frequency
  LoRa.onReceive(takeAction); // call function "takeAction" when data received over LoRa wireless
  LoRa.receive(); // start receiving
}

void loop()
{
}
