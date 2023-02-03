#include <Wire.h>
#include "Adafruit_seesaw.h"
#define RELAY_PIN    2

Adafruit_seesaw soil_sense;

bool soilSensorInit() {
  if (!soil_sense.begin(0x36)) {
    Serial.println("error: soil sensor not initialized");
    return false;

  } else {
    Serial.print("soil sensor started");
    return true;
  }
}

void soilCapSense() {
  int valsoil = soil_sense.touchRead(0);
  if (valsoil < 700) {
    digitalWrite(RELAY_PIN, HIGH);
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
  }
  Serial.print("The soil moisture level is: ");
  Serial.println(valsoil);
}

void soilTempSense() {
  float tempvalue = soil_sense.getTemp();
  Serial.print("The Temp is: ");
  Serial.println(tempvalue); 
}

