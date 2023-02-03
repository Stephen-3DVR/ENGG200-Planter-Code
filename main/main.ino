#include <Wire.h>
#include <Arduino_FreeRTOS.h>

#define RELAY_PIN    2  // Arduino pin that connects to relay
#define MOISTURE_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor

#define THRESHOLD 100

void setup() {
  Wire.begin();
  Serial.begin(9600); //init i2c and serial
  soilSensorInit();

  pinMode(RELAY_PIN, OUTPUT); //init pins

  xTaskCreate(soilCapSense, "Soil Moisture Sensing",
                50, NULL, 2, NULL);
  xTaskCreate(soilTempSense, "Soil Temp Sensing",
                50, NULL, 2, NULL);
  xTaskCreate(soilTempSense, "Soil Temp Sensing",
                50, NULL, 2, NULL);              
  vTaskStartScheduler(); 
}

void loop() {}
