#include "sensor.h"
#include <Arduino.h>

bool is_sensor_blocked(int pin) {
  return digitalRead(pin) == 0;
}
