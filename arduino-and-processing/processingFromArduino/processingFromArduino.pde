/***************************************
 * processingFromArduino
 * 
 * Send to and receive from Processing
 * over the Serial port.
 * 
 * author: Ammon Edwin Shepherd
 * date: 12 May 2021
 * license: MIT License
 * https://github.com/ammonshepherd/arduino-tuts/blob/master/LICENSE
 ****************************************/

import processing.serial.*;

Serial myPort;       

void setup() {
  myPort = new Serial(this, Serial.list()[3], 9600);
  //printArray(Serial.list());
}

void draw() {
  println(myPort.readStringUntil('\n'));
}
