/* *********************************
 *  Distance Sensor Controlled Motor
 *  Motor and sensor code altered from 
 *  - https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v33/experiment-12-driving-a-motor
 *  - https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40/circuit-3b-distance-sensor
 *  
 *  Control a motor with an ultrasonic distance sensor
 *  
 *  Components needed:
 *  1 - Arduino Uno R3 + USB A-to-B Cable
 *  1 - Breadboard 
 *  10 - Jumper Wires
 *  1 - DC Motor
 *  2 - 330Ω Resistor
 *  1 - LED (any color)
 *  1 - NPN transistor
 *  1 - Diode 1N4148
 *  1 - HC-SR04 ultrasonic distance sensor
 *  1 - computer to connect the Arduino to with the Arduino IDE software installed (https://www.arduino.cc/en/software)
 *  
 *  Wiring Diagram:
 *  https://github.com/ammonshepherd/arduino-tuts/tree/master/distance-sensor-motor
 *  
 *  Author: Ammon Shepherd
 *  Date: 13 April 2021
********************************* */

const int motorPin = 6;
const int trigPin = 11;
const int echoPin = 12;
const int ledPin = 8;

float distance = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(motorPin, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  int speed;
  
  distance = getDistance();

  Serial.print(distance);
  // Serial.println(" in"); // Uncomment for inches
  Serial.println(" cm"); // Uncomment for centimeters

  //speed = map(distance, 0, 15, 0, 255); // Uncomment for inches
  speed = map(distance, 0, 50, 100, 255); // Uncomment for centimeters
  speed = constrain(speed, 100, 255);

  Serial.print("speed: ");
  Serial.println(speed);

  analogWrite(motorPin, speed);

  delay(500);
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
