// voltmeter
// Arduino Uno or Leonardo

int voltsInPin = 3;
int gndPin = A2;
int plusPin = A4;

void setup()
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  Serial.begin(9600);
  Serial.println("Voltmeter");
}

void loop()
{
  int rawReading = analogRead(voltsInPin);
  float volts = rawReading / 204.8; 
  Serial.println(volts);
  delay(200);
}
