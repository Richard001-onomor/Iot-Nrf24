#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

int potPin = A0;
int potValue = 0;
char text;
char reply[32];


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.openWritingPipe(address);

  
}

void loop() {
  radio.stopListening();
  potValue = analogRead(potPin);
  delay(1000);

  if(potValue>=0 && potValue<=340){
    text='A';
    
    
    
    }
    else if(potValue>340 && potValue<=680){
      text='B';
     
      }
      else{
        text='C';
       
        }
     radio.write(&text, sizeof(text));

  
  
    
    }

  
