#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int red_led=3;
int potValue;


RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002","00003"}; // Addresses of the receiver boards

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  pinMode(red_led,OUTPUT);
  radio.openWritingPipe(addresses[2]);  
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

  if(potValue<=500){
    digitalWrite(red_led,HIGH);
    
       
    
  }
  else{
    digitalWrite(red_led,LOW);

   
  }
  
   
};

