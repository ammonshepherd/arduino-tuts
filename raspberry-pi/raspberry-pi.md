# Connecting Raspberry Pi and Arduino

## Hardware

- Raspberry Pi
- Arduino

## Software

- Arduino IDE
- Python (for interfacing with the Arduino with scripts)


## Set up

Plug the Arduino into the Raspberry Pi with USB.

Install the Arduino IDE

```
sudo apt-get install arduino
```

Install Python's serial library

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
