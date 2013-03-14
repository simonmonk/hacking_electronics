// rf_remote
// Arduino Uno or Leonardo

int gndPin = A3;
int plusPin = A5;
int bPin = A2;
int cPin = A1;
int dPin = A0;

void setup()
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  pinMode(bPin, INPUT);
  pinMode(cPin, INPUT);
  pinMode(dPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print(digitalRead(bPin));
  Serial.print(digitalRead(cPin));
  Serial.println(digitalRead(dPin));
  delay(500);
}
