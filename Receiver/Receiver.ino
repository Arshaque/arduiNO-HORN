#include<LiquidCrystal.h>  
#include<IRremote.h>

//IR
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

//LCD
int Contrast=80;
int BackLight = 30;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

//Buzzer
int speakerPin = 13;


 void setup()
 { 
    analogWrite(6,Contrast);
     analogWrite(9,BackLight);
     lcd.begin(16, 2);
     Serial.begin(9600);
  irrecv.enableIRIn();
     pinMode(speakerPin,OUTPUT);
  }  
  
  void buzz(){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      digitalWrite(speakerPin, HIGH);
      delay(200);
      digitalWrite(speakerPin,LOW);
      delay(50);
  }
     delay(2000);
  }
  
  
  
  
     void loop()
 { 
     lcd.setCursor(0, 0);
     lcd.print("Have a safe ride!");
     if(irrecv.decode(&results))
    {
      lcd.clear();
      Serial.println(results.value, HEX);
      irrecv.resume();
      lcd.setCursor(0, 0);
     lcd.print("Side Please!");
     buzz();
    }
     delay(300);
}
