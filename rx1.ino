#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
Servo sv;

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001"; // rcvr address
void setup() {
  Serial.begin(9600);
  sv.attach(5);// servo attach at pin 5
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN); // range set to be min
  radio.startListening();// start receiving data
}
void loop() {
  if (radio.available()) {
    int text = 0;
    radio.read(&text, sizeof(text)); // storing data 
    text = map(text,0,1023,0,180); // map these values b/w 0 to 180 degree
    sv.write(text); // servo writing the position 
    Serial.println(text);
  }
}
