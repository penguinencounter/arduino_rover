#include "movement.h"  // To add to your sketch, use #include "movement.h"


void boosterStart(int left, int right) {
    if (left > 0) {
        analogWrite(9, 255);
        analogWrite(10, 0);
    }
    else if (left < 0) {
        analogWrite(10, 255);
        analogWrite(9, 0);
    }
    if (right > 0) {
        analogWrite(5, 255);
        analogWrite(6, 0);
    }
    else if (right < 0) {
        analogWrite(6, 255);
        analogWrite(5, 0);
    }
    delay(100);
}

void instantMove(int left, int right) {
    /** 
     * Moves the robot forward/back with specified motor speeds.
     * No boost start.
    **/
    if (left > 0) {
        analogWrite(9, left);
        analogWrite(10, 0);
    }
    else if (left < 0)
    {
        analogWrite(9, 0);
        analogWrite(10, left);
    }
    else {
        analogWrite(9, 0);
        analogWrite(10, 0);
    }
    if (right > 0) {
        analogWrite(5, right);
        analogWrite(6, 0);
    }
    else if (right < 0)
    {
        analogWrite(5, 0);
        analogWrite(6, right);
    }
    else {
        analogWrite(5, 0);
        analogWrite(6, 0);
    }
    
}

void move(int left, int right) {
    /** 
     * Moves the robot forward/back with specified motor speeds.
     * Uses 100ms for the boost start.
    **/
    boosterStart(left, right);
    instantMove(left, right);
}

void stopAll() {
    instantMove(0, 0);
}
