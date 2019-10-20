/*
  Blink
  Turns an LED on for two second, then off for two second, repeatedly.
*/

//Constants 
const int ledPin =  LED_BUILTIN;

String command = "";

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);


}

// the loop function runs over and over again forever
void loop() {
    while (Serial.available()) {
        command = Serial.readString();
    }

    if(command != ""){
        if(command == "ON"){
            digitalWrite(ledPin, HIGH);
            Serial.println("LED ON");
        } else {
            if(command == "OFF"){
                digitalWrite(ledPin, LOW);
                Serial.println("LED OFF");
            }else
            {
                Serial.println("UNKNOW COMMAND");
            }

            
        }
        command = "";
    }
      
      delay(100);            
}
