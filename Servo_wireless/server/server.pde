import processing.serial.*;
import netP5.*;
import oscP5.*;
OscP5 osc;
Serial serial;
int perg;
int color1=0;
int color2=0;
int color3=0;
void setup(){
  size(400, 400);
  serial = new Serial(this, "COM3", 9600);
  osc = new OscP5(this, 10002);
  osc.plug(this, "press", "/press");
}
void draw(){
  background(color1, color2, color3);
  if(perg ==1){
    color1 = 255;
    color2 = 0;
    color3 = 0;
    serial.write(1);
  }else if(perg ==2){
    color1 = 0;
    color2 = 255;
    color3 = 0;
    serial.write(180);
  }else if(perg == 3){
    color1 = 0;
    color2 = 0;
    color3 = 255;
    serial.write(90);
  }else if(perg == 4){
    color1 = 255;
    color2 = 255;
    color3 = 255;
    serial.write(45);
  }
}
void press(int _press){
  perg = _press;
}
