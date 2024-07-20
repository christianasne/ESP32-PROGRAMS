int enA = 13;
int in1 = 12;
int in2 = 14;
 
// Motor B
 
int enB = 27;
int in3 = 26;
int in4 = 25;

//const int bootButtonPin = 0;
const int buttonPins[9] = {15, 4, 16, 17, 5, 18, 19, 21, 0};  
bool buttonStates[9];

int selectedStrategy = -1; // Variable to store the selected strategy
bool initialStrategyExecuted = false; // Flag to indicate if the initial strategy has been executed

void Attack()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

 
   analogWrite(enA, 255);
   analogWrite(enB, 255);


}
void Forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

 
   analogWrite(enA, 100);
   analogWrite(enB, 100);


}
void Backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);

} 
void Left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);

} 
void Right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);

} 
void Stop()
{
   digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0); 
}
void Strat1()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 100);
  analogWrite(enB, 255);
}
void Strat2()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 60);
}
void Strat3()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 255);
}
void BackLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 255);
}
void BackRight()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 0);

}
void BackStrat()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 150);

}


void setup() {
  // Initialize Serial communication
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 // pinMode(bootButtonPin, INPUT_PULLUP); 


  // Set up the digital pins for input  
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    // Enable internal pull-up resistors
    //digitalWrite(buttonPins[i], HIGH);
  }
  pinMode(22, INPUT);
  pinMode(23, INPUT);

  // Wait for strategy selection
  waitForStrategy();
}

void loop() {
  // If the initial strategy has been executed, run the default program continuously
  if (initialStrategyExecuted) {
    defaultProgram();
  } else {
    // Perform the selected strategy
    switch (selectedStrategy) {
      case 0:
        strategy0();
        break;
      case 1:
        strategy1();
        break;
      case 2:
        strategy2();
        break;
      case 3:
        strategy3();
        break;
      case 4:
        strategy4();
        break;
      case 5:
        strategy5();
        break;
      case 6:
        strategy6();
        break;
      case 7:
        strategy7();
        break;
      case 8:
        nostrat();
        break;
    }
    // Set the flag to indicate that the initial strategy has been executed
    initialStrategyExecuted = true;
  }
}

void waitForStrategy() {
  // Wait for strategy selection
  Serial.println("Waiting for strategy selection...");
  while (selectedStrategy == -1) {
    // Read the state of each button
    for (int i = 0; i < 9; i++) {
    buttonStates[i] = !digitalRead(buttonPins[i]); 
      // Check if the button is pressed
      if (buttonStates[i]) {
      digitalWrite(2, HIGH);
      selectedStrategy = i;
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.println(" is pressed.");
      break; // Exit the loop if a button is pressed

    }
    }
    delay(100); // Add a small delay to reduce CPU usage
  }
}

void strategy0() {
  // Implement strategy 0 here
  Serial.println("Strategy 0 activated.");
  delay(5000);
  // Your code for strategy 0
  BackRight();
  delay(200);
  //Stop();
  //delay(2000);
  Backward();
  delay(400);
 // Stop();
  //delay(2000);
  Right();
  delay(50);



  // Attack();
  // delay(200);

}

void strategy1() {
  // Implement strategy 1 here
  Serial.println("Strategy 1 activated.");
  delay(5000);
  Right();
  delay(250);
}

void strategy2() {
  // Implement strategy 2 here
  Serial.println("Strategy 2 activated.");
  delay(5000);
  // Your code for strategy 2
  Right();
  delay(100);
}

void strategy3() {
  // Implement strategy 3 here
  Serial.println("Strategy 3 activated.");
  delay(5000);
  // Your code for strategy 3
  Left();
  delay(100);
}

void strategy4() {
  // Implement strategy 4 here
  Serial.println("Strategy 4 activated.");
  delay(5000);
  Right();
  delay(100);
  Strat1();
  delay(800);
  Left();
  delay(250);
  // Your code for strategy 
  }

void strategy5() {
  // Implement strategy 5 here
  Serial.println("Strategy 5 activated.");
  delay(5000);
  Backward();
  delay(300);
  // Your code for strategy 5
}

void strategy6() {
  // Implement strategy 6 here
  Serial.println("Strategy 6 activated.");
  delay(5000);
    Right();
  delay(125);
  Strat1();
  delay(800);
  Left();
  delay(250);
  // Your code for strategy 6
}

void strategy7() {
  // Implement strategy 7 here
  Serial.println("Strategy 7 activated.");
  delay(5000);
  Left();
  delay(100);
  Strat2();
  delay(800);
  Right();
  delay(250);
  // Your code for strategy 7
}
void nostrat() {
  // Implement strategy 7 here
  Serial.println("No strat");
  delay(5000);
}

void defaultProgram() {
  if (digitalRead(23) == LOW || digitalRead(22) == LOW) 
  {
    Serial.println("BACKWARD");
    Backward();
    delay(300);
    Right();
    delay(150);
  }
  else if (analogRead(33) > 800)
  {
    Serial.println("ATTACK");
    Attack();
  }
  else if (analogRead(32) > 800)
  {
    Serial.println("LEFT");
    Left();
  }
  else if (analogRead(34) > 800)
  {
    Serial.println("RIGHT");
    Right();
  }
  else if (analogRead(35) > 800)
  {
    Serial.println("ENEMY BACK");
    Right();
    delay(250);
  }
  else
  {
    Serial.println("ELSE");
    Forward();
  }
}



