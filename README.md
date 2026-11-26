# FISH-FEEDING-SYSTEM-WITH-WATER-QUALITY-MONITORING
FISH FEEDING SYSTEM WITH WATER QUALITY MONITORING USING IOT

1. Project Overview

The Fish Feeding System with Water Quality Monitoring using IoT is designed to automate fish feeding and monitor water conditions in a fish tank.

The system uses an ESP8266 Wi-Fi microcontroller to monitor water temperature, pH value, and water level. The Blynk IoT mobile application allows users to monitor sensor readings remotely and control fish feeding.

2. Objectives

- Automate fish feeding using a servo motor.
- Monitor water temperature using a DHT11 sensor.
- Monitor water pH using a pH sensor.
- Detect water level using a water level sensor.
- Automatically activate the water pump when the water level is low.
- Provide remote monitoring and control using the Blynk application.

3. Components Required

Hardware Components

- ESP8266 NodeMCU
- DHT11 Temperature Sensor
- pH Sensor
- Water Level Sensor
- Servo Motor
- Water Pump
- Relay Module (if required)
- Jumper Wires
- Breadboard
- Fish Food Container
- Power Supply

Software Requirements

- Arduino IDE
- Blynk IoT Application
- ESP8266 Board Package
- DHT Sensor Library
- Servo Library
- Blynk Library

4. Pin Configuration

Component| ESP8266 Pin
Servo Motor| D4
DHT11 Sensor| D1
Water Level Sensor| D6
Water Pump| D7
pH Sensor| A0

5. Working Principle

1. The DHT11 sensor measures the temperature around the fish tank.
2. The pH sensor measures the pH level of the aquarium water.
3. The water level sensor detects whether the water level is sufficient.
4. When the water level is low, the ESP8266 activates the water pump.
5. The servo motor rotates to release fish food when the user presses the feeding button in the Blynk application.
6. Sensor readings are displayed through the Blynk mobile application.

6. Blynk Application Configuration

The Blynk application is used for remote monitoring and controlling the system.

Virtual Pin| Function
V0| Temperature Display
V1| Fish Feeding Control
V2| pH Value Display
V3| Water Level Display

7. Features

- Automatic water pump control.
- Remote fish feeding control.
- Real-time temperature monitoring.
- Water pH monitoring.
- Water level detection.
- Wireless monitoring using Wi-Fi.

8. Advantages

- Reduces manual work.
- Prevents unnecessary fish feeding.
- Helps maintain suitable water conditions.
- Saves time and effort.
- Supports remote monitoring.

9. Future Scope

- Automatic pH correction.
- Automatic feeding based on time scheduling.
- Cloud-based data storage.
- Mobile notifications for abnormal water conditions.
- Improved water quality monitoring using additional sensors.

10. Conclusion

The Fish Feeding System with Water Quality Monitoring using IoT provides an efficient solution for fish tank management. It combines automated feeding, water quality monitoring, and remote control using ESP8266 and the Blynk IoT application. This system helps reduce manual effort and supports better fish tank maintenan
