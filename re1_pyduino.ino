# include <SPI.h>
# include <nRF24L01.h>
# include <RF24.h>

int red_led=3;

char incomingData;

RF24 radio(7,8);

const byte address[6] = "00001";
void setup() {
  // put your setup code here, to run once:
  pinMode(red_led,OUTPUT);
 
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

  if(incomingData == 'H'){
      digitalWrite(red_led,HIGH);
      }
       if(incomingData == 'I'){
      digitalWrite(red_led,LOW);
      }
      

      
    

  Serial.println(incomingData);
  }
}
