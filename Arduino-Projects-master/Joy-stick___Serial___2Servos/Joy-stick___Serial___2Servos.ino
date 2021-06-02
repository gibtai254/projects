

//include servo library

#include <Servo.h>


const int xPin1 = A0;   // joystick x direction pin                                             
const int yPin1 = A1;

const int xPin2 = A3;
const int yPin2 = A4;// joystick y direction pin 

const int servo1xPin = 9;// first servo
const int servo1yPin = 10;// second servo

const int servo2xPin = 11;
const int servo2yPin = 12;

int xValue1;
int yValue1;

int xValue2;
int yValue2;

int X_pos1 = 90; // storing servo position
int Y_pos1 = 90;

int X_pos2 = 90; // storing servo position
int Y_pos2 = 90;
 
Servo servox1;// create servo object to control a servo
Servo servoy1;// create servo object to control a servo
Servo servox2;// create servo object to control a servo
Servo servoy2;// create servo object to control a servo

void setup() 
{
  pinMode (xPin1, INPUT) ;                     
  pinMode (yPin1, INPUT) ;
  pinMode (xPin2, INPUT) ;                     
  pinMode (yPin2, INPUT) ;
  
  servox1.attach(servo1xPin );  // attaches the servo
  servoy1.attach(servo1yPin);  // attaches the servo
  servox2.attach(servo2xPin ); 
  servoy2.attach(servo2yPin); 
  
  servox1.write(X_pos1);
  servoy1.write(Y_pos1);
  servox2.write(X_pos2);
  servoy2.write(Y_pos2);
  
}

void loop() 
{
  xValue1 = analogRead(xPin1);  
  yValue1 = analogRead(yPin1);
    
  xValue2 = analogRead(xPin2);  
  yValue2 = analogRead(yPin2);
  
// For 1st X-Axis Servo
  if (xValue1 < 300)
  {
    if (X_pos1 < 10) 
    {
      // Do Nothing 
    } 
    else
    {
      X_pos1 = X_pos1 - 5;
      servox1.write(X_pos1);
      delay(100); 
    } 
  } 
  
  if (xValue1 > 700)
  {
    if (X_pos1 > 160)
    {
      // Do Nothing  
    }
    else
    {
      X_pos1 = X_pos1 + 5;
      servox1.write(X_pos1);
      delay(100);
    }
  }
                    // For Y-Axis Servo
if (yValue1 < 300)
  {
    if (Y_pos1 < 10) 
    {
                 // Do Nothing 
    } 
    else
    {
      Y_pos1 = Y_pos1 - 5;
      servoy1.write(Y_pos1);
      delay(100); 
    } 
  } 
  
  if (yValue1 > 700)
  {
    if (Y_pos1 > 160)
    {
                  // Do Nothing  
    }
    else
    {
      Y_pos1 = Y_pos1 + 5;
      servoy1.write(Y_pos1);
      delay(100);
    }
  }
// For 2nd X-Axis Servo
  if (xValue2 < 300)
  {
    if (X_pos2 < 10) 
    {
      // Do Nothing 
    } 
    else
    {
      X_pos2 = X_pos2 - 5;
      servox2.write(X_pos2);
      delay(100); 
    } 
  } 
  
  if (xValue2 > 700)
  {
    if (X_pos2 > 160)
    {
      // Do Nothing  
    }
    else
    {
      X_pos2 = X_pos2 + 5;
      servox2.write(X_pos2);
      delay(100);
    }
  }
// For Y-Axis Servo
if (yValue2 < 300)
  {
    if (Y_pos2 < 10) 
    {
      // Do Nothing 
    } 
    else
    {
      Y_pos2 = Y_pos2 - 5;
      servoy2.write(Y_pos2);
      delay(100); 
    } 
  } 
  
  if (yValue2 > 700)
  {
    if (Y_pos2 > 160)
    {
      // Do Nothing  
    }
    else
    {
      Y_pos2 = Y_pos2 + 5;
      servoy2.write(Y_pos2);
      delay(100);
    }
  }
  
}


