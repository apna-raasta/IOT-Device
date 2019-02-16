#include <LiquidCrystal.h> // includes the LiquidCrystal Library
int Contrast=20;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define trigPin 13
#define echoPin 12

void setup() {
 Serial.begin (9600);
 Serial.println("--- Start Serial Monitor SEND_RCVE ---");
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 lcd.print("Hello");
 distance = (duration/2) / 29.1;
Serial.println (distance);
 if (distance <= 150){
 tone(9,400,100);
 }
 else {
 noTone(9);
 }
 delay(50);
}
