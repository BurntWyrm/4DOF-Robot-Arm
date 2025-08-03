#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

// This code is for testing the PCA9865 Servo and DS3240 Servos

// Variable Declerations
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600
#define USMIN 600 // Position 0
#define USMAX 2350 // Position 180
#define SERVO_FREQ 50

int pulse_width;

// Motor pins
int servoPin = 15;

// Pot pins
int potPin = A0;

void setup(){
  
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  
}

void loop(){
  moveMotor(potPin, servoPin);
}
 
void moveMotor(int controlIn, int motorOut)
{
  int potVal = analogRead(controlIn);                       // Read potentiometer value (0–1023)
  int degrees = map(potVal, 0, 1023, 0, 180);               // Map to 0–180 degrees
  int pulse_wide = map(degrees, 0, 180, USMIN, USMAX);      // Convert degrees to microseconds
  int pulse_width = int(float(pulse_wide) / 1000000 * SERVO_FREQ * 4096); // Convert to PWM steps

  pwm.setPWM(motorOut, 0, pulse_width);
}
