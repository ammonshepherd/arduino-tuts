import processing.serial.*;

Serial myPort;

void setup() {
  size(200, 200);
  myPort = new Serial(this, Serial.list()[3], 9600);
}

void draw() {
  if (mousePressed == true) {
    myPort.write('1');
    println("1");
  } else {
    myPort.write('0');
  }
}
