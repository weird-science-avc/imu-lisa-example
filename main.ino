#include "stupidc.h"
const int IMU_MEMORY = 20;
Orientation orientation;
unsigned long duration;
float lastYaw;

void setup() {
  Serial.begin(115200);
  duration = millis();
}

void loop() {
  updateOrientation(orientation);
  if (millis() - duration >= 10) {
    int cmaplus1 = (orientation.yaw + IMU_MEMORY * lastYaw)/(IMU_MEMORY + 1);
    Serial.print("last yaw (10 ms ago): "); Serial.print(lastYaw);
    Serial.print("current yaw: "); Serial.println(cmaplus1);
    lastYaw = cmaplus1;
    Serial.print("roll: "); Serial.print(orientation.roll); Serial.print(" roll: "); Serial.println(orientation.roll);
  }
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

