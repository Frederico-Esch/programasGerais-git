int motorPin = 10;
int leit;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  if(Serial.available() > 1){
    leit = Serial.parseInt();
    analogWrite(motorPin, leit);
    if(leit == 0){
      Serial.println("motor parado");
    }else{
      Serial.print("velocidade setada para: ");
      Serial.println(leit);
    }
  }

}
