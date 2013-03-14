// egg_and_spoon_adafruit
// Arduino Uno or Leonardo

int gndPin1 = A2;
int gndPin2 = 3;
int xPin = 5;
int yPin = 4;
int zPin = 3;
int plusPin = A0;
int ledPin = 8;
int buzzerPin = 6;

int levelX = 0;
int levelY = 0;

int ledThreshold = 10;
int buzzerThreshold = 40;

void setup()
{
  pinMode(gndPin1, OUTPUT);
  digitalWrite(gndPin1, LOW);
  pinMode(gndPin2, OUTPUT);
  digitalWrite(gndPin2, LOW);
  pinMode(plusPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  pinMode(A1, INPUT); // 3V output 
  calibrate();
}

void loop()
{
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  boolean shakey = (abs(x - levelX) > ledThreshold || abs(y - levelY) > ledThreshold);
  digitalWrite(ledPin, shakey);
  boolean lost = (x > levelX + buzzerThreshold || y > levelY + buzzerThreshold);
  if (lost)
  {
    tone(buzzerPin, 400);
  }   
}

void calibrate()
{
  delay(200); // give accelerometer time to turn on
  levelX = analogRead(xPin);
  levelY = analogRead(yPin);
}
