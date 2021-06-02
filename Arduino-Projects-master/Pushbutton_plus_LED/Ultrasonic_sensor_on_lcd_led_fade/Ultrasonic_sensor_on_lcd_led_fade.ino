/*
* Ultrasonic Sensor HC-SR04 and LCD 
*
* by Isaac Mwondi
*
*/
#include <LiquidCrystal.h> // includes the LiquidCrystal Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int trigPin = 9;
const int echoPin = 10;
const int led1 = 8;
const int led2 = 7;
const int led3 = 6;
long duration, cm2;
int distanceCm, distanceInch;
int fadeValue , fadeValue2;

void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode (led3, OUTPUT);
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

 if (distanceCm<100)   // If Distance is less than 100 cm then do the following:

 {    // Maps the LED brightness inversely proportional to the distance 

  cm2 = 40 - distanceCm;  

  fadeValue2 = map(cm2 , 0, 40, 0, 254);


  analogWrite(led1, fadeValue2);  // Writes the fadeValue to pin 8
  analogWrite(led2, fadeValue2);  //Writes the fadeValue to pin 7
  analogWrite(led3, fadeValue2);  //Writes the fadeVale to pin 6
 }
 else
 {
   analogWrite(led1, 0);  //If distance is larger than 100cm then switch off all leds 
   analogWrite(led2, 0);
   analogWrite(led3, 0);
 }

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
delay(10);

lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(10);
}
