// magnetic_sensor
// Arduino Uno or Leonardo

int gndPin = A1;
int sensePin = 2;
int plusPin = A3;

void setup()
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  int raw = analogRead(sensePin);
  Serial.println(raw);
  delay(1000);
}

