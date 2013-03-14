// range_finder_maxsonar
// Arduino Uno or Leonardo

int readingPin = 0;

int lastDistance = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(takeSounding_in());
  delay(500);
}

int takeSounding_in()
{
  int rawReading = analogRead(readingPin);
  return rawReading / 2;
}

int takeSounding_cm()
{
  return takeSounding_cm() * 5 / 2;
}
