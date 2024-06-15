/*
    Project name : Ultrasonic Sensor
    Modified Date: 15-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-ultrasonic-sensor
*/

// Define pin numbers for the ultrasonic sensor
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT); // Set echo pin as input
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by sending a 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters (assumes speed of sound is 343 m/s)
  float distance_cm = (duration / 2) * 0.0343;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  delay(1000); // Add a small delay before the next reading
}
