#include <nRF24L01p.h>
#include <SPI.h>

#define CE_PIN 9
#define CSN_PIN 10

nRF24L01p transmitter(10,9);

//const uint64_t pipe = 0xE8E8F0F0E1LL;
int sayac = 1;
String mesaj = "AkilliEv";

void setup()
{
     SPI.begin();
     SPI.setBitOrder(MSBFIRST);
     transmitter.channel(90);
     transmitter.TXaddress("tiny");
     transmitter.init();
}

void loop()
{
     transmitter.txPL(mesaj + (sayac));
     transmitter.send(FAST);
     delay(500);
     sayac += 2;
}

