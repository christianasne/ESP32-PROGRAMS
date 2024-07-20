/*
============================================================================
FILE : ESP32 SERIAL MONITOR BLINK 
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program for blinking the built-in LED on ESP32 through 
serial monitor 
============================================================================
*/
String cmd;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    cmd = Serial.readString();
    if (cmd == "on")
    {
      digitalWrite(2, HIGH);
    }
    else if (cmd == "off")
    {
      digitalWrite(2, LOW);
    }
  }
}
