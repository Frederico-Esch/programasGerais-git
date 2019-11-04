#define motor 9
void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);

}

void loop() {
  if(Serial.available() > 0){
    int velo = Serial.parseInt();
    if(velo > 0 && velo < 900){
      analogWrite(motor, velo);
    }else if(velo == 1000){
      analogWrite(motor, 0);
    }
  }
  delay(100);
}
