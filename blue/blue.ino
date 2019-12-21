#include <SoftwareSerial.h>
#define led 6
SoftwareSerial series(2,3); //RX - TX
void setup(){
  pinMode(led, OUTPUT);
  series.begin(9600);
  Serial.begin(9600);
}
void loop(){
 if(series.available() > 0){
  char msg = series.read();
  if(msg == 'a'){
    digitalWrite(led, HIGH);
  }else if(msg == 'b'){
    digitalWrite(led, LOW);
  }
  series.println(msg);
  delay(100);
 }
}
