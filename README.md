# Kaleidoscope-LEDEffect-HomeKeys


A simple LED effect for Kaleidoscope that lights up the ten home keys.

## Using the extension

To use the plugin, include the header, and tell the firmware to use it:
```c++
#include <Kaleidoscope-LEDEffect-HomeKeys.h>

void setup() {

  Kaleidoscope.setup();
  
  Kaleidoscope.use(&LEDHomeKeys);
 
}
```

You can also optionally override one or more of the default LED colors used:
```c++
#include <Kaleidoscope-LEDEffect-HomeKeys.h>

void setup() {

  Kaleidoscope.setup();
  
  Kaleidoscope.use(&LEDHomeKeys);
  
  // OPTIONALLY OVERRIDE THE PREDEFINED LED COLORS
  // Set the home thumb keys to a dim green using decimal values
  LEDHomeKeys.thumb_color = CRGB(0,128,0);
  // Set the home index finger keys to bright red (255,0,0) using hexadecimal
  LEDHomeKeys.index_finger_color = CRGB(0xFF, 0x00, 0x00);
  // Set non index finger home keys to yellow (255, 255, 0) using decimal values
  LEDHomeKeys.non_index_fingers_color = CRGB(255,255,0);
  
}
```

## Plugin properties

The plugin provides the `LEDHomeKeys` object, which has the following
properties to set the LED colors used. In all cases, the values are
`cRGB` values. They can be set either with decimal or hexadecimal values
 and can be set to `0,0,0` to turn off the corresponding LEDs.

### `.index_finger_color`
Sets the color to use for the two index finger home keys. The default is a
 moderate red `#9F0000`.

### `.non_index_fingers_color`
Sets the color to use for the eight non index (and non thumb) finger home
keys. The default is a moderate blue `#00009F`.

### `.thumb_color`
Sets the color to use for the two thumb home keys. The default is a dim
purple `#500070`.


## Plugin methods

There are no public methods.


## Dependencies

* [Kaleidoscope-LEDControl](https://github.com/keyboardio/Kaleidoscope-LEDControl)
