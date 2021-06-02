
#include <Servo.h>

Servo servo1;

int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
 
void setup() 
{
  
servo1.attach(5); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
 
}
 
void loop() {
  
  ultra();
  servo1.write(0);
  if(distance <= 10){
  servo1.write(180);
  
  }
}
 
void ultra(){
  
  digitalWrite(trigPin, LOW)
  
  digitalWrite(echopin,HIGH);

  
delayMicroseconds(500)
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  
  }
