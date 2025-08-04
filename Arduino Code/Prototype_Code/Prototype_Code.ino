// This code is for testing the prototype of the 4DOF robot arm

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// SERVO OFFSET
#define MIN 1125 // min pos of the DS3240 servo, 0
#define MAX 2700 // max pos of the DS3240 servo, 180
#define L1MIN 750 // min pos of the Ds3240 servo, 0~
#define L1MAX 3250 // max pos of the DS3240 servo, 270~
#define FREQUENCY 50


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

void setup() {
  Serial.begin(9600); // Starts Serial Monitor for Debugging
  pinMode(buttonPin, INPUT); // Initialize button

  // Starts PWM
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

// --- Main Program --- //
void loop() {
  moveBase(potL1Pin, servoL1Pin);
  moveActuator(potL2Pin, servoL2Pin);
  moveActuator(potL3Pin, servoL3Pin);
  moveActuator(potL4Pin, servoL4Pin);
  gripperState();
}

void moveBase(int potIn, int servoOut){
  int potVal = analogRead(potIn); // Reads and stores pot value
  potVal = map(potVal, 0, 1023, 0, 270);
  // Maps pot position to servo
  int pulse_wide = map(potVal, 0, 270, L1MIN, L1MAX);
  int pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);

  pwm.setPWM(servoOut, 0, pulse_width);
}

void moveActuator(int potIn, int servoOut){
  int potVal = analogRead(potIn); // Reads and stores pot value
  potVal = map(potVal, 0, 1023, 0, 270);
  // Maps pot position to servo
  int pulse_wide = map(potVal, 0, 270, MIN, MAX);
  int pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);

  pwm.setPWM(servoOut, 0, pulse_width);
}

void gripperState(){
  int buttonVal = digitalRead(buttonPin); // Stores button info
  String state;
  if (buttonVal == HIGH){
    // Insert open gripper function
    state = "On";
    Serial.println(state);
  }else if (buttonVal == LOW){
    // Inser close gripper function
    state = "Off";
    Serial.println(state);
  }
}

