// rover
// Arduino Uno or Leonardo

int fullPower = 255;
int slowPower = 220  ;

int PWMApin = 9;
int AIN1pin = 7;
int AIN2pin = 8;
int PWMBpin = 3;
int BIN1pin = 5;
int BIN2pin = 4;

int remotePins[] = {10, 11, 12, 13};
int lastPinStates[] = {0, 0, 0, 0};

void setup()
{
  pinMode(PWMApin, OUTPUT);
  pinMode(AIN1pin, OUTPUT);
  pinMode(AIN2pin, OUTPUT);
  pinMode(PWMBpin, OUTPUT);
  pinMode(BIN1pin, OUTPUT);
  pinMode(BIN2pin, OUTPUT);
  for (int i = 0; i < 4; i++)
  {
    pinMode(remotePins[i], INPUT);
  }
  Serial.begin(9600);
}

void loop()
{
   int keyPressed = getKeyPress();
   Serial.println(keyPressed);
   if (keyPressed == 3)
   {
     stopMotors();
   }
   else if (keyPressed == 0)
   {
     turnLeft();
   }
   else if (keyPressed == 2)
   {
     turnRight();
   }
   else if (keyPressed == 1)
   {
     forward();
   }
   delay(20);
}

void stopMotors()
{
  digitalWrite(AIN1pin, LOW);
  digitalWrite(AIN2pin, LOW);
  analogWrite(PWMApin, 0);
  digitalWrite(BIN1pin, LOW);
  digitalWrite(BIN2pin, LOW);
  analogWrite(PWMBpin, 0);
}
  
void turnLeft()
{
  digitalWrite(AIN1pin, HIGH);
  digitalWrite(AIN2pin, LOW);
  analogWrite(PWMApin, slowPower);
  digitalWrite(BIN1pin, LOW);
  digitalWrite(BIN2pin, HIGH);
  analogWrite(PWMBpin, slowPower);
}

void turnRight()
{
  digitalWrite(AIN1pin, LOW);
  digitalWrite(AIN2pin, HIGH);
  analogWrite(PWMApin, slowPower);
  digitalWrite(BIN1pin, HIGH);
  digitalWrite(BIN2pin, LOW);
  analogWrite(PWMBpin, slowPower);
}

void forward()
{
  digitalWrite(AIN1pin, LOW);
  digitalWrite(AIN2pin, HIGH);
  analogWrite(PWMApin, fullPower);
  digitalWrite(BIN1pin, LOW);
  digitalWrite(BIN2pin, HIGH);
  analogWrite(PWMBpin, fullPower);
}

int getKeyPress()
{
  // the outputs on the RF module toggle
  // so see what's changed and thats the 
  // key that was pressed
  int result = -1;
  for (int i = 0; i < 4; i++)
  {
    int remoteInput = digitalRead(remotePins[i]);
    //Serial.print(remoteInput);
    if (remoteInput != lastPinStates[i])
    {
      result = i;
    }
    lastPinStates[i] = remoteInput;
  }
  return result;
}
  
