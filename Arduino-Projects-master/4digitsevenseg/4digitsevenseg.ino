/*
 * Use the `SevSeg` library to display an increasing number on
 * our four-digit-display.
 */
#include "SevSeg.h"//Initiate a seven segment controller object
SevSeg sevseg; 

void setup(){
  byte numDigits = 4;
  //
   // these refer to digits.
   //
  byte digitPins[] = {10, 11, 12, 13};//Digits: 9,10,11,12 <--put one resistor (ex: 220 Ohms, or 330 Ohms, etc, on each digit pin)
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4}; //Segments: A,B,C,D,E,F,G,Period!

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}
// the setup routine runs once when you press reset:
void loop(){
    sevseg.setNumber(4999, 3);
    sevseg.refreshDisplay(); // Must run repeatedly; don't use blocking code (ex: delay()) in the loop() function or this won't work right
}

