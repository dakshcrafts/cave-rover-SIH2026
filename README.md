<div align="center">

# CAVE ROVER — Mine Safety & Rescue Robot

### Smart India Hackathon 2026 | Problem Statement ID: **SIH26039**

![Category](https://img.shields.io/badge/Category-Hardware-blue?style=for-the-badge)
![Theme](https://img.shields.io/badge/Theme-Smart_Automation-orange?style=for-the-badge)
![SIH](https://img.shields.io/badge/SIH-2026-red?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Arduino_Uno-teal?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

**An autonomous, multi-sensor rover designed to navigate dangerous underground mine and cave environments, detect hazardous gases, capture real-time thermal & visual data, and relay critical information to rescue teams — saving lives when human entry is too risky.**

---

</div>

## Table of Contents

- [About the Project](#about-the-project)
- [Problem Statement](#problem-statement)
- [Key Features](#key-features)
- [System Architecture](#system-architecture)
- [Tech Stack](#tech-stack)
- [Hardware Components](#hardware-components)
- [Circuit Diagram](#circuit-diagram)
- [Pin Configuration](#pin-configuration)
- [Communication Protocol](#communication-protocol)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Demo](#demo)
- [Media Gallery](#media-gallery)
- [Team](#team)
- [Acknowledgements](#acknowledgements)
- [License](#license)

---

## About the Project

Underground mining and cave exploration are among the most dangerous occupations worldwide. Collapsed tunnels, toxic gas buildup, unstable terrain, and zero visibility make rescue operations extremely hazardous. **Cave Rover** is a rugged, sensor-packed robot that can be deployed into these hostile environments to:

- **Navigate** tight, dark tunnels using differential-drive motor control
- **Detect** lethal gases (methane, CO, LPG) in real time
- **Measure** ambient temperature to identify fire or explosion risks
- **Map** obstacles using ultrasonic ranging to avoid collisions
- **Stream** live video (day & night) via an onboard ESP32-CAM module
- **Communicate** all sensor telemetry wirelessly to a base-station control app

> *"When humans can't go in, the rover goes in for them."*

---

## Problem Statement

**PS ID:** SIH26039  
**Title:** Smart Automation — Mine Safety & Rescue Rover  

Mining accidents claim hundreds of lives every year. Current rescue methods rely on human teams entering unstable tunnels, risking secondary collapses and gas poisoning. There is an urgent need for an affordable, field-deployable robotic solution that can scout dangerous zones, relay live sensor data, and assist rescue teams in making informed decisions — all without risking a single human life.

---

## Key Features

| Feature | Description |
|:--------|:------------|
| **Differential Drive Motor Control** | 2-motor L298N driver setup for forward, reverse, left, right, and emergency stop |
| **Bluetooth Remote Control** | HC-05 Bluetooth module for wireless command & control from any smartphone or laptop |
| **Gas Detection (MQ Sensor)** | Real-time monitoring of methane, CO, and LPG concentrations with analog threshold alerts |
| **Ultrasonic Obstacle Detection** | HC-SR04 sensor for distance measurement and collision avoidance |
| **Thermal Sensing** | Temperature monitoring to detect hotspots, fire risks, and equipment malfunction |
| **Night Vision / LED Illumination** | High-power LED array for照亮 pitch-dark tunnels; ESP32-CAM with IR for night vision streaming |
| **Live Video Streaming** | ESP32-CAM module streams real-time video over WiFi to the rescue team's dashboard |
| **Real-Time Sensor Telemetry** | All sensor readings transmitted via Bluetooth for live monitoring at the base station |
| **Compact & Rugged Design** | Built on a chassis small enough to fit through narrow mine shafts |

---

## System Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    BASE STATION                         │
│              (Laptop / Control App)                     │
│                                                         │
│   ┌─────────────┐   ┌──────────────┐   ┌────────────┐  │
│   │  Control UI  │   │  Sensor Data │   │ Video Feed │  │
│   │  (Commands)  │   │   Dashboard  │   │ (ESP32-CAM)│  │
│   └──────┬──────┘   └──────┬───────┘   └─────┬──────┘  │
│          │    Bluetooth     │    Bluetooth     │  WiFi   │
└──────────┼─────────────────┼──────────────────┼─────────┘
           │                 │                  │
    ═══════╪═════════════════╪══════════════════╪═════════
           │                 │                  │
┌──────────┼─────────────────┼──────────────────┼─────────┐
│          ▼                 ▼                  ▼         │
│   ┌─────────────┐   ┌──────────────┐   ┌────────────┐  │
│   │   HC-05     │   │   Arduino    │   │ ESP32-CAM  │  │
│   │  Bluetooth  │◄──│     Uno      │──►│  (Video)   │  │
│   └─────────────┘   └──────┬───────┘   └────────────┘  │
│                             │                           │
│              ┌──────────────┼──────────────┐            │
│              │              │              │            │
│         ┌────┴────┐   ┌────┴────┐   ┌────┴────┐       │
│         │ L298N   │   │ Sensors │   │  LED    │       │
│         │ Motor   │   │ MQ /    │   │ Night   │       │
│         │ Driver  │   │ Ultrasonic│  │  Vision │       │
│         └────┬────┘   └─────────┘   └─────────┘       │
│              │                                         │
│         ┌────┴────┐                                    │
│         │ DC Motor│                                    │
│         │ Wheels  │                                    │
│         └─────────┘                                    │
│                                                         │
│                    CAVE ROVER                           │
└─────────────────────────────────────────────────────────┘
```

---

## Tech Stack

| Layer | Technology |
|:------|:-----------|
| **Microcontroller** | Arduino Uno (ATmega328P) |
| **Video Module** | ESP32-CAM (OV2640 camera, WiFi streaming) |
| **Motor Driver** | L298N Dual H-Bridge |
| **Communication** | HC-05 Bluetooth Module (SPP — Serial Port Profile) |
| **Sensors** | MQ-135 (Gas), HC-SR04 (Ultrasonic), LM35 / DS18B20 (Thermal) |
| **Programming Language** | C/C++ (Arduino IDE) |
| **Control App** | Bluetooth RC Controller (Android) / Custom Dashboard |
| **Power** | 12V Li-Po Battery Pack |

---

## Hardware Components

| # | Component | Quantity | Purpose |
|:-:|:----------|:--------:|:--------|
| 1 | Arduino Uno | 1 | Main controller — processes commands & sensor data |
| 2 | ESP32-CAM | 1 | Night vision & live video streaming over WiFi |
| 3 | L298N Motor Driver | 1 | Drives 2 DC motors with PWM speed control |
| 4 | HC-05 Bluetooth Module | 1 | Wireless communication with base station |
| 5 | MQ-135 Gas Sensor | 1 | Detects harmful gases (CH₄, CO, NH₃, benzene) |
| 6 | HC-SR04 Ultrasonic Sensor | 1 | Obstacle detection & distance measurement |
| 7 | LM35 Temperature Sensor | 1 | Ambient temperature monitoring |
| 8 | High-Power LED | 1 | Night vision illumination |
| 9 | DC Gear Motors | 2 | Differential drive locomotion |
| 10 | Robot Chassis (4WD) | 1 | Rugged frame for rough terrain |
| 11 | 12V Li-Po Battery | 1 | Power supply for motors & electronics |
| 12 | Jumper Wires & Connectors | — | Wiring & prototyping |
| 13 | Voltage Regulator (7805) | 1 | Step-down 12V → 5V for Arduino & sensors |

---

## Circuit Diagram

```
                          ┌──────────────────────┐
                          │     ARDUINO UNO       │
                          │                       │
   ┌──────────┐           │  D13 ──── IN1 (L298N) │──── OUT1/OUT2 ──► Left Motor
   │  HC-05   │           │  D12 ──── IN2 (L298N) │
   │Bluetooth │           │  D11 ──── IN3 (L298N) │──── OUT3/OUT4 ──► Right Motor
   │          │           │  D10 ──── IN4 (L298N) │
   │  TX ◄────┼───────────┤  D0  (RX)             │
   │  RX ◄────┼───────────┤  D1  (TX)             │     ┌────────────┐
   │  VCC ────┼── 5V      │                       │     │  L298N     │
   │  GND ────┼── GND     │  D9  ───── LED (+)    │     │  Motor     │
   └──────────┘           │                       │     │  Driver    │
                          │  D2  ──── TRIG (HC-SR04)    │            │
                          │  D3  ──── ECHO (HC-SR04)    │  12V ◄────┤ Battery
                          │                       │     │  5V  ◄────┤ 7805 Reg
                          │  A0  ◄──── OUT (MQ-135)     │  GND ─────┤ Common GND
                          │                       │     └────────────┘
                          │  A1  ◄──── LM35 OUT   │
                          │                       │
                          │  5V  ───── Sensor VCC  │
                          │  GND ───── Sensor GND  │
                          └──────────────────────┘

   ┌──────────────┐       ┌──────────────┐       ┌──────────────┐
   │   MQ-135     │       │  HC-SR04     │       │    LM35      │
   │  Gas Sensor  │       │  Ultrasonic  │       │  Temperature │
   │              │       │              │       │   Sensor     │
   │  VCC ── 5V   │       │  VCC ── 5V   │       │  VCC ── 5V   │
   │  GND ── GND  │       │  GND ── GND  │       │  GND ── GND  │
   │  AOUT ── A0  │       │  TRIG ── D2  │       │  OUT ── A1   │
   │              │       │  ECHO ── D3  │       │              │
   └──────────────┘       └──────────────┘       └──────────────┘

   ┌──────────────┐
   │  ESP32-CAM   │          Powered independently via USB / 5V supply
   │              │          Streams video over WiFi to base station
   │  OV2640      │          (Not connected to Arduino — runs standalone)
   └──────────────┘
```

> **Note:** For a detailed, high-resolution circuit diagram, see the [Media Gallery](#media-gallery) section below.

---

## Pin Configuration

### Motor Driver (L298N)

| Arduino Pin | L298N Pin | Function |
|:-----------:|:---------:|:---------:|
| D13 | IN1 | Left Motor — Forward |
| D12 | IN2 | Left Motor — Reverse |
| D11 | IN3 | Right Motor — Forward |
| D10 | IN4 | Right Motor — Reverse |

### Sensors

| Arduino Pin | Sensor Pin | Function |
|:-----------:|:----------:|:---------:|
| A0 | MQ-135 OUT | Gas concentration (analog) |
| A1 | LM35 OUT | Temperature reading (analog) |
| D2 | HC-SR04 TRIG | Ultrasonic trigger |
| D3 | HC-SR04 ECHO | Ultrasonic echo |

### Communication

| Arduino Pin | Module Pin | Function |
|:-----------:|:----------:|:---------:|
| D0 (RX) | HC-05 TX | Receive Bluetooth data |
| D1 (TX) | HC-05 RX | Send serial data (via voltage divider) |

### Other

| Arduino Pin | Component | Function |
|:-----------:|:---------:|:---------:|
| D9 | LED (+) | Night vision / headlight |

---

## Communication Protocol

The rover uses **Bluetooth SPP (Serial Port Profile)** via the **HC-05 module** for all wireless communication between the base station and the rover.

### Command Protocol

Single-character commands are sent from the control app to the Arduino over Bluetooth Serial at **9600 baud**:

| Command | Action | Description |
|:-------:|:------|:------------|
| `F` | Forward | All motors rotate forward |
| `B` | Backward | All motors rotate in reverse |
| `L` | Turn Left | Right-side motors activate |
| `R` | Turn Right | Left-side motors activate |
| `S` | Stop | All motors off (emergency stop) |
| `W` | LED On | Night vision LED ON |
| `w` | LED Off | Night vision LED OFF |

### Data Flow

```
Control App ──[Bluetooth]──► HC-05 ──[Serial]──► Arduino Uno
                                                        │
                                                        ├──► Motor Commands ──► L298N ──► DC Motors
                                                        ├──► Sensor Reads ──► Gas / Temp / Ultrasonic
                                                        └──► LED Control ──► Night Vision LED

ESP32-CAM ──[WiFi Stream]──────────────────────────► Base Station (Browser)
```

---

## Project Structure

```
cave-rover-SIH2026/
├── README.md                          # This file
└── cave-rover/
    ├── LICENSE                        # MIT License
    ├── docs/
    │   └── wiring.md                  # Detailed wiring notes
    └── firmware/
        └── rover_control.ino          # Main Arduino firmware
```

---

## Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8+ or v2.x)
- HC-05 Bluetooth Module (paired with your control device)
- USB cable for uploading firmware

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/dakshcrafts/cave-rover-SIH2026.git
   cd cave-rover-SIH2026/cave-rover/firmware
   ```

2. **Open in Arduino IDE**
   - Launch Arduino IDE
   - Go to `File → Open` and select `rover_control.ino`

3. **Select Board & Port**
   - Go to `Tools → Board → Arduino Uno`
   - Go to `Tools → Port` and select your COM port

4. **Upload the Firmware**
   - Click the **Upload** button (→)
   - Wait for `Done uploading.` confirmation

5. **Pair HC-05 via Bluetooth**
   - Power on the rover
   - On your phone/laptop, search for Bluetooth devices
   - Pair with **HC-05** (default PIN: `1234` or `0000`)

6. **Control the Rover**
   - Open any Bluetooth Serial Controller app
   - Connect to HC-05 at **9600 baud**
   - Send commands: `F`, `B`, `L`, `R`, `S`, `W`, `w`

---

## Demo

<!-- Replace the placeholder link below with your actual Google Drive video link -->
[![Cave Rover Demo](https://img.shields.io/badge/Watch_Demo-Google_Drive-blue?style=for-the-badge)](YOUR_GOOGLE_DRIVE_LINK_HERE)

> **Demo Video:** [Click here to watch the Cave Rover project video](YOUR_GOOGLE_DRIVE_LINK_HERE)

---

## Media Gallery

### Build Photos

<!-- Replace the placeholder link below with your actual image URL -->

![Cave Rover Build](YOUR_IMAGE_LINK_1)

**Cave Rover — Project Build**

### Circuit Diagram

<!-- Replace with your actual circuit diagram image -->
![Circuit Diagram](YOUR_CIRCUIT_DIAGRAM_IMAGE_LINK)

---

## Team — **Innovation's Life**

| # | Name | Role |
|:-:|:-----|:-----|
| 1 | **Shubham Kumar** | Team Lead / Hardware Integration |
| 2 | **Ankit Bisht** | Firmware Development / Embedded Systems |
| 3 | **Daksh Sharma** | Circuit Design / Electronics |
| 4 | **Sachin Sharma** | Sensor Integration / Testing |
| 5 | **Manvi Sahani** | App UI / Frontend Development |
| 6 | **Honey Kain** | Documentation / Research |

**College:** R.D. Engineering College

---

## Acknowledgements

- **Smart India Hackathon 2026** — for the platform and problem statements
- **R.D. Engineering College** — institutional support and resources
- Arduino & ESP32 open-source communities
- SIH organizing committee and mentors

---

<div align="center">

### Built with passion by **Team Innovation's Life** for **SIH 2026**

*"Engineering innovation for a safer tomorrow."*

![SIH 2026](https://img.shields.io/badge/Smart_India_Hackathon-2026-blue?style=for-the-badge)
![Made with Arduino](https://img.shields.io/badge/Made_with-Arduino-teal?style=for-the-badge)
![R.D. Engineering College](https://img.shields.io/badge/R.D._Engineering_College-orange?style=for-the-badge)

</div>
