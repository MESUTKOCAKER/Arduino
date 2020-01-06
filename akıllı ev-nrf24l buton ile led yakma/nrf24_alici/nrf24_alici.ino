//şu anki kodlar buton basılınca sayının sonuna 1
//butona 2. kez basınca 0 olan kodları içerir
#include <SPI.h>
#include <nRF24L01p.h>

int message;

nRF24L01p receiver(10,9);


int led = 7;
void setup()
{
     delay(150);
     SPI.begin();
     SPI.setBitOrder(MSBFIRST);
     receiver.channel(90);
     receiver.RXaddress("tiny");
     receiver.init();
     Serial.begin(9600);
     pinMode(led, OUTPUT);
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
               int ledDurum = (int)message;
               ledDurum = ledDurum %10;
               digitalWrite(led, ledDurum);
               message = "";
          }
          delay(100);
     }
 }


 
