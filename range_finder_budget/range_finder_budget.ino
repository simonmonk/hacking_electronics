// range_finder_budget
// Arduino Uno or Leonardo

int trigPin = 9;
int echoPin = 10;
int gndPin = 11;
int plusPin = 8;

int lastDistance = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
}

void loop()
{
  Serial.println(takeSounding_in());
  delay(500);
}

int takeSounding_cm()
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  int duration = pulseIn(echoPin, HIGH); 
  int distance = duration / 29 / 2;
  if (distance > 500)
  {
    return lastDistance;
  }
  else
  {
    lastDistance = distance;
    return distance;
  }
}

int takeSounding_in()
{
  return takeSounding_cm() * 2 / 5;
}
