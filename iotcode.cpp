// Constants:
const int ledPin = 13;   // LED pin
const int flexPin = A0;  // Flex sensor pin
const int flexPin1 = A1;  // Flex sensor pin
const int threshold = 130; // Set a threshold value for LED blinking
const int threshold1 = 315; // Set a threshold value for LED blinking

// Variables:
int value; // Variable to store sensor value
int value1; // Variable to store sensor value

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start serial communication
}

void loop() {
  value = analogRead(flexPin); // Read flex sensor value
  //Serial.print("Flex Sensor 1 Value: ");
  //Serial.println(value); // Print the sensor value
  value1 = analogRead(flexPin1); // Read flex sensor value
  Serial.print("Flex Sensor 2 Value: ");
  Serial.println(value1); // Print the sensor value

  if (value > threshold || value1 > threshold1) {  // If value is greater than threshold
    Serial.println("Bending detected! Blinking LED...");
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    delay(200);                  // Wait
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    delay(200);                  // Wait
  } else {
    Serial.println("No bending detected.");
    digitalWrite(ledPin, LOW);   // Keep LED OFF
  }

  delay(100); // Small delay before next reading
}
