// stepper
// Arduino Uno or Leonardo

int PWMApin = 9;
int AIN1pin = 7;
int AIN2pin = 8;
int PWMBpin = 3;
int BIN1pin = 5;
int BIN2pin = 4;

void setup()
{
  pinMode(PWMApin, OUTPUT);
  pinMode(AIN1pin, OUTPUT);
  pinMode(AIN2pin, OUTPUT);
  pinMode(PWMBpin, OUTPUT);
  pinMode(BIN1pin, OUTPUT);
  pinMode(BIN2pin, OUTPUT);
}

void loop()
{
  forward(10, 200);
  delay(1000);
  back(5, 200);
  delay(1000);
}
  
  
void forward(int d, int steps)  
{
  for (int i = 0; i < steps / 4; i++)
  {
    setStep(1, 0, 1, 0);
    delay(d);
    setStep(0, 1, 1, 0);
    delay(d);
    setStep(0, 1, 0, 1);
    delay(d);
    setStep(1, 0, 0, 1);
    delay(d);
  }
}

void back(int d, int steps)  
{
  for (int i = 0; i < steps / 4; i++)
  {
    setStep(1, 0, 0, 1);
    delay(d);
    setStep(0, 1, 0, 1);
    delay(d);
    setStep(0, 1, 1, 0);
    delay(d);
    setStep(1, 0, 1, 0);
    delay(d);
  }
}
  
void setStep(int w1, int w2, int w3, int w4)
{
  digitalWrite(AIN1pin, w1);
  digitalWrite(AIN2pin, w2);
  digitalWrite(PWMApin, 1);
  digitalWrite(BIN1pin, w3);
  digitalWrite(BIN2pin, w4);
  digitalWrite(PWMBpin, 1);
}
