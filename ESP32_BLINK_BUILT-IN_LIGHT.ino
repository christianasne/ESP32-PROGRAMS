/*
============================================================================
FILE : ESP32 BLINK BUILT-IN LIGHT 
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program for blinking the built-in LED on ESP32
============================================================================
*/

//#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x27, 16, 2);
// watch video for details of 0x3F I2C address
// end of settings for LCD1602 with I2C

int ledPin = 2; //Pin where LED is connected 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  //lcd.begin();  
  //lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
    //lcd.clear();
    //lcd.print("HIGH");
    digitalWrite(2, HIGH);
    delay(500);
    //lcd.clear();
    //lcd.print("LOW");
    digitalWrite(2, LOW);
    delay(500);

}
