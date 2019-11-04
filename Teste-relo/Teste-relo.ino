const int bth = 10;
const int bte = 11;
const int led = 12;
byte hor = 6;
const byte dig[12][8] = {
  {0, 1, 0, 0, 0, 0, 0, 1}, //6
  {0,0,0,1,1,1,1,1}, //7
  {0,0,0,0,0,0,0,1}, //8
  {0,0,0,1,1,0,0,1}, //9
  {0,0,0,1,0,0,0,1}, //A
  {1,0,0,1,0,0,1,1}, //1 1
  {0,0,1,0,0,1,0,1}, //2
  {1,0,0,1,1,1,1,0}, //1.
  {0,0,1,0,0,1,0,0}, //2.
  {0,0,0,0,1,1,0,0}, //3.
  {1,0,0,1,1,0,0,0}, //4.
  {0,1,0,0,1,0,0,0} //5.
};
int count = 0;
void setup() {
  pinMode(bth, INPUT_PULLUP);
  pinMode(bte, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  for(int o = 3; o < 10; o++){
    pinMode(o, OUTPUT);
    digitalWrite(o, LOW);
  }
  Serial.begin(9600);
}

void loop() {
  Serial.println("Main loop");
  atualiza(hor);
  if(digitalRead(bth) == 0){
    Serial.println("left button");
    hor++;
    if(hor < 18){
      atualiza(hor);
    }else{
      hor = 6;
    }
    delay(100);
  }
  if(digitalRead(bte) == 0){
    count = 18 - hor;
    count = count * 1000;
    for(int i = 2; i < 10; i++){
      digitalWrite(i, HIGH);  
    }
    delay(count);
    digitalWrite(led, HIGH);

  }
  delay(10);
}
void atualiza(byte matriz){
  int pin = 2;
  Serial.println("atualiza");
  matriz = matriz - 6;
  for(byte p = 0; p < 8; p++){
    digitalWrite(pin, dig[matriz][p]);
    pin++;
    Serial.println(dig[matriz][p]);
    delay(100);
  }
  delay(10);
}
