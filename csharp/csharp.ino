const int led = 12;
char cs;
int stats = 0;
int csi = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

void loop() {
  if (Serial.available() > 0){
    cs = Serial.read();
    if(cs == 'a'){
      if(stats == 0){
        digitalWrite(led, HIGH);
        stats = 1;
        Serial.println("ligado");

      }else if(stats == 1){
        digitalWrite(led, LOW);
        stats = 0;
        Serial.println("desligado");

      }
    }else {
      csi = cs - '0';
    }
  }
  if (csi > 0){
    for(int i = 0; i < csi; i++){
      delay(1000);  
    }
    digitalWrite(led, HIGH);
    for(int o = 0; o < csi; o++){
      delay(1000);
    }
    digitalWrite(led, LOW);
    stats = 0;
  }

}
