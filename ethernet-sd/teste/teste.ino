#include<Ethernet.h>
#include<SD.h>

//imagereq
//mainreq
//getURL

byte mac[] =  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,77);
EthernetServer server(80);
char HTTP_req[50];
int i = 0;
File webFile;

void setup(){
    Ethernet.begin(mac, ip);
    server.begin();
    Serial.begin(9600);

    //cartão
    Serial.println("CARTÂO");
    SD.begin(4);
    if(!SD.begin(4)){
        Serial.println("ERRO");
    }
    if(!SD.exists("index.htm")){
        Serial.println("index não existe");
    }
}

void loop(){
    EthernetClient client = server.available();

    if(client){ //alguem conectou
        boolean currentLineIsBlank = true;
        while(client.connected()){ //ta conectado
            if(client.available()){ //pode receber
                char c = client.read();
                if (i < 20){
                  HTTP_req[i] = c;
                  i++;
                }
                
                if(c == '\n' && currentLineIsBlank){
                    if(strEx(HTTP_req, "GET / ")){
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        //client.println("Connection: keep-alive");
                        client.println();
                        webFile = SD.open("index.htm");
                        //client.write(HTTP_req);
                    }
                    if(strEx(HTTP_req, "GET /ligado.jpg")){
                      client.println("HTTP/1.1 200 OK");
                      client.println();
                      webFile = SD.open("ligado.jpg");
                    }
                    //lendo e fechando webFile
                    if(webFile){
                        while(webFile.available()){
                            client.write(webFile.read());
                        }
                        webFile.close();
                    }//lendo e fechando webFile
                    i = 0;
                    break;
                }//if c== '\n' && currentLineIsBlank
                if(c == '\n'){
                    currentLineIsBlank = true;
                }//if c == '\n'
                else if (c != '\r'){
                    currentLineIsBlank = false;
                }
            }//client.available
        }//while client.connected
        delay(1);
        client.stop();
    }//if cliente
}
boolean strEx(char *str, char *sfind){
  char found = 0;
  char index = 0;
  char len = strlen(str);
  while(index < len){
    if(str[index] == sfind[found]){
       found++;
       if(strlen(sfind) == found){
        return true;
       }
    }else{
      found = 0;
    }
    index++;
  }
  return false;
}
