// color_sensing
// Arduino Uno or Leonardo

int pulsePin = 7;
int prescale0Pin = 3;
int prescale1Pin = 4;
int colorSelect0pin = 5;
int colorSelect1pin = 6;


void setup()
{
  pinMode(prescale0Pin, OUTPUT);
  pinMode(prescale1Pin, OUTPUT);
  // set maximum prescale 
  digitalWrite(prescale0Pin, HIGH);
  digitalWrite(prescale1Pin, HIGH);
  pinMode(colorSelect0pin, OUTPUT);
  pinMode(colorSelect1pin, OUTPUT);
  pinMode(pulsePin, INPUT);
  Serial.begin(9600);
  Serial.println("Color Reader");
}

void loop()
{
  long red = readRed();
  long green = readGreen();
  long blue = readBlue();
  if (red < green && red < blue)
  {
    Serial.println("RED");
  }
  if (green < red && green < blue)
  {
    Serial.println("GREEN");
  }
  if (blue < green && blue < red)
  {
    Serial.println("BLUE");
  }
  delay(500);
}

long readRed()
{
  return (readColor(LOW, LOW));
}

long readGreen()
{
  return (readColor(HIGH, HIGH));
}

long readBlue()
{
  return (readColor(LOW, HIGH));
}

long readWhite()
{
  return (readColor(HIGH, LOW));
}

long readColor(int bit0, int bit1)
{
  digitalWrite(colorSelect0pin, bit0);
  digitalWrite(colorSelect1pin, bit1);
  long start = millis();
  for (int i=0; i< 1000; i++)
  {
    pulseIn(pulsePin, HIGH);
  }
  return (millis() - start);
}

void printRGB()
{
  Serial.print(readRed()); Serial.print("\t");
  Serial.print(readGreen()); Serial.print("\t");
  Serial.print(readBlue()); Serial.print("\t");
  Serial.println(readWhite());
}
