/***************************************
 * arduinoToProcessingPhotoresistor
 * 
 * Send to and receive from Processing
 * over the Serial port.
 * 
 * author: Ammon Edwin Shepherd
 * date: 12 May 2021
 * license: MIT License
 * https://github.com/ammonshepherd/arduino-tuts/blob/master/LICENSE
 ****************************************/

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println( analogRead(0) );
}
