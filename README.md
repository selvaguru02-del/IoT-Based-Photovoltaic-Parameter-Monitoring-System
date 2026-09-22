**IoT-Based Photovoltaic Parameter Monitoring System**

An IoT-enabled solar photovoltaic (PV) monitoring system built around an Arduino Mega 2560 and NodeMCU ESP8266. 
The system measures important PV and environmental parameters, 
processes the sensor readings, and sends them over Wi-Fi to a Firebase Realtime Database for remote monitoring.

**Overview**

Solar PV systems benefit from continuous monitoring because output can be affected by operating conditions and problems such as faulty connections, dust, shading, and temperature. 
This project implements a low-cost wireless monitoring approach that allows PV parameters to be observed remotely instead of relying only on manual inspection.

The prototype uses a 5 W polycrystalline solar panel. Voltage, current, light intensity, temperature, and humidity are measured by sensors connected to the Arduino Mega 2560. 
Power is calculated from measured voltage and current. The Arduino processes the readings and transfers the data to a NodeMCU ESP8266 through serial communication. The ESP8266 then uploads the information to Firebase through Wi-Fi, enabling real-time observation from a cloud interface.

**Features**

Real-time PV parameter monitoring

Wireless transmission using Wi-Fi

Firebase Realtime Database integration

Voltage measurement

Current measurement using ACS712

Power calculation (P = V × I)

Light-intensity measurement using an LDR

Temperature and humidity measurement using DHT11

Arduino Serial Plotter visualization

Remote monitoring through cloud/web and mobile-compatible interfaces

System Architecture

The project follows a three-layer IoT architecture:

Sensing/Processing Layer – Sensors collect PV and environmental measurements and the Arduino Mega 2560 processes them.

Network/Transport Layer – The NodeMCU ESP8266 provides Wi-Fi connectivity and transfers the readings over the network.

Application Layer – Firebase provides cloud-based real-time data storage and remote access to the monitored parameters.

**Hardware Requirements**

Component

5 W Polycrystalline Solar Panel
  -PV energy source under monitoring

Arduino Mega 2560
  -Sensor acquisition and data processing

NodeMCU ESP8266
  -Wi-Fi connectivity and cloud communication

Voltage Sensor
  -Measures PV output voltage

ACS712 Current Sensor
  -Measures PV/load current

LDR Sensor
  -Measures light intensity in lux

DHT11
  -Measures temperature and humidity

Regulated Power Supply
  -Supplies required circuit power

Connecting wires / load
  -Prototype interconnection and testing
  Solar Panel Ratings Used in the Prototype
  
**Solar Panel Ratings Used in the Prototype**

-Maximum power: 5 W
-Rated operating voltage: 8 V
-Rated operating current: 0.59 A
-Open-circuit voltage: 10 V
-Short-circuit current: 0.67 A

**Software Requirements**

-Arduino IDE
-ESP8266 board package for Arduino IDE
-DHT library
-ArduinoJson library
-FirebaseArduino library
-Firebase Realtime Database

The Arduino and NodeMCU exchange the processed sensor information using serial communication.

**Measurements**

Voltage

The voltage sensor uses a voltage-divider approach. The implementation in the report uses R1 = 30 kΩ and R2 = 7.5 kΩ to calculate the panel voltage from the Arduino ADC value.

Current

An ACS712 Hall-effect current sensor is used. The Arduino reads the analog sensor voltage and converts it into current using the sensor sensitivity used in the prototype code.

Power

PV output power is calculated as:

Power (W) = Voltage (V) × Current (A)

Light Intensity

An LDR connected to A2 is used to estimate incident light intensity in lux.

Temperature and Humidity

A DHT11 connected to A3 provides temperature in degrees Celsius and relative humidity as a percentage.

**Setup**

Install the Arduino IDE.

Add ESP8266 board support through Arduino IDE Board Manager.

Select NodeMCU 1.0 (ESP-12E Module) for the ESP8266 program.

Install the required libraries: DHT, ArduinoJson, and FirebaseArduino.

Connect the voltage, ACS712, LDR, and DHT11 sensors to the Arduino Mega according to the pin table above.

Connect the Arduino Mega and NodeMCU for serial data transfer.

Create a Firebase project and configure a Realtime Database.

Configure the NodeMCU firmware with the required Wi-Fi and Firebase project credentials.

Upload the sensor-acquisition program to the Arduino Mega.

Upload the communication/cloud program to the NodeMCU ESP8266.

Power the system and observe readings through the Arduino serial tools and Firebase database.

**Security note:** Do not commit Wi-Fi passwords, Firebase secrets, API keys, or other credentials to a public GitHub repository. Store credentials in a local configuration file excluded with .gitignore, or use another secret-management method.

**Results**

The prototype was used to monitor voltage, current, temperature, humidity, and light intensity periodically from morning to evening.
The report presents readings over time intervals from approximately 9:00 AM to 6:00 PM. Sensor readings were processed by the Arduino, transferred to the NodeMCU, and uploaded to the Firebase Realtime Database. 
The same real-time measurements were also visualized as graphs using the Arduino IDE Serial Plotter.

**Applications**

Small solar PV installations
Remote PV performance monitoring
Preventive-maintenance support
Solar research and educational prototypes
Smart-grid and renewable-energy monitoring concepts
Extension to industrial and commercial solar installations

**Future Improvements**

The report proposes several improvements for future versions, including:
Use more accurate and properly calibrated sensors.
Verify current measurements with a clamp meter during practical deployment.
Design a dedicated PCB to improve reliability and reduce wiring/disconnection problems.
Test the monitoring system in real operating environments.
Scale the architecture for larger solar plants and preventive-maintenance applications.

**Project Goal**

The goal of this project is to demonstrate how IoT can simplify photovoltaic-system supervision by combining low-cost sensors, microcontrollers, wireless communication, and cloud storage. 
Remote access to operating data can help users understand PV performance and support maintenance decisions without continuous on-site supervision.

**License**

No license is specified in the project report. Before publishing the repository, choose an appropriate open-source license if you want others to use, modify, or distribute the project.
