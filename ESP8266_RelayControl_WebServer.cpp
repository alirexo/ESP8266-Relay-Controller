// Program for controlling relays using ESP8266 module
// Author: Ali Etabak (ReXo)
// Description: This code is designed to control two 5V relays through a web-based user interface.
// Purpose: To wirelessly turn devices (such as lights) on and off via Wi-Fi network.

// Adding required libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Configure Wi-Fi network credentials
const char* ssid = "Your-Wife-SSID";            // Wi-Fi network name
const char* password = "Your-Wife-Password";    // Wi-Fi password

// Define GPIO pins for connecting to relays
const int relayPin1 = D0;   // GPIO pin connected to the first relay channel
const int relayPin2 = D1;   // GPIO pin connected to the second relay channel

// Create a web server on port 80
ESP8266WebServer server(80);  

// HTML code for a simple graphical interface to control the relays
String htmlContent = "<html>\
                        <head>\
                          <title>Control Relays</title>\
                          <style>\
                            body { font-family: Arial, sans-serif; text-align: center; padding: 20px; }\
                            .button { padding: 15px 30px; font-size: 18px; cursor: pointer; margin: 10px; border-radius: 5px; border: none; }\
                            .on { background-color: #4CAF50; color: white; }\
                            .off { background-color: #f44336; color: white; }\
                          </style>\
                        </head>\
                        <body>\
                          <h1>Control Relay 1</h1>\
                          <button class='button on' onclick='location.href=\"/relay1/on\"'>Relay 1 ON</button>\
                          <button class='button off' onclick='location.href=\"/relay1/off\"'>Relay 1 OFF</button>\
                          <h1>Control Relay 2</h1>\
                          <button class='button on' onclick='location.href=\"/relay2/on\"'>Relay 2 ON</button>\
                          <button class='button off' onclick='location.href=\"/relay2/off\"'>Relay 2 OFF</button>\
                        </body>\
                      </html>";

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  
  // Set pins as output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, LOW);  // Turn off relay 1
  digitalWrite(relayPin2, LOW);  // Turn off relay 2

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..."); // Attempting to connect to Wi-Fi network
  }
  Serial.println("Connected to WiFi"); // Successful connection to Wi-Fi
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Display IP address assigned to the board

  // Set HTTP routes for controlling relays
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", htmlContent);  // Send HTML interface to browser
  });

  server.on("/relay1/on", HTTP_GET, []() {
    digitalWrite(relayPin1, HIGH);  // Turn on relay 1
    server.sendHeader("Location", "/");  // Redirect to the main page
    server.send(303);  // Redirect to the main page
  });

  server.on("/relay1/off", HTTP_GET, []() {
    digitalWrite(relayPin1, LOW);   // Turn off relay 1
    server.sendHeader("Location", "/");  // Redirect to the main page
    server.send(303);  // Redirect to the main page
  });

  server.on("/relay2/on", HTTP_GET, []() {
    digitalWrite(relayPin2, HIGH);  // Turn on relay 2
    server.sendHeader("Location", "/");  // Redirect to the main page
    server.send(303);  // Redirect to the main page
  });

  server.on("/relay2/off", HTTP_GET, []() {
    digitalWrite(relayPin2, LOW);   // Turn off relay 2
    server.sendHeader("Location", "/");  // Redirect to the main page
    server.send(303);  // Redirect to the main page
  });

  // Start the web server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();  
}
