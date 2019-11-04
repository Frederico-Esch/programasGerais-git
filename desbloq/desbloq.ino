#define bu1 3 
#define bu2 4 
#define bu3 5 
#define bu4 6 
#define bu5 7 
#define bu6 8 
#define red 9
#define gre 10
#define blu 11
int but1 = bu1;
int but2 = bu2;
int but3 = bu3;
int but4 = bu4;
int but5 = bu5;
int but6 = bu6;
int flag = 0;
int pressed = 0;
void setup() {
  pinMode(bu1, INPUT_PULLUP);
  pinMode(bu2, INPUT_PULLUP);
  pinMode(bu3, INPUT_PULLUP);
  pinMode(bu4, INPUT_PULLUP);
  pinMode(bu5, INPUT_PULLUP);
  pinMode(bu6, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(gre, HIGH);
  delay(100);
  digitalWrite(blu, HIGH);
  delay(100);
  writing();
}

void loop() {
  reading();
}
void reading(){
  digitalWrite(red, LOW);
  digitalWrite(gre, LOW);
  digitalWrite(blu, HIGH);
  if(flag == 0){
    if(digitalRead(but1) == 0){
      grelight(500);
      flag = 1;
    }else if(digitalRead(but3) == 0 || digitalRead(but2) == 0 || digitalRead(but4) == 0 || digitalRead(but5) == 0 || digitalRead(but6) == 0 ){
      redlight(500);
      flag = 0;
    }
  }else if(flag == 1){
    if(digitalRead(but2) == 0){
      grelight(500);
      flag=2;
    }else if(digitalRead(but1) == 0 || digitalRead(but5) == 0 || digitalRead(but4) == 0 || digitalRead(but3) == 0 || digitalRead(but6) == 0 ){
      redlight(500);
      flag =0;
    }
  }else if(flag==2){
    if(digitalRead(but3) == 0){
      grelight(500);
      flag=3;
    }else if(digitalRead(but1) == 0 || digitalRead(but2) == 0 || digitalRead(but4) == 0 || digitalRead(but5) == 0 || digitalRead(but6) == 0 ){
      redlight(500);
      flag=0;
    }
  }
  else if(flag == 3){
    desbloqueaste(); 
  }
}
void redlight(int dt){
  digitalWrite(red, HIGH);
  digitalWrite(gre, LOW);
  digitalWrite(blu, LOW);
  delay(dt); 
}
void grelight(int dt1){
  digitalWrite(red, LOW);
  digitalWrite(gre, HIGH);
  digitalWrite(blu, LOW);
  delay(dt1);
  
}
void blulight(int dt2){
  digitalWrite(red, LOW);
  digitalWrite(gre, LOW);
  digitalWrite(blu, HIGH);
  delay(dt2);
}
void desbloqueaste(){
  bool dmc = true;
  while(dmc){
    grelight(1);
    if(digitalRead(but1) == 0 || digitalRead(but2) == 0 || digitalRead(but4) == 0 || digitalRead(but5) == 0 || digitalRead(but6) == 0 || digitalRead(but3) == 0){
      flag = 0;
      dmc =false;
    }
  }
}

void writing(){
  int stage= 1;
  bool regis = true;
  but1 = 0;
  but2 = 0;
  but3 = 0;
  but4 = 0;
  but5 =0 ;
  but6=0;
  while(regis){
    redlight(1);
    if(stage == 1){
      for(int i = 3; i < 9; i++){
        if(digitalRead(i) == 0){
          but1 = i;
          stage = 2;
          grelight(500);
        }
      }
    }else if(stage == 2){
      for(int i = 3; i < 9; i++){
        if(digitalRead(i) == 0 && but1 != i){
          but2 = i;
          stage = 3;
          grelight(500);
        }else if(digitalRead(i) == 0 && but1 == i){
          blulight(500);
        }
      }
    }else if(stage == 3){
      for(int i = 3; i < 9; i++){
        if(digitalRead(i) == 0 && but1 != i && but2 != i){
          but3 = i;
          stage = 4;
          grelight(500);
        }else if(digitalRead(i) == 0){
          blulight(500);
        }
      }
    }else if(stage == 4){
      for(int i = 3; i < 9; i++){
        if(i != but1 && i != but2 && i != but3 && but4 == 0){
          but4 = i; 
        }else if(i != but1 && i != but2 && i != but3 && but5 == 0){
          but5 = i;
        }else if(i != but1 && i != but2 && i != but3 && but6 == 0){
          but6 = i;
        }else{
          stage = 0;
        }
      }
    }else if(stage == 0){
      regis = false;
    }
  }
}
