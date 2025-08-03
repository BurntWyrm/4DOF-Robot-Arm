// This code is for testing the controller potentiometers

// Variable Declarations

// End Effector Input, Output and State
int buttonPin = 13;
int buttonVal = 0;
String state = "";

// Potentiometer Inputs
int potL1Pin = A0;
int potL2Pin = A1;
int potL3Pin = A2;
int potL4Pin = A3;

// Setup
void setup() {
  // Starts Serial Monitor
  Serial.begin(9600);
  // Initializes button pin as Input
  pinMode(buttonPin, INPUT);
}

// Main Program
void loop() {
  // Reads potentiometer angle
  PotAngle(potL1Pin);
  PotAngle(potL2Pin);
  PotAngle(potL3Pin);
  PotAngle(potL4Pin);
  ButtonState();
}

// End Effector State Reader
void ButtonState(){
  // Stores button state
  buttonVal = digitalRead(buttonPin);

  //
  if (buttonVal == HIGH){
    state = "On";
  }
  else if (buttonVal == LOW){
    state = "Off";
  }
  Serial.print("Button State: ");
  Serial.println(state);
  Serial.println("-----------------");
}

// PotAngle Reader
void PotAngle(int potIn){
  int potVal = analogRead(potIn);
  int degrees = map(potVal, 0, 1023, 0, 180);

  String potName;
  switch(potIn){
    case A0: potName = "Joint L1"; break;
    case A1: potName = "Joint L2"; break;
    case A2: potName = "Joint L3"; break;
    case A3: potName = "Joint L4"; break;
    default: potName = "Unknown Pot";
  }

    Serial.print(potName);
    Serial.print(": ");
    Serial.print(degrees);
    Serial.println(" Degrees");
    Serial.println("-----------------");
    delay(500);
}