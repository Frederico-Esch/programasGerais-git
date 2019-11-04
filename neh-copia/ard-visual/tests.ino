#define led0 A0
#define led2 A1
#define led4 A2
#define led8 A3
#define but0 13
#define but2 12
#define but4 11
#define but8 10
#define tempo 500

bool zero = false;
bool dois = false;
bool quatro = false;
bool oito = false;
//descrição dos segmentos {false} para ligado e {true} para desligado já que é catodo comum
bool segments[16][7] = {
    {false,false,false,false,false,false,true}, // 0
    {true,false,false,true,true,true,true},// 1
    {false,false,true,false,false,true,false},// 2
    {false,false,false,false,true,true,false},// 3
    {true,false,false,true,true,false,false},// 4
    {false,true,false,false,true,false,false},// 5
    {false,true,false,false,false,false,false},// 6
    {false,false,false,true,true,true,true},// 7
    {false,false,false,false,false,false,false},// 8
    {false,false,false,false,true,false,false},// 9
    {false,false,false,true,false,false,false},// 10
    {true,true,false,false,false,false,false},// 11
    {false,true,true,false,false,false,true},// 12
    {true,false,false,false,false,true,false},// 13
    {false,true,true,false,false,false,false},// 14
    {false,true,true,true,false,false,false}}; // 15

void setup(){
    //Serial.begin(9600);
    for (int i = 13; i> 3; i--){
        pinMode(i, INPUT_PULLUP);
    }
    for(int i = 3; i < 10; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(led0, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led8, OUTPUT);
}
void loop(){
    if(digitalRead(but0) == 0){
        zero = !zero;
        delay(tempo);
    }else if(digitalRead(but2) == 0){
        dois = !dois;
        delay(tempo);
    }else if(digitalRead(but4) == 0){
        quatro = !quatro;
        delay(tempo);
    }else if(digitalRead(but8) == 0){
        oito = !oito;
        delay(tempo);
    }
    digitalWrite(led0,zero);
    digitalWrite(led2,dois);
    digitalWrite(led4,quatro);
    digitalWrite(led8,oito);
    serialWrite();
    delay(10);
}

void serialWrite(){
    int pri = 0;
    int seg = 0; 
    int ter = 0;
    int qua = 0;
    int final = 0;
    pri = zero;
    if(dois){
        seg = 2;
    }
    if(quatro){
        ter = 4;
    }
    if(oito){
        qua = 8;
    }
    final = pri + seg + ter + qua;
    displaySeg(final);
    delay(100);
}

void displaySeg(int num){
    for(int i = 0; i < 7; i++){
        digitalWrite(i+3,segments[num][i]);
    }
}