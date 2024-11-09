# Password-based Lock System Using Arduino

## Overview
This project simulates a secure, password-protected locking system using an Arduino microcontroller. The system utilizes a 4x4 keypad for password entry, a servo motor for lock actuation, an LCD display for feedback, and a buzzer for audio notifications. It provides reliable access control by verifying passwords against a stored value, unlocking the servo upon successful authentication.

## Table of Contents
- [Features](#features)
- [Components Used](#components-used)
- [Circuit Diagram](#circuit-diagram)
- [Code](#code)
- [Tinkercad Model](#tinkercad-model)
- [Future Enhancements](#future-enhancements)
- [Applications](#applications)
- [Contact](#contact)
- [References](#references)

## Features
- **Password Authentication**: Secure access using a pre-set password; displays "Access Granted" upon correct entry.
- **Manual and Auto-Lock**: Users can re-lock the system manually, or it can lock automatically after access.
- **Incorrect Password Handling**: Displays "Access Denied" on incorrect password entry, with a lockout feature after 5 failed attempts.
- **Buzzer Notifications**: Sound feedback on password entry success or failure.

## Components Used
- **Arduino UNO**: Microcontroller for controlling system operations.
- **Keypad (4x4)**: Interface for user password entry.
- **Servo Motor**: Controls the physical lock mechanism.
- **LCD Display (16x2)**: Provides system status and prompts.
- **Buzzer**: Alerts user of successful or unsuccessful access attempts.

## Circuit Diagram
Refer to the attached circuit diagram for wiring details, including connections between the Arduino, keypad, servo, LCD, and buzzer.

## Code
The code for this project is in the `mpmc_project_code.ino` file. It includes:
- Initialization of components.
- Password input and verification logic.
- Servo motor control for locking and unlocking.
- Feedback display and sound cues.

## Tinkercad Model
[View the working model on Tinkercad]((https://www.tinkercad.com/things/c1TV7XWGPtN-password-based-lock-system-using-arduino?sharecode=BAOVYjgSVy7Q-7IYpapEbHUVDGulkOeWNhRU7VrGPME)

## Future Enhancements
- **Biometric Integration**: Adding fingerprint or facial recognition.
- **Remote Access**: IoT functionality for remote control via a mobile app.
- **Multi-user Management**: Different access codes for various users.
- **Power Backup**: Battery integration for operation during power outages.

## Applications
- **Home Security**: Secure access to safes or doors.
- **Office Security**: Controlled entry to restricted rooms or storage.
- **Industrial Security**: Access control for warehouses or equipment rooms.

## Contact
skygriffin20.contact@gmail.com

## References
- [How2Electronics](https://how2electronics.com/password-based-security-system-arduino-keypad/)
- [YouTube - svsembedded](https://youtu.be/0LUMOex8zSk?si=zI8aL4m6F0YZxNI7)
