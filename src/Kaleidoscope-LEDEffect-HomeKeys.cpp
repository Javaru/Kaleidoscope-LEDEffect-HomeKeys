#include <Kaleidoscope-Hardware-Model01.h>
#include <Kaleidoscope-Hardware.h>
#include "Kaleidoscope-LEDEffect-HomeKeys.h"

namespace kaleidoscope {

    /*
       From "Why is cRGB data structure bgr inside"
          https://community.keyboard.io/t/why-is-crgb-data-structure-bgr-inside/431
       It is in BGR order because that’s the order the hardware wants, and having the struct in the same order allows
       the firmware to just copy buffers over, without having to rearrange them first. This is considerably more
       performant. It is called cRGB mostly for historical reasons, Color or something would perhaps be more appropriate.
       Renaming to cBGR would be wrong, though, because other hardware may very well have a different order (for example,
       the Shortcut is GRB).

       You can use the CRGB macro which arranges the r/g/b order to the hardware-specific order at compile time (thus
       no performance penalty): cRGB ActiveModColorEffect::sticky_color = CRGB(0xff, 0, 0)
       */

    cRGB LEDHomeKeys::non_home_key_color = CRGB(0x30, 0x30, 0x30);

//    cRGB LEDHomeKeys::index_finger_color = (cRGB) {0x00, 0x00, 0x9f};
    cRGB LEDHomeKeys::index_finger_color =  CRGB(0x9f, 0x00, 0x00);

//    cRGB LEDHomeKeys::non_index_fingers_color = (cRGB) {0x9f, 0x00, 0x00};
    cRGB LEDHomeKeys::non_index_fingers_color = CRGB(0x00, 0x00, 0x9f);

//    cRGB LEDHomeKeys::thumb_color = (cRGB) {0x70, 0x00, 0x50};
    cRGB LEDHomeKeys::thumb_color = CRGB(0x50, 0x00, 0x70);

    void LEDHomeKeys::onActivate(void) {
        ::LEDControl.set_all_leds_to(non_home_key_color);

        // Row & Col map available at http://www.keyboard-layout-editor.com/#/gists/208ec9c7f9a08382c101b558f1d983b1
        ::LEDControl.setCrgbAt(2, 4, index_finger_color);           // Left Index (F)
        ::LEDControl.setCrgbAt(2, 3, non_index_fingers_color);      // Left Middle (D)
        ::LEDControl.setCrgbAt(2, 2, non_index_fingers_color);      // Left Ring (S)
        ::LEDControl.setCrgbAt(2, 1, non_index_fingers_color);      // Left Pinky (A)
        ::LEDControl.setCrgbAt(1, 7, thumb_color);                  // Left Thumb (bksp)

        ::LEDControl.setCrgbAt(2, 11, index_finger_color);          // Right Index (J)
        ::LEDControl.setCrgbAt(2, 12, non_index_fingers_color);     // Right Middle (K)
        ::LEDControl.setCrgbAt(2, 13, non_index_fingers_color);     // Right Ring (L)
        ::LEDControl.setCrgbAt(2, 14, non_index_fingers_color);     // Right Pinky (;)
        ::LEDControl.setCrgbAt(1, 8, thumb_color);                  // Right Thumb (space)
    }
}

kaleidoscope::LEDHomeKeys LEDHomeKeys;
