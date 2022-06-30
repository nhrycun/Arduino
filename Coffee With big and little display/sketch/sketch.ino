
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int sensorPin = A0;
const float baselineTemp = 21.0;
int reply;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);                                    //This opens up the serial port to communicate to the computer.
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {  // A for loop that acts much like an array in sintax structure.
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display(); 
}



void loop() {
  // put your main code here, to run repeatedly:

  int sensorVal = analogRead(sensorPin);
  //Serial.print("The Temp Senor Value: ");
  //Serial.print(sensorVal);
  // Convert the ADC reading to a voltage reading
  float voltage = (sensorVal / 1024.0) * 5.0;
  //Serial.print("  The Volts: ");
  //Serial.print(voltage);
  //Serial.print(", degrees C: ");
  // Convert the voltage to a temperature in degrees.
  float temperature = ((voltage - 0.5) * 100);
  //Serial.println(temperature);
  int temperatureC = (voltage - 0.5) * 100;
  //Serial.println(temperatureC);
  Serial.write(temperatureC);

  if (temperature < baselineTemp + 9) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("COLD!!");
    lcd.setCursor(1, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    digitalWrite(2, HIGH);
    //    delay(1000);
    //    digitalWrite(2,LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

    //Little Display
      delay(2000);
  display.clearDisplay();
display.startscrollright(0x00, 0x0F);
display.invertDisplay(true);

  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(temperatureC);
  display.display();


  } else if (temperature >= baselineTemp + 9 && temperature < baselineTemp + 11) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Warm");
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    lcd.setCursor(1, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);

        //Little Display
      delay(2000);
  display.clearDisplay();
display.startscrollright(0x00, 0x0F);
display.invertDisplay(true);

  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(temperatureC);
  display.display();

  } else if (temperature >= baselineTemp + 11 && temperature < baselineTemp + 14) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Drink, it's ");
    lcd.setCursor(0, 1);
    lcd.print("perfect.");
    lcd.setCursor(8, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

        //Little Display
      delay(2000);
  display.clearDisplay();
display.startscrollright(0x00, 0x0F);
display.invertDisplay(true);

  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(temperatureC);
  display.display();

  } else if (temperature >= baselineTemp + 14) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Too hot.");
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    lcd.setCursor(1, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);

        //Little Display
      delay(2000);
  display.clearDisplay();
display.startscrollright(0x00, 0x0F);
display.invertDisplay(true);

  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(temperatureC);
  display.display();
  }
  delay(1000);
}
