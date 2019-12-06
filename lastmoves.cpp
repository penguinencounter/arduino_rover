#include "Arduino.h"
#include "rover.h"
#include "lastmoves.h"
extern Dirs lastMovements[5];

Dirs listAllSame() {
  Dirs currentType = lastMovements[0];
  for (int x = 1; x < 5; x ++) {
    if (lastMovements[x] != currentType) {
      currentType = NONE;
      break;
    }
  }
  return currentType;
}
