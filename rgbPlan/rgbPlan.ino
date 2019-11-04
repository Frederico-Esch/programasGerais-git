int num;
int stats = 0;
int red = 0;
int green = 0;
int blue = 0;
int verm = 0;
int verd = 0;
int azul = 0;
const int redPin = 9; 
const int greenPin = 10 ;
const int bluePin = 11;
void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  if (Serial.available() > 0){
    char merdinha = Serial.read();
    if(merdinha == 'r'){
      stats = 1;
      Serial.println("red");
      while(stats == 1){
        delay(100);
        if(Serial.available() > 0){
          num = Serial.parseFloat();
          if(num > 0){
            red = num;
            stats = 0; 
          }
        }
        
      }
    }else if(merdinha == 'b'){
      stats = 1;
      Serial.println("blue");
      while(stats == 1){
        delay(100);
        if(Serial.available() > 0){
          num = Serial.parseFloat();
          if(num > 0){
            blue = num;
            stats = 0;
          }
        }
      }
    }else if(merdinha == 'g'){
      stats =1;
      Serial.println("green");
      while(stats == 1){
        delay(100);
        if(Serial.available() > 0){
          num = Serial.parseFloat();
          if(num > 0){
            green = num;
            stats = 0;
          }
        }
      }
    }else if(merdinha == 'q'){
      red = 0;
      blue = 0;
      green = 0;
      Serial.println("merda");
      colorir(red, green, blue);
    }else if(merdinha == 'c'){
      colorir(red, green, blue);
    }
  }
}
void colorir(int r, int g, int b){
  Serial.println("foi");
  verm = 255 - r;
  verd = 255 - g;
  azul = 255 - b;
  analogWrite(redPin, verm);
  analogWrite(greenPin, verd);
  analogWrite(bluePin, azul);
}
