const int pinoPot = A5; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
int leituraA5; //VARIÁVEL QUE ARMAZENA O VALOR LIDO NO PINO ANALÓGICO
const int led = 13;
const int led2 = 12;
const int led3 = 8;
  
void setup(){  
  pinMode(pinoPot, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  Serial.begin(9600); //INICIALIZA A SERIAL
}    
void loop(){  
  leituraA5 = analogRead(pinoPot); //LÊ O VALOR NO PINO ANALÓGICO (VALOR LIDO EM BITS QUE VAI DE 0 A 1023)
  Serial.print(leituraA5); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(" bits"); //IMPRIME NO MONITOR SERIAL O VALOR LIDO
  if (leituraA5 >1000){
    digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if( (leituraA5 <1000) && (leituraA5 > 500)){
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else if (leituraA5<500){
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  delay(100); //INTERVALO DE 100ms
}
