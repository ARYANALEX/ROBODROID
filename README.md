# 🤖 RoboDroid – Android-Controlled Pick and Place Robot

RoboDroid is an Android-controlled, four-wheeled robotic vehicle equipped with a servo-driven robotic arm that can **pick and place** objects. It blends the power of **automobile mechanics** and **robotics automation** into a smart system controlled wirelessly via Bluetooth.

## 📜 Features

- Wireless control via Android (Bluetooth-based)
- Forward, backward, left, and right movement
- Robotic arm with pick-and-place functionality
- Servo-based multi-joint arm system
- Compact and Arduino-based

---

## 🧰 Hardware Requirements

- Arduino Uno or compatible board
- HC-05 Bluetooth module
- L298N motor driver or H-Bridge setup
- 4 DC motors with wheels
- 4 Servo motors (for robotic arm)
- Power supply (Battery pack)
- Chassis and mechanical frame
- Android smartphone with a Bluetooth terminal app

---

## 🔌 Pin Configuration

| Component         | Arduino Pin |
|------------------|-------------|
| Servo S1         | 8           |
| Servo S2         | 9           |
| Servo S3         | 10          |
| Servo S4         | 11          |
| Motor Left IN1   | 2           |
| Motor Left IN2   | 3           |
| Motor Right IN3  | 4           |
| Motor Right IN4  | 5           |
| Bluetooth RX/TX  | 0 / 1       |

> **Note:** Ensure you're not using Serial Monitor and Bluetooth module simultaneously, as both use UART (TX/RX).

---

## 📱 Android Controls

Use any Bluetooth terminal app or a custom Android app to send the following commands:

| Command | Action            |
|---------|-------------------|
| `f`     | Move Forward      |
| `b`     | Move Backward     |
| `l`     | Turn Left         |
| `r`     | Turn Right        |
| `s`     | Stop              |
| `p`     | Pick Object       |
| `d`     | Drop Object       |

---

## 🧠 How It Works

1. Motors are driven via digital pins using H-Bridge logic.
2. Servos control the robotic arm's joints and gripper.
3. Bluetooth module receives commands from the phone.
4. Based on commands, respective movement or arm actions are performed.

---

## 🚀 Getting Started

### 1. Upload the Code
Upload the Arduino code (`.ino`) provided in this repo to your Arduino board using the Arduino IDE.

### 2. Connect Hardware
Assemble the bot and connect all components as per the pin configuration above.

### 3. Power On
Connect power to motors and servos (external battery pack recommended).

### 4. Pair Bluetooth
Pair your Android device with the HC-05 module.

### 5. Control
Use a Bluetooth terminal app to send commands and control the bot.

---

## 🛠️ Future Improvements (Suggestions)

- Add obstacle detection using ultrasonic sensors.
- Integrate line-following or IR sensors for autonomous movement.
- Create a custom Android app with buttons and sliders.
- Add feedback from sensors (e.g., gripper force or object detection).

---

## 📄 License

This project is open-source and free to use under the MIT License.
