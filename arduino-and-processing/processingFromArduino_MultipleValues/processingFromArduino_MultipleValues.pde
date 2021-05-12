/***************************************
 * processingFromArduino_MultipleValues
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

// Instantiate here so it is accessable in multiple functions
String serialValues;

void setup() {
  size(640, 360);
  serialObject = new Serial(this, Serial.list()[3], 9600);
  serialObject.bufferUntil(10); // 10 is ASCII code for line feed
}

void draw() {
  // Split the serialValuess into a String array
  String[] vals = splitTokens(serialValues, ",");
  // Strings are easiest to convert to floats
  float distance = float(vals[0]);
  float light = float(vals[1]);

  background(0);
  stroke(255);
  strokeWeight(2);

  // map(<current value from sensor>, <lowest value from sensor>, <highest value from sensor>, <lowest desired value>, <highest desired value>) 
  float mappedLight = map(light, 350, 870, 0, 255);
  fill(mappedLight, 100, 180);
 
  float mappedDistance = map(distance, 1, 33, 10, 300);
  mappedDistance = constrain(mappedDistance, 10, 300);
  ellipse(320, 180, mappedDistance, mappedDistance);
}

void serialEvent(Serial p) {
  serialValues = p.readString();
}
