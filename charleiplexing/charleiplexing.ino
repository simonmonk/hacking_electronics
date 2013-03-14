// charlieplexing
// Arduino Uno or Leonardo

int pin1 = 12;
int pin2 = 11;
int pin3 = 10;

int pinStates[][3] = {
  {1, 0, -1}, // A
  {0, 1, -1}, // B
  {-1, 1, 0}, // C
  {-1, 0, 1}, // D
  {1, -1, 0}, // E
  {0, -1, 1}  // F
};


void setup()
{
}

void loop()
{
  for (int i = 0; i < 6; i++)
  {
    setPins(pinStates[i][0], pinStates[i][1], pinStates[i][2]); 
    delay(1000);
  }
}

void setPins(int p1, int p2, int p3)
{
  setPin(pin1, p1);
  setPin(pin2, p2);
  setPin(pin3, p3);
}

void setPin(int pin, int value)
{
  if (value == -1)
  {
    pinMode(pin, INPUT);
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, value);
  }
}
