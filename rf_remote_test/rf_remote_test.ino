// rf_remote

int gndPin = 17;
int plusPin = 19;
int bPin = 16;
int cPin = 15;
int dPin = 14;

int modePin = 18;

void setup()
{
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  pinMode(bPin, INPUT);
  pinMode(cPin, INPUT);
  pinMode(dPin, INPUT);
  pinMode(modePin, OUTPUT);
  digitalWrite(modePin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  Serial.print(digitalRead(bPin));
  Serial.print(digitalRead(cPin));
  Serial.println(digitalRead(dPin));
  delay(500);
}
