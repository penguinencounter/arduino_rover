#include "movement.h"  // To add to your sketch, use #include "movement.h"
#include "Arduino.h"



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
void boosterStart(int left, int right) {
    if (abs(left * 2) > 128) {
      if (left > 0) {
        left = 64;
      } else {
        left = -64;
      }
    }
    if (abs(right * 2) > 128) {
      if (right > 0) {
        right = 64;
      } else {
        right = -64;
      }
    }
    instantMove(left*2, right*2);
    delay(100);
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
