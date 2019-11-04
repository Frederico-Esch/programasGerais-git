#include <Servo.h>
#define serv 10
//#define test1 9
//#define test2 8
//#define test3 7
Servo servo;
int value;
void setup() {
  Serial.begin(9600);
  servo.attach(serv);
  servo.write(0);
//  pinMode(test1, OUTPUT);
//  pinMode(test2, OUTPUT);
//  pinMode(test3, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
      value = Serial.read();
      Serial.println(value);
      if(value == 1){
        servo.write(0);
      }else if(value == 45){
        servo.write(45);  
      }else if(value == 90){
        servo.write(90);
      }else if(value == 135){
        servo.write(135);
      }else if(value == 180){
        servo.write(180);
      }
      
      //servo.write(value);
    }
}
