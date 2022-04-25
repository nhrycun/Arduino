#include <Servo.h>

Servo myServo;

int const tempPin = A0;
int tempVal;
int angle;
int lightState = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(4, OUTPUT);
  

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
tempVal = analogRead(tempPin);
Serial.print(", tempVal: ");
Serial.print(tempVal);
angle = map(tempVal, 0, 1023, 0, 179);
Serial.print(", angle: ");
Serial.println(angle);

delay(15);
lightState = tempVal;
if(lightState < 154){
  digitalWrite(4, HIGH);
  Serial.print(" Red Light ON!! ");
  myServo.write(angle = 150);
}
else{
  digitalWrite(4, LOW);
  Serial.print(" Red Light OFF!! ");
   myServo.write(angle = 0);
}

}
