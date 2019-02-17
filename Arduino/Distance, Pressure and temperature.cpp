#include <Adafruit_BMP085.h>
#include <Wire.h>
Adafruit_BMP085 bmp;

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
  Serial.print("Temperature = ");
    Serial.print(bmp.readRawTemperature()/1000);
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");
 distance = (duration/2) / 29.1;
 Serial.print("Distance");
Serial.println (distance);
 if (distance <= 150){
 tone(9,250,1000);
 }
 else {
 noTone(9);
 }
}
