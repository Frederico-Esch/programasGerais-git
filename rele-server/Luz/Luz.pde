import netP5.*;
import oscP5.*;
OscP5 osc;
NetAddress server;
//PImage img;
int var = 1;
void setup(){
  size(displayWidth, displayHeight, P3D);
  //img = loadImage("int.png");
  osc = new OscP5(this, 100);
  server = new NetAddress("192.168.0.106", 10002);
}
void draw(){
  background(0);
  switch(var){
    case 0:
      fill(0, 255,0);
      break;
    case 1:
      fill(255, 0, 0);
      break;
  }
  ellipse(width/2, height/2, 200, 200);
}
void mousePressed(){
  if(var == 1) {
    var = 0;
  }
  else {
    var = 1;
  }
  OscMessage m = new OscMessage("/test");
  m.add(1);
  osc.send(m, server);
}
