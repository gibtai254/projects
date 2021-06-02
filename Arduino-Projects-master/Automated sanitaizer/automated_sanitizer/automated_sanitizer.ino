/*code by Hassan
 written on 4/02/2020
 */
// include the servo library
  #include <Servo.h>
  #include <Servo.h>

 int servoPin = 8;
 int servoP = 5;

 const int pingPin = 9; //Trigger Pin of Ultrasonic Sensor
 const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
 

 long duration;
 int distance;
 int safetyDistance;
 
 Servo servo1;
 Servo servo2;

   void setup() {
    Serial.begin(9600); // starting Serial Terminal
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
    
   
 }

void loop() {
   
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(pingPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration*0.034/2;
  safetyDistance = distance;
  if(safetyDistance<=5){
    digitalWrite(servoPin, HIGH);
    servo1.write(0);
    servo2.write(1654);
     delay(100);
  }
  else if(safetyDistance>=5){
    digitalWrite(servoPin,LOW);
    servo1.write(150);
    servo2.write(0);
    delay(100);
   
  }

   if(safetyDistance<=5){
    digitalWrite(servoP, HIGH);
    servo1.write(0);
    delay(100);
    }
    else{
   digitalWrite(servoP,LOW);
   servo1.write(150);
   delay(100);
  }
  
  Serial.print("Distance:  ");
  Serial.print(distance);
}
/*
  prints the distance on the serial monitor
  Serial.print("Distance:  ");
  Serial.print(distance);
  // make servo go to 0 degrees
  servo1.write(0);
  delay(delay_time);
  // make servo go to 90 degrees
  servo1.write(90);
  delay(delay_time);
  // make servo go to 180 degrees
  servo1.write(180);
  delay(delay_time);
  // make servo go to 90 degrees
  servo1.write(90);
  delay(delay_time);
}*/
