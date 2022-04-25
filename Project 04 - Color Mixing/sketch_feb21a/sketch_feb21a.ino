const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup(){
  Serial.begin(9600);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
    
}

void loop(){
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  
  Serial.print(" Raw Sensor Values  \t  red:  ");
  Serial.print(redSensorValue);
  
  Serial.print(" Raw Sensor Values  \t  green:  ");
  Serial.print(greenSensorValue);
  
  Serial.print(" Raw Sensor Values  \t  blue:  ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print(" Mapped Sensor Values \t red:  ");
  Serial.print(redValue);
  Serial.print(" Mapped Sensor Values \t green:  ");
  Serial.print(greenValue);
  Serial.print(" Mapped Sensor Values \t blue:  ");
  Serial.print(blueValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
    
}