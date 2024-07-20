/*
============================================================================
FILE : ESP32 LCD SCREEN
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program to use LCD using ESP32 board 
============================================================================
*/

// start of settings for LCD1602 with I2C
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x20, 16, 2);
// watch video for details of 0x3F I2C address
// end of settings for LCD1602 with I2C

int count =0;
void setup() {
  lcd.begin();  
  lcd.backlight();
  lcd.print("EMPOWER");
  lcd.setCursor(0,1);
  lcd.print("Demo");  
  delay(2000); 
}


void loop() {
 // Robojax ESP32 LCD-1602-I2C 
  lcd.clear();// clear previous values from screen
  lcd.print("EMPOWER ROBOTICS");
  lcd.setCursor(0,1);
  lcd.print("Robot:");
  lcd.setCursor(11,1);  
  lcd.print(count);
  count++;
  delay(200); 
}
 