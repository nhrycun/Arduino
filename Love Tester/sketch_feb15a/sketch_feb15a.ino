const int sensorPin = A0;
const float baselineTemp = 21.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //This opens up the serial port to communicate to the computer.
  for(int pinNumber = 2; pinNumber <5; pinNumber++){ // A for loop that acts much like an array in sintax structure.
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorVal = analogRead(sensorPin);
  Serial.print("The Temp Senor Value: ");
  Serial.print(sensorVal);
  // Convert the ADC reading to a voltage reading
  float voltage = (sensorVal/1024.0)*0.5;
  Serial.print("The Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  // Convert the voltage to a temperature in degrees.
  float temperature = (voltage-0.5)*100;
  Serial.println(temperature);

  if(temperature < baselineTemp+2){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }else if(temperature >= baselineTemp+6){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  delay(1);
}
