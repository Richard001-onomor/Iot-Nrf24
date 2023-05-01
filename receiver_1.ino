#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

int ledPin = 3;
int potValue = 0;
char text;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, address);
  radio.startListening();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (radio.available()) {
    radio.read(&text, sizeof(text));

  Serial.println(text);

  if(text=='A'){
    analogWrite(ledPin,15);

 
    
    
    }else if(text=='B'){
      analogWrite(ledPin,110);

    
      }else{
        analogWrite(ledPin,255);

       
     
        }

    
  }

  
}
