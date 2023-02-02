#include <Wire.h>

int soilSensor() {
  return Wire.requestFrom(address, numbytes); // read the analog value from sensor
}