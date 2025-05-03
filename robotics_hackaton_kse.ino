

int SENSOR_0_PIN = 2;
int SENSOR_1_PIN = 3;
int SENSOR_2_PIN = 4;
int SENSOR_3_PIN = 5;
int SENSOR_4_PIN = 6;

int L2 = SENSOR_0_PIN;
int L1 = SENSOR_1_PIN;
int C0 = SENSOR_2_PIN;
int R2 = SENSOR_3_PIN;
int R1 = SENSOR_4_PIN;

int MOTOR_LEFT_PIN = 8;
int MOTOR_RIGHT_PIN = 9;

#pragma region Setup

void setup_pins() {
    pinMode(SENSOR_0_PIN, INPUT);
    pinMode(SENSOR_1_PIN, INPUT);
    pinMode(SENSOR_2_PIN, INPUT);
    pinMode(SENSOR_3_PIN, INPUT);
    pinMode(SENSOR_4_PIN, INPUT);
    pinMode(MOTOR_LEFT_PIN, OUTPUT);
    pinMode(MOTOR_RIGHT_PIN, OUTPUT);
    Serial.println("Pins initialized");
}

void setup() 
{
  Serial.begin(115200);
  setup_pins();
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
  delay(100);
}
