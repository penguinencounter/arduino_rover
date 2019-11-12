#include "movement.h" // Movement lib
#include "sensors.h"

int sensors[3];
bool sensorsBits[3];
bool senseBlack = false;


void setup() {
    setThreshold(150);
}

void loop() {
    if (!senseBlack) {
        readSensors();
        sensorsToBools();
        if (sensorsBits[0] && sensorsBits[2]) {
            senseBlack = true;
            return;
        }
        if (sensorsBits[0]) {
            move(128, 0);
        } else if (sensorsBits[2]) {
            move(0, 128);
        } else {
            move(128, 128);
        }
        
    }
    delay(100);
}
