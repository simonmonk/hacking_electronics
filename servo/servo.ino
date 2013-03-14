// servo
// Arduino Uno or Leonardo

#include <Servo.h> 

int gndPin = A0;
int plusPin = A2;
int potPin = 1;
int servoControlPin = 2;
 
Servo servo;  
 
void setup() 
{ 
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  servo.attach(servoControlPin); 
} 
 
void loop() 
{ 
  int potPosition = analogRead(potPin);   // 0 to 1023 
  int angle = potPosition / 6;            // 0 to 170
  servo.write(angle);                 
} 
