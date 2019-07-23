
/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include "Keypad.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos; 
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  myservo.attach(12); 
}
int i=0; 
char  pass[5]; 
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
   
    if(i<=3){
      pass[i] = customKey;
      Serial.println(pass);
      }
     i++;
     if(i==4){
        pass[4]='\0';
        if(pass[0]=='1' and pass[1]=='2' and pass[2]=='3' and pass[3]=='4'){
          Serial.println("code accepter");
            for (pos = 30; pos <= 120; pos +=10 ) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  delay(3000);
  for (pos = 120; pos >= 30; pos-= 10) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
}
      }else{
        Serial.println("code eroné");
      }
      i=0;
    }
  }
}
