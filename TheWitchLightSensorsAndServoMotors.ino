#include <Servo.h>

// ===== SENSORS =====
int pinCircleSensor = A0;
int pinArmsSensor   = A1;

int valCircle = 0;
int valArms   = 0;

// ===== SERVOS =====
Servo servoCircle;
Servo servoArms;

int pinCircle = 9;
int pinArms   = 10;

// ===== TIMER =====
unsigned long triggerTime = 0;
bool isActive = false;
int duration = 4000;

// ===== TRIGGER =====
int lastCircle = 0;
int triggerThreshold = 15;

// ===== MOTION =====
float t = 0;
float speed = 0.03;
float fastSpeed = 0.15;

void setup() {
  servoCircle.attach(pinCircle);
  servoArms.attach(pinArms);

  servoCircle.write(90);
  servoArms.write(90);
}

void loop() {

  valCircle = analogRead(pinCircleSensor);
  valArms   = analogRead(pinArmsSensor);

  // ===== TRIGGER =====
  int change = abs(valCircle - lastCircle);

  if (change > triggerThreshold) {
    isActive = true;
    triggerTime = millis();
  }

  lastCircle = valCircle;

  // ===== SPEED =====
  float currentSpeed = isActive ? fastSpeed : speed;
  t += currentSpeed;

  // ===== ARMS =====
  int armsAngle = 90 + 25 * sin(t);
  servoArms.write(armsAngle);

  // ===== CIRCLE =====
  if (isActive) {
    servoCircle.write(96); // slow spin

    if (millis() - triggerTime > duration) {
      isActive = false;
    }
  } else {
    servoCircle.write(90);
  }

  delay(20);
}