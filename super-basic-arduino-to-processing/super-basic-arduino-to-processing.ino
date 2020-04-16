/* Super Basic Sending Data to Serial Port
 *  author: Ammon Shepherd
 *  date: 14 April 2020
 */

// The basic setup is to start the Serial port at baud rate 9600
void setup() {
  Serial.begin(9600);
}

// All you need to do is send data with Serial.print
void loop() {
  /* The for loop is just imitating a sensor and is here
   *  to create a changing value that is sent to the serial
   *  port. Replace this with the sensor values
   */
  for ( int v = 0; v < 100; v++ ) {
    // Sends "Variable = #" to the serial port
    Serial.print("Variable = ");
    Serial.println(v);
    delay(200);
  }
}
