// methane
// Arduino Uno or Leonardo

int analogPin = 3;

void setup()
{
  Serial.begin(9600);
  Serial.println("Methane Detector");
}

void loop()
{
  Serial.println(analogRead(analogPin));
  delay(500);
}
