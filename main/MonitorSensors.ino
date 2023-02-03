#include <Wire.h>
#include "Adafruit_seesaw.h"

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
    if (machinestate != 3){
      machinestate = 2;
    }
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
    if (machinestate != 3){
      machinestate = 1;
    }
  }
  Serial.print("The soil moisture level is: ");
  Serial.println(valsoil);
}

void soilTempSense() {
  float tempvalue = soil_sense.getTemp();
  if (tempvalue > 35.0 || tempvalue < 15.0) {
    machinestate = 3;
    println("TEMPERATURE IS CRITICAL")
  }
  Serial.print("The Temp is: ");
  Serial.println(tempvalue); 
}

void photoSense() {
  int valphoto = analogRead(A0);
  if (valphoto < 126) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  Serial.print("The light level is: ");
  Serial.println(valphoto);
}

void diagLED() {
  switch (machinestate) {
    case 1 : //Buisness as usual
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      break;

    case 2 : //Water dispensing
      digitalWrite(BLUE_LED, HIGH);
      vTaskDelay(250 / portTICK_PERIOD_MS);
      digitalWrite(BLUE_LED, LOW);
      vTaskDelay(250 / portTICK_PERIOD_MS);
      break;

    case 3: //critical values from sensors
      digitalWrite(RED_LED, HIGH);
      vTaskDelay(100 / portTICK_PERIOD_MS);
      digitalWrite(RED_LED, LOW);
      vTaskDelay(100 / portTICK_PERIOD_MS);
      break;
  }
}