const int pinoR = 9;
const int pinoG = 10;
const int pinoB = 11;
bool looping = true;
void setup() {
  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);
  Serial.begin(9600);
  Serial.println("b-azul/r-vermelho/g-verde/c-ciano/a-amarelo/v-verde-musgo");
}

void loop() {
  teste();
  if(Serial.read() == 't'){
    looping = true;
    Serial.println("b-azul/r-vermelho/g-verde/c-ciano/a-amarelo/v-verde-musgo");
  }

}
void teste(){
  while(looping){
    if(Serial.read() == 'b'){
      colorp(0, 0, 255);
      looping = false;
    }
    else if(Serial.read() == 'r'){
      colorp(255, 0, 0);
      looping = false;
    }
    else if(Serial.read() == 'g'){
      colorp(0 , 255, 0);
      looping = false;
    }
    else if(Serial.read() == 'v'){
      colorp(255, 255, 0);
      looping = false;
    }
    else if(Serial.read() == 'c'){
      colorp(0, 80, 80);
      looping = false;
    }
    else if(Serial.read() == 'a'){
      colorp(200, 89, 0);
      looping = false;
    }
  }
}
void colorp(int red, int green, int blue){
  red = 255-red;
  green = 255-green;
  blue = 255-blue;
  analogWrite(pinoR, red);
  analogWrite(pinoG, green);
  analogWrite(pinoB, blue);
}
