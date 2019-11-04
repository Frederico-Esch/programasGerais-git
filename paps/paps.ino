#include <NewPing.h>
#define pinled 12
#define pinbuz 10
#define trig 8
#define echo 6
NewPing sensor(trig, echo, 200);
int batata;
void setup() {
  Serial.begin(9600);
  pinMode(pinled, OUTPUT);
  pinMode(pinbuz, OUTPUT);

}

void loop() {
  batata = sensor.ping_cm();
  if((batata < 50) && (batata > 0)) ligar(1);
  else if((batata < 100) && (batata > 0)) ligar(2);
  else ligar(0);
  Serial.print(200);
  Serial.print(" ");
  Serial.print(0);
  Serial.print(" ");
  Serial.print(100);
  Serial.print(" ");
  Serial.print(50);
  Serial.print(" ");
  Serial.println(batata);
  delay(20);

}
void ligar(int valor){
  if(valor == 1){
    digitalWrite(pinled, HIGH);
    digitalWrite(pinbuz, HIGH);
    delay(sensor.ping_cm()*2);
    digitalWrite(pinbuz, LOW);
    delay(sensor.ping_cm()*2);
    digitalWrite(pinbuz, HIGH);
  }
  else if(valor == 2){
    digitalWrite(pinled, HIGH);
    digitalWrite(pinbuz, LOW);
  }
  else{
    digitalWrite(pinled, LOW);
    digitalWrite(pinbuz, LOW);
  }
}
