// This code is for testing the prototype of the robot arm

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       650 // min pos of the servo, 0
#define MAX_PULSE_WIDTH       2350 // max pos of the servo, 270 or 180 (depends on the motor)
#define FREQUENCY             50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // Initialize the PWM Servo Driver

// - Variable Declerations - //

// Potentiometer Inputs
int potL1Pin = A0;
int potL2Pin = A1;
int potL3Pin = A2;
int potL4Pin = A3;

// Servo Inputs
int servoL1Pin = 15;
int servoL2Pin = 14;
int servoL3Pin = 13;
int servoL4Pin = 12;

// End Effector Input, Output and State
int buttonPin = 8;
String state = "";

void setup() {
  Serial.begin(9600); // Starts Serial Monitor for Debugging
  pinMode(buttonPin, INPUT); // Initialize button

  // Starts PWM
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

// --- Main Program --- //
void loop() {
  // Reads Potentiometer Angles + Button State | ONLY USE FOR DEBUGGING, DO NOT MAKE ACTIVE UNLESS YOU WANT SIGNIFICANT DELAYS WITH THE MOVEMENT OF THE PROTOTYPE |
  //CurrentAngle(potL1Pin);
  //CurrentAngle(potL2Pin);
  //CurrentAngle(potL3Pin);
  //CurrentAngle(potL4Pin);
  //ButtonState();

  // Moves Actuators
  moveActuator(potL1Pin, servoL1Pin);
}

void moveActuator(int controlIn, int actuatorOut){
  int potVal = analogRead(controlIn);
  int angle = map(potVal, 800, 240, 0, 180); // map to 0-180 degrees
  int pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH); // scale pulse width for 0-180°
  int pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  pwm.setPWM(actuatorOut, 0, pulse_width);
}

void ButtonState(){
  int buttonVal = digitalRead(buttonPin); // Stores button input
  String state; // current button state

  if (buttonVal == HIGH){
    state = "On";
  } else if (buttonVal == LOW){
    state = "Off";
  }
  Serial.print("Button State: ");
  Serial.println(state);
  Serial.println("-----------------");
}

void CurrentAngle(int potIn){
  int potVal = analogRead(potIn); // Stores pot input
  int degrees = map(potVal, 0, 1023, 0, 180); // maps to 180 degrees

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


