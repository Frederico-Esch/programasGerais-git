#define pino 8
int veri = 1;
void setup() {
  Serial.begin(9600);
  pinMode(pino, OUTPUT);
  digitalWrite(pino, HIGH);
}

void loop() {
  if(Serial.available() > 0){
    if(Serial.read() == 1){
      ligar();
    }
  }
}
void ligar(){
  if(veri == 1){
    digitalWrite(pino, LOW);
    veri = 0;
  }else{
    digitalWrite(pino, HIGH);
    veri = 1;
  }
}
