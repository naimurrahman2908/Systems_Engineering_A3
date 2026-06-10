// --- Pin Definitions ---
// IR Sensors
const int irLeftPin = 2;
const int irRightPin = 12;

// Motor A (Left Motor Control)
const int ena = 3;  // PWM pin for speed
const int in1 = 8;  // Direction pin 1
const int in2 = 9;  // Direction pin 2

// Motor B (Right Motor Control)
const int in3 = 10;  // Direction pin 1
const int in4 = 11;  // Direction pin 2
const int enb = 5;  // PWM pin for speed

// Adjust speed here (0 is stopped, 255 is full power)
const int motorSpeed = 130; 

// --- STATE MEMORY ---
// 'F' = Forward, 'L' = Left, 'R' = Right
char lastState = 'F'; 

void setup() {
  Serial.begin(9600);

  pinMode(irLeftPin, INPUT_PULLUP);
  pinMode(irRightPin, INPUT_PULLUP);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.println("Line Follower System Initialized...");
}

void loop() {
  // Read the sensors (Assuming 0 = Line detected, 1 = Background clear)
  int leftSensor = digitalRead(irLeftPin);
  int rightSensor = digitalRead(irRightPin);

  // --- Decision Logic ---
  
  if (leftSensor == 1 && rightSensor == 1) {
    // Both sensors on the line (e.g., at an intersection)
    moveForward();
    lastState = 'F';
  } 
  else if (leftSensor == 1 && rightSensor == 0) {
    // Left sensor is on the line -> Drifted right, steer LEFT
    turnLeft();
    lastState = 'L'; // Remember the line was last seen on the left
  } 
  else if (leftSensor == 0 && rightSensor == 1) {
    // Right sensor is on the line -> Drifted left, steer RIGHT
    turnRight();
    lastState = 'R'; // Remember the line was last seen on the right
  } 
  else if (leftSensor == 0 && rightSensor == 0) {
    // Both sensors lost the line,completly out of track
    if (lastState == 'L') {
      spinLeft();  // Aggressively turn left
    } 
    else if (lastState == 'R') {
      spinRight(); // Aggressively turn right
    } 
    else {
      moveForward(); // If it hasn't seen a line yet, just inch forward
    }
  }

  // A tiny delay for stabillity
  delay(10); 
}

// --- Motor Movement Functions ---

void moveForward() {
  // motors are not same power
  analogWrite(enb, 130);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  // Sweeping turn for smooth path following
  analogWrite(ena, 130);
  analogWrite(enb, 130);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  // Sweeping turn for smooth path following
  analogWrite(ena, 90);
  analogWrite(enb, 130);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// 360 turn

void spinRight() {
  // Hard pivot right: Left motor forward, Right motor backward
  analogWrite(ena, 120);
  analogWrite(enb, 120);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void spinLeft() {
  // Hard pivot left: Left motor backward, Right motor forward
  analogWrite(ena, 120);
  analogWrite(enb, 120);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void motorStop() {
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
