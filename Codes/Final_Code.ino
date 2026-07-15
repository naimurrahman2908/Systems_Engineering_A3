// --- Pin Definitions ---
// IR Sensors
const int irLeftPin = 2;
const int irRightPin = 12;

// Ultrasonic Sensors
const int trigLeft = 13;
const int echoLeft = 4;
const int trigRight = 6;
const int echoRight = 7;

// Motor A (Left Motor Control)
const int ena = 3;  // PWM pin for speed
const int in1 = 8;  // Direction pin 1
const int in2 = 9;  // Direction pin 2

// Motor B (Right Motor Control)
const int in3 = 10; // Direction pin 1
const int in4 = 11; // Direction pin 2
const int enb = 5;  // PWM pin for speed

// --- Speed Adjustments ---
const int leftMotorSpeed = 70; 
const int rightMotorSpeed = 79; // Balanced to match left motor's output

// --- Distance Threshold ---
const int obstacleDistance = 24; // 25cm limit

// --- STATE MEMORY ---
// 'F' = Forward, 'L' = Left, 'R' = Right
char lastState = 'F'; 
int obstacleCount = 0; // Initialize to 0 for logical counting

void setup() {
  Serial.begin(9600);

  // Initialize IR Sensors
  pinMode(irLeftPin, INPUT);
  pinMode(irRightPin, INPUT);

  // Initialize Ultrasonic Sensors
  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);
  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);

  // Initialize Motors
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.println("System Initialized (Smart Delay Obstacle Avoidance)...");
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 20000); 
  int distance = duration * 0.034 / 2;
  
  return distance;
}

void secondObstacleAction() {
   motorStop();
        delay(500);
  slowspinLeft();
  delay(200); // Give the robot time to move OFF the current line before checking again
  while (digitalRead(irLeftPin) == 0 && digitalRead(irRightPin) == 0) {
    // Let the motors run until a sensor finds the line
    delay(10); 
  }
}

void loop() {
  // 1. Check for obstacles first
  int distanceLeft = getDistance(trigLeft, echoLeft);
  delay(5);
  int distanceRight = getDistance(trigRight, echoRight);

  // 2. OBSTACLE AVOIDANCE "DETOUR" LOGIC
  if ((distanceLeft > 0 && distanceLeft <= obstacleDistance) || 
      (distanceRight > 0 && distanceRight <= obstacleDistance)) {
    
    motorStop();
    delay(50); // Brief pause to let motors settle (reduces electrical noise)
    
    // Read them one more time to verify
    distanceLeft = getDistance(trigLeft, echoLeft);
    delay(30); 
    distanceRight = getDistance(trigRight, echoRight);
    
    // If it STILL sees the obstacle, execute the detour
    if ((distanceLeft > 0 && distanceLeft <= obstacleDistance) || 
        (distanceRight > 0 && distanceRight <= obstacleDistance)) {
          
      obstacleCount++; // Increment the counter no matter what
      
      if (obstacleCount == 2) {
        // Execute the custom function on the 2nd obstacle
        secondObstacleAction();
        return; // Return to the top of the loop after completing the action
      } else {
        motorStop();
        delay(500); 
        
        DriftLeft();
        delay(600);
        
        DriftRight();
        while (digitalRead(irLeftPin) == 0 && digitalRead(irRightPin) == 0) {
          // Let the motors run until a sensor finds the line
          delay(10); 
        }
        
        // Once the loop breaks, at least one sensor found the line!
        return; 
      } 
    } 
  } // <--- THIS CLOSING BRACE WAS MISSING

  // 3. NORMAL LINE FOLLOWING LOGIC (Runs if no obstacle detected)
  int leftSensor = digitalRead(irLeftPin);
  int rightSensor = digitalRead(irRightPin);

  if (leftSensor == 1 && rightSensor == 1) {
    moveForward();
    lastState = 'F';
  } 
  else if (leftSensor == 1 && rightSensor == 0) {
    turnLeft();
    lastState = 'L'; 
  } 
  else if (leftSensor == 0 && rightSensor == 1) {
    turnRight();
    lastState = 'R'; 
  } 
  else if (leftSensor == 0 && rightSensor == 0) {
    // Completely lost the track! Use memory to find it.
    if (lastState == 'L') {
      spinLeft();  
    } 
    else if (lastState == 'R') {
      spinRight(); 
    } 
    else {
      moveForward(); 
    }
  }

  delay(10); 
}

// --- Motor Movement Functions ---
void moveForward() {
  analogWrite(ena, leftMotorSpeed);
  analogWrite(enb, rightMotorSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void slowmoveForward() {
  analogWrite(ena, 70);
  analogWrite(enb, 80);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void superslowmoveForward() {
  analogWrite(ena, 74);
  analogWrite(enb, 78);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  analogWrite(ena, 89);
  analogWrite(enb, 60);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  analogWrite(ena, 60); 
  analogWrite(enb, 81);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void spinRight() {
  analogWrite(ena, 85);
  analogWrite(enb, 94); 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void spinLeft() {
  analogWrite(ena, 85);
  analogWrite(enb, 94); 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void slowspinLeft() {
  analogWrite(ena, 68);
  analogWrite(enb, 70); 
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

void DriftLeft() {
  analogWrite(ena, 60);
  analogWrite(enb, 95);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void DriftRight() {
  analogWrite(ena, 75);
  analogWrite(enb, 50);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
