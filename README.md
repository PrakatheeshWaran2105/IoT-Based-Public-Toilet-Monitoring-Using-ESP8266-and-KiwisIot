# IoT-Based-Public-Toilet-Monitoring-Using-ESP8266-and-KiwisIot
An IoT-based public toilet monitoring system using NodeMCU ESP8266 and an HC-SR04 ultrasonic sensor to monitor occupancy and transmit real-time sensor data to the KiwisIoT cloud dashboard.
IoT-Based Public Toilet Monitoring Using ESP8266 and KiwisIoT

About the Project

The IoT-Based Public Toilet Monitoring System uses NodeMCU ESP8266 and an HC-SR04 ultrasonic sensor to monitor the occupancy status of a public toilet area. The ultrasonic sensor measures the distance, and the ESP8266 processes the readings to identify whether the monitored area is occupied or available.

The project integrates with the KiwisIoT IoT platform for cloud-based monitoring. The ESP8266 connects to Wi-Fi and uses the KiwisIoT library to transmit sensor information to the configured device topic. The platform receives the data and makes it available through the online dashboard.

Two monitoring channels are used in KiwisIoT:

Channel 0 – Distance: Displays the ultrasonic sensor measurement in centimeters.

Channel 1 – Occupancy Status: Displays the availability status, where 0 represents Available and 1 represents Occupied.

Through the KiwisIoT dashboard, users can remotely view the latest distance measurements and occupancy information. This project demonstrates how IoT connectivity and cloud-based data visualization can support smarter public facility management.

Project Link:https://www.hackster.io/prakatheesh2105/iot-based-public-toilet-monitoring-using-esp8266-and-kiwisio-70ba0f

KiwisIoT Platform:

https://www.kiwisiot.in/

Explore More Projects:

https://github.com/Kiwistron/KiwisIoT-Projects
