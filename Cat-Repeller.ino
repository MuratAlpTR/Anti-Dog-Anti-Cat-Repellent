                                                      //  “The project was written by MuratAlpTR” // 

// Animal Repellent using Ultrasonic Sensor

const int trigPin = 9; // Ultrasonic sensor's trigger pin
const int echoPin = 10; // Ultrasonic sensor's echo pin
const int buzzerPin = 11; // Buzzer pin
const int catButtonPin = 3; // Cat button pin

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(catButtonPin, INPUT_PULLUP); // Connect the cat button with an internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < 50) { // If an animal is closer than 50 cm
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer
    delay(1000); // Wait for 1 second
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  }

  // Check the cat button
  if (digitalRead(catButtonPin) == LOW) {
    Serial.println("Cat button pressed!");
    // Perform cat repellent actions here
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500); // Wait for 0.5 seconds
}


                                                      //  “The project was written by MuratAlpTR” // 
