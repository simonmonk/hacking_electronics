// temperature_sensor
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
  float volts = raw / 205.0;
  float tempC = 100.0 * volts - 50;
  float tempF = tempC * 9.0 / 5.0 + 32.0;
  Serial.print(tempC);
  Serial.print(" C ");
  Serial.print(tempF);
  Serial.println(" F");  
  delay(1000);
}

