int FSR;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop() {
  FSR = 1023 - analogRead(A0);
  //FSR =analogRead(A0);
  Serial.print("FSR Value = ");
  Serial.println(FSR);
  Serial1.print("FSR Value = ");
  Serial1.println(FSR);
  
  // Check if the FSR value is below the threshold (500)
  if (FSR  > 500) {
   Serial.println("Object removed");
   Serial1.println("Object removed");
  }

  delay(500);
}

