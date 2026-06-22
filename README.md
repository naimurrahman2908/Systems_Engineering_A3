# Line Following Robot Prototype

## Project Overview

This project presents the design and development of a Line Following Robot Prototype as part of the Systems Engineering course at Hochschule Hamm-Lippstadt.

The robot is designed to autonomously follow a predefined path using infrared (IR) sensors while detecting obstacles using ultrasonic sensors. The system integrates hardware components, embedded software, system modeling techniques, and simulation-based validation.

---

## Team Members

- Naimur Rahman
- Hany Chowdhury
- Torikul Islam
- Adham Elsaygh

---

## Project Objectives

The main objectives of this project are:

- Design an autonomous line-following robot
- Detect and avoid obstacles during navigation
- Apply systems engineering principles throughout development
- Create SysML models for system analysis and design
- Validate system behavior through simulation and testing

---

## System Architecture

The robot consists of the following major subsystems:

### Hardware Components

- Arduino Uno
- IR Line Sensors
- Ultrasonic Sensors
- L293D Motor Driver
- DC Motors
- Battery Pack
- Chassis and Wheels

### Software Components

- Arduino Embedded Program
- Sensor Processing Logic
- Line Following Algorithm
- Obstacle Detection Algorithm
- Motor Control Logic

---

## Repository Structure

```text

Systems_Engineering_A3/

│

├── Codes/

├── Prototype_Design/

├── SysML_Diagrams/

├── Tinkercad_Design/

│

└── LineFollowingRobot_Report/

    ├── figures/

    ├── sections/

    ├── main.tex

    └── report.pdf

```

---

## SysML Models

The project documentation includes:

- Block Definition Diagram (BDD)
- Internal Block Diagram (IBD)
- Use Case Diagram
- Sequence Diagram
- Package Diagram
- Activity Diagram
- State Machine Diagram

---

## Robot Operation

1. IR sensors continuously detect the line position.
2. Arduino processes sensor data.
3. Motor driver adjusts wheel speeds.
4. Ultrasonic sensors monitor obstacles.
5. The robot follows the path while maintaining safe operation.

---

## Simulation and Testing

The system was tested through:

- Sensor validation
- Motor control verification
- Line tracking experiments
- Obstacle detection experiments
- System integration testing

Results demonstrate reliable line-following performance and successful obstacle detection under normal operating conditions.

---

## Technologies Used

- Arduino IDE
- GitHub
- LaTeX (IEEE Format)
- SysML
- Visual Paradigm
- Tinkercad

---

## Report Compilation

The project report is written in LaTeX and automatically compiled using GitHub Actions.

Every push to the repository automatically:

1. Builds the LaTeX report
2. Generates the PDF
3. Updates the latest report.pdf file

---

### Latest Report

[Download PDF Report](LineFollowingRobot_Report/report.pdf)


## Future Improvements

Potential enhancements include:

- PID-based line tracking
- Wireless communication
- Improved obstacle avoidance
- Machine learning-based navigation
- Real-time telemetry monitoring

---

## Course Information

**Course:** Systems Engineering  
**Program:** Electronic Engineering  
**University:** Hochschule Hamm-Lippstadt (HSHL)  
**Semester:** Summer Semester 2026

---
