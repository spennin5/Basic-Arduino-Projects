#include <SoftwareSerial.h>
SoftwareSerial myserial(10, 11); // RX, TX

String voice;
int led5 = 13; //Connect LED 5 To Pin #6 

void setup() {
  Serial.begin(9600);
  myserial.begin(9600);
  pinMode(led5, OUTPUT);
}
  
void loop() {
  while (myserial.available()){  //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable 
    char c = myserial.read(); //Conduct a serial read
    if (c == '#') {
      break;
    } //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
    if(voice == "*on") {
      digitalWrite(led5, HIGH);
    }
    else if(voice == "*off") {
      digitalWrite(led5, LOW);
    }
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
