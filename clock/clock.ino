// clock
// Arduino Uno or Leonardo

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "RTClib.h"

RTC_DS1307 RTC;
Adafruit_7segment disp = Adafruit_7segment();

void setup() 
{
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) 
  {
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  disp.begin(0x70);
}

void loop() 
{
  disp.print(getDecimalTime());
  disp.drawColon(true);
  disp.writeDisplay();
  delay(500);
  disp.drawColon(false);
  disp.writeDisplay();
  delay(500);
}

int getDecimalTime()
{
  DateTime now = RTC.now();
  int decimalTime = now.hour() * 100 + now.minute();
  return decimalTime;
}

