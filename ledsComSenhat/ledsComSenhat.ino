  const int led = 13;
  const int led2 = 8;
  const int button = 12;
  bool looping = true;
  int logi = 0;
void teste(){
  while(looping){
    if(Serial.read() == '1'){
      logi = 1;
      Serial.println("vermelho");
      looping = false;
    }
    else if(Serial.read() == '2'){
      logi = 2;
      Serial.println("verde/amarelo");
      looping = false;
    }
        
    else if(Serial.read() == '3'){
      logi = 3;
      Serial.println("ambos");
      looping = false;
      
    }  
  }
}
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(led, LOW);
}

void loop() {
  delay(1000);
  Serial.println("1-Led vermelho; 2-Led verde/amarelo; 3-ambos Leds; após selecionado aperte 't' para selecionar nova cor");
  looping = true;
  teste();



  
    while(logi==1){
     if(digitalRead(button) == LOW){
       digitalWrite(led, HIGH);
     }
     else{
       digitalWrite(led, LOW);
     }
     if (Serial.read() == 't'){ 
       Serial.println("1-Led vermelho; 2-Led verde/amarelo; 3-ambos Leds;"); 
       looping = true;
       teste();
     }
   }






   while(logi==2){
     if(digitalRead(button) == LOW){
       digitalWrite(led2, HIGH);
     }
     else{
       digitalWrite(led2, LOW);
     }
     if(Serial.read() == 't'){
       Serial.println("1-Led vermelho; 2-Led verde/amarelo; 3-ambos Leds;");
       looping = true;
       teste();
     }
   }

  







  

   while(logi==3){
     if(digitalRead(button) == LOW){
       digitalWrite(led, HIGH);
       digitalWrite(led2, HIGH);
     }
     else{
       digitalWrite(led, LOW);
       digitalWrite(led2, LOW);
     }
     if(Serial.read() == 't'){
       Serial.println("1-Led vermelho; 2-Led verde/amarelo; 3-ambos Leds;");  
       looping = true;
       teste();
     }
   }


}
