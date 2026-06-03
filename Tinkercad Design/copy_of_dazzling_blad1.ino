// --- PIN DEFINITIONS ---

// Master ON/OFF Switch
const int SWITCH_PIN = A0;

// IR Sensors (Line Following)
const int TOP_IR_PIN = 13;    // Left/Top IR Sensor
const int BOTTOM_IR_PIN = 2;  // Right/Bottom IR Sensor

// Top Ultrasonic Sensor
const int TOP_TRIG_PIN = 11;
const int TOP_ECHO_PIN = 12;

// Bottom Ultrasonic Sensor
const int BOTTOM_TRIG_PIN = 7;
const int BOTTOM_ECHO_PIN = 8;

// L293D Motor Driver Signals
const int ENABLE_12_PIN = 9;   // Left Motor Enable (Controls the bottom motor)
const int INPUT1_PIN = 3;      // Bottom Motor (Output 1)
const int INPUT2_PIN = 4;      // Bottom Motor (Output 2)
const int INPUT3_PIN = 5;      // Top Motor (Output 3)
const int INPUT4_PIN = 6;      // Top Motor (Output 4)
const int ENABLE_34_PIN = 10;  // Right Motor Enable (Controls the top motor)

// --- CONSTANTS ---
const int OBSTACLE_THRESHOLD = 20; // Stop distance in centimeters

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);

  // Configure Switch and IR Sensor Pins
  pinMode(SWITCH_PIN, INPUT);
  pinMode(TOP_IR_PIN, INPUT);
  pinMode(BOTTOM_IR_PIN, INPUT);

  // Configure Ultrasonic Pins
  pinMode(TOP_TRIG_PIN, OUTPUT);
  pinMode(TOP_ECHO_PIN, INPUT);
  pinMode(BOTTOM_TRIG_PIN, OUTPUT);
  pinMode(BOTTOM_ECHO_PIN, INPUT);

  // Configure Motor Driver Control Pins
  pinMode(INPUT1_PIN, OUTPUT);
  pinMode(INPUT2_PIN, OUTPUT);
  pinMode(INPUT3_PIN, OUTPUT);
  pinMode(INPUT4_PIN, OUTPUT);
  
  // Configure and activate both H-Bridge Enable channels
  pinMode(ENABLE_12_PIN, OUTPUT);
  pinMode(ENABLE_34_PIN, OUTPUT);
  digitalWrite(ENABLE_12_PIN, HIGH); // Power up bottom motor channel
  digitalWrite(ENABLE_34_PIN, HIGH); // Power up top motor channel
}

void loop() {
  // 1. Check Master Switch Status
  int switchState = digitalRead(SWITCH_PIN);
  
  if (switchState == LOW) {
    // If master switch is OFF, completely halt vehicle operations
    stopMotors();
    Serial.println("System OFF - Switch to ON to start.");
    delay(200); 
    return; // Skip the rest of the loop
  }

  // 2. Measure Distances from Ultrasonic Sensors
  long topDistance = getDistance(TOP_TRIG_PIN, TOP_ECHO_PIN);
  long bottomDistance = getDistance(BOTTOM_TRIG_PIN, BOTTOM_ECHO_PIN);

  // 3. Obstacle Avoidance Logic (Safety Priority)
  if (topDistance < OBSTACLE_THRESHOLD || bottomDistance < OBSTACLE_THRESHOLD) {
    stopMotors();
    Serial.println("OBSTACLE DETECTED! Braking system engaged.");
    delay(100);
    return; // Override line following until path is clear
  }

  // 4. Line Following Logic
  int topIR = digitalRead(TOP_IR_PIN);       // Reads HIGH if tracking line
  int bottomIR = digitalRead(BOTTOM_IR_PIN); // Reads HIGH if tracking line

  if (topIR == HIGH && bottomIR == HIGH) {
    moveForward();
    Serial.println("Path clear: Moving Forward.");
  } 
  else if (topIR == LOW && bottomIR == HIGH) {
    turnRight();
    Serial.println("Deviation detected: Adjusting Right.");
  } 
  else if (topIR == HIGH && bottomIR == LOW) {
    turnLeft();
    Serial.println("Deviation detected: Adjusting Left.");
  } 
  else {
    // Both sensors off the line
    stopMotors();
    Serial.println("Line lost: Stopped.");
  }

  delay(50); // Small stability delay for Tinkercad solver
}

// --- ROBOT MOVEMENT FUNCTIONS ---

void moveForward() {
  digitalWrite(INPUT1_PIN, HIGH);
  digitalWrite(INPUT2_PIN, LOW);
  digitalWrite(INPUT3_PIN, HIGH);
  digitalWrite(INPUT4_PIN, LOW);
}

void turnLeft() {
  // Pivot left: stop left (bottom) motor, drive right (top) motor forward
  digitalWrite(INPUT1_PIN, LOW);
  digitalWrite(INPUT2_PIN, LOW);
  digitalWrite(INPUT3_PIN, HIGH);
  digitalWrite(INPUT4_PIN, LOW);
}

void turnRight() {
  // Pivot right: drive left (bottom) motor forward, stop right (top) motor
  digitalWrite(INPUT1_PIN, HIGH);
  digitalWrite(INPUT2_PIN, LOW);
  digitalWrite(INPUT3_PIN, LOW);
  digitalWrite(INPUT4_PIN, LOW);
}

void stopMotors() {
  digitalWrite(INPUT1_PIN, LOW);
  digitalWrite(INPUT2_PIN, LOW);
  digitalWrite(INPUT3_PIN, LOW);
  digitalWrite(INPUT4_PIN, LOW);
}

// --- ULTRASONIC DISTANCE SENSOR FUNCTION ---
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return 999;                 // Return safe distance if timeout occurs
  
  // Convert flight duration to centimeters
  return duration * 0.034 / 2;
}