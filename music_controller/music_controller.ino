// music_controller
// Arduino Leonardo Only
// Adafruit Accelerometer

int gndPin = A2;
int xPin = 5;
int yPin = 4;
int zPin = 3;
int plusPin = A0;

int levelX = 0;
int oldTilt = 4;

void setup() 
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  calibrate();
  Keyboard.begin();
}

void loop() 
{
  int x = analogRead(xPin);
  // levelX-70 levelX levelX + 70
  int tilt = (x - levelX) / 14 + 4;
  if (tilt < 0) tilt = 0;
  if (tilt > 8) tilt = 8;
  // 0 left, 4 is level, 8 is right
  if (tilt != oldTilt)
  {
      Keyboard.print(tilt);
      oldTilt = tilt;
  }
}

void calibrate()
{
  delay(200); // give accelerometer time to turn on
  levelX = analogRead(xPin);
}
