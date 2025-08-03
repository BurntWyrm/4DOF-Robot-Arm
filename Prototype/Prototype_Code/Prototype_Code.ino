#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Code For Prototype Robot Arm 

// Potentiometer Analog Pins
int potBase = A0;
int potShoulder = A1;
int potElbow = A2;
int potWrist = A3; 

// Potentiometer Value Storage
int potBaseVal = 0;
int potShoulderVal = 0;
int potElbowVal = 0;
int potWristVal = 0;

void setup() {
  Serial.begin(9600);
}


// Main
void loop() {
  // Reads potentiometer value at the input pin
potBaseVal = analogRead(potBase);
potShoulderVal = analogRead(potShoulder);
potElbowVal = analogRead(potElbow);
potWristVal = analogRead(potWrist);

//Serial.print("Base: ");
//Serial.println(potBaseVal);

Serial.print("Shoulder: ");
Serial.println(potShoulderVal);

//Serial.print("Elbow: ");
//Serial.println(potElbowVal);

//Serial.print("Wrist: ");
//Serial.println(potWristVal);
delay(1000);
}
