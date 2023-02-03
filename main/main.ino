#include <Wire.h>
#include <Arduino_FreeRTOS.h>

#define RELAY_PIN    2  // Arduino pin that connects to relay
#define LED_PIN      4  // pin connected to LED relay transistor for grow lights
#define PHOTO_PIN    A0

#define BLUE_LED     5
#define RED_LED      6

#define THRESHOLD 100

int machinestate;

void setup() {
  
  Serial.begin(9600); //init i2c and serial
  soilSensorInit();

  pinMode(RELAY_PIN, OUTPUT); //init pins

  xTaskCreate(soilCapSense, "Soil Moisture Sensing",
                50, NULL, 2, NULL);
  xTaskCreate(soilTempSense, "Soil Temp Sensing",
                50, NULL, 2, NULL);
  xTaskCreate(photoSense, "Light Level Sensing",
                50, NULL, 2, NULL);
  xTaskCreate(diagLED, "LED Readout",
                50, NULL, 3, NULL);              
  vTaskStartScheduler(); 
}

void loop() {}
