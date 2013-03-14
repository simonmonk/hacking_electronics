// variable_led_flash
// Arduino Uno or Leonardo

int voltsInPin = 3;
int gndPin = A2;
int plusPin = A4;
int ledPin = 9;

void setup()
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int rawReading = analogRead(voltsInPin);
  int period = map(rawReading, 0, 1023, 100, 500);
  digitalWrite(ledPin, HIGH);
  delay(period);
  digitalWrite(ledPin, LOW);
  delay(period);
}
