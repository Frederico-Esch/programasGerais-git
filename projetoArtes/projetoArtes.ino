#define button 12
#define red 9
#define green 10
#define blue 11
int state = 0;
void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
}

void loop() {
  if(state == 0){
    colorir(255, 255, 255);
  }else if(state == 1){
    colorir(0, 255, 255);
  }else if(state == 2){
    colorir(255, 0, 255);
  }else if(state == 3){
    colorir(255, 255, 0);
  }else if(state == 4){
    colorir(0, 0, 255);
  }else if(state == 5){
    colorir(0, 255, 0);
  }else if(state == 6){
    colorir(255, 0, 0);
  }else if(state == 7){
    colorir(0, 0, 0);
  }
  if(digitalRead(button) == 0){
    state ++;
    if(state > 7){
      state = 0;
    }
    delay(100);
  }
  delay(100);
}
void colorir(int verm, int verd, int azul){
  analogWrite(red, verm);
  analogWrite(green, verd);
  analogWrite(blue, azul);
  delay(10);
}
