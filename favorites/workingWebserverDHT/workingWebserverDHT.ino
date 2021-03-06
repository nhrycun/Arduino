#include <dht.h>



#define dht_apin 18  // set the pin for the sensor output. Output has a resister 108mhz on it.
dht DHT;


#include <WiFi.h>

//const char* ssid = "NTH Telus";
//const char* password = "cgwxk2ntzt";
const char* ssid = "NTH";
const char* password = "teresa3884";

//Background Images for the website
//const char* bgCalm = "https://drive.google.com/uc?export=view&id=1XSnYp3YTNQmV2nWWJrZg07X6IXtezxnk";
//const char* bgAngry = "https://drive.google.com/uc?export=view&id=1HUMCTw977PAL5y9UZpfz9o42BD4YNtbB";

WiFiServer server(80);

String hostname = "OfficeTemperature";

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);  // led Pin
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.setHostname(hostname.c_str());  //define hostname
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    delay(500);  //Delay to let system boot
    Serial.println("DHT11 Humidity & temperature Sensor\n\n");
    delay(1000);  //Wait before accessing Sensor
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("GatewayIP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS 1: ");
  Serial.println(WiFi.dnsIP(0));
  Serial.print("DNS 2: ");
  Serial.println(WiFi.dnsIP(1));

  server.begin();
}

int value = 0;

void loop() {

  WiFiClient client = server.available();  // listen for incoming clients
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char character = client.read();
        Serial.write(character);
        if (character == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 15");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          if (((DHT.temperature > 21) && (DHT.temperature < 28)) || ((DHT.humidity > 21) && (DHT.humidity < 81))) {
            client.println("<body style=\"background-image: url('https://drive.google.com/uc?export=view&id=1HUMCTw977PAL5y9UZpfz9o42BD4YNtbB'); background-size: cover; background-repeat: no-repeat;\">");
          }
          client.print("<Title>Arduino Office Temperature </Title>");
          client.print("<h1>Office Temperature</h1>");
          client.print("<h4>Temperature in C: ");
          client.print(int(DHT.temperature));
          client.print("C");
          client.print("</h4><h4>Humidity: ");
          client.print(int(DHT.humidity));
          client.print("%");
          if (DHT.humidity > 80) {
            client.println("<body style=\"background-image: url('https://drive.google.com/uc?export=view&id=1HUMCTw977PAL5y9UZpfz9o42BD4YNtbB'); background-size: cover; background-repeat: no-repeat;\">");
            client.print("<h4>Humidity is too high</h4>");
          }
          if (DHT.humidity < 20) {
            client.println("<body style=\"background-image: url('https://drive.google.com/uc?export=view&id=1HUMCTw977PAL5y9UZpfz9o42BD4YNtbB'); background-size: cover; background-repeat: no-repeat;\">");
            client.print("<h4>Humidity is too low</h4>");
          }
          client.println("</h4>");
          if (DHT.temperature > 27) {
            client.println("<body style=\"background-image: url('https://drive.google.com/uc?export=view&id=1HUMCTw977PAL5y9UZpfz9o42BD4YNtbB'); background-size: cover; background-repeat: no-repeat;\">");
            client.print("<h4>Turn the fan on!</h4>");
          }
          if (DHT.temperature < 20) {
            client.println("<body style=\"background-image: url('https://drive.google.com/uc?export=view&id=1HUMCTw977PAL5y9UZpfz9o42BD4YNtbB'); background-size: cover; background-repeat: no-repeat;\">");
            client.print("<h4>Turn the A/C off!</h4>");
          }

          client.println("<br />");
          client.println("</html>");
          break;
        }

        if (character == '\n') {
          currentLineIsBlank = true;
        } else if (character != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
  DHT.read11(dht_apin);

  Serial.print("Current humidity = ");
  Serial.print(int(DHT.humidity));
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(int(DHT.temperature));
  Serial.println("C  ");
  delay(1000);
}