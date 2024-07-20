/*
============================================================================
FILE : ESP32 BUTTON MODULE
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program for 2x4 button module using ESP32 board
============================================================================
*/
const int buttonPins[8] = {15, 4, 16, 17, 5, 18, 19, 21}; //Pins where button module are attach to ESP32
bool buttonStates[8];

void setup() {
  Serial.begin(115200); 
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    buttonStates[i] = !digitalRead(buttonPins[i]); 
    if (buttonStates[i]) {
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.println(" is pressed.");
    }
  }
  delay(200); 
}
