byte dig[12][8] = {
  {0,0,0,0,0,0,1,1},
  {1,0,0,1,1,1,1,1},
  {0,0,1,0,0,1,0,1},
  {0,0,0,0,1,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,1,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,0,0,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,1,1,0,0,1},
  {0,0,0,1,0,0,0,1},
  {1,1,1,1,1,1,1,0}
};
void setup() {
  for(int contador = 2; contador< 10; contador++){
    pinMode(contador, OUTPUT);
  }
  for(int i = 2; i < 10; i++){
    digitalWrite(i, LOW);
  }

}

void loop() {
  for(byte a = 0; a < 12; a++){
    ligadis(a);
    delay(500);
  }
  delay(2000);
}
void ligadis(byte matriz){
  int pino = 2;
  for(byte digits = 0; digits < 8; digits++){
    digitalWrite(pino, dig[matriz][digits]);
    pino++;
  }
}
