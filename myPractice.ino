#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int pot=A0;
int potValue;


RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002","00003"}; // Addresses of the receiver boards

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  pinMode(pot,INPUT);
  radio.openWritingPipe(addresses[0]);  
  radio.openReadingPipe(1,addresses[1]); 
  radio.openReadingPipe(1,addresses[2]);
      
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_1MBPS);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  potValue=analogRead(pot);
  Serial.println(potValue);

  radio.stopListening();
  radio.write(&potValue , sizeof(potValue));

 



  

       
};
