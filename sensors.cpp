#include "sensors.h"
#include "Arduino.h"

extern int sensors[3];
extern bool sensorsBits[3];
static int _threshold = 0;


void setThreshold(int threshold) {
  _threshold = threshold;
}


void readSensors() {
  sensors[0] = analogRead(A0);
  sensors[1] = analogRead(A1);
  sensors[2] = analogRead(A2);
}


void sensorsToBools() {
  sensorsBits[0] = sensors[0] >= _threshold;
  sensorsBits[1] = sensors[1] >= _threshold;
  sensorsBits[2] = sensors[2] >= _threshold;
}
