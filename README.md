# Arduino Rover
My Git Repo for our Arduino Rover challenge.

## Download Instructions
 * Click `Clone or Download` in the corner.
 * In the popup box, click `Download ZIP`. If a "Want to be notified" box pops up, ignore it.
 * Wait for the download to finish.
 * Extract the ZIP file:
    * Click the download (at the bottom of the page in Chrome, in the downloads area in Firefox)
    * Click the `Extract all files` button or `Extract` button.
    * Choose to extract the files somewhere memorable.
    * Open the folder, and the folder inside it (`arduino_rover-master`)
    * Copy everything to the folder in which your Arduino sketch resides.

## Use
Add this line to the top of your arduino sketch (`.ino`), and then the library has been added!
```
#include "movement.h"
```
### move(int left, int right)
Move the motor. Negative speeds supported. Boost start will be activated.

### stopAll()
Stop everything.
