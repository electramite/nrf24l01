#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>  // you need to install these 3 library first                
RF24 radio(7, 8); // CE, CSN pin of nrf connected to 7,8 of arduino
const byte address[6] = "00001"; // this is the tx address
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);// range set to be min
  radio.stopListening();// start transmitting data
}
void loop() {
  int text = analogRead(A0); // reading pot value
  radio.write(&text, sizeof(text));// sending pot value
 delay(50);
}
