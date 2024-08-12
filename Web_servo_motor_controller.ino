#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <ESP32Servo.h>
#include <SPIFFS.h> 

const int servoPin = 16; // Pin connected to the servo motor
Servo myServo;
AsyncWebServer server(80);

void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);

    // Attach the servo to the pin
    myServo.attach(servoPin);

    // Initialize SPIFFS
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    // Connect to Wi-Fi
    WiFi.begin("your_SSID", "your_PASSWORD");

    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("Connected to WiFi");

    // Print the IP address
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Serve the HTML file
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", String(), false);
    });

    // Handle setting the servo angle
    server.on("/setAngle", HTTP_GET, [](AsyncWebServerRequest *request){
        if (request->hasParam("value")) {
            String angleValue = request->getParam("value")->value();
            int angle = angleValue.toInt();
            Serial.print("Received angle: ");
            Serial.println(angle);
            myServo.write(angle); // Set the servo angle
            Serial.print("Servo angle set to: ");
            Serial.println(angle);
            request->send(200, "text/plain", "OK");
        } else {
            Serial.println("No value received");
            request->send(400, "text/plain", "Bad Request");
        }
    });

    // Start the server
    server.begin();
}

void loop() {
    // Nothing to do here, everything is handled asynchronously
}
