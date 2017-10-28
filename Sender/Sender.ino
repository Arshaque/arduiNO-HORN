// Joystick x- and y- axes are connected to A1 and A0 analog pins of Arduino.
// Servos are connectd to PWM Pins 9 and 10.

//#include <IRremote.h>
#include <Servo.h>


//unsigned int m[] = {1,2,3,4};
//IRsend irsend;
Servo ser; 
int irPin = 3;
int irGnd = 4;
const int buttonPin = 7;
int buttonState = 0; 
int joyX = A1; //  X - axis of Joystick
//int joyY = A0; // y - axis of Joystick
int x=0;//,y=0; 

void setup()
{ 
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(irPin, OUTPUT);
  pinMode(irGnd, OUTPUT);
  ser.attach(9); // servo on PIN 9
} 

void sendIRS(){
  digitalWrite(irPin,HIGH);
   digitalWrite(irGnd,LOW);
   delay(100);
   digitalWrite(irPin,LOW);
}

void loop()
{ 
  x = joyX;    // y value btwn 0 and 1023) 
  x = map(analogRead(joyX), 0, 1024, 90, 1);
  ser.write(x); 
  buttonState = digitalRead(buttonPin);
  //irsend.sendRaw(m,4, 12); 
  Serial.println(x);
  //Serial.println(sw1);
  Serial.println(buttonState);
 if(buttonState == LOW){
   sendIRS();
 }
}
