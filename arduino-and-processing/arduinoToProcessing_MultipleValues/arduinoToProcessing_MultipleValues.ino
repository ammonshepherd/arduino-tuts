/***************************************
 * arduinoToProcessing_MultipleValues
 * 
 * Send to and receive from Processing
 * over the Serial port.
 * 
 * author: Ammon Edwin Shepherd
 * date: 12 May 2021
 * license: MIT License
 * https://github.com/ammonshepherd/arduino-tuts/blob/master/LICENSE
 ****************************************/

const int trigPin = 12;
const int echoPin = 11;

float distance = 0;


void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int speed;

  distance = getDistance();

  // Set up the Serial output data to look like this:
  // distance,light
  // example: 42.42,242
  Serial.print(distance);
  Serial.print(',');
  Serial.println( analogRead(0) );
}


float getDistance() {
  float echoTime;
  float calculatedDistance;

  // Make sure transmission pin is turned off first
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //send out 10ms ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);

  //half the bounce time multiplied by the speed of sound
  //calculatedDistance = echoTime / 148.0; // Uncomment for inches
  calculatedDistance = echoTime / 58.2; // Uncomment for centimeters

  return calculatedDistance;
}
