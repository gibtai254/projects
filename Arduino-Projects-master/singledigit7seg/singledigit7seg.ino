//Single digit Seven segment 

#include <SevSeg.h>

SevSeg sevseg; //we create a sevseg object

void setup(){
  byte numDigits = 1;// This sets the number of digits on your display.If you’re using a 4 digit display, set this to 4.
    
  byte digitPins[] = {}; // Creates an array that defines the ground pin
    
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};//This declares an array that defines which Arduino pins are connected to each segment of the display.
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; //This sets the type of display.
    
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    
    sevseg.setBrightness(90); // This function sets the brightness of the display. It can be adjusted from 0 to 100.
}

void loop(){
        sevseg.setNumber(4); // This function prints the number to the display. 
        
        sevseg.refreshDisplay(); //This function is required at the end of the loop section to continue displaying the number.      
}


