#include "movement.h" // Movement lib
#include "sensors.h"

int sensors[3];
bool sensorsBits[3];
bool senseBlack = false;


void setup() {
    setThreshold(25);
    Serial.begin(9600);
    while (!Serial) {
       ; // wait for serial port to connect. Needed for native USB
     }
}

void loop() {
    char text[30] = {};
    
    readSensors();
    sensorsToBools();
    sprintf(text, "%d %d, %d %d, %d %d\n", sensors[0], sensorsBits[0], sensors[1], sensorsBits[1], sensors[2], sensorsBits[2]);
    Serial.print(text);
    if (!senseBlack) {

        if (!sensorsBits[0] && !sensorsBits[1] && !sensorsBits[2]) {
            move(64, 64);
        }
        else if (sensorsBits[0] && !sensorsBits[2]) {
            move(255, 0);
            while (sensorsBits[0]) {
              readSensors();
              sensorsToBools();
              delay(200);         
           }
        }
        else if (sensorsBits[2] && !sensorsBits[0]) {
            move(0, 255);
            while (sensorsBits[2]) {
              readSensors();
              sensorsToBools();
              delay(200);         
           }
        } else {
            stopAll();
        }
    } else {
      
    }
    delay(100);
}
