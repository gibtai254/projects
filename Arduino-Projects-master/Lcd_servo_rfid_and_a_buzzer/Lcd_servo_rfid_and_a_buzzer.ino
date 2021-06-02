// Include required libraries
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
// Create instances
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 mfrc522(10, 9); // MFRC522 mfrc522(SS_PIN, RST_PIN)
Servo sg90;
// Initialize Pins for led's, servo and buzzer
// Blue LED is connected to 5V
constexpr uint8_t greenLed = 25;
constexpr uint8_t redLed = 24;
constexpr uint8_t servoPin = 52;
constexpr uint8_t buzzerPin = 30;
String tagUID = "29 B9 ED 23";  // String to store UID of tag. Change it with your tag's UID
void setup() {
  // Arduino Pin configuration
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
  sg90.attach(servoPin);  //Declare pin 9 for servo
  sg90.write(0); // Set initial position at 90 degrees
  lcd.begin();   // LCD screen
  lcd.backlight();
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  lcd.clear();
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print(" RFID Door Lock");
  lcd.setCursor(0, 1);
  lcd.print(" Show Your Tag ");
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  //Reading from the card
  String tag = "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    tag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    tag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  tag.toUpperCase();
  //Checking the card
  if (tag.substring(1) == tagUID) //change here the UID of the card/cards that you want to give access
  {
    // If UID of tag is matched.
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    lcd.setCursor(0, 1);
    lcd.print("Door Opened");
    sg90.write(90);
    digitalWrite(greenLed, HIGH);
    delay(3000);
    digitalWrite(greenLed, LOW);
    sg90.write(0);
    lcd.clear();
  }
  else
  {
    // If UID of tag is not matched.
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong Tag Shown");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redLed, HIGH);
    delay(3000);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redLed, LOW);
    lcd.clear();
  }
}
