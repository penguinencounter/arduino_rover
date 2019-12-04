#include "sensors.h"
#include "Arduino.h"
#include "rover.h"

extern int sensors[3];
extern bool sensorsBits[3];
static int _threshold = 0;
int sensorModifiers[3];

void setThreshold(int threshold) {
  _threshold = threshold;
}


void setModifiers(int left, int middle, int right) {
  sensorModifiers[0] = left;
  sensorModifiers[1] = middle;
  sensorModifiers[2] = right;
}


void readSensors() {
  sensors[0] = analogRead(A0) + sensorModifiers[0];
  sensors[1] = analogRead(A1) + sensorModifiers[1];
  sensors[2] = analogRead(A2) + sensorModifiers[2];
}


void sensorsToBools() {
  sensorsBits[0] = sensors[0] >= _threshold;
  sensorsBits[1] = sensors[1] >= _threshold;
  sensorsBits[2] = sensors[2] >= _threshold;
}


bool exclusive(Dirs sensor) {
  switch (sensor) {
    LEFT:
      return sensorsBits[0] && !sensorsBits[2];
    FORWARD:
      return !sensorsBits[0] && sensorsBits[1] && !sensorsBits[2];
    RIGHT:
      return !sensorsBits[1] && sensorsBits[2];
  }
}
