# Gas Detection System

This project is a gas detection system using an ESP8266 microcontroller. 
It monitors gas levels using a gas sensor and sends alerts through Blynk and email if dangerous levels are detected.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Respository Structure](#respository-structure)

## Introduction
The Gas Detection System is designed to detect gas leaks and alert users through both the Blynk app and email notifications.
It uses an ESP8266 microcontroller to read values from a gas sensor and triggers an alert if the gas concentration exceeds a predefined threshold.

## Features
- Real-time gas level monitoring
- Visual and auditory alerts using LEDs and a buzzer
- Remote monitoring and control via Blynk app
- Email notifications for high gas levels

## Hardware Requirements
- ESP8266 microcontroller
- Gas sensor (e.g., MQ-2, MQ-135)
- Buzzer
- LEDs (Green and Red)
- Resistors
- Breadboard and jumper wires
- WiFi network

## Software Requirements
- Arduino IDE
- Blynk app
- Python 3.x (for email notifications)

## Installation
### Hardware Setup
1. Connect the gas sensor to the ESP8266:
   - Sensor Analog Pin to A0 of ESP8266
   - VCC to 3.3V
   - GND to GND
2. Connect the Green LED to pin D8 and the Red LED to pin D6.
3. Connect the Buzzer to pin D5.

### Software Setup
1. Clone this repository:
   ```bash
   git clone https://github.com/your_username/gas-detection-system.git

2. Open Gas_Monitoring_System.ino in Arduino IDE.
3. In Gas_Monitoring_Syatem.ino file replace the first 3 lines from Blynk App Configurations.
4. Replace auth, ssid, and pass with your Blynk authentication token, WiFi SSID, and password.
5. Upload the code to your ESP8266.
   
### Email Notification Setup
1. Open alert.py.
2. Replace the email configuration placeholders with your actual email details.
3. Ensure the necessary Python libraries are installed:
    pip install requests smtplib
   
### Usage
1. Power the ESP8266 and gas sensor setup.
2. Open the Blynk app and connect to your device using the authentication token.
3. Monitor the gas levels in real-time using the Blynk app.
4. If gas levels exceed the threshold, the system will trigger visual and auditory alerts and send an email notification.
Contributing
Contributions are welcome! Please open an issue or submit a pull request for any changes.

### Repository Structure
gas-detection-system/
├── Gas_Monitoring_System/
   ├── Gas_Monitoring_System.ino
├── alert.py
└── README.md
