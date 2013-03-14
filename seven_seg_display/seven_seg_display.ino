// seven_seg_display
// Arduino Uno or Leonardo

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_7segment disp = Adafruit_7segment();

void setup() 
{
  Wire.begin();
  disp.begin(0x70);
}

void loop() 
{
  disp.print(millis() / 10);
  disp.writeDisplay();
  delay(10);
}


