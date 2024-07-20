/*
============================================================================
FILE : ESP32 MOTOR
AUTHOR : Christian Andrie Asne
DESCRIPTION : A program for using any type of motor driver using ESP32 board
============================================================================
*/
// Motor A
int enA = 13;
int in1 = 14;
int in2 = 12;
 
// Motor B
 
int enB = 27;
int in3 = 26;
int in4 = 25;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(115200);
    
}
void Forward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

 
   analogWrite(enA, 255);
   analogWrite(enB, 255);


}
void Backward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   analogWrite(enA, 255);
   analogWrite(enB, 255);
}


void loop()
{
  Serial.print("Forward");
  Forward();
  delay(1000);
  Serial.print("Backward");
  Backward();
  delay(1000);
   
}
