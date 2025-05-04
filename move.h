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

void moveForward(int speed) {
  analogWrite(MOTOR_RIGHT_ANALOG_PIN, speed);
  analogWrite(MOTOR_LEFT_ANALOG_PIN, speed);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
}

int getTurnTime360(int pwm) {
  // A ≈ 138000 підібрано з експериментальних даних
  return 138000 / pwm;
}

void setMotors(int leftSpeed, int rightSpeed) {
  analogWrite(ENA, constrain(abs(leftSpeed), 0, 255));
  analogWrite(ENB, constrain(abs(rightSpeed), 0, 255));

  digitalWrite(IN1, leftSpeed >= 0 ? HIGH : LOW);
  digitalWrite(IN2, leftSpeed >= 0 ? LOW : HIGH);

  digitalWrite(IN3, rightSpeed >= 0 ? HIGH : LOW);
  digitalWrite(IN4, rightSpeed >= 0 ? LOW : HIGH);
}

void turnByAngle(int angle, int speed) {
  if (angle == 0 || speed <= 0) return;

  int dir = angle > 0 ? 1 : -1;  // 1 = праворуч, -1 = ліворуч
  int turnTime360 = getTurnTime360(speed);
  int duration = abs(angle) * turnTime360 / 360;

  // Для танкового повороту: один мотор вперед, інший назад
  int leftMotor = dir * speed;
  int rightMotor = -dir * speed;

  setMotors(stamp.speed, stamp.speed);
  delay(duration);
  stopMotors();
}

// Move the robot using data from moveStamp
void move(MoveStamp stamp) {
  moveForward(stamp.speed);
  delay(stamp.time);
  stopMotors();
  turnByAngle(stamp.delta_rotation, stamp.speed);
  delay(stamp.time);
  stopMotors();
  // if (stamp.delta_rotation == 0) {
  //   // Move forward or backward
  //   moveForward(stamp.speed);
  //   delay(stamp.time);
  //   stopMotors();
  // } else if (stamp.delta_rotation > 0) {
  //   // Rotate clockwise
  //   moveForward(stamp.speed);
  //   rotateClockwise(stamp.speed, stamp.time);
  //   delay(stamp.time);
  //   stopMotors();
  // } else {
  //   // Rotate counter-clockwise
  //   moveForward(stamp.speed);
  //   rotateCounterClockwise(-stamp.delta_rotation);
  //   delay(stamp.time);
  //   stopMotors();
  // }

}
void moveBackward(int speed) {
  analogWrite(MOTOR_RIGHT_ANALOG_PIN, speed);
  analogWrite(MOTOR_LEFT_ANALOG_PIN, speed);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
}

// Takes moveStamp and reverse it
void moveReverse(MoveStamp stamp) {
  moveBackward(stamp.speed);
  delay(stamp.time);
  stopMotors();
  turnByAngle(-stamp.delta_rotation, stamp.speed);
  delay(stamp.time);
  stopMotors();
  // if (stamp.delta_rotation == 0) {
  //   // Move forward or backward
  //   moveForward(-stamp.speed);
  //   delay(stamp.time);
  //   stopMotors();
  // } else if (stamp.delta_rotation > 0) {
  //   // Rotate clockwise
  //   moveForward(-stamp.speed);
  //   rotateClockwise(-stamp.speed, stamp.time);
  //   delay(stamp.time);
  //   stopMotors();
  // } else {
  //   // Rotate counter-clockwise
  //   moveForward(-stamp.speed);
  //   rotateCounterClockwise(-stamp.delta_rotation);
  //   delay(stamp.time);
  //   stopMotors();
  // }
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

void stopMotors() {
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
}

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

void rotateClockwise(int rotate_speed) {
  analogWrite(MOTOR_RIGHT_ANALOG_PIN, rotate_speed);
  analogWrite(MOTOR_LEFT_ANALOG_PIN, rotate_speed);
  digitalWrite(motorRightPin1, LOW);
  digitalWrite(motorRightPin2, HIGH);
  digitalWrite(motorLeftPin1, HIGH);
  digitalWrite(motorLeftPin2, LOW);
 }


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