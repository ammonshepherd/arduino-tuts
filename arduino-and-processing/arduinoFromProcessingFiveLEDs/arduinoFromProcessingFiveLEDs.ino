int RED = 13;
int YEL = 12;
int GRE = 11;
int BLU = 10;
int WHI = 9;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YEL, OUTPUT);
  pinMode(GRE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(WHI, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char val = 'x';

  if (Serial.available()) {
    val = Serial.read();
  }


  if (val == 'r') {
    digitalWrite(RED, HIGH);
  } else {
    digitalWrite(RED, LOW);
  }


  if (val == 'y') {
    digitalWrite(YEL, HIGH);
  } else {
    digitalWrite(YEL, LOW);
  }


  if (val == 'g') {
    digitalWrite(GRE, HIGH);
  } else {
    digitalWrite(GRE, LOW);
  }


  if (val == 'b') {
    digitalWrite(BLU, HIGH);
  } else {
    digitalWrite(BLU, LOW);
  }


  if (val == 'w') {
    digitalWrite(WHI, HIGH);
  } else {
    digitalWrite(WHI, LOW);
  }

  delay(1000);
}
