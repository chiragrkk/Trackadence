#define BLYNK_TEMPLATE_ID "TMPL3cQIBonVE"
#define BLYNK_TEMPLATE_NAME "Mini Project"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
const char* ssid = "Aakruthi_EXT";
const char* password = "poornimaravi";

// Blynk auth token
char auth[] = "8k34kK4QZ8_AEB8jeygnFvHJiT18la1k"; 

const int trigPin1 = 13;
const int echoPin1 = 14;

const int trigPin2 = 18; 
const int echoPin2 = 19;

const int trigPin3 = 21;  // New ultrasonic sensor
const int echoPin3 = 22;  // New ultrasonic sensor

#define SOUND_VELOCITY 0.034
#define MAX_DISTANCE_CM 400  // Maximum measurable distance in cm

const int RELAY1_PIN = 25; // GPIO pin for relay 1
const int RELAY2_PIN = 26; // GPIO pin for relay 2
const int RELAY3_PIN = 27; // GPIO pin for relay 3

long duration1, duration2, duration3;
float distanceCm1, distanceCm2, distanceCm3;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);  // New sensor setup
  pinMode(echoPin3, INPUT);   // New sensor setup

  // Relay pins setup
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);

  digitalWrite(RELAY1_PIN, HIGH); // Initially turn off all relays
  digitalWrite(RELAY2_PIN, HIGH);
  digitalWrite(RELAY3_PIN, HIGH);

  // Connect to WiFi and Blynk
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  Blynk.begin(auth, ssid, password);
}

float measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distanceCm = duration * SOUND_VELOCITY / 2;

  // Validate distance and return only values within the range
  if (distanceCm >= 0 && distanceCm <= MAX_DISTANCE_CM) {
    return distanceCm;
  } else {
    return -1;  // Return -1 for invalid distances
  }
}

BLYNK_WRITE(V3) {
  int relay1State = param.asInt();
  digitalWrite(RELAY1_PIN, relay1State == 1 ? LOW : HIGH);
  Serial.println(relay1State == 1 ? "Relay 1: ON" : "Relay 1: OFF");
}

BLYNK_WRITE(V4) {
  int relay2State = param.asInt();
  digitalWrite(RELAY2_PIN, relay2State == 1 ? LOW : HIGH);
  Serial.println(relay2State == 1 ? "Relay 2: ON" : "Relay 2: OFF");
}

BLYNK_WRITE(V5) {
  int relay3State = param.asInt();
  digitalWrite(RELAY3_PIN, relay3State == 1 ? LOW : HIGH);
  Serial.println(relay3State == 1 ? "Relay 3: ON" : "Relay 3: OFF");
}

void loop() {
  Blynk.run();

  // Measure distance for each sensor
  distanceCm1 = measureDistance(trigPin1, echoPin1);
  distanceCm2 = measureDistance(trigPin2, echoPin2);
  distanceCm3 = measureDistance(trigPin3, echoPin3);

  // Print sensor data
  if (distanceCm1 != -1) {
    Serial.print("Sensor 1 - Distance (cm): ");
    Serial.println(distanceCm1);
    Blynk.virtualWrite(V0, distanceCm1);
  } else {
    Serial.println("Sensor 1 - Out of range");
  }

  if (distanceCm2 != -1) {
    Serial.print("Sensor 2 - Distance (cm): ");
    Serial.println(distanceCm2);
    Blynk.virtualWrite(V1, distanceCm2);
  } else {
    Serial.println("Sensor 2 - Out of range");
  }

  if (distanceCm3 != -1) {
    Serial.print("Sensor 3 - Distance (cm): ");
    Serial.println(distanceCm3);
    Blynk.virtualWrite(V2, distanceCm3);
  } else {
    Serial.println("Sensor 3 - Out of range");
  }

  delay(5000);  // Wait for 1 second
}
