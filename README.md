# smart-light-control
# 🚨 Arduino Ultrasonic Sensor Based Automatic Light Control

## 📌 Project Overview

* This project is an **automatic light control system** using an **Arduino Uno** and an **ultrasonic sensor**.
* The ultrasonic sensor detects the presence of a person/object based on the distance measured from the sensor.
* When an object/person comes within a predefined distance, the Arduino automatically **turns ON the light**.
* When the object/person moves away beyond the predefined distance, the Arduino **turns OFF the light**.
* The system reduces the need for manual switching and can be used for **automatic lighting and basic presence detection applications**.

---

## 🧰 Components Required

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* LED / Light
* Resistor for LED (typically 220Ω)
* Breadboard
* Jumper wires
* USB cable
* Power supply

---

## 🔌 Connections

### HC-SR04 → Arduino Uno

| HC-SR04 Pin | Arduino Uno |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | Digital Pin |
| ECHO        | Digital Pin |

### LED → Arduino Uno

| LED         | Arduino Uno                         |
| ----------- | ----------------------------------- |
| Anode (+)   | Digital Output Pin through resistor |
| Cathode (-) | GND                                 |

> The exact Arduino pins used for TRIG, ECHO, and LED should match the pins defined in the source code.

---

## ⚙️ Working Principle

* The **HC-SR04 ultrasonic sensor** is used to measure the distance of an object from the sensor.
* The Arduino sends a short electrical pulse to the **TRIG pin** of the ultrasonic sensor.
* The HC-SR04 sends an ultrasonic sound wave toward the object.
* The sound wave reflects back from the object and is received by the sensor.
* The sensor produces a pulse on its **ECHO pin**.
* The duration of this ECHO pulse represents the time taken by the ultrasonic wave to travel to the object and return.
* Arduino measures this time using the `pulseIn()` function.
* The distance is calculated using the speed of sound.

### 📐 Distance Calculation

The basic relationship is:

```text
Distance = (Time × Speed of Sound) / 2
```

The division by 2 is required because the ultrasonic wave travels:

```text
Sensor → Object
Object → Sensor
```

Therefore, the measured time represents the **round-trip travel time**.

---

## 🔄 Complete System Flow

```text
        START
          ↓
   Initialize Arduino
          ↓
   Initialize Sensor
          ↓
   Send TRIG Pulse
          ↓
   Ultrasonic Wave
          ↓
      Object
          ↓
   Echo Received
          ↓
 Calculate Distance
          ↓
  Is Object Within
  Set Distance?
       ↙       ↘
     YES        NO
      ↓          ↓
   Light ON    Light OFF
       ↘        ↙
       Read Distance
          Again
```

---

## 🧠 Program Working

* The Arduino first configures the ultrasonic sensor pins and LED pin.
* The `loop()` function continuously checks the distance measured by the ultrasonic sensor.
* A short HIGH pulse is generated on the TRIG pin to start an ultrasonic measurement.
* The sensor sends an ultrasonic burst.
* Arduino measures the duration of the returning ECHO pulse.
* The measured time is converted into distance.
* The calculated distance is compared with a predefined threshold value.
* If the measured distance is **less than or equal to the threshold**, the Arduino considers an object/person to be present.
* The Arduino sets the LED output HIGH, turning the light **ON**.
* If the measured distance is **greater than the threshold**, the Arduino sets the LED output LOW, turning the light **OFF**.
* This process continuously repeats while the Arduino is powered.

---

## 💡 Example Operation

Suppose the threshold distance is set to **50 cm**:

```text
Object distance = 30 cm
        ↓
30 cm < 50 cm
        ↓
Object detected
        ↓
Light ON
```

If the object moves away:

```text
Object distance = 80 cm
        ↓
80 cm > 50 cm
        ↓
Object not detected
        ↓
Light OFF
```

---

## 🛠️ Main Concepts Used

* Arduino Uno
* Embedded C/C++ programming
* Digital input and output
* Ultrasonic distance measurement
* GPIO control
* Sensor interfacing
* Conditional statements
* `digitalWrite()`
* `digitalRead()`
* `pulseIn()`
* Distance calculation
* Real-time sensor-based control

---

## 🎯 Applications

* Automatic room lighting
* Corridor lighting
* Staircase lighting
* Presence detection
* Energy-saving lighting systems
* Smart-home prototypes
* Basic automation systems

---

## 🚀 Future Improvements

The project can be extended by:

* Replacing the LED with a relay-controlled AC/DC light.
* Adding an **LDR** so that the light operates only when it is dark.
* Adding multiple ultrasonic sensors for larger areas.
* Adding an LCD/OLED display to show the measured distance.
* Adding a timer so that the light remains ON for a specific duration.
* Using an ESP32 to add **Wi-Fi-based monitoring and control**.
* Adding motion/presence logic to make the system more reliable.

---

## 📁 Project Structure

```text
Arduino-Ultrasonic-Automatic-Light/
│
├── Arduino-Ultrasonic-Automatic-Light.ino
├── README.md
└── circuit/
    └── circuit-diagram.png
```

---

## 📷 Project Demonstration

Add your circuit image/video here:

```markdown
![Project Circuit](circuit/circuit-diagram.png)
```

You can also add a short demonstration video/GIF showing the light turning ON when an object approaches the ultrasonic sensor.

---

## 👨‍💻 Project Summary

* **Microcontroller:** Arduino Uno
* **Sensor:** HC-SR04 Ultrasonic Sensor
* **Output:** LED/Light
* **Programming Language:** C/C++ (Arduino)
* **Communication:** Digital GPIO
* **Main Function:** Automatic light control based on detected distance
* **Concept:** Sensor-based automation

