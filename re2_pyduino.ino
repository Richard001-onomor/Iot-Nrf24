# include <SPI.h>
# include <nRF24L01.h>
# include <RF24.h>

int white_led=5;
char incomingData;

RF24 radio(7,8);

const byte address[6] = "00001";
void setup() {
  // put your setup code here, to run once:
  
  pinMode(white_led,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel (RF24_PA_MIN);


}
unsigned long previousMillis = 0;
const long interval = 1000;


void loop() {
  // put your main code here, to run repeatedly:
   unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
  radio.startListening();
  radio.read(&incomingData, sizeof(incomingData));

 

       if(incomingData == 'J'){
      digitalWrite(white_led,HIGH);
      }
       if(incomingData == 'K'){
      digitalWrite(white_led,LOW);
      }

      if(incomingData == 'W'){
      digitalWrite(white_led,HIGH);
      }
      if(incomingData == 'P'){
      digitalWrite(white_led,LOW);
      }

       if(incomingData == 'L'){
      analogWrite(white_led,45);
      }
      if(incomingData == 'U'){
      analogWrite(white_led,LOW);
      }

       if(incomingData == 'M'){
      analogWrite(white_led,150);
      }
      if(incomingData == 'Q'){
      analogWrite(white_led,LOW);
      }
    

  Serial.println(incomingData);
  }
}
