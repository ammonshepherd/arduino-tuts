# Connecting Raspberry Pi and Arduino

## Hardware

- Raspberry Pi
- Arduino

## Software

- Arduino IDE
- Python (for interfacing with the Arduino with scripts)


## Set up

Plug the Arduino into the Raspberry Pi with USB.

### Raspberry Pi set up
- Install the OS
  - Follow instructions on their Downloads page: https://www.raspberrypi.org/downloads/
  - I found that our Raspberry Pi B only works best with Raspbian Wheezy or
    Jessie lite.


#### Software and updates
- Update the OS with `sudo apt-get update` and `sudo apt-get upgrade`
- Set time and date with `sudo dpkg-reconfigure tzdata` and then restart the Pi
- Install the Arduino IDE with `sudo apt-get install arduino`
- Install Python's serial library

## Code


### Arduino Code
This code is uploaded to the Arduino using the Arduino IDE.

Change the variable in the `Serial.println()` line to output degrees in Celsius
or Fahrenheit.

```c++
// Analog pin for the Temperature sensor
const int temPin = 0;

// Time in milliseconds
const int secs = 5000;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float voltage, degC, degF;
  
  voltage = analogRead(temPin) * 0.004882814;
 
  degC = (voltage - 0.5) * 100.0;
  degF = degC * (9.0/5.0) + 32.0;
  
  Serial.println(degC);
  
  delay(secs);
}
```

### Python Code

To capture the temperature in a file on the Raspberry Pi, use the code in the
tempsensor.py file.

```python
# Call with three arguments
# 1 = port
# 2 = Baudrate
# 3 = output file name
# ex: python tempsensor.py /dev/ttyACM0 9600 readings.csv

import serial, sys, datetime


with open(sys.argv[3], "w") as f:
  with serial.Serial(port=sys.argv[1], baudrate=sys.argv[2]) as ser:
    if ser.isOpen():
      ser.readline()
    while ser.isOpen():
      f.write('{}, {}'.format(datetime.datetime.now().strftime('%c'), ser.readline()))
```
To run this code, type:

```bash
python tempsensor.py /dev/ttyACM0 9600 temp-readings.csv
```

To send the sensor data to your Adafruit IO account, use the code in the
adafruit.py file.

```python
from Adafruit_IO import *
import serial, sys

# Adafruit IO Key, read it from a file named aio-key
with open ("aio-key", "r") as keyfile:
    aiokey = keyfile.read().strip()

aio = Client(aiokey)

with serial.Serial(port=sys.argv[1], baudrate=sys.argv[2]) as ser:
    if ser.isOpen():
        ser.readline()
    while ser.isOpen():
        aio.send('Foo', ser.readline())
```

To run this code, type:

```bash
python adafruit.py /dev/ttyACM0 9600
```
