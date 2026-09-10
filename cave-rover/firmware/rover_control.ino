/*
  Mining Safety & Rescue Rover - Motor & LED Control
  ---------------------------------------------------
  Receives single-character commands over Serial (from Bluetooth/HC-05,
  or a control app) and drives a 2-motor differential rover, plus an
  onboard LED (used for night vision / headlight illumination).

  Command set:
    F -> Forward
    B -> Backward
    L -> Turn Left  (right motors on)
    R -> Turn Right (left motors on)
    W -> LED ON
    w -> LED OFF
    S -> STOP (all motors off)

  Pin map:
    13 -> Left motor  IN1 (forward)
    12 -> Left motor  IN2 (reverse)
    11 -> Right motor IN1 (forward)
    10 -> Right motor IN2 (reverse)
    9  -> LED
*/

char t;

void setup() {
  pinMode(13, OUTPUT);  // left motors  forward
  pinMode(12, OUTPUT);  // left motors  reverse
  pinMode(11, OUTPUT);  // right motors forward
  pinMode(10, OUTPUT);  // right motors reverse
  pinMode(9, OUTPUT);   // LED
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {                 // move forward (all motors forward)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  }

  else if (t == 'B') {            // move reverse (all motors reverse)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  }

  else if (t == 'L') {            // turn left (right side motors rotate)
    digitalWrite(11, HIGH);
  }

  else if (t == 'R') {            // turn right (left side motors rotate)
    digitalWrite(13, HIGH);
  }

  else if (t == 'W') {            // LED ON
    digitalWrite(9, HIGH);
  }

  else if (t == 'w') {            // LED OFF
    digitalWrite(9, LOW);
  }

  else if (t == 'S') {            // STOP (all motors off)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  delay(100);
}
