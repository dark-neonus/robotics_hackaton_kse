#define MOTOR_RIGHT_PIN1 8
#define MOTOR_RIGHT_PIN2 9

#define MOTOR_LEFT_PIN1 10
#define MOTOR_LEFT_PIN2 11

#define MOTOR_RIGHT_ANALOG_PIN 12
#define MOTOR_LEFT_ANALOG_PIN 13



void setup_motors() {
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_ANALOG_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_ANALOG_PIN, OUTPUT);
  Serial.println("Motors initialized");
}

void forward(int speed = 150) {
  analogWrite(MOTOR_RIGHT_ANALOG_PIN, speed);
  analogWrite(MOTOR_LEFT_ANALOG_PIN, speed);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
}

void stopMotors() {
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
}

void rotate180() {
  // analogWrite(MOTOR_RIGHT_PIN1, 128)
  // analogWrite(MOTOR_LEFT_PIN2, 128)
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  delay(1000);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
}

void backward() {
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
}
