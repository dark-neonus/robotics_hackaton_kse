
#include "move.h"

#define SENSOR_0_PIN 2
#define SENSOR_1_PIN 3
#define SENSOR_2_PIN 4
#define SENSOR_3_PIN 5
#define SENSOR_4_PIN 6

#define L2 SENSOR_0_PIN
#define L1 SENSOR_1_PIN
#define C0 SENSOR_2_PIN
#define R1 SENSOR_3_PIN
#define R2 SENSOR_4_PIN

const int baseSpeed = 120;
const int turnAdjust = 40;


#pragma region Setup

void setup_sensor() {
    pinMode(SENSOR_0_PIN, INPUT);
    pinMode(SENSOR_1_PIN, INPUT);
    pinMode(SENSOR_2_PIN, INPUT);
    pinMode(SENSOR_3_PIN, INPUT);
    pinMode(SENSOR_4_PIN, INPUT);
    Serial.println("Pins initialized");
}

void setup() 
{
  Serial.begin(115200);
  setup_sensor();
  setup_motors();
}

#pragma endregion

static int sensor_data[5];
void readSensors(bool print = false, bool nice = false) {
  sensor_data[0] = digitalRead(SENSOR_0_PIN);
  sensor_data[1] = digitalRead(SENSOR_1_PIN);
  sensor_data[2] = digitalRead(SENSOR_2_PIN);
  sensor_data[3] = digitalRead(SENSOR_3_PIN);
  sensor_data[4] = digitalRead(SENSOR_4_PIN);
  if (print) {
    // Print data separated by |
    // Serial.print("Sensor data: ");
    for (int i = 0; i < 5; i++) {
      if (nice) {
        if (sensor_data[i] == 0) {
          Serial.print("#");
        } else {
          Serial.print(".");
        }
      }
      else {
        Serial.print(sensor_data[i]);
        if (i < 4) {
            Serial.print(" | ");
        }
      }
    }
    Serial.println();
  }
}

void loop() 
{
  readSensors(true, true);
  if (C0) {
    // Чітко на лінії — їдемо прямо
    moveForward(baseSpeed, baseSpeed);
  }
  else if (L1) {
    // Трохи лівіше
    moveForward(baseSpeed - turnAdjust, baseSpeed + turnAdjust);
  }
  else if (R1) {
    // Трохи правіше
    moveForward(baseSpeed + turnAdjust, baseSpeed - turnAdjust);
  }
  else if (L2) {
    // Сильно ліво
    moveForward(baseSpeed - 2 * turnAdjust, baseSpeed + 2 * turnAdjust);
  }
  else if (R2) {
    // Сильно право
    moveForward(baseSpeed + 2 * turnAdjust, baseSpeed - 2 * turnAdjust);
  }
  else {
    // Лінію втрачено — виконуємо повернення
    recoverToCenterLine();
  }

  delay(10);
}

void recoverToCenterLine() {
  const int smallTurnSpeed = 100;
  const int forwardSpeed = 80;

  while (true) {
    bool R1;

    if (C0) break; // Знайшли центр — виходимо

    if (L2 || L1) {
      // Малий поворот ліворуч
      moveForward(smallTurnSpeed - 40, smallTurnSpeed + 40);
    }
    else if (R1 || R2) {
      // Малий поворот праворуч
      moveForward(smallTurnSpeed + 40, smallTurnSpeed - 40);
    }
    else {
      // Просто рух вперед, шукаємо
      moveForward(forwardSpeed, forwardSpeed);
    }

    delay(100);
  }
}
