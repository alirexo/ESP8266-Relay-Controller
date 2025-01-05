# ESP8266 Relay Controller

## Overview

This project provides a web-based interface for controlling **5V relays** using an **ESP8266 Wi-Fi module**. It allows you to switch two relay channels (e.g., for lights or appliances) on and off via a simple HTML interface hosted on the ESP8266 itself.

> **Author:** Ali Atabak (ReXo)\
> **License:** Not Set

> ⚠️ **Disclaimer:** This project is for educational purposes only. Any misuse is the responsibility of the user.

---

## Features

- Control up to **2 relays** via Wi-Fi.
- Simple web-based user interface accessible from any browser.
- Supports **ESP8266** microcontroller.

---

## Prerequisites

### Hardware Requirements:

- **ESP8266** development board (e.g., NodeMCU).
- **5V Relay Module** (2 channels).
- USB cable for programming the ESP8266.
- Power supply (5V for relays).

### Software Requirements:

- Arduino IDE (latest version).
- Libraries:
  - `ESP8266WiFi.h`
  - `ESP8266WebServer.h`

---

## Installation

### Step 1: Install Arduino IDE

- Download and install the **Arduino IDE** from the [official Arduino website](https://www.arduino.cc).

### Step 2: Install ESP8266 Board Package

1. Open **Arduino IDE**.
2. Go to **File** -> **Preferences**.
3. Add the following URL in the **Additional Board Manager URLs** field:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

4. Go to **Tools** -> **Board** -> **Boards Manager**.
5. Search for **esp8266** and install it.

### Step 3: Install Required Libraries

1. Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
2. Search for the following libraries and install them:
   - **ESP8266WiFi**
   - **ESP8266WebServer**

### Step 4: Upload the Code

1. Clone this repository:
   ```
   git clone https://github.com/alirexo/ESP8266-Relay-Controller.git
   ```

2. Open the code in Arduino IDE. The main code file is located in `ESP8266_RelayControl_WebServer.cpp`. You can open this file by navigating to it in the cloned folder.

3. Replace the Wi-Fi credentials in the code:
   ```cpp
   const char* ssid = "Your-WiFi-SSID";            // Wi-Fi Name
   const char* password = "Your-WiFi-Password";    // Wi-Fi Password
   ```

4. Select the correct board and port:
   - **Board:** NodeMCU 1.0 (ESP-12E Module).
   - **Port:** The COM port where your ESP8266 is connected.

5. After making the necessary changes, click **Upload** in the Arduino IDE to upload the code to the ESP8266.

---

## Usage

1. After uploading, open the **Serial Monitor** in Arduino IDE and set the baud rate to **115200**.
2. Note the IP address displayed in the Serial Monitor.
3. Open any web browser and enter the IP address (e.g., `http://192.168.1.100`).
4. Use the buttons to control the relays:
   - **Relay 1 ON / OFF**
   - **Relay 2 ON / OFF**

---

## Wiring Diagram

```
Relay 1 -> GPIO D0 (Pin 16)
Relay 2 -> GPIO D1 (Pin 5)
VCC -> 5V
GND -> GND
```

---

## Example Output

```
Connecting to WiFi...
Connected to WiFi
IP Address: 192.168.1.100
```

---

## Troubleshooting

1. **Wi-Fi Not Connecting:** Double-check the SSID and password.
2. **No IP Address Displayed:** Verify the board settings and connections.
3. **Relay Not Responding:** Check GPIO pin connections and power supply.

---

### Made by Ali Atabak (ReXo)

---
