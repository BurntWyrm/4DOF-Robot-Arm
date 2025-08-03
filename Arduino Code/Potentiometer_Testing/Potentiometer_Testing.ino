// Code for testing potentiometers

/// Variable Declerations

// Potentiometer Inputs
int potA0Pin = A5;

// Potentiometer Value Storage
int potA0Val = 0;

void setup() {
 Serial.begin(9600); // Starts Serial Monitor 
}

// Main Program
void loop() {
  potA0Val = analogRead(potA0Pin); // Stores Potentiometer Input

  // Prints Current Input in Real Time
  Serial.print("Current Value: ");
  Serial.println(potA0Val);

  int potA0ValMapped = map(potA0Val, 0, 1023, 0, 180); // Converts the reading from the potentiometer to an output value a servo can understand

  // Prints Mapped pot input
  Serial.print("Mapped Value: ");
  Serial.print(potA0ValMapped);
  Serial.println(" Degrees");

  delay(100);
}
 