#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>

// Pins
int traffic_1_R = D3;
int traffic_1_G = D2;
int traffic_2_R = D1;
int traffic_2_G = D0;

// Wi-Fi credentials
const char* ssid = "SSID";
const char* password = "PWD";

// Server URL
const char* serverURL = "https://andu.jaidrew.co.in/ambulance/direction.txt";

// Blinking time for green light
int blink_interval = 500;

void setup() {
  Serial.begin(115200);

  pinMode(traffic_1_R, OUTPUT);
  pinMode(traffic_1_G, OUTPUT);
  pinMode(traffic_2_R, OUTPUT);
  pinMode(traffic_2_G, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to Wi-Fi\n");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi\n");
}

void loop() {
  // Step 1: Default state: Light 1 green, Light 2 red
  digitalWrite(traffic_1_G, HIGH);
  digitalWrite(traffic_1_R, LOW);
  digitalWrite(traffic_2_G, LOW);
  digitalWrite(traffic_2_R, HIGH);
  //delay(500);

  // Step 3: Get server response
  String response = "";
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure();
    HTTPClient http;

    Serial.println("Sending GET request...");
    http.begin(client, serverURL);
    int httpCode = http.GET();

    if (httpCode > 0) {
      response = http.getString();
      response.trim();  // Remove whitespace or newline characters
      Serial.println("Server Response: '" + response + "'");
    } else {
      Serial.println("HTTP GET request failed!");
    }

    http.end();
  }

  // Step 2: reverse for 2 seconds
  digitalWrite(traffic_1_G, LOW);
  digitalWrite(traffic_1_R, HIGH);
  digitalWrite(traffic_2_G, HIGH);
  digitalWrite(traffic_2_R, LOW);
  delay(500);

  // Step 4: Handle response
  if (response == "NS") {
    Serial.println("\nAmbulance mode\n");
    digitalWrite(traffic_1_G, LOW);
    digitalWrite(traffic_1_R, HIGH);
    digitalWrite(traffic_2_G, HIGH);
    digitalWrite(traffic_2_R, LOW);
    delay(10000);
  }
}
