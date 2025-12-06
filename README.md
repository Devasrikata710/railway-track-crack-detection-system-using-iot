# railway-track-crack-detection-system-using-iot
🚆 TrackSafe — Smart Railway Track Crack Detection System

A compact, automated railway inspection system built using Arduino to detect cracks, gaps, and obstacles on railway tracks—helping prevent derailments and enabling faster maintenance.

✨ Project Overview

TrackSafe is designed to:
Detect cracks or misalignments on railway tracks.
Stop when an obstacle is detected and resume when cleared.
Send GPS-based alerts when cracks are found.Provide real-time monitoring via Bluetooth.
The system moves along the tracks autonomously before a train arrives, ensuring safe and efficient inspection.

🧠 How It Works:
The device is placed on the track and starts moving automatically.Ultrasonic Sensor detects obstacles → stops movement until path is clear.IR Sensor checks for cracks or gaps in the rail.
If a crack is detected:The GPS module records coordinates.A Bluetooth alert is sent for quick maintenance.System continues scanning until the inspection is complete.

🛠 Technologies Used

1.Arduino UNO

2.IR Sensor (crack detection)

3.Ultrasonic Sensor (obstacle detection)

4.L298N Motor Driver

5.GPS Module

6.Bluetooth Module

7.DC Motors & Chassis

⚙ Components & Purpose:
IR Sensor	Detects cracks or track gaps
Ultrasonic Sensor	Detects obstacles and stops movement
GPS Module	Sends location of cracks
Bluetooth Module	Provides real-time updates
L298N Driver	Controls motor movement
Arduino UNO	Central controller
🚀 Getting Started

Prerequisites:
Arduino IDE + libraries (SoftwareSerial.h, TinyGPS++.h)

Steps:

1.Connect components as per circuit.

2.Open trackSafe.ino in Arduino IDE.

3.Install libraries and upload the code.

4.View results via Serial Monitor or Bluetooth app.

🎯 Key Takeaways

This project strengthened skills in:

1.Embedded systems
2.Sensor integration.
3.GPS tracking
4.IoT-based automation
Real-time monitoring for safety-critical applications
TrackSafe highlights how simple embedded tech can make railway operations safer and smarter

<div style="display: flex; gap: 20px; align-items: center;">
  <img src="https://github.com/Devasrikata710/railway-track-crack-detection-system-using-iot/blob/9b125709adf995b682475a05e7900c938e9dc329/1111.jpeg" width="400">
    <img src="https://raw.github.com/Devasrikata710/railway-track-crack-detection-system-using-iot/main/2222.jpeg" width="400">
</div>




