#include <NewPing.h>
#define pin_trig 8
#define pin_echo 9
#define pin_buzzer 10
bool estado = true;
NewPing sonar(pin_trig, pin_echo, 200);
void setup() {
  pinMode(pin_buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int result = sonar.ping_cm();
  if((result < 80) && (result != 0)){
    estado = !estado;
    digitalWrite(pin_buzzer, estado);
    Serial.println(result);
    delay(2000);
  }
  Serial.println(result);

}
