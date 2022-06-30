/*
  Arduino LSM9DS1 - Simple Magnetometer

  This example reads the magnetic field values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 10 Jul 2019
  by Riccardo Rizzo

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>
 #define RED 22     
 #define BLUE 24     
 #define GREEN 23
 #define LED_PWR 25

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

    pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(LED_PWR, OUTPUT);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;



  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
    if(x > 50 || x < 10){
          digitalWrite(RED, LOW); // turn the LED off by making the voltage LOW
  delay(200);            // wait for a second
  digitalWrite(GREEN, LOW);
  delay(200);  
  digitalWrite(BLUE, LOW);
  delay(200);  
  digitalWrite(RED, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(200);                         
  digitalWrite(GREEN, HIGH);
  delay(200);  
  digitalWrite(BLUE, HIGH);
  delay(200);  
  digitalWrite(LED_PWR, HIGH);
  delay(200);  
  digitalWrite(LED_PWR, LOW);
  delay(200);

    }
  }
}