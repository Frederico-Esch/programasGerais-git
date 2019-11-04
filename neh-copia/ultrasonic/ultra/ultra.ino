#include <NewPing.h>
#define Trigger 11
#define Eco 12
NewPing sens(Trigger, Eco);
void setup(){
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    
}
void loop(){
    
    int result = sens.ping_cm();
    Serial.println(result);
    if(result >= 150){
        led(3);
    }else if(result>100 && result<150){
        led(2);
    }else if(result<=100 && result>0){
        led(1);
    }
    delay(50);
}
void led(int valor){
    if(valor == 1){
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        digitalWrite(8,HIGH);
    }else if(valor == 2){
        digitalWrite(7,HIGH);
        digitalWrite(6,LOW);
        digitalWrite(8,LOW);
    }else if(valor == 3){
        digitalWrite(7,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(8,LOW);
    }
}