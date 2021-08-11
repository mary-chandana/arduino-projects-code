#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(5,6,8,9,10,11);

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

int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;

void setup()
{
servo_8.attach(8, 500, 2500);    
pinMode(A2, INPUT);
pinMode(2, OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(7, 7);
  if (dist <= 100) {
    servo_8.write(90);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HAVE A NICE DAY!");
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_8.write(0);
    delay(1000); // Wait for 1000 millisecond(s)
  }
    if (analogRead(A2) > 600) {
    digitalWrite(2, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TURN ON");
    lcd.setCursor(0,1);
    lcd.print("THE LIGHTS");
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(2, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if(analogValue>sensorThresh)
  {
    tone(buzzer,1047,1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("EVACUATE");
    delay(1000);
  }
  else
  {
    noTone(buzzer);
    lcd.clear();
    delay(1000);
  }  
     
}