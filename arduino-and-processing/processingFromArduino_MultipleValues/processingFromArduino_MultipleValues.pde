import processing.serial.*;

Serial serialObject; 

// Instantiate here so it is accesible in multiple functions
String sensorValue;

void setup() {
  size(640, 360);
  serialObject = new Serial(this, Serial.list()[3], 9600);
  serialObject.bufferUntil(10); // 10 is ASCII code for line feed
}

void draw() {
  // Split the sensorValues into a String array
  String[] vals = splitTokens(sensorValue, ",");
  // Strings are easiest to convert to floats
  float distance = float(vals[0]);
  float light = float(vals[1]);

  background(0);
  stroke(255);
  strokeWeight(2);

  // map(<current value from sensor>, <lowest value from sensor>, <highest value from sensor>, <lowest color value>, <highest color value>) 
  float mappedLight = map(light, 70, 600, 0, 255);
  fill(mappedLight, 100, 180);

  float mappedDistance = map(distance, 0, 40, 0, 300);
  mappedDistance = constrain(mappedDistance, 0, 300);
  ellipse(320, 180, mappedDistance, mappedDistance);
}

void serialEvent(Serial p) {
  sensorValue = p.readString();
}
