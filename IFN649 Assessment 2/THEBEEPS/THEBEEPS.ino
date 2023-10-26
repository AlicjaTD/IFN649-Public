// #define LEDPIN 1
// #define BUZZERPIN 2  // Replace with the actual buzzer pin

// void setup() {
//   // Setup serial for monitor and Setup Serial1 for BlueTooth
//   Serial.begin(9600);
//   Serial1.begin(9600);
//   pinMode(LEDPIN, OUTPUT);
//   pinMode(BUZZERPIN, OUTPUT);  // Set the buzzer pin as an output
// }

// void loop() {
//   if (Serial1.available() > 0) {
//     String str = Serial1.readStringUntil('\n');
//     Serial.println(str);  // Print the received message
//     if (str == "LED_ON") {
//       digitalWrite(LEDPIN, HIGH);  // Turn on the LED
//       Serial.println("LED ON");
//     } else if (str == "LED_OFF") {
//       digitalWrite(LEDPIN, LOW);  // Turn off the LED
//       Serial.println("LED OFF");
//     } else if (str == "BUZZER_ON") {
//       digitalWrite(BUZZERPIN, HIGH);  // Activate the buzzer
//       Serial.println("BUZZER ON");
//     } else if (str == "BUZZER_OFF") {
//       digitalWrite(BUZZERPIN, LOW);  // Deactivate the buzzer
//       Serial.println("BUZZER OFF");
//     }
//   }
// }




// #define LEDPIN 1

// void setup() {
//     // Setup serial for monitor and Setup Serial1 for BlueTooth
//     Serial.begin(9600);
//     Serial1.begin(9600);
//     pinMode(LEDPIN, OUTPUT);
// }

// void loop() {
//     if (Serial1.available() > 0) {
//         String str = Serial1.readStringUntil('\n');
//         Serial.println(str);  // Print the received message
//         if (str == "LED_ON") {
//             digitalWrite(LEDPIN, HIGH);
//             Serial.println("LED ON");
//         } else if (str == "LED_OFF") {
//             digitalWrite(LEDPIN, LOW);
//             Serial.println("LED OFF");
//         } else if (str == "BUZZER_ON") {
//             digitalWrite(LEDPIN, HIGH);  // Turn on LED (you can adjust this based on your actual buzzer setup)
//             Serial.println("Buzzer ON");
//         }
//     }
// }





#define LEDPIN 1
void setup() {
// Setup serial for monitor and Setup Serial1 for BlueTooth
Serial.begin(9600);
Serial1.begin(9600);
pinMode(LEDPIN, OUTPUT);
}

void loop() {
  if (Serial1.available() > 0) {
    String str = Serial1.readStringUntil('\n');
    Serial.println(str);  // Print the received message
    if (str == "LED_ON") {
      digitalWrite(LEDPIN, HIGH);
      Serial.println("LED ON");
    } else (str == "LED_OFF") {
      digitalWrite(LEDPIN, LOW);
      Serial.println("LED OFF");
    }
  }
}



// //Downstream Communication Example
// void loop() {
// // Process commands from bluetooth first.
// if(Serial1.available() > 0){
//   String str = Serial1.readString().substring(0);
//   Serial.println(str);
//   if(str == "LED_ON"){
//   digitalWrite(LEDPIN, HIGH);
//   Serial.println("LED ON");
//   } else if(str == "LED_OFF"){
//    digitalWrite(LEDPIN, LOW);
//    Serial.println("LED OFF"); 
//   }
// }
// }