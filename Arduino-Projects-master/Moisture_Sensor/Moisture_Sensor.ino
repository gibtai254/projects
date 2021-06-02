/*
  Moisture Sensor measures soil moisture grace to the changes in
  electrical conductivity of the earth ( soil resistance increases with drought ). 


 
*/
//First of all, we have defined two variables; one for the soil moisture sensor pin and the other for storing the output of the sensor
int sensorPin = A0; // Soil Sensor input at Analog PIN A0

int sensorValue; 

int limit = 300; 

void setup() {
   //communication between the Arduino and serial monitor
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 
}

void loop() {

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 
 if (sensorValue<limit) {
 digitalWrite(13, HIGH); 
 }
 else {
 digitalWrite(13, LOW); 
 }
 
 delay(1000); 
}
