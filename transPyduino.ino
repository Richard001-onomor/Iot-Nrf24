# include <SPI.h>
# include <nRF24L01.h>
# include <RF24.h>

RF24 radio(7,8);

const byte address[6] = "00001";

char incomingData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel (RF24_PA_MIN);

}
unsigned long previousMillis = 0;
const long interval = 1000;

void loop() {
  // put your main code here, to run repeatedly:
 unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
  radio.stopListening();
  if(Serial.available()>0){
    incomingData = Serial.read();
  radio.write(&incomingData, sizeof(incomingData));
  }
  Serial.println(incomingData);
  }

}
