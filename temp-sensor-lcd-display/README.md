# Temperature Sensor & LCD 

This tutorial will help you put together a temperature and humidity sensor and
be able to view the data on the Liquid Crystal Display (LCD).

## Components Needed
- Arduino
  - https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6
- DHT11 Temperature & Humidity Sensor
  - https://www.amazon.com/NOYITO-Digital-Temperature-Humidity-Arduino/dp/B07HX14M4K
  - https://www.adafruit.com/product/386
- LCD display
  - https://www.amazon.com/Arducam-Display-Controller-Character-Backlight/dp/B019D9TYMI
- 10K Potentiometer
  - https://www.amazon.com/uxcell-Carbon-Potentiometer-Variable-Resistors/dp/B07W78RFQF
- Breadboard
  - https://www.amazon.com/HiLetgo-Solderless-Breadboard-Circuit-Prototyping/dp/B00LSG5BJK
- wires
  - https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78

- Or get a full kit
  - https://www.amazon.com/ELEGOO-Project-Tutorial-Controller-Projects/dp/B01D8KOZF4


## Other resources
- https://www.electronicshub.org/dht11-humidity-sensor-arduino/
- https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
- https://www.circuitbasics.com/how-to-set-up-an-lcd-display-on-an-arduino/
- https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40/circuit-4a-lcd-hello-world
- http://omerk.github.io/lcdchargen/

### Documentation
- https://www.arduino.cc/reference/en/libraries/dht-sensor-library/
- https://www.arduino.cc/en/Reference/LiquidCrystal


## Wiring Diagrams

### Temp & Humidity Sensor





## Code
- DHT11 sensor

```c++
#include <dht.h>

dht DHT;
const int THPIN = 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int check = DHT.read11(THPIN);

  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C");
  
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  Serial.println();

  delay(1500);
  }
```

- LCD
```c++
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World!");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("My scrolling text...");
 
  lcd.scrollDisplayLeft();

  delay(1000);
  
}
```

- DHT11 and LCD
```c++
#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;
const int DHT11_PIN = 7;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int check = DHT.read11(DHT11_PIN);

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print( (char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  
  delay(1500);
}
```
