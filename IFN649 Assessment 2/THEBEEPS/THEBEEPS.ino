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


