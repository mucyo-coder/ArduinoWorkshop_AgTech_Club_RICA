// Project 49 sensor-side sketch

#define LORAFREQ (915000000L)
#include <SPI.h>
#include <LoRa.h>

float sensor = 0;
float voltage = 0;
float celsius = 0;
float fahrenheit = 0;

void loraSendC()
{
  LoRa.beginPacket(); // start sending data
  sensor = analogRead(0);
  voltage = ((sensor * 5000) / 1024);
  voltage = voltage - 500;
  celsius = voltage / 10;
  fahrenheit = ((celsius * 1.8) + 32);
  LoRa.print("Temperature: ");
  LoRa.print(celsius, 2);
  LoRa.print(" degrees C");
  LoRa.endPacket(); // finished sending data
  LoRa.receive();   // start listening

}

void loraSendF()
// send temperature in Fahrenheit
{
  LoRa.beginPacket(); // start sending data
  sensor = analogRead(0);
  voltage = ((sensor * 5000) / 1024);
  voltage = voltage - 500;
  celsius = voltage / 10;
  fahrenheit = ((celsius * 1.8) + 32);
  LoRa.print("Temperature: ");
  LoRa.print(fahrenheit, 2);
  LoRa.print(" degrees F");
  LoRa.endPacket(); // finished sending data
  LoRa.receive();   // start listening
}

void takeAction(int packetSize)
// things to do when data received over LoRa wireless
{
  char incoming[6] = "";
  int k, n;
  for (int i = 0; i < packetSize; i++)
  {
    k = i;
    if (k > 6)
    {
      k = 6; //make sure we don't write past end of string
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
    loraSendC();
  }
  if (incoming[3] == '2')
  {
    loraSendF();
  }
}

void setup()
{
  LoRa.begin(LORAFREQ); // start up LoRa at specified frequency
  LoRa.onReceive(takeAction); // call function "takeAction" when data received over LoRa wireless
  LoRa.receive(); // start receiving
}

void loop()
{
}
