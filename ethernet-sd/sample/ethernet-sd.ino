//#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
// TENTATIVA
bool imageReq(String *requisicao);
bool mainPageRequest(String *requisicao);
String getURLRequest(String *requisicao);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 77);  // Endereço IP que a Ethernet Shield terá. Deve ser alterado para um endereço livre da sua rede.
EthernetServer server(80);      // Cria um servidor WEB na porta 80
String HTTP_req; 
File webFile;

void setup()
{
    Ethernet.begin(mac, ip);  // Inicializa a Ethernet Shield
    server.begin();           // Inicia esperando por requisições dos clientes (Browsers)
    Serial.begin(9600);       // Inicia a comunicação Serial
    
    // inicia o leitor de cartão SD
    Serial.println("Iniciando o cartao SD...");
    SD.begin(4);
    if (!SD.begin(4)) {
        Serial.println("ERRO - a inicializacao do cartao SD falhou!");
        return;    //aborta a função SETUP caso exista erro
    }
    
    Serial.println("Cartao iniciado com SUCESSO!!");
    // verifica a existencia do arquivo index.htm no cartao SD
    boolean veri = SD.exists("index.htm");
    if (!veri) {
        Serial.println("ERRO - O arquivo index.htm nao foi localizado!");
        return;   //aborta a função SETUP caso exista erro
    }
    
    Serial.println("Arquivo index.htm encontrado!");
}


void loop()
{
    EthernetClient client = server.available();  // Tenta pegar uma conexão com o cliente (Browser)

    if (client) {  // Existe um cliente em conexão ?
      
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // os dados do cliente estão disponiveis para serem lidos
                char c = client.read(); // lê 1 byte (character) do cliente
                HTTP_req += c; 
                // a ultima linha da requisição do cliente é branca e termina com o caractere \n
                // responde para o cliente apenas após a última linha recebida
                if (c == '\n' && currentLineIsBlank) {
                  
                    // envia o cabeçalho de uma resposta http padrão
                    //client.println("HTTP/1.1 200 OK");
                    //client.println("Content-Type: text/html");
                    //client.println("Connection: close");
                    //client.println();
                    if (mainPageRequest(&HTTP_req)) {
                        //URLValue = getURLRequest(&HTTP_req);
                                                 
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connection: close");
                        client.println();
                        webFile = SD.open("index.htm");        // abre o arquivo da pagina WEB
                    }
                    if(imageReq(&HTTP_req)){
                        //URLValue = getURLRequest(&HTTP_req);
               
                        client.println("HTTP/1.1 200 OK");
                        client.println("Connection: close");
                        client.println();
                        webFile = SD.open("ligado.jpg");
                    }
                    // ENVIA A PÁGINA WEB
                    if (webFile) {
                        while(webFile.available()) {
                            client.write(webFile.read());  // envia a pagina WEB para o cliente (browser)
                        }
                        webFile.close();
                    }
                    break;
                }
                
                // toda linha de texto recebida do cliente termina com os caracteres \r\n
                if (c == '\n') {
                    // ultimo caractere da linha do texto recebido
                    // iniciando nova linha com o novo caractere lido
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // um caractere de texto foi recebido do cliente
                    currentLineIsBlank = false;
                }
            } // fim do if (client.available())
        } // fim do while (client.connected())
        
        delay(1);      // da um tempo para o WEB Browser receber o texto
        client.stop(); // termina a conexão

    } // fim do if (client)
} // fim do loop

String getURLRequest(String *requisicao) {
int inicio, fim;
String retorno;

  inicio = requisicao->indexOf("GET") + 3;
  fim = requisicao->indexOf("HTTP/") - 1;
  retorno = requisicao->substring(inicio, fim);
  retorno.trim();

  return retorno;
}

bool mainPageRequest(String *requisicao) {
String valor;
bool retorno = false;

  valor = getURLRequest(requisicao);
  valor.toLowerCase();

  if (valor == "/") {
     retorno = true;
  }

  if (valor.substring(0,2) == "/?") {
     retorno = true;
  }  

  if (valor.substring(0,10) == "/index.htm") {
     retorno = true;
  }  

  return retorno;
}
bool imageReq(String *requisicao){
  String valor;
  bool retorno = false;
  valor = getURLRequest(requisicao);
  valor.toLowerCase();
  if(valor == "/ligado.jpg"){
    retorno = true;
  }
  return retorno;
}
