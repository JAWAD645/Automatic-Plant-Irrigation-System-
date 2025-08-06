

# 🌱 Automatic Plant Irrigation System with Remote-Controlled Shade

An **Arduino-based smart irrigation system** that monitors soil moisture and automatically waters plants when they are dry. Additionally, it features a **remote-controlled shade** to manage sunlight exposure. A **16x2 LCD display** shows real-time soil moisture and system status, making it perfect for home gardening and small-scale farming.

---

## ✨ Features

* **Automatic Watering**: Waters plants only when soil moisture drops below a threshold.
* **Real-Time Display**: LCD shows soil moisture percentage and pump status.
* **Remote Shade Control**: Servo-controlled shade can be opened/closed using an IR remote.
* **Water Conservation**: Reduces water wastage by irrigating only when needed.
* **Compact & Cost-Effective**: Easy to build with widely available components.

---

## 🛠️ Components Used

| # | Component                        |
| - | -------------------------------- |
| 1 | Arduino Uno                      |
| 2 | Soil Moisture Sensor             |
| 3 | Relay Module (for water pump)    |
| 4 | Water Pump                       |
| 5 | 16x2 LCD with I2C                |
| 6 | Servo Motor (for shade)          |
| 7 | IR Receiver Module + Remote      |
| 8 | Breadboard & Jumper Wires        |
| 9 | Power Supply (USB or 5V Adapter) |

---

## 🔌 Circuit Diagram

![Circuit Diagram](link-to-your-schematic-image)
*(Replace with actual image link from your repo)*

---

## ⚙️ How It Works

1. The **soil moisture sensor** continuously monitors the soil’s humidity level.
2. If moisture drops below a predefined threshold, the **Arduino triggers the relay** to activate the water pump.
3. The **LCD display** updates the current soil moisture percentage and pump status in real time.
4. The **IR remote** allows manual control of the **servo motor** to open or close the shade.

---

## 💻 Arduino Code

The project uses three libraries:

* [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C) – for LCD display
* [`Servo`](https://www.arduino.cc/reference/en/libraries/servo/) – for servo motor control
* [`IRremote`](https://github.com/z3t0/Arduino-IRremote) – for IR remote control

### Steps to Upload:

1. Install Arduino IDE → [Download](https://www.arduino.cc/en/software)
2. Install required libraries via **Library Manager**
3. Paste the provided `.ino` code into the IDE
4. Select **Board: Arduino Uno** and correct **COM port**
5. Upload the code to your Arduino

---

## 🚀 Getting Started

### Prerequisites

* Arduino IDE installed
* Required libraries added
* Basic understanding of circuit wiring

### Setup

1. Connect components as per the **circuit diagram**.
2. Calibrate the soil moisture threshold in the code (`dryThreshold` variable).
3. Upload the code to your Arduino board.
4. Power the system via USB or 5V adapter.

---

## 📊 Applications

* Smart home gardens 🌿
* Indoor plant monitoring
* Small-scale greenhouse irrigation
* Water conservation projects

---

## 🌟 Advantages

* Saves water and reduces human effort
* Provides real-time monitoring
* Manual sunlight control for sensitive plants
* Affordable and easy to assemble

---

## ⚠️ Limitations

* Requires recalibration of moisture sensor over time
* IR remote needs line-of-sight
* Dependent on power supply for continuous operation

---

## 🔮 Future Enhancements

* Add **Wi-Fi/GSM module** for remote monitoring via mobile app
* Integrate **automatic sunlight detection** for shade control
* Power system using **solar energy** for sustainability

---

## 📷 Project Preview

*(Add real project photos here once uploaded)*

---

## 🤝 Contributing

Contributions are welcome!

* Fork this repository
* Make improvements
* Create a pull request

---

## 📝 License

This project is licensed under the **MIT License** – feel free to use and modify it.

---

## ❤️ Acknowledgments

* Open-source Arduino libraries community
* Inspiration from sustainable gardening initiatives

---
