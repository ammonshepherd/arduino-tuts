/***************************************
 * processing_bi_directional
 * 
 * Send to and receive from Arduino over
 * the Serial port.
 * 
 * author: Ammon Edwin Shepherd
 * date: 12 May 2021
 * license: MIT License
 * https://github.com/ammonshepherd/arduino-tuts/blob/master/LICENSE
 ****************************************/

import processing.serial.*;
Serial serialObject;

String serialValue;

void setup() {
  size(600, 600);
  serialObject = new Serial(this, Serial.list()[3], 9600);
  serialObject.bufferUntil(10);
}

void draw() {
  /* The serialValue is a String containing
   *  a single digit. We need that to be a char
   *  so we grab the character at index 0 (the
   *  first position of a character in the String. */
  if (serialValue.charAt(0) == '1') {
    background(20);
  } else {
    background(200, 189, 46);
  }

  if (mousePressed == true) {
    serialObject.write("1");
  } else {
    serialObject.write("0");
  }
}

void serialEvent(Serial p) {
  serialValue = p.readString();
}
