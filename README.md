
# Embedded Device Health Monitor

## Overview
An ESP32-based embedded system simulation that monitors temperature and humidity using a DHT22 sensor. It detects threshold violations and activates an LED when high temperature is detected.

## Features
- Real-time temperature monitoring
- Humidity monitoring
- High-temperature alert at 30°C or above
- LED warning indicator
- Low- and high-humidity warnings
- Sensor error handling
- Serial Monitor output

## Hardware and Tools
- ESP32
- DHT22 temperature and humidity sensor
- LED
- Wokwi simulator
- Arduino framework (C++)

## Pin Connections

| Component | ESP32 Pin |
|---|---|
| DHT22 VCC | 3V3 |
| DHT22 DATA | GPIO 15 |
| DHT22 GND | GND |
| LED Anode (+) | GPIO 4 |
| LED Cathode (-) | GND |

## Test Results
- Normal condition: 24°C, 40% humidity — Status NORMAL
- High temperature: 32°C — LED ON and alert displayed
- Low humidity: 15% — Low-humidity warning displayed

## How It Works
The ESP32 reads temperature and humidity values from the DHT22 sensor every two seconds. It compares the readings with configured thresholds and reports the system status through the Serial Monitor. The LED turns on when the temperature reaches 30°C or higher.

## Simulation
https://wokwi.com/projects/478828678086158337

## Author
Nisarga H G
