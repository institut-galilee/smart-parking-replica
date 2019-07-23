
// include the library code:
#include <LiquidCrystal.h>
#include "SR04.h"
#define TRIG_PIN 2
#define ECHO_PIN 3
#define TRIG_PINN 0
#define ECHO_PINN 1
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
SR04 sr = SR04(ECHO_PINN,TRIG_PINN);
long d,d2;

int pinLed1 = 5;

int pinLed2 = 4;
int pinLed11 = 6;

int pinLed22 = 13;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);
 int place=2;
 boolean ocupe=false;
 boolean ocupe2=false;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
   pinMode(pinLed1, OUTPUT);
   pinMode(pinLed2, OUTPUT);
     pinMode(pinLed11, OUTPUT);
   pinMode(pinLed22, OUTPUT);
      digitalWrite(pinLed2, HIGH);
      digitalWrite(pinLed22, HIGH);

}

void loop() {
  d=sr04.Distance();
  d2=sr.Distance();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
 lcd.print("Plc libre: ");
  //lcd.setCursor(1, 2);
  lcd.print(place);
  if(d<5 and ocupe==false){
    ocupe=true;
    place--;
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, LOW);

  }else if(d>=5){
    
    if(place<2 and ocupe==true){
      ocupe=false;
      place++;
      digitalWrite(pinLed1, LOW);
      digitalWrite(pinLed2, HIGH);


  }  
    }
      if(d2<5 and ocupe2==false){
    ocupe2=true;
    place--;
    digitalWrite(pinLed11, HIGH);
    digitalWrite(pinLed22, LOW);

  }else if(d2>=5){
    
    if(place<2 and ocupe2==true){
      ocupe2=false;
      place++;
      digitalWrite(pinLed11, LOW);
      digitalWrite(pinLed22, HIGH);
  }  
    }
    
  // print the number of seconds since reset:
  
}

