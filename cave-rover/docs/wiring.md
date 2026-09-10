# Wiring Notes

## Motor Driver (e.g. L298N)

| Arduino Pin | Driver Pin | Function             |
|-------------|------------|-----------------------|
| 13          | IN1        | Left motor forward     |
| 12          | IN2        | Left motor reverse     |
| 11          | IN3        | Right motor forward    |
| 10          | IN4        | Right motor reverse    |

- Connect motor driver `OUT1/OUT2` to the left motor(s), `OUT3/OUT4` to the
  right motor(s).
- Power the driver's motor supply (12V/battery) separately from the
  Arduino's 5V logic supply; share a common ground.

## LED

| Arduino Pin | Function |
|-------------|----------|
| 9           | LED (+)  |

Use a current-limiting resistor in series with the LED.

## Bluetooth Module (e.g. HC-05)

| Arduino Pin | HC-05 Pin |
|-------------|-----------|
| TX (pin 1)  | RX        |
| RX (pin 0)  | TX        |
| 5V          | VCC       |
| GND         | GND       |

> Note: HC-05 RX is 3.3V logic — use a voltage divider on the Arduino TX
> line if your module isn't 5V-tolerant.

## Sensors (to be wired as added)

- **Gas sensor (MQ-series):** analog output → Arduino analog pin (e.g. A0)
- **Ultrasonic (HC-SR04):** TRIG/ECHO → two digital pins (e.g. D2/D3)
- **Thermal camera / night vision camera:** typically wired via I2C (thermal)
  or run from a separate microcontroller (e.g. ESP32-CAM) for video
  streaming, since a single Arduino Uno has limited processing power and
  memory for video.

Update this file with exact pins once the additional sensors are wired in.
