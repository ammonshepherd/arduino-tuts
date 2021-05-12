/***************************************
 * arduino-bi-directional
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
int tiltPin = 3;
int ledPin = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Serial.println(digitalRead(tiltPin));

  if (Serial.available())
  {
    val = Serial.read();
  }

  if (val == '1')
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}
