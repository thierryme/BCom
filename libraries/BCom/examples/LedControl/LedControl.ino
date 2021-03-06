/*
  Control of a led from an Android program over bluetooth
  Language: Wiring/Arduino


 Created August, 2016
 by Thierry Meister
 */

#include "BCom.h"


BFrameIn frame;
BCom bluetooth(&Serial1); //Use Serial if only one serial port on the arduino card

int pin_led = 13; //usual led pin on Arduino


void setup() {
  // start serial port at 115200 bps:
  Serial.begin(115200);
  Serial1.begin(115200);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only
}

void loop() {

  if(bluetooth.read(frame))
  {
    Serial.print(frame);
    if(frame.LED==1)
    {
        analogWrite(pin_led, map(frame.throttle,0,100,0,255));
    }
    else if(frame.LED==0)
    {
        digitalWrite(pin_led, LOW);
    }
  }
}
