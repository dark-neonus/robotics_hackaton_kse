// // --- Конфігурація сенсорів ---
// const int sensors[5] = {A0, A1, A2, A3, A4};
// const int threshold = 500; // Чим менше значення, тим темніше (чорна лінія)

// // --- Піни двигунів L298N ---
// const int ENA = 5;    // PWM для лівого мотора
// const int IN1 = 8;
// const int IN2 = 9;

// const int ENB = 6;    // PWM для правого мотора
// const int IN3 = 10;
// const int IN4 = 11;

// // --- Швидкості ---
// const int baseSpeed = 120;
// const int turnAdjust = 40;

// void setup() {
//   // Мотори
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);

//   pinMode(ENB, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);

//   // Сенсори
//   for (int i = 0; i < 5; i++) {
//     pinMode(sensors[i], INPUT);
//   }

//   Serial.begin(9600);
// }

// void loop() {
//   bool onLine[5];
//   for (int i = 0; i < 5; i++) {
//     int value = analogRead(sensors[i]);
//     onLine[i] = (value < threshold);
//   }

//   if (onLine[2]) {
//     // Чітко на лінії — їдемо прямо
//     moveForward(baseSpeed, baseSpeed);
//   }
//   else if (onLine[1]) {
//     // Трохи лівіше
//     moveForward(baseSpeed - turnAdjust, baseSpeed + turnAdjust);
//   }
//   else if (onLine[3]) {
//     // Трохи правіше
//     moveForward(baseSpeed + turnAdjust, baseSpeed - turnAdjust);
//   }
//   else if (onLine[0]) {
//     // Сильно ліво
//     moveForward(baseSpeed - 2 * turnAdjust, baseSpeed + 2 * turnAdjust);
//   }
//   else if (onLine[4]) {
//     // Сильно право
//     moveForward(baseSpeed + 2 * turnAdjust, baseSpeed - 2 * turnAdjust);
//   }
//   else {
//     // Лінію втрачено — виконуємо повернення
//     recoverToCenterLine();
//   }

//   delay(10);
// }

// void moveForward(int leftSpeed, int rightSpeed) {
//   analogWrite(ENA, constrain(leftSpeed, 0, 255));
//   analogWrite(ENB, constrain(rightSpeed, 0, 255));

//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);

//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// void recoverToCenterLine() {
//   const int smallTurnSpeed = 100;
//   const int forwardSpeed = 80;

//   while (true) {
//     bool onLine[5];
//     for (int i = 0; i < 5; i++) {
//       onLine[i] = analogRead(sensors[i]) < threshold;
//     }

//     if (onLine[2]) break; // Знайшли центр — виходимо

//     if (onLine[0] || onLine[1]) {
//       // Малий поворот ліворуч
//       moveForward(smallTurnSpeed - 40, smallTurnSpeed + 40);
//     }
//     else if (onLine[3] || onLine[4]) {
//       // Малий поворот праворуч
//       moveForward(smallTurnSpeed + 40, smallTurnSpeed - 40);
//     }
//     else {
//       // Просто рух вперед, шукаємо
//       moveForward(forwardSpeed, forwardSpeed);
//     }

//     delay(100);
//   }
// }
