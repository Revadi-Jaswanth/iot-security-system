# Task 3: IoT Security System

## Components
- ESP32‑CAM module (AI‑Thinker)
- PIR motion sensor
- Breadboard & jumper wires
- Smartphone with Blynk app (Email widget)

## Implementation Steps
1. **Circuit Setup**  
   - PIR output→GPIO13, VCC→5V, GND→GND.  
   - Connect camera pins per your ESP32‑CAM module.
2. **Blynk Configuration**  
   - Create project; enable Email widget; note Blynk token.
3. **Upload Code**  
   - Add camera_config, Blynk token, Wi‑Fi creds in `SecuritySystem.ino`.
   - Upload using ESP32‑CAM board settings.
4. **Test**  
   - Move in front of sensor; check email for captured image.
