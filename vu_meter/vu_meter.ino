// vu_meter
// Arduino Uno or Leonardo

int gndPin = A1;
int plusPin = A0;
int soundPin = 2;

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
  int value = analogRead(soundPin);
  int topLED = 1 + abs(value - 511) / 10;

  for (int i = 0; i < topLED; i++)
  {
      Serial.print("*");
  }
  Serial.println();
  delay(100);
}
