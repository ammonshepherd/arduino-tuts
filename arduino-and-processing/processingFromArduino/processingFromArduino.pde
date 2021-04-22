import processing.serial.*;

Serial myPort;       

void setup() {
  myPort = new Serial(this, Serial.list()[3], 9600);
  //printArray(Serial.list());
}

void draw() {
  println(myPort.readStringUntil('\n'));
}
