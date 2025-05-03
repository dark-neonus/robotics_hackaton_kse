
// int motorRightPin1 = 8;
// int motorRightPin2 = 9;

// int motorLeftPin1 = 10;
// int motorLeftPin2 = 11;



// void setup() {
//   pinMode(motorRightPin1, OUTPUT);
//   pinMode(motorRightPin2, OUTPUT);
//   pinMode(motorLeftPin1, OUTPUT);
//   pinMode(motorLeftPin2, OUTPUT);

//   // Ініціалізація серійного порту
//   Serial.begin(115200);
// }

// void loop() {
//   forward();
// }

// void forward() {
//   digitalWrite(motorRightPin1, HIGH);
//   digitalWrite(motorRightPin2, LOW);
//   digitalWrite(motorLeftPin1, HIGH);
//   digitalWrite(motorLeftPin2, LOW);
// }

// void stopMotors() {
//   digitalWrite(motorRightPin1, LOW);
//   digitalWrite(motorRightPin2, LOW);
//   digitalWrite(motorLeftPin1, LOW);
//   digitalWrite(motorLeftPin2, LOW);
// }

// void rotate180() {
//   // analogWrite(motorRightPin1, 128)
//   // analogWrite(motorLeftPin2, 128)
//   digitalWrite(motorRightPin1, HIGH);
//   digitalWrite(motorRightPin2, LOW);
//   digitalWrite(motorLeftPin1, LOW);
//   digitalWrite(motorLeftPin2, HIGH);
//   delay(1000);
//   digitalWrite(motorRightPin1, LOW);
//   digitalWrite(motorRightPin2, LOW);
//   digitalWrite(motorLeftPin1, LOW);
//   digitalWrite(motorLeftPin2, LOW);
// }

// void backward() {
//   digitalWrite(motorRightPin1, LOW);
//   digitalWrite(motorRightPin2, HIGH);
//   digitalWrite(motorLeftPin1, LOW);
//   digitalWrite(motorLeftPin2, HIGH);
// }