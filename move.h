#ifndef MOVE_H
#define MOVE_H

#include "navigation.h"

#define MOTOR_RIGHT_PIN1 12
#define MOTOR_RIGHT_PIN2 13

#define MOTOR_LEFT_PIN1 7
#define MOTOR_LEFT_PIN2 8

#define MOTOR_RIGHT_ANALOG_PIN 10
#define MOTOR_LEFT_ANALOG_PIN 11

void setup_motors() {
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_ANALOG_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_ANALOG_PIN, OUTPUT);
  Serial.println("Motors initialized");
}

// Move the robot using data from moveStamp
void move(MoveStamp stamp) {
  // Implementation here
}

// Takes moveStamp and reverse it
void moveReverse(MoveStamp stamp) {
  // Implementation here
}

// void forward(int speed = 150) {
//   analogWrite(MOTOR_RIGHT_ANALOG_PIN, speed);
//   analogWrite(MOTOR_LEFT_ANALOG_PIN, speed);
//   digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
//   digitalWrite(MOTOR_RIGHT_PIN2, LOW);
//   digitalWrite(MOTOR_LEFT_PIN1, HIGH);
//   digitalWrite(MOTOR_LEFT_PIN2, LOW);
// }
// void move(int leftSpeed, int rightSpeed) {
//   analogWrite(MOTOR_RIGHT_ANALOG_PIN, constrain(leftSpeed, 0, 255));
//   analogWrite(MOTOR_LEFT_ANALOG_PIN, constrain(rightSpeed, 0, 255));

//   digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
//   digitalWrite(MOTOR_RIGHT_PIN2, LOW);

//   digitalWrite(MOTOR_LEFT_PIN1, HIGH);
//   digitalWrite(MOTOR_LEFT_PIN2, LOW);
// }

// void stopMotors() {
//   digitalWrite(MOTOR_RIGHT_PIN1, LOW);
//   digitalWrite(MOTOR_RIGHT_PIN2, LOW);
//   digitalWrite(MOTOR_LEFT_PIN1, LOW);
//   digitalWrite(MOTOR_LEFT_PIN2, LOW);
// }

// void rotate180() {
//   // analogWrite(MOTOR_RIGHT_PIN1, 128)
//   // analogWrite(MOTOR_LEFT_PIN2, 128)
//   digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
//   digitalWrite(MOTOR_RIGHT_PIN2, LOW);
//   digitalWrite(MOTOR_LEFT_PIN1, LOW);
//   digitalWrite(MOTOR_LEFT_PIN2, HIGH);
//   delay(1000);
//   digitalWrite(MOTOR_RIGHT_PIN1, LOW);
//   digitalWrite(MOTOR_RIGHT_PIN2, LOW);
//   digitalWrite(MOTOR_LEFT_PIN1, LOW);
//   digitalWrite(MOTOR_LEFT_PIN2, LOW);
// }

// void rotateClockwise(int rotate_speed) {
//   analogWrite(MOTOR_RIGHT_ANALOG_PIN, rotate_speed);
//   analogWrite(MOTOR_LEFT_ANALOG_PIN, rotate_speed);
//   digitalWrite(motorRightPin1, LOW);
//   digitalWrite(motorRightPin2, HIGH);
//   digitalWrite(motorLeftPin1, HIGH);
//   digitalWrite(motorLeftPin2, LOW);
//  }


//  void rotateCounterClockwise(int rotate_speed) {
//   analogWrite(MOTOR_RIGHT_ANALOG_PIN, rotate_speed);
//   analogWrite(MOTOR_LEFT_ANALOG_PIN, rotate_speed);
//   digitalWrite(motorRightPin1, HIGH);
//   digitalWrite(motorRightPin2, LOW);
//   digitalWrite(motorLeftPin1, LOW);
//   digitalWrite(motorLeftPin2, HIGH);
//  }

// void backward() {
//   analogWrite(MOTOR_RIGHT_ANALOG_PIN, speed);
//   analogWrite(MOTOR_LEFT_ANALOG_PIN, speed);
//   digitalWrite(MOTOR_RIGHT_PIN1, LOW);
//   digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
//   digitalWrite(MOTOR_LEFT_PIN1, LOW);
//   digitalWrite(MOTOR_LEFT_PIN2, HIGH);
// }

#endif