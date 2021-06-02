/*External pull up resistor
 * 
 * By default, the pin state will be HIGH
 * 
When you press the push button the state will change to LOW.

*/
#define button 5

boolean buttonState;

void setup() {
  
pinMode(button,INPUT);digitalWrite(button,LOW);
Serial.begin(9600);//Intiallize the serial connection

}

void loop() {
  
buttonState = digitalRead(button);
Serial.println(buttonState);

}
