// Project 61 - Arduino and twitter

#include <SPI.h> 
#include <Ethernet.h>
#include <Twitter.h>

// Ethernet Shield Settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,1); // Replace this with your project's IP address

Twitter twitter("insertyourtokenhere");

// Message to post
char msg[] = "I'm alive!";

void setup()
{
  delay(1000);
}

void loop()
{
    Ethernet.begin(mac, ip);
  // or you can use DHCP for autoomatic IP address configuration.
  // Ethernet.begin(mac);
  Serial.begin(9600);
  
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
      int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
  do {} while (1);
}
