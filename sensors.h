#pragma once
#include "rover.h"
void setThreshold(int threshold);
void readSensors();
void sensorsToBools();
void setModifiers(int left, int middle, int right);
bool exclusive(Dirs sensor);
