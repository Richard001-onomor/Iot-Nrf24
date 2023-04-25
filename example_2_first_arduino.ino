    #include <SPI.h>
    #include <nRF24L01.h>
    #include <RF24.h>
    RF24 radio(7, 8); // CE, CSN
    const byte addresses [][6] = {"00001", "00002"};  //Setting the two addresses. One for transmitting and one for receiving
    
    int POT=A0;
    char text[30];
    char text1[30];
   

    int sensorValue ;        // value read from the pot
    int outputValue ;

    // int sensorValue1 ;        // value read from the pot
    // int outputValue1 ;

    
    void setup() {
      pinMode(POT, INPUT);
      Serial.begin(9600);
      radio.begin();                           //Starting the radio communication
      radio.openWritingPipe(addresses[1]);     //Setting the address at which we will send the data
      radio.openReadingPipe(1, addresses[0]);  //Setting the address at which we will receive the data
      radio.setPALevel(RF24_PA_MIN); //You can set it as minimum or maximum depending on the distance between the transmitter and receiver. 
    }
    void loop() 
    {  
      delay(500);
      radio.stopListening();      
      sensorValue = analogRead(POT);
//      outputValue= map(sensorValue, 0, 1023, 0, 255);
      radio.write(&sensorValue, sizeof(sensorValue));  

//      Serial.println(sensorValue);

      radio.startListening();
      delay(500);
      if(radio.available()){
        radio.read(&text, sizeof(text));
        radio.read(&text1, sizeof(text1));
       
        

        
        Serial.print("reply from Red led :");
        Serial.println(text);

        Serial.println("------------------");
        Serial.print("reply from Yellow led :");
        Serial.println(text1);
        
        
      
      
            

   

      }
      }
