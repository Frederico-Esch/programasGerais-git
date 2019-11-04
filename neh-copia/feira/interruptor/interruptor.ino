#include <NewPing.h>
#define Trig 12
#define Eco 11
#define led 10
#define inter 9
NewPing sens(Trig, Eco, 100);
int result;
int before_inter;
void setup(){
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(inter, INPUT_PULLUP);
    before_inter = digitalRead(inter);
}
void loop(){
    result = sens.ping_cm();
    if(digitalRead(inter) != before_inter){
        digitalWrite(led, HIGH);
    }else{
        digitalWrite(led, LOW);
    }
    Serial.println(result);
    if(result < 200 && result>0){
        before_inter = digitalRead(inter);
    }
    
}
