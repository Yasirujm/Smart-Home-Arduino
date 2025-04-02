#include <Servo.h>

int echoPin1 = 10;
int trigPin1 = 5;
long duration1; // sound wave
int distance1;  // Distance measurement
Servo doorServo1; 
bool isDoor1Open = false; // Track the door state

int echoPin2 = 6;  // Echo pin for the second ultrasonic sensor
int trigPin2 = 7;   // Trigger pin for the second ultrasonic sensor
long duration2;     // Variable for sound wave for the second sensor
int distance2;      // Distance measurement for the second sensor
Servo doorServo2;   // Create a Servo object for the second door
bool isDoor2Open = false; // Track the state of the second door

int echoPin3 = 11;  // Echo pin for the third ultrasonic sensor
int trigPin3 = 12;   // Trigger pin for the third ultrasonic sensor
long duration3;     // Variable for sound wave for the third sensor
int distance3;      // Distance measurement for the third sensor
Servo doorServo3;   // Create a Servo object for the third door
bool isDoor3Open = false; // Track the state of the third door

int ledPinRain = 4;      // Define the LED pin for rain sensor
int rainSensorPin = A3;  // Define the rain sensor pin
int motorPin = 1;        // Pin to control the motor
int fanThreshold = 29;   // Temperature threshold to turn on the motor (adjust as needed)

#include <DHT.h>

#define DHTPIN 2         // Pin where the temp sensor is connected
#define DHTTYPE DHT22    // DHT 22 (AM2302) sensor type

DHT dht(DHTPIN, DHTTYPE);

const int ledPinLight = 13; // LED pin for light sensor
const int ldrPin = A0;      // LDR pin
int light = 0;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  doorServo1.attach(9); // Attach the servo to pin 9

  pinMode(trigPin2, OUTPUT);// ultrasonic 2
  pinMode(echoPin2, INPUT);//ultrasonic 2
  doorServo2.attach(3); // servo 2 pin

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  doorServo3.attach(8); // Attach the servo for the third door to pin 8

  
  pinMode(ledPinRain, OUTPUT); // Set the LED pin for rain sensor as an output
  pinMode(ledPinLight, OUTPUT);// Set the LED pin for light sensor as an output
  pinMode(motorPin, OUTPUT);   // Set the motor pin as an output
  dht.begin();                // Initialize the DHT sensor
  pinMode(ldrPin, INPUT);     // Initialize the LDR pin as an input
  Serial.begin(9600);         // Enable serial monitor
}

void loop() {
  digitalWrite(trigPin1, LOW);  // Clears trigPin condition.
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH); // Sets trigPin high for 10 microseconds.
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH); // Returns sound wave travel time in microseconds
  distance1 = duration1 * 0.034 / 2;  // Calculating the distance: sound wave / 2

  Serial.print("Distance 1 : ");
  Serial.print(distance1);
  Serial.println(" cm");

  if (distance1 <= 15) {
    // Open the door when the distance is less than or equal to 50 cm
    if (!isDoor1Open) {
      doorServo1.write(160); // Adjust the servo position to open the door (90 degrees)
      isDoor1Open = true; // Set the door state to open
    }
  } else {
    // Close the door if it's open and the distance exceeds 50 cm
    if (isDoor1Open) {
      doorServo1.write(0); // Close the door by resetting the servo position (0 degrees)
      isDoor1Open = false; // Set the door state to closed
    }
  }

  digitalWrite(trigPin2, LOW);  // Clears trigPin2 condition.
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH); // Sets trigPin2 high for 10 microseconds.
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH); // Returns sound wave travel time in microseconds
  distance2 = duration2 * 0.034 / 2;  // Calculating the distance: sound wave / 2

  Serial.print("Distance 2 : ");
  Serial.print(distance2);
  Serial.println(" cm");

  if (distance2 <= 15) {
    // Open the second door when the distance is less than or equal to 50 cm
    if (!isDoor2Open) {
      doorServo2.write(160); // Adjust the servo position to open the second door (90 degrees)
      isDoor2Open = true; // Set the state of the second door to open
    }
  } else {
    // Close the second door if it's open and the distance exceeds 50 cm
    if (isDoor2Open) {
      doorServo2.write(0); // Close the second door by resetting the servo position (0 degrees)
      isDoor2Open = false; // Set the state of the second door to closed
    }
  }

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;

  Serial.print("Distance 3 : ");
  Serial.print(distance3);
  Serial.println(" cm");

  // Control the third door
  if (distance3 <= 10) {
    if (!isDoor3Open) {
      doorServo3.write(120);
      isDoor3Open = true;
    }
  } else {
    if (isDoor3Open) {
      doorServo3.write(0);
      isDoor3Open = false;
    }
  }

  int value = analogRead(rainSensorPin);   // Read analog value from the rain sensor
  float temperature = dht.readTemperature();// Read temperature in Celsius
  int ldrStatus = analogRead(ldrPin);       // Read the status of the LDR value

  Serial.print("Rain Sensor Value: ");
  Serial.println(value);                    // Print the rain sensor value to the serial monitor

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (value < 900) { // Check if the value is less than 600 (indicating heavy rain)
    blinkLED(ledPinRain); // Call the blinkLED function to blink the rain LED
    Serial.println("Heavy rain detected");
  } else {
    digitalWrite(ledPinRain, LOW); // Turn off the rain LED if it's not heavy rain
  }

  // Check if the temperature exceeds the threshold
  if (!isnan(temperature) && temperature > fanThreshold) {
    // Turn on the motor
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor turned ON");
  } else {
    // Turn off the motor
    digitalWrite(motorPin, LOW);
    Serial.println("Motor turned OFF");
  }

  // Check light level and control the light LED
  if (ldrStatus <= 150) {
    digitalWrite(ledPinLight, HIGH); // Turn on the light LED
    Serial.println("Room is dark, LED is ON");
  } else {
    digitalWrite(ledPinLight, LOW); // Turn off the light LED if it's bright
    Serial.println("Room is bright, LED is OFF");
  }

  Serial.print("Light Level: ");
  Serial.println(ldrStatus);
  
  delay(2000); // Delay between readings
}

void blinkLED(int pin) {
  // Blink the LED on and off
  digitalWrite(pin, HIGH); // Turn on the LED
  delay(500);               // Delay for half a second (500 milliseconds)
  digitalWrite(pin, LOW);  // Turn off the LED
  delay(500);               // Delay for half a second (500 milliseconds)
}