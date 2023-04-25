#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte addresses [][6] = {"00001", "00002"};    //Setting the two addresses. One for transmitting and one for receiving

    int red_led = 3;
    int yellow_led=4;

    int sensorValue;


void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  Serial.begin(9600);
  radio.begin();                            //Starting the radio communication
  radio.openWritingPipe(addresses[0]);      //Setting the address at which we will send the data
  radio.openReadingPipe(1, addresses[1]);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);            //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
}

void loop() 
{
  delay(500);
    radio.startListening();
    radio.read(&sensorValue, sizeof(sensorValue));
    Serial.print("\n sensor = ");
    Serial.print(sensorValue);

    delay(500);     
    if(sensorValue <= 500){
      digitalWrite(red_led, HIGH);

      radio.stopListening();
      const char text[] = "Red Light is On";
      radio.write(&text, sizeof(text));
      
     
    }
    else{
      digitalWrite(red_led,LOW);
      const char text[] = " Red Light is off";
      radio.write(&text, sizeof(text));
      
    }

      if(sensorValue >= 500){
      digitalWrite(yellow_led, HIGH);

       radio.stopListening();
      const char text1[] = "Yellow Light is On";
      radio.write(&text1, sizeof(text1));
      
     
    }
    else{
      digitalWrite(yellow_led,LOW);

      radio.stopListening();
      const char text1[] = "Yellow Light is off";
      radio.write(&text1, sizeof(text1));
      
      
    }

    
   
 


  


}
