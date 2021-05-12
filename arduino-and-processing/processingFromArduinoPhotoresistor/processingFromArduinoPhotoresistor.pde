/***************************************
 * processingFromArduinoPhotoresistor
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

Serial serialObject; 
float sensorValue;

void setup() {
  size(640, 360);
  serialObject = new Serial(this, Serial.list()[3], 9600);
  serialObject.bufferUntil(10); // 10 is ASCII code for line feed
}

void draw() {
  background(0);

  // Set circle border color and size
  stroke(255);
  strokeWeight(2);

  // map(<current value from sensor>, <lowest value from sensor>, <highest value from sensor>, <lowest color value>, <highest color value>) 
  float mappedValue = map(sensorValue, 70, 600, 0, 255);
  //print(mappedValue);
  fill(mappedValue, 100, 180);
  ellipse(320, 180, mappedValue, mappedValue);
}

void serialEvent(Serial p) {
  sensorValue = float(p.readString());
  //println(sensorValue);
}
