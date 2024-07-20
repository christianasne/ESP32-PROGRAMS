/*
============================================================================
FILE : ESP32 BLUETOOTH 
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program for establishing connection through Bluetooth using
ESP32 board
============================================================================
*/
#include "BluetoothSerial.h"
// watch video for details of 0x3F I2C address
// end of settings for LCD1602 with I2C
BluetoothSerial serialBT;
char command;
void setup() {
  // put your setup code here, to run once:
    serialBT.begin("Christian Bluetooth");//Feel free to change the name of the bluetooth s
    pinMode(2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    if(serialBT.available())
    {
    command = serialBT.read();
    }
switch(command){
    case 'F':
      digitalWrite(2, HIGH);

  Serial.print("Forward");
      break;
    case 'B':
      digitalWrite(2, LOW);

    Serial.print("Backward");

      break;
    case 'L':
      digitalWrite(2, HIGH);

      break;
    case 'R':
      digitalWrite(2, LOW);

      break;
}
}
