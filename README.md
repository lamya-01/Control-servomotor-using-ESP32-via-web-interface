
https://github.com/user-attachments/assets/3c21e133-79cf-4835-bcd0-e4d45bd48732
# Control-servomotor-using-ESP32-via-web-interface

### Overview

This project demonstrates how to control a servo motor using an ESP32 microcontroller via a web interface. The user can adjust the servo angle from 0° to 180° using a slider in a web browser. The ESP32 serves a webpage where the angle can be set, and it also controls the servo motor based on the user's input.

### Features

- Web-based Control: The servo motor angle is controlled through a web interface.
- ESPAsyncWebServer: Handles HTTP requests asynchronously.
- SPIFFS: Serves the HTML page from the ESP32's flash memory.
- Servo Motor Control: Adjust the angle of the servo motor between 0° and 180°.

### Components Required

- ESP32 Development Board
- Servo Motor
- Jumper Wires
- Power Supply for ESP32 ( you can use Arduino UNO )
- Internet connection with Wi-Fi

### Software Requirements

- Arduino IDE (with ESP32 board support)
- ESPAsyncWebServer Library
- ESP32Servo Library
- AsyncTCP Library
- SPIFFS Library

### Wiring

1. Servo Motor:
   - Signal (Yellow/White) to GPIO 16 on ESP32
   - VCC (Red) to 3.3V on ESP32 or to 5v on Arduino UNO.
   - GND (Black/Brown) to GND on ESP32 or Arduino UNO if use it .

2. ESP32:
   - GND (Black/Brown) to GND on Arduino UNO.(if you use Arduino UNO).
   - Connect to your computer via USB for programming.
   - Connect Arduino UNO to your computer via USB.

### Project Setup

1. Install Arduino IDE and Libraries:
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Add ESP32 to Arduino IDE by adding the following URL in Preferences > Additional Boards Manager URLs:
    
     https://dl.espressif.com/dl/package_esp32_index.json
     
   - Install the following libraries via Library Manager:
     - ESPAsyncWebServer
     - ESP32Servo
     - AsyncTCP
     - SPIFFS

2. Code Setup:
   - Copy the provided code into your Arduino IDE.
   - Replace "your_SSID" and "your_PASSWORD" in the setup() function with your Wi-Fi network credentials.
   - Upload the code to your ESP32.

3. SPIFFS Setup:
   - Create a folder named data in the same directory as your Arduino sketch.
   - Place your index.html file inside this data folder.
   - Use the [ESP32 filesystem uploader](https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/) tool to upload the index.html to SPIFFS.

4. Run the Project:
   - Open the Serial Monitor in Arduino IDE and set the baud rate to 115200.
   - Upon successful connection to Wi-Fi, the ESP32 will print its IP address in the Serial Monitor.
   - Open a web browser and enter the ESP32's IP address to access the servo control webpage.

### Web Interface

- Slider Control: Use the slider to set the desired angle for the servo motor. The angle will update in real-time and will be displayed next to the slider.


 ### Example

https://github.com/user-attachments/assets/3dc935c1-1540-4362-82f9-4df1b8ed70cb











 


 
 


https://github.com/user-attachments/assets/7749b112-1c29-4e5d-bedb-ff77c9bca19b

