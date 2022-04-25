
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);

const int sensorPin = A0;
const float baselineTemp = 21.0;
int reply;

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:
  Serial.begin(9600); //This opens up the serial port to communicate to the computer.
  for(int pinNumber = 2; pinNumber <5; pinNumber++){ // A for loop that acts much like an array in sintax structure.
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
 lcd.setCursor(3,0);
  lcd.print("How hot is ");
lcd.setCursor(3,1);
lcd.print("the coffee? ");

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorVal = analogRead(sensorPin);
  Serial.print("The Temp Senor Value: ");
  Serial.print(sensorVal);
  // Convert the ADC reading to a voltage reading
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print("  The Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  // Convert the voltage to a temperature in degrees.
  float temperature = ((voltage - 0.5)*100);
  Serial.println(temperature);
  int temperatureC = (voltage - 0.5)*100;

  if(temperature < baselineTemp+9){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("COLD!!");
    lcd.setCursor(1,1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    digitalWrite(2,HIGH);
//    delay(1000);
//    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
 
  }else if(temperature >= baselineTemp+9 && temperature < baselineTemp+11){
        lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Warm");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  lcd.setCursor(1,1);
  lcd.print("Temp: ");
  lcd.print(temperature);
 
  }else if(temperature >= baselineTemp+11 && temperature < baselineTemp+14){
        lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Drink, it's ");
    lcd.setCursor(0,1);
    lcd.print("perfect.");
  lcd.setCursor(8,1);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);

  }else if(temperature >= baselineTemp+14){
        lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Too hot.");
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
  lcd.setCursor(1,1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  }
  delay(1000);

}
