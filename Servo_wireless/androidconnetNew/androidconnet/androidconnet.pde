import netP5.*;
import oscP5.*;
OscP5 osc;
NetAddress server;
int varName;
void setup(){
  fullScreen();
  osc = new OscP5(this, 2);
  server = new NetAddress("192.168.0.106", 10002);
}
void draw() {

}
void mousePressed(){
  OscMessage newMessage = new OscMessage("/press");  
  if(mouseY > height/2){
    if(mouseX>width/2){
      newMessage.add(1);
    }else{
      newMessage.add(2);
    }
  }else{
    if(mouseX>width/2){
      newMessage.add(3);
    }else{
      newMessage.add(4);
    }
  } 
  osc.send(newMessage, server);
}
