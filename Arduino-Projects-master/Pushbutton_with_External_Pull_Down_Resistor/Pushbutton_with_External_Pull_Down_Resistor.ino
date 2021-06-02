/* Push button with external pull down resistor
 *  By default, the pin state will be LOW
When we press the push button the state will change to HIGH from LOW
 */

#define button 5

boolean buttonState;

void setup() {
  
pinMode(button,INPUT);
Serial.begin(9600);

}

void loop() {
  
 buttonState = digitalRead(button);
 Serial.println(buttonState);
 
}
