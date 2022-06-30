#include <WiFi.h>
#include <WebServer.h>


#include "DHT.h"

#define DHTPIN 18    // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

// float temperature, humidity, pressure, altitude;

/*Put your SSID & Password*/
const char* ssid = "NTH";  // Enter SSID here
const char* password = "teresa3884";  //Enter Password here

WebServer server(80);





DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  
  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");

dht.begin();


}
void loop() {
  server.handleClient();
    // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
    // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  server.send(200, "text/html", SendHTML(h,t,f,hic)); 
  Serial.print(h);
  Serial.print(t);
  Serial.print(f);
  Serial.print(hic);

}

void handle_OnConnect() {
 

}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(float h,float t,float f,float hic){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Temp and Humidity</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP32 Temperature and Humdity</h1>\n";
  ptr +="<p>Temperature: ";
  ptr +=t;
  ptr +="&deg;C</p>";
  ptr +="<p>Humidity: ";
  ptr +=h;
  ptr +="%</p>";
  ptr +="<p>Fahreheit: ";
  ptr +=f;
  ptr +="F</p>";
  ptr +="<p>Heat Index: ";
  ptr +=hic;
  ptr +="C</p>";
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
