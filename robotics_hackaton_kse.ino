
#include "move.h"
#include "navigation.h"

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

static int sensor_data[5];
void readSensors(bool print = false, bool nice = false) {
  sensor_data[0] = digitalRead(SENSOR_0_PIN) ? 0 : 1;
  sensor_data[1] = digitalRead(SENSOR_1_PIN) ? 0 : 1;
  sensor_data[2] = digitalRead(SENSOR_2_PIN) ? 0 : 1;
  sensor_data[3] = digitalRead(SENSOR_3_PIN) ? 0 : 1;
  sensor_data[4] = digitalRead(SENSOR_4_PIN) ? 0 : 1;
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

namespace Navigation {
  StackArray<Node> nodes;
  
  void addNode(bool left, bool right, bool center) {
      Node newNode(left, right, center);
      nodes.push(newNode);
  }

  const int baseSpeed = 120;
  const int StampTime = 100;

  void run() {
    MoveStamp current_move = MoveStamp(0, 0, 0);
    Node current_node = nodes.peek();

    while (!nodes.isEmpty()) {
      current_node = nodes.pop();
      if (!current_node.left_branch && !current_node.right_branch && !current_node.center_branch) {
        // If there is no branches left move back node
        // Here handle logic of moving back maybe it can not work
        continue;
      }
      // if (current_node.moves.isEmpty()) {
      //   continue;
      // }
      
      // Choose first move based on branches
      if (current_node.center_branch) {
        current_move = MoveStamp(baseSpeed, 0, StampTime);
      } else if (current_node.right_branch) {
        current_move = MoveStamp(baseSpeed, 90, StampTime);
      } else if (current_node.left_branch) {
        current_move = MoveStamp(baseSpeed, -90, StampTime);
      }

      while (true) {
        move(current_move);
        current_node.moves.push(current_move);
        readSensors();

        if (sensor_data[2] == 1 && sensor_data[0] == 0 && sensor_data[1] == 0 && sensor_data[3] == 0 && sensor_data[4] == 0) {
          // Move forward
          current_move = MoveStamp(baseSpeed, 0, StampTime);
          continue;
        }

        // Here more logic and sensor parsing

        // Condition of returning back
        if (sensor_data[0] == 0 && sensor_data[1] == 0 && sensor_data[2] == 0 && sensor_data[3] == 0 && sensor_data[4] == 0) {
          while (!current_node.moves.isEmpty()) {
            MoveStamp move = current_node.moves.pop();
            moveReverse(move);
          }
        }

        if (sensor_data[1] == 1 && sensor_data[2] == 1 && sensor_data[3] == 1) {
          // Put back current node to stack
          nodes.push(current_node);
          // Create new node and add branches depend on logic
          nodes.push(Node(true, true, true));
          break;
        }

        // remove current branch from node path suggestions
        if (current_node.moves.isEmpty()) {
          if (current_node.center_branch) {
            current_node.center_branch = false;
          } else if (current_node.right_branch) {
            current_node.right_branch = false;
          } else if (current_node.left_branch) {
            current_node.right_branch = false;
          }
          nodes.push(current_node);
          break;
        }
        
      }
      
    }
  }
};

#pragma region Setup

void setup_sensor() {
    pinMode(SENSOR_0_PIN, INPUT);
    pinMode(SENSOR_1_PIN, INPUT);
    pinMode(SENSOR_2_PIN, INPUT);
    pinMode(SENSOR_3_PIN, INPUT);
    pinMode(SENSOR_4_PIN, INPUT);
    Serial.println("Pins initialized");
    Navigation::addNode(false, true, false);
}

void setup() 
{
  Serial.begin(115200);
  setup_sensor();
  setup_motors();
}

#pragma endregion



static const int patterns[8][5] = {
    {1,1,0,1,1},  // пряма центр
    {1,1,0,0,1},  // зсув вліво
    {1,0,0,1,1},  // зсув вправо
    {0,0,0,1,1},  // крутий поворот вліво
    {1,1,0,0,0},  // крутий поворот вправо
    {1,0,0,0,0},  // сильний зсув вправо
    {0,0,0,0,1},  // сильний зсув вліво
    {1,1,1,1,1}   // не бачимо лінії
};

void generateSensorPattern(int (&sensors)[5], int pattern_id) {
    for(int i = 0; i < 5; ++i) {
        sensors[i] = !(patterns[pattern_id][i]);
    }
}


const int baseSpeed = 120;
const int turnAdjust = 40;

int sensor_sum = 0;
void loop() 
{
  // readSensors(true, true);
  // sensor_sum = sensor_data[0] + sensor_data[1] + sensor_data[2] + sensor_data[3] + sensor_data[4];
  // // move(100, 100);
  
  // Navigation::run();
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  analogWrite(MOTOR_RIGHT_ANALOG_PIN, 150);
  analogWrite(MOTOR_LEFT_ANALOG_PIN, 150);

  delay(10);
}

// const int smallTurnSpeed = 100;
// const int forwardSpeed = 80;

// void recoverToCenterLine() {

//   while (true) {

//     if (C0) break; // Знайшли центр — виходимо

//     if (L2 || L1) {
//       // Малий поворот ліворуч
//       move(smallTurnSpeed - 40, smallTurnSpeed + 40);
//     }
//     else if (R1 || R2) {
//       // Малий поворот праворуч
//       move(smallTurnSpeed + 40, smallTurnSpeed - 40);
//     }
//     else {
//       // Просто рух вперед, шукаємо
//       move(forwardSpeed, forwardSpeed);
//     }

//     delay(100);
//   }
// }
