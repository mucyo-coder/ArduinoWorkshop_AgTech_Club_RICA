// Project 49 computer-side/transmitter sketch

#define LORAFREQ (915000000L)
#include <SPI.h>
#include <LoRa.h>

char command;

void loraSend(int controlCode)
{
  LoRa.beginPacket(); // start sending data
  LoRa.print("ABC"); // "ABC" is our three character code for the transmitter.
  LoRa.print(controlCode); // send our instructions (controlcode codes)
  LoRa.endPacket(); // finished sending data
  LoRa.receive();   // start listening
}

void takeAction(int packetSize)
// send text received sensor Arduino via LoRa to serial monitor
{
  char incoming[31] = "";
  int k, n;
  for (int i = 0; i < packetSize; i++)
  {
    k = i;
    if (k > 31)
    {
      k = 31; //make sure we don't write past end of string
    }
    incoming[k] = (char)LoRa.read();
    Serial.print(incoming[k]); // display temp information sent from sensor board
  }
  Serial.println();
}

void setup()
{
  LoRa.begin(LORAFREQ); // start up LoRa at specified frequency
  LoRa.onReceive(takeAction); // call function "takeAction" when data received over LoRa wireless
  LoRa.receive(); // start receiving
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Enter 1 for Celsius or 2 for Fahrenheit then Enter: ");
  Serial.flush(); // clear any "junk" out of the serial buffer before waiting
  while (Serial.available() == 0)
  {
    // do nothing until something enters the serial buffer
  }
  while (Serial.available() > 0)
  {
    command = Serial.read() - '0';
    // read the number in the serial buffer,
    // remove the ASCII text offset for zero: '0'
  }
  Serial.println();
  loraSend(command);
  delay(2000);
}
