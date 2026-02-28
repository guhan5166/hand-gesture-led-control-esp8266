# Hand Gesture LED Control using ESP8266

This project demonstrates a real-time hand gesture controlled LED system using a laptop camera, Python, and an ESP8266 microcontroller over Wi-Fi.

## 🔧 Technologies Used
- Python
- OpenCV
- MediaPipe
- ESP8266 (NodeMCU)
- Arduino IDE
- Wi-Fi (HTTP communication)

## ⚙️ Hardware Components
- NodeMCU ESP8266
- 3 LEDs
- 3 × 220Ω Resistors
- Breadboard and jumper wires

## 🧠 Working Principle
1. Laptop camera captures hand gestures.
2. Python detects and counts fingers using MediaPipe.
3. Python sends HTTP commands over Wi-Fi.
4. ESP8266 receives commands and controls LEDs.

## ✋ Gesture Mapping
  Gesture      Action 
  1 Finger     LED 1 ON 
  2 Fingers    LED 2 ON 
  3 Fingers    LED 3 ON 
  5 Fingers    All LEDs ON 
  Closed Fist  All LEDs OFF 

## ▶️ How to Run
1. Upload `hand_led_control.ino` to ESP8266 using Arduino IDE.
2. Connect ESP8266 to Wi-Fi and note its IP address.
3. Update ESP8266 IP in `hand_led_control.py`.
4. Create and activate Python virtual environment.
5. Install required Python libraries.
6. Run the Python script.

## 📽️ Demo Video
https://www.linkedin.com/posts/guhan5166_python-opencv-mediapipe-activity-7416152394004180992-RJ7T?utm_source=social_share_send&utm_medium=android_app&rcm=ACoAAGL0OwgBfeybBRfI52tgYAi14AVKBheuAGQ&utm_campaign=copy_link

## 📌 Applications
- Touchless control systems
- Smart home automation
- Human–computer interaction

## 👤 Author
Guhan R.
