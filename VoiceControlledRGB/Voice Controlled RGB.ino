#include <SoftwareSerial.h>
SoftwareSerial myserial(10,11); //RX, TX

String voice;
int red = 6;
int green = 5;
int blue = 3;
#define COMMON_ANODE
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);
}

void loop() {

  // put your main code here, to run repeatedly:
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
      if(voice=="*blue"){
        setColor(255,0,0);
      }
      else if(voice=="*red"){
        setColor(0,255,0);
      }
      else if(voice=="*green"){
        setColor(0,0,255);
      }
      else if(voice=="*strobe"){
        for (int i=0;i<10;i++){
          digitalWrite(red,LOW);
          digitalWrite(blue,LOW);
          digitalWrite(green,LOW);
          delay(100);
          digitalWrite(red,HIGH);
          digitalWrite(blue,HIGH);
          digitalWrite(green,HIGH);
          delay(100);
        }
      }
      else if(voice=="*random"){
        int rr = random(255);
        int rb = random(255);
        int rg = random(255);
        setColor(rr,rg,rb);
      }
      else if(voice=="*off"){
        digitalWrite(red,HIGH);
        digitalWrite(blue,HIGH);
        digitalWrite(green,HIGH);
      }
      voice="";
    } 
}

void setColor(int blueI, int redI, int greenI){
  #ifdef COMMON_ANODE
    redI = 255 - redI;
    greenI = 255 - greenI;
    blueI = 255 - blueI;
  #endif
  analogWrite(red, redI);
  analogWrite(green, greenI);
  analogWrite(blue, blueI); 
}
