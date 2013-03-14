// mosfet_motor_speed
// Arduino Uno or Leonardo

int voltsInPin = 0;
int motorPin = 5;

void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  int rawReading = analogRead(voltsInPin);
  int power = rawReading / 4;
  analogWrite(motorPin, power);
}
