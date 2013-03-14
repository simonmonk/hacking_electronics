// valiable_led_brightness
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
  int brightness = rawReading / 4;
  analogWrite(ledPin, brightness);
}
