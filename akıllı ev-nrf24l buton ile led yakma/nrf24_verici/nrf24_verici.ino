//şu anki kodlar buton basılınca sayının sonuna 1
//butona 2. kez basınca 0 olan kodları içerir
#include <nRF24L01p.h>
#include <SPI.h>

#define CE_PIN 9
#define CSN_PIN 10

nRF24L01p transmitter(10,9);

//const uint64_t pipe = 0xE8E8F0F0E1LL;
int sayac = 1;
int mesaj = 0;

//potasiometre
int aci = 98;
//potasiometre


/*verici buton*/
const int buttonPin = 2;//buton
int lambadurum = 0;
/*verici buton*/


void setup()
{
     SPI.begin();
     SPI.setBitOrder(MSBFIRST);
     transmitter.channel(90);
     transmitter.TXaddress("tiny");
     transmitter.init();
     pinMode(buttonPin, INPUT);//buton
}

void loop()
{
  if(digitalRead(buttonPin) == 1)
  {
    if(lambadurum%10 == 1)
      lambadurum = aci * 10;
    else
      lambadurum = aci * 10 + 1;
      delay(24);
  }
    mesaj = lambadurum;


    
     transmitter.txPL(mesaj);
     transmitter.send(FAST);
     delay(100);
     sayac += 2;
}

