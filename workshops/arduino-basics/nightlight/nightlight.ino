/************************************
 * Nightlight Sketch
 * 
 * Use a photoresistor and an LED to
 * create a nightlight circuit.
 * 
 * See here for circuit diagram and
 * further instructions:
 * https://github.com/ammonshepherd/arduino-tuts/workshops/arduino-basics
 * 
 * Author: Ammon Shepherd
 * Date: May 4, 2021
 * 
 * License: CC BY-NC-SA 4.0, https://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1
 */
int threshold = 100;
int resistance;
int initialPhotoValue;

void setup() {
pinMode(12, OUTPUT);
initialPhotoValue = analogRead(0);
}

void loop() {
  // Read the data from analog pin 0, and
  // store it in the variable named 'resistance'.
  resistance = analogRead(0);

  // logic test. Is the new value lower than the
  // initial value minus the threshold?
  if (resistance < initialPhotoValue - threshold) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
}
