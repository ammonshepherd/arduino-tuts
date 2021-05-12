/***************************************
 * arduinoFromProcessing
 * 
 * Send to and receive from Processing
 * over the Serial port.
 * 
 * author: Ammon Edwin Shepherd
 * date: 12 May 2021
 * license: MIT License
 * https://github.com/ammonshepherd/arduino-tuts/blob/master/LICENSE
 ****************************************/

char val;
int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
  }

  if (val == '1') {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(10);
}
