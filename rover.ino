#include "movement.h" // Movement lib
#include "sensors.h"
#include "lastmoves.h"

int sensors[3];
bool sensorsBits[3];
bool senseBlack = false;
long iter = 0;
bool serialAvail = false;
Dirs last = NONE;
Dirs lastMovements[5] = {NONE, NONE, NONE, NONE, NONE};
byte lastMovementsIdx = 0;

void setup() {
  senseBlack = false;
  setThreshold(20);
  setModifiers(10, 7, 10);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

void loop() {
  char text[30] = {};
  bool extreme = false;
  delay(0);
  stopAll();
  delay(250);
  readSensors();
  sensorsToBools();
  
  sprintf(text, "%d %d, %d %d, %d %d -", sensors[0], sensorsBits[0], sensors[1], sensorsBits[1], sensors[2], sensorsBits[2]);
  if (serialAvail) {
    //Serial.print(text);
  }
  if (!senseBlack) {  
    if (!sensorsBits[0] && !sensorsBits[2]) { 
     // Serial.print("forward ...\n");
      last = FORWARD;
      instantMove(128, 128);
      delay(100);
      return;
    }
    else if (sensorsBits[0] && !sensorsBits[2]) {
    //  Serial.print("to left of line\n"); 
    last = LEFT;
    instantMove(-172, 172);
      delay(50);
      return;
    }
    else if (sensorsBits[2] && !sensorsBits[0]) { 
     // Serial.print("to right of line\n");
     last = RIGHT;
      instantMove(172, -172); 
      delay(50);
      return;
    } else if (sensorsBits[0] && sensorsBits[1] && sensorsBits[2]) {
        
    } else if (sensorsBits[0] && !sensorsBits[1] && sensorsBits[2]) {
      digitalWrite(13, HIGH);
      delay(250);
      digitalWrite(13, LOW);
      delay(250);
      digitalWrite(13, HIGH);
      delay(250);
      digitalWrite(13, LOW);
      senseBlack = true;
      return;
    }
    else {
      
    
    }
  } else {
    sensorsBits[0] = !sensorsBits[0];
      sensorsBits[1] = !sensorsBits[1];
      sensorsBits[2] = !sensorsBits[2];
      if (exclusive(FORWARD)) {
      last = FORWARD;
      instantMove(128, 128);
      delay(50);
      } else if (exclusive(LEFT)) {
        last = RIGHT;
      instantMove(172, -172); 
      delay(50);
      return;
      } else if (exclusive(RIGHT)) {
        last = LEFT;
    instantMove(-172, 172);
      delay(50);
      return;
  }


  // Jerk the robot.
//  lastMovements[lastMovementsIdx] = last;
//  lastMovementsIdx ++;
//  if (lastMovementsIdx == 5) {
//    lastMovementsIdx = 0;
//  }
//  Dirs listType = listAllSame();
//  switch (listType) {
//    case LEFT:
//      instantMove(-172, 172);
//      delay(100);
//      break;
//    case RIGHT: 
//      instantMove(172, -172); 
//      delay(100);
//      break;
//  }
}
}
