/* Super Basic Getting input from Arduino
 * author: Ammon Shepherd
 * date: 14 April 2020
 */

// This line imports the serial library for processing to handle
// the serial information
import processing.serial.*;

// Here we create a serial object and give it a handle/name to use later
Serial myPort;       

// This creates a variable that we'll use later to store the information
// from the arduino.
String val;


void setup() {
  /* This line will list all the available serial ports. Use it the
  *  the first time you run the sketch to see which serial port number
  *  you should use in a following line. You will pick the number
  *  that corresponds to the USB port where the Arduino is plugged into.
  *  This usually has "/dev/cu.usbmodem" for Mac or "COM1" for Windows.
  *  It will look something like this:
  *  
  *   [0] "/dev/cu.Bluetooth-Incoming-Port"
  *   [1] "/dev/cu.usbmodem1432201"
  *   [2] "/dev/tty.Bluetooth-Incoming-Port"
  *   [3] "/dev/tty.usbmodem1432201"
  */
  printArray(Serial.list());

  /* This opens the serial port obect with 3 selected values
  *  this = which Serial object to use. We want the myPort object, 
  *         but we can reference it using the 'magic' word 'this'
  *  Serial.list()[1] = Serial.list() returns an array. We want the
  *         second element in the array (index starts at zero).
  *  9600 = this is the baud rate. It should equal the rate used in
  *         your Arduino sketch, in the setup function where it states
  *         "Serial.begin(9600)"
  */
  myPort = new Serial(this, Serial.list()[1], 9600);
  
  /* This waits until it sees a new line character "\n" and treats 
  *  everything it sees until that as one chunck of code.
  */
  myPort.bufferUntil('\n');
}

/* We don't need anything here for the basic setup. We can use the 
*  "val" variable (created above and given values in the serialEvent 
*  function below.
*/
void draw() {
}


// This function takes care of getting the information from the serial port
void serialEvent( Serial myPort) {
  /* Read the information from the serail port and put it into the variable
  *  named 'val'. You can use this variable in the draw function. 
  */
  val = myPort.readStringUntil('\n');
  
  /* Sometimes Processing reads the serial port before there is data there, 
  *  resulting in a 'null' value. This checks to make sure the value is not
  *  null before doing something with the variable.
  */
  if (val != null) {
    // This just prints out the value of the variable.
    println(val);
  }
}
