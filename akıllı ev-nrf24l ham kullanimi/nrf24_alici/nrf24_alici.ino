#include <SPI.h>
#include <nRF24L01p.h>

String message;

nRF24L01p receiver(10,9);

void setup()
{
     delay(150);
     SPI.begin();
     SPI.setBitOrder(MSBFIRST);
     receiver.channel(90);
     receiver.RXaddress("tiny");
     receiver.init();
     Serial.begin(9600);
}

void loop()
{
     if (receiver.available())
     {
          receiver.read();
          receiver.rxPL(message);
          if(message != "")
          {
               Serial.println(message);
               message = "";
          }
          delay(100);
     }
 }


 
