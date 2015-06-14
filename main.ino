#include "stupidc.h"

Orientation orientation;

void setup() {
  Serial.begin(115200);
}

void loop() {
  updateOrientation(orientation);
  Serial.print("Orientation: "); Serial.print(orientation.pitch);
  Serial.print("\t"); Serial.print(orientation.roll);
  Serial.print("\t"); Serial.print(orientation.yaw); Serial.println();
}


int updateOrientation(Orientation &o) {
  if (Serial.available() > 0) {
    o.roll = Serial.parseFloat();
    o.pitch = Serial.parseFloat();
    o.yaw = Serial.parseFloat();
    char garbage[20];
    Serial.readBytesUntil('\0', garbage, 20);
  }
  return 1;
}

