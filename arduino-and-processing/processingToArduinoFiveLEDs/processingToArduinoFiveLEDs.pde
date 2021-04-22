import processing.serial.*;

Serial myPort;

void setup() {
  size(200, 200);
  myPort = new Serial(this, Serial.list()[3], 9600);
}

void draw(){}

void keyPressed() {
  if(key == 'r') {
    myPort.write('r');
  }
  if (key == 'y') {
    myPort.write('y');
  }
  if (key == 'g') {
    myPort.write('g');
  }
  if (key == 'b') {
    myPort.write('b');
  }
  if (key == 'w') {
    myPort.write('w');
  }
}
