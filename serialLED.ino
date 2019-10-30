/*
  serialLED
  Toggle a built-in LED by serial port with commands ON, OFF.
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
        if(command == "ON"||command == "on"){
            digitalWrite(ledPin, HIGH);
            Serial.println("LED ON");
        } else {
            if(command == "OFF"||command == "off"){
                digitalWrite(ledPin, LOW);
                Serial.println("LED OFF");
            }else
            {
                Serial.println("UNKNOWN COMMAND");
            }    
        }
        command = "";
    }
    delay(100);            
}
