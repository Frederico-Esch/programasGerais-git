import netP5.*;
import oscP5.*;
import processing.serial.*;
OscP5 osc;
Serial serial; 
void setup(){
  size(400, 400);
  osc = new OscP5(this, 10002);
  serial = new Serial(this, "COM3", 9600);
  osc.plug(this, "test", "/test");
}
void draw(){
  background(0);
}
void test(int _test){
  if(_test == 1){
    serial.write(1);
  }
}
void mousePressed(){
  serial.write(1);
}
