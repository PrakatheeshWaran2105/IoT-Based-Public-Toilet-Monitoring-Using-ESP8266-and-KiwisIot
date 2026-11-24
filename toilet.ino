
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT topic
const char* topic = "YOUR_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

// Pin connections
#define TRIG_PIN D1
#define ECHO_PIN D2
#define BUZZER_PIN D5

// Flood warning distance (adjust after testing)
const float FLOOD_THRESHOLD = 10.0;

float distance;
bool floodAlert = false;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  kiwisiot.begin();

  Serial.println("Smart Street Flood Monitoring Started");
}

void loop() {
  kiwisiot.run();

  // Send ultrasonic trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Sensor reading failed");
    delay(1000);
    return;
  }

  // Calculate distance in cm
  distance = duration * 0.0343 / 2;

  // Check flood condition
  floodAlert = (distance <= FLOOD_THRESHOLD);

  // Buzzer control
  digitalWrite(BUZZER_PIN, floodAlert ? HIGH : LOW);

  // Serial Monitor output
  Serial.print("Water Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (floodAlert) {
    Serial.println("WARNING: FLOOD ALERT!");
  } else {
    Serial.println("Status: NORMAL");
  }

  // Send data to KiwisIoT
  kiwisiot.send("0", String(distance));
  kiwisiot.send("1", floodAlert ? "1" : "0");

  delay(1000);
}
