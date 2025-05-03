// // Стартовий пін, за яким, по зростанню, мають йти наступні
// int LED0_PIN = 2;

// void setup() {
//   Serial.begin(9600);

//   // Записуємо піни від LED0_PIN до LED0_PIN + 5
//   // Це означає, що порти входу датчика мають йти послідовно один за одним
//   // В порядку зростання
//   for (int i = LED0_PIN; i < LED0_PIN + 5; i++) {
//     pinMode(i, INPUT);
//   }
// }

// int* readPins() {
//   static int pinValues[5];
//   for (int i = 0; i < 5; i++) {
//     pinValues[i] = digitalRead(i + LED0_PIN);
//   }
//   return pinValues;
// }

// void loop() {
//   int* values = readPins();
//   for (int i = 0; i < 5; i++) {
//     Serial.print("Пін ");
//     Serial.print(i + 2);
//     Serial.print(": ");
//     Serial.print(values[i]);
//     Serial.print("  ");
//   }
//   Serial.println();
//   delay(250);
// }

