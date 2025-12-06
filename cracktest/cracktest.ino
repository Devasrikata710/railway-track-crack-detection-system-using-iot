const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
const int ENA = 9;
const int ENB = 10;
const int TRIG_PIN = 11;
const int ECHO_PIN = 12;
const int BUZZER_PIN = 13;
const int LED = 8;

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gpsSerial(2, 3);
TinyGPSPlus gps;

const int MOTOR_SPEED = 150;
const int STOP_DISTANCE = 5;

float distance;
float duration;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(9600);
  gpsSerial.begin(9600);

  Serial.println("🚗 Ultrasonic Obstacle Detection Started");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  distance = (duration * 0.034) / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (distance <= STOP_DISTANCE && distance > 0) {
    stopMotors();
    digitalWrite(LED, HIGH);
    tone(BUZZER_PIN, 450);
    Serial.println("⚠ Obstacle detected! Stopped.");

    if (gps.location.isValid()) {
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
    } else {
      Serial.println("GPS not available");
    }

    delay(700);
  } 
  else {
    moveForward(MOTOR_SPEED);
    noTone(BUZZER_PIN);
    digitalWrite(LED, LOW);
  }

  delay(100);
}

void moveForward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}