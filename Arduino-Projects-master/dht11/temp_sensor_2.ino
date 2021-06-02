
#include <LiquidCrystal.h> // load lib
#include <DHT.h> // load lib
                      
LiquidCrystal mlcd(10,9,5,4,3,2); // make a lcd object

#define dht_apin   11 
dht DHT;  // sensor pin S to pin11

void setup() {

mlcd.begin(16,2); // to tell arduino there are 16 colunms and 2 rows
}


void loop(){
DHT.read11(dht_apin);
mlcd.setCursor(0,0); // row 1
mlcd.print(" Humidity = "); // print on the lcd Humidity =  
mlcd.print(DHT.humidity);  // to print the humidity          

mlcd.setCursor(0,1);
mlcd.print(" Temp = ");  // print on the lcd temp =     
mlcd.print(DHT.temperature);  // print on the lcd temperture       
mlcd.println(" C ");
delay (250); // delay                  

}

