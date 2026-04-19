// Project: The Witch
// Author: Nia
// Description: Light sensors control servo movement. The arms move slowly as an idle motion,
// while sudden changes in light trigger the circular rotation.
#include <Servo.h>

// SENSORS
// Light sensor for triggering the circle motion
int pinCircleSensor = A0;

// Light sensor influencing arm movement
int pinArmsSensor   = A1;

int valCircle = 0;
int valArms   = 0;


// SERVOS
Servo servoCircle;  // continuous rotation (background circles)
Servo servoArms;    // 180° servo (arms)

int pinCircle = 9;
int pinArms   = 10;


// TIMER FOR INTERACTION
// Controls how long the circle keeps spinning after trigger
unsigned long triggerTime = 0;
bool isActive = false;
int duration = 4000; // 4 seconds


// TRIGGER DETECTION
// Detects sudden light change (hand wave)
int lastCircle = 0;
int triggerThreshold = 15;


// MOTION CONTROL
// t is used to create smooth sine wave movement
float t = 0;

// Slow idle movement
float speed = 0.03;

// Faster movement when activated
float fastSpeed = 0.15;


void setup() {
  // Attach servos to pins
  servoCircle.attach(pinCircle);
  servoArms.attach(pinArms);

  // Start both servos at neutral position
  servoCircle.write(90); 
  servoArms.write(90);
}


void loop() {

  // READ SENSOR VALUES
  valCircle = analogRead(pinCircleSensor);
  valArms   = analogRead(pinArmsSensor);


  // TRIGGER LOGIC
  // Compare current and previous light values
  int change = abs(valCircle - lastCircle);

  // If sudden change detected → activate interaction
  if (change > triggerThreshold) {
    isActive = true;
    triggerTime = millis(); // start timer
  }

  lastCircle = valCircle;


  // MOTION SPEED
  // Idle = slow, Activated = faster
  float currentSpeed = isActive ? fastSpeed : speed;
  t += currentSpeed;


  // ARM MOVEMENT
  // Sine wave creates smooth up/down motion
  int armsAngle = 90 + 25 * sin(t);
  servoArms.write(armsAngle);


  // CIRCLE MOVEMENT
  if (isActive) {
    // Continuous servo rotates slightly off 90 to spin slowly
    servoCircle.write(96);

    // Stop after duration time
    if (millis() - triggerTime > duration) {
      isActive = false;
    }
  } else {
    // Stop rotation
    servoCircle.write(90);
  }

  delay(20); // small delay for stability
}
