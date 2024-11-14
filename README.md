Robotic Arm Controlled by Bluetooth and MPU6050 Sensor
This project is a robotic arm controlled via Bluetooth and gesture detection using an MPU6050 accelerometer and gyroscope sensor. The robotic arm's joints (base, shoulder, elbow, and gripper) are operated by servo motors, and an RGB LED provides visual feedback on the arm's position.

Table of Contents
Features
Components Required
Circuit Setup
Code Explanation
How to Use
Future Improvements
Features
Bluetooth Control: Operate the gripper and reset position via Bluetooth commands.
Gesture-Based Movement: The MPU6050 sensor interprets hand gestures to control the arm's base, shoulder, and elbow.
Visual Feedback: An RGB LED changes colors based on the arm's orientation to indicate the arm's state.
Reset Position: A command to reset all servos to a default position.
Components Required
Arduino Board (e.g., Arduino Uno or Mega)
Bluetooth Module (HC-05 or HC-06)
MPU6050 Accelerometer and Gyroscope Sensor
Servos (4x, for base, shoulder, elbow, and gripper)
RGB LED (with individual Red, Green, and Blue pins)
Resistors (for LED, optional)
Connecting Wires
Power Supply
Circuit Setup
Bluetooth Module:

Connect VCC to 5V and GND to GND on the Arduino.
Connect TX on Bluetooth to Arduino RX (pin 10), and RX on Bluetooth to Arduino TX (pin 11).
MPU6050 Sensor:

Connect VCC to 5V and GND to GND on the Arduino.
Connect SCL to A5 (for Uno) or SCL on other boards.
Connect SDA to A4 (for Uno) or SDA on other boards.
Servos:

Base Servo connected to pin 3
Shoulder Servo connected to pin 4
Elbow Servo connected to pin 5
Gripper Servo connected to pin 6
Ensure servos share a common GND with the Arduino.
RGB LED:

Connect Red, Green, and Blue pins to Arduino pins 6, 5, and 3, respectively, with appropriate resistors if necessary.
Code Explanation
The code performs the following functions:

Bluetooth Commands:

The Arduino listens for Bluetooth commands to open (O) or close (C) the gripper or reset (R) the arm position.
Gesture-Based Movement:

The MPU6050 sensor reads the X, Y, and Z acceleration values to map the movement of the base, shoulder, and elbow servos.
Servo angles are mapped to a range that keeps the robotic arm movements stable.
RGB LED Feedback:

The LED provides visual feedback based on the arm’s orientation:
Red: Arm tilted to the left.
Blue: Arm tilted to the right.
Green: Arm in the central position.
How to Use
Upload the Code:

Upload the provided Arduino code to your board.
Connect Bluetooth:

Pair the Bluetooth module with your phone or another Bluetooth device.
Use a Bluetooth terminal app to send commands:
"O": Open the gripper.
"C": Close the gripper.
"R": Reset all servos to the default position.
Gesture Control:

Move the MPU6050 sensor to control the arm’s base, shoulder, and elbow. The accelerometer values adjust the servos, allowing you to control the arm’s orientation based on tilt and position.
Future Improvements
Add a Gyroscope for more precise movement tracking.
Fine-Tune Bluetooth Commands for additional control options like speed adjustments.
Enhance Visual Feedback by adding more RGB LED patterns for different states.
Integrate a Distance Sensor to avoid obstacles in the arm’s path.
