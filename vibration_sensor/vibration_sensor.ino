// vibration_sensor
// Arduino Uno or Leonardo

int gndPin = A0;
int sensePin = 1;
int ledPin = 8;

int normalReading = 0;
int threshold = 10;

void setup()
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(ledPin, OUTPUT);
  normalReading = calibrate();
}

void loop()
{
  int reading = analogRead(sensePin);
  if (reading > normalReading + threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
}

int calibrate()
{
  int n = 100;
  long total = 0;
  for (int i = 0; i < n; i++)
  {
    total = total + analogRead(sensePin);
    delay(1);
  }
  return total / n;
}
