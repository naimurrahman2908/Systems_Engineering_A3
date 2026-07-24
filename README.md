# 🤖 Line Following and Obstacle Avoidance Robot

![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-C++-orange)
![Documentation](https://img.shields.io/badge/Documentation-LaTeX-green)
![License](https://img.shields.io/badge/Project-Academic-lightgrey)

---

## 📖 Project Overview

This repository contains the design, implementation, modelling, and testing of an autonomous **Line Following and Obstacle Avoidance Robot** developed as part of the **Systems Engineering** course at **Hochschule Hamm-Lippstadt (HSHL)**.

The robot autonomously follows a predefined black line using infrared (IR) sensors while detecting obstacles with ultrasonic sensors. The project combines embedded software, hardware integration, SysML modelling, and automated technical documentation using LaTeX.

---

## 👥 Team Members

| Member | Responsibility |
|---------|----------------|
| **Naimur Rahman** | Introduction and Objectives |
| **Hany Chowdhury** | System Design and Engineering Approach |
| **Torikul Islam** | Hardware & Software Implementation, Simulation & Testing |
| **Adham Elsaygh** | Challenges and Solutions |

---

# 🎯 Project Objectives

The objectives of this project are to:

- Design an autonomous mobile robot capable of following a black line.
- Detect and avoid obstacles during navigation.
- Reacquire the line after obstacle avoidance.
- Perform an automatic 180° turn after detecting the second obstacle.
- Apply Systems Engineering principles throughout development.
- Model the complete system using SysML.
- Validate the final prototype through experimental testing.

---

# ⭐ Features

- Autonomous Line Following
- Obstacle Detection
- Obstacle Avoidance
- Automatic Line Reacquisition
- 180° Turnaround
- PWM Motor Speed Control
- Embedded Arduino Software
- SysML-Based System Design
- Automated LaTeX Report Generation

---

# 🏗 System Architecture

The robot consists of four major subsystems.

| Subsystem | Components | Function |
|------------|------------|----------|
| Sensing | IR Sensors, Ultrasonic Sensors | Detects the line and obstacles |
| Control | Arduino Uno | Processes sensor data |
| Actuation | L293D Driver, DC Motors | Controls movement |
| Power | 12V Battery | Powers the robot |

---

# 🔧 Hardware Components

- Arduino Uno
- 2 × IR Line Sensors
- 2 × HC-SR04 Ultrasonic Sensors
- L293D Motor Driver
- 2 × DC Geared Motors
- Breadboard
- Wooden Chassis
- 12 V Battery
- Wheels

---

# 🔌 Wiring Connections

## 🔵 Arduino UNO Pin Configuration

| Component | Arduino Pin | Description |
|-----------|-------------|-------------|
| Left IR Sensor | D2 | Left line detection |
| Right IR Sensor | D12 | Right line detection |
| Left Ultrasonic Trigger | D13 | Trigger signal |
| Left Ultrasonic Echo | D4 | Echo signal |
| Right Ultrasonic Trigger | D6 | Trigger signal |
| Right Ultrasonic Echo | D7 | Echo signal |
| Left Motor Enable (ENA) | D3 (PWM) | Speed control |
| Left Motor IN1 | D8 | Motor direction |
| Left Motor IN2 | D9 | Motor direction |
| Right Motor Enable (ENB) | D5 (PWM) | Speed control |
| Right Motor IN3 | D10 | Motor direction |
| Right Motor IN4 | D11 | Motor direction |

---

## ⚡ Power Connections

| Connection | Description |
|------------|-------------|
| 12 V Battery → Motor Driver | Main power supply |
| Motor Driver 5 V → Arduino UNO | Regulated controller power |
| Arduino 5 V → Sensors | Sensor power supply |
| Common Ground | Shared by all components |

> **Important:** All electronic modules share a common ground to ensure stable operation.

---

# 💻 Software Components

- Arduino IDE
- Embedded C++
- Line Following Algorithm
- Obstacle Detection Algorithm
- Obstacle Avoidance Routine
- Line Reacquisition Logic
- Motor Control Functions

---

# 🔄 Robot Operation

The robot operates according to the following sequence:

1. Detect the black line using IR sensors.
2. Read sensor values.
3. Calculate steering direction.
4. Control both motors independently.
5. Continuously monitor obstacles.
6. Detect the first obstacle.
7. Execute obstacle avoidance.
8. Search for and reacquire the line.
9. Continue navigation.
10. Detect the second obstacle.
11. Perform a 180° turn.
12. Continue autonomous operation.

---

# 📊 SysML Models

The project documentation includes:

- Block Definition Diagram (BDD)
- Internal Block Diagram (IBD)
- Use Case Diagram
- Activity Diagram
- Sequence Diagram
- State Machine Diagram
- Package Diagram

---

# 🧪 Testing

The robot was experimentally evaluated using a custom test track with a **2.5 cm black line**, including gentle and sharp curves as well as two obstacles.

### Testing Included

- IR Sensor Validation
- Ultrasonic Sensor Validation
- Motor Verification
- Line Following
- Sharp Curve Tracking
- Gentle Curve Tracking
- Obstacle Avoidance
- Line Reacquisition
- 180° Turn
- Full System Integration

---

## 📈 Performance Summary

| Test | Result |
|------|--------|
| Line Following | ✅ Successful |
| Gentle Curves | ✅ Successful |
| Sharp Curves | ✅ Successful |
| First Obstacle Detection | ✅ Successful |
| Obstacle Avoidance | ✅ Successful |
| Line Reacquisition | ✅ Successful |
| Second Obstacle Detection | ✅ Successful |
| 180° Turn | ✅ Successful |
| Complete Trials | **10 / 10** |
| Overall Success Rate | **100%** |

---

# 🛠 Technologies Used

- Arduino IDE
- C++
- GitHub
- GitHub Actions
- LaTeX (IEEE Format)
- SysML
- Visual Paradigm
- Tinkercad

---

# 📁 Repository Structure

```text
Systems_Engineering_A3/
│
├── Codes/
│
├── Prototype_Design/
│
├── SysML_Diagrams/
│
├── Tinkercad_Design/
│
└── LineFollowingRobot_Report/
    ├── figures/
    ├── sections/
    ├── main.tex
    └── report.pdf
```

---

# 📄 Report Compilation

The project documentation is written in **LaTeX** using the IEEE Conference format.

GitHub Actions automatically:

- Builds the report
- Compiles the PDF
- Commits the latest report
- Keeps documentation up to date

---

# 📚 Latest Report

The latest IEEE report is available below.

➡️ **[Download PDF Report](./LineFollowingRobot_Report/report.pdf)**

---

# 🚀 Future Improvements

Potential future enhancements include:

- PID Controller
- Wireless Communication
- Bluetooth Monitoring
- Wi-Fi Connectivity
- Camera-Based Navigation
- Machine Learning
- Real-Time Telemetry
- Improved Chassis Design
- Battery Monitoring

---

# 🎓 Course Information

| Item | Details |
|------|---------|
| Course | Systems Engineering |
| Degree | Electronic Engineering |
| University | Hochschule Hamm-Lippstadt |
| Semester | Summer Semester 2026 |

---

# 📜 License

This repository was developed for academic purposes as part of the **Systems Engineering** course at **Hochschule Hamm-Lippstadt**.
