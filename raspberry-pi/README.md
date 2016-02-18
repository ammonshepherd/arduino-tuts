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

### Optional
- Install Node.js, for using the Johnny-five JavaScript framework
  - Find the latest node version at 

```
$ wget http://nodejs.org/dist/v0.12.2/node-v0.12.2.tar.gz
$ tar xvzf node-v0.12.2.tar.gz
$ cd node-v0.12.2
``` 
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

To run this code, type:

```bash
python tempsensor.py /dev/ttyACM0 9600 temp-readings.csv
```

To send the sensor data to your Adafruit IO account, use the code in the
adafruit.py file.

To run this code, type:

```bash
python adafruit.py /dev/ttyACM0 9600
```
