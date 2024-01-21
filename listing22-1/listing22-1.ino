// Listing 22-1 - testing 3G shield

#include <SoftwareSerial.h> // Virtual serial port
SoftwareSerial cell(2,3);
char incoming_char = 0;
void setup()
{
  //Initialize serial ports for communication.
  Serial.begin(9600);
  cell.begin(4800);
  Serial.println("Starting SIM5320 communication...");
}
void loop()
{
  // If a character comes in from 3G shield
  if( cell.available() > 0 )
  {
    // Get the character from the cellular serial port.
    incoming_char = cell.read();
    // Print the incoming character to the Serial monitor.
    Serial.print(incoming_char);
  }
  // If a character is coming from the terminal to the Arduino...
  if( Serial.available() > 0 )
  {
    incoming_char = Serial.read(); //Get the character coming from the terminal
    cell.print(incoming_char); //Send the character to the cellular module.
  }
}
