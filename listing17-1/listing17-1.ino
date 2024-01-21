// Listing 17-1
int receiverpin = 2; // pin 1 of IR receiver to Arduino digital pin 2
#include <IRremote.h> // use the library
IRrecv irrecv(receiverpin); // create instance of irrecv
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // start the IR receiver
}
void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.print(results.value, HEX); // display IR code on the Serial Monitor
    Serial.print(" ");
    irrecv.resume(); // receive the next value
  }
}
