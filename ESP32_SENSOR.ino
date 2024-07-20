/*
============================================================================
FILE : ESP32 Sensor 
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program for digital or analog sensor using ESP32 board
============================================================================
*/

/*
 const int analogPin = 17;  // Change according to your connection
 int sensorValue = 0;

 void setup() {
   Serial.begin(115200);  // Start the serial communication at 115200 baud rate
 }

 void loop() {
   sensorValue = analogRead(analogPin);  // Read the analog value from the sensor
   Serial.print("Analog value: ");
   Serial.println(sensorValue);  // Print the analog value to the Serial Monitor
   delay(100);  // Wait for 500 milliseconds before reading again
 }
*/
const int digitalPin = 15;  // Change according to your connection
int sensorValue = 0;

void setup() {
  Serial.begin(115200);  // Start the serial communication at 115200 baud rate
  pinMode(digitalPin, INPUT);  // Set the digital pin as input
}

void loop() {
  sensorValue = digitalRead(digitalPin);  // Read the digital value from the sensor
  Serial.print("Digital value: ");
  Serial.println(sensorValue);  // Print the digital value to the Serial Monitor
  delay(10);  // Wait for 500 milliseconds before reading again
}
