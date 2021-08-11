// C++ code
//
#include <Servo.h>

int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_8;

void setup()
{
  servo_8.attach(8, 500, 2500);

  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(7, 7);
  if (dist <= 100) {
    servo_8.write(90);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_8.write(0);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (digitalRead(2) == 1) {
    digitalWrite(12, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(12, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  dist = 0.01723 * readUltrasonicDistance(3, 3);
  if (dist > 150) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
  } else {
    if (dist > 100 && dist <= 150) {
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
    } else {
      if (dist > 50 && dist <= 100) {
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(9, LOW);
      } else {
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(9, HIGH);
      }
    }
  }
}