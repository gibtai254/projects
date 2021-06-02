/*Using a joystick with the serial monitor
The joystick is similar to two potentiometers connected together, 
one for the vertical movement (Y-axis) and other for the horizontal movement (X-axis).
Using the joystick pins
VCC

GND

VRx -> Variable resistance x

VRY -> Variable resistance Y

SW -> Switch / Button

Connection
MODULE -> ARDUINO

VCC -> 5V
GND -> GND
VRx -> A0
VRy -> A1
SW -> Pin 2


*/
const int xPin = A0;                                               
const int yPin = A1;
const int switchPin = 2;

int xValue;
int yValue;
int switchValue;

void setup() 
{
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() 
{
  switchValue = digitalRead(switchPin);
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  
  Serial.print("Switch:  ");
  Serial.print(switchValue);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(yValue);
  Serial.print("\n\n");
  delay(1000);
}
