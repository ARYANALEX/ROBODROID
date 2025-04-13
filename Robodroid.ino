// ROBODROID
// RoboDroid, our Android-controlled "Pick and Place" robotic vehicle, combines the realms of automobile and robotics to redefine automation.

#include <Servo.h>

Servo S1, S2, S3, S4;

int S1pin = 8;
int S2pin = 9;
int S3pin = 10;
int S4pin = 11;

int motorIn1 = 2;
int motorIn2 = 3;
int motorIn3 = 4;
int motorIn4 = 5;

void setup() {
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);

  S1.attach(S1pin);
  S2.attach(S2pin);
  S3.attach(S3pin);
  S4.attach(S4pin);

  Serial.begin(9600);

  S1.write(90);
  S2.write(180);
  S3.write(20);
  S4.write(0);
}

void forward() {
  digitalWrite(motorIn1, HIGH); // left motor
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, HIGH); // right motor
  digitalWrite(motorIn4, LOW);
}

void backward() {
  digitalWrite(motorIn1, LOW); // left motor
  digitalWrite(motorIn2, HIGH);
  digitalWrite(motorIn3, LOW); // right motor
  digitalWrite(motorIn4, HIGH);
}

void left() {
  digitalWrite(motorIn1, LOW); // left motor
  digitalWrite(motorIn2, HIGH);
  digitalWrite(motorIn3, HIGH); // right motor
  digitalWrite(motorIn4, LOW);
}

void right() {
  digitalWrite(motorIn1, HIGH); // left motor
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW); // right motor
  digitalWrite(motorIn4, HIGH);
}

void stops() {
  digitalWrite(motorIn1, LOW); // left motor
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW); // right motor
  digitalWrite(motorIn4, LOW);
}

void loop() {
  if (Serial.available() >= 0) {
    char input = Serial.read();

    if (input == 'f') {
      forward();
    } else if (input == 'b') {
      backward();
    } else if (input == 'l') {
      left();
    } else if (input == 'r') {
      right();
    } else if (input == 's') {
      stops();
    } else if (input == 'p') {
      pick();
    } else if (input == 'd') {
      drop();
    }
  }
}

void pick() {
  for (int i = 90; i >= 0; i--) {
    S1.write(i);
    delay(20);
  }

  for (int i = 20; i <= 90; i++) {
    S3.write(i);
    delay(20);
  }

  for (int i = 180; i >= 85; i--) {
    S2.write(i);
    delay(20);
  }

  for (int i = 0; i <= 180; i++) {
    S4.write(i);
    delay(20);
  }
}

void drop() {
  for (int i = 85; i <= 120; i++) {
    S2.write(i);
    delay(15);
  }

  for (int i = 0; i <= 180; i++) {
    S1.write(i);
    delay(15);
  }

  for (int i = 120; i >= 85; i--) {
    S2.write(i);
    delay(15);
  }

  for (int i = 180; i >= 0; i--) {
    S4.write(i);
    delay(15);
  }

  for (int i = 85; i <= 180; i++) {
    S2.write(i);
    delay(15);
  }

  for (int i = 180; i >= 90; i--) {
    S1.write(i);
    delay(15);
  }

  for (int i = 90; i >= 20; i--) {
    S3.write(i);
    delay(15);
  }
}
