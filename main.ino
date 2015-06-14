#include "stupidc.h"

Orientation orientation;

void setup() {}

void loop() {
  updateOrientation(orientation);
}


int updateOrientation(Orientation &o) {
  if (Serial.available() > 0) {
    o.roll = Serial.parseInt();
    o.pitch = Serial.parseInt();
    o.yaw = Serial.parseInt();
    char garbage[20];
    Serial.readBytesUntil('\0', garbage, 20);
  }
  return 1;
}

