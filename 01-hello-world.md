# Hello World!

In computer programming, when you learn a new language for the first time, you
usually write a 'hello world!' program. This gets you into the very basics of
the programming language, how to edit and execute code, some basic print
statements, etc.

A comparable example for Arduinos is making an LED blink. 

## Setup

### Physical set up.

- Connect the Arduino to your computer via the USB cable.
- Plug the LED into the GND and 13 pins. The long wire should go into the hole labeled 13.

![led-blink](images/led-blink.gif)

(image source: https://github.com/rwaldron/johnny-five)

### Code

- Open the Arduino IDE and create a new sketch (File->New)
- It should be populated with this basic code already:

```c
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

- Add some code to make the LED blink

```c
// Create a variable to set the LED pin
int ledPin = 13;

void setup() {
  // Set the pin to be an output pin
  pinMode(ledPin, OUTPUT);
}

// Whatever is in the loop will repeat over and over again.
void loop() {
  // Push some voltage to the pin
  // digitalWrite is either, HIGH or LOW, on or off
  digitalWrite(ledPin, HIGH);

  // delay makes the script wait for the given miliseconds
  // this keeps the light on
  delay(100);

  digitalWrite(ledPin, LOW);
  delay(100);
}
```

### Make it so
- Validate the code (click the check mark in the upper left corner)
- Upload the code to the Arduino (click the arrow in the circle)
