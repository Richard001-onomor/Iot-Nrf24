#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int white_led=3;
int potValue;


RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002","00003"}; // Addresses of the receiver boards

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  pinMode(white_led,OUTPUT);
  radio.openWritingPipe(addresses[1]);  
  radio.openReadingPipe(1,addresses[0]); 
      
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_1MBPS);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
 

  radio.startListening();
  radio.read(&potValue , sizeof(potValue));
  Serial.println(potValue);

  if(potValue>=500){
    digitalWrite(white_led,HIGH);
    
    radio.stopListening();
    const char reply [32]="white led is on";
    radio.write(&reply,  sizeof(reply))  ; 
      
  }
     
  else{
    digitalWrite(white_led,LOW);

    radio.stopListening();
    const char reply []="white led is off";
    radio.write(&reply,  sizeof(reply));

       
  }
    
  
   
};

