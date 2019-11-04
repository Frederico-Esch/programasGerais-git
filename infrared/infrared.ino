#include <IRremote.h>
const int RECV_PIN = 2;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
byte sts1 =0;
byte sts2 = 0;
byte sts3 = 0;
IRrecv irrecv(RECV_PIN);
long int cod1 = 2154996824;
long int cod2 = 2154964057;
long int cod3 = 2154996828;
decode_results results;
void setup() {
  irrecv.enableIRIn();
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

}

void loop() {
  if (irrecv.decode(&results)){
    if((results.value == cod1) && (sts1 == 1)){
      digitalWrite(led1, sts1);
      sts1 = 0;
    }
    else if((results.value == cod1) && (sts1 == 0)){
      digitalWrite(led1, sts1);
      sts1 = 1;
    }
    if((results.value == cod2) && (sts2 == 1)){
      digitalWrite(led2, sts2);
      sts2 = 0;
    }
    else if((results.value == cod2) && (sts2 == 0)){
      digitalWrite(led2, sts2);
      sts2 = 1;
    }
    if((results.value == cod3) && (sts3 == 1)){
      digitalWrite(led3, sts3);
      sts3 = 0;
    }
    else if((results.value == cod3) && (sts3 == 0)){
      digitalWrite(led3, sts3);
      sts3 = 1;
    }
    delay(200);
    irrecv.resume();
  }
  delay(10);
  
}
