/*
 Task 3: IoT Security System (ESP32-CAM + PIR + Blynk Email)
 Detects motion via PIR, captures image with ESP32-CAM, and emails alert.
*/
#include "esp_camera.h"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Configure camera pins for AI-Thinker module here:
// #include "camera_pins.h" with appropriate camera_config struct

char auth[] = "YourBlynkToken";
char ssid[] = "YourSSID";
char pass[] = "YourPassword";

const int PIR_PIN = 13;           // GPIO13 for PIR sensor
volatile bool motionDetected = false;

void IRAM_ATTR onPIR() {
  motionDetected = true;          // ISR flag
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), onPIR, RISING);
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);
  esp_camera_init(&camera_config);
}

void loop() {
  if (motionDetected) {
    motionDetected = false;
    camera_fb_t *fb = esp_camera_fb_get();
    if (fb) {
      // send email with attachment
      Blynk.email("you@domain.com", 
                  "Motion Detected!", 
                  "See attached photo", 
                  fb->buf, 
                  fb->len);
      esp_camera_fb_return(fb);
    }
  }
  Blynk.run();
}
