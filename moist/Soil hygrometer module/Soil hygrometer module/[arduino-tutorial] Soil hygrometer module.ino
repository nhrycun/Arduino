/*	Arduino Tutorial - How to use a Soil Hygrometer Module
	Dev: Michalis Vasilakis // Date: 18/05/2016 // www.ardumotive.com	*/


//Constants 
const int hygrometer = 34;	//Hygrometer sensor analog pin output at pin 34 of ESP32 Arduino

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//Variables 
int value;

void setup(){
	
	Serial.begin(9600);
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

void loop(){
	
	// When the plant is watered well the sensor will read a value 380~400, I will keep the 400 
	// value but if you want you can change it below. 
	
	value = analogRead(hygrometer);		//Read analog value 
	value = constrain(value,400,1023);	//Keep the ranges!
	value = map(value,400,1023,100,0);	//Map value : 400 will be 100 and 1023 will be 0
	Serial.print("Soil humidity: ");
	Serial.print(value);
	Serial.println("%");

  delay(2000);
  display.clearDisplay();

  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(value);
  display.display(); 

	delay(2000); //Read every 2 sec.
}
