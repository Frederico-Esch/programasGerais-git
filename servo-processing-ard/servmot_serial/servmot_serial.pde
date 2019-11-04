import processing.serial.*;
import controlP5.*;
ControlP5 cp5;
Serial serial;
int info = 0;
void setup(){
    size(400, 400);
    cp5 = new ControlP5(this);
    cp5.addKnob("Angle").setPosition(100, 100).setSize(200, 200).setRange(0,180).setNumberOfTickMarks(4).setAngleRange(PI).setStartAngle(PI).snapToTickMarks(true).setColorBackground(color(128)).setColorActive(color(255,0,0)).setColorForeground(color(200,0,0));
    cp5.addButton("Enviar").setPosition(width-90, height-90).setSize(70,70).setColorBackground(color(128)).setColorForeground(color(180,00,00));
    serial = new Serial(this, "COM3", 9600);
}
void draw(){
  background(220);
  textAlign(CENTER, TOP);
  textSize(25);
  fill(0);
  text("Servo Control", width/2, 0);
  serial.write(info);
  println(serial.readString());
}
void Enviar(){
  if(floor(cp5.get("Angle").getValue()) == 0){
    info = 1;
  }else{
    info =floor(cp5.get("Angle").getValue());
  }
  
  
}
