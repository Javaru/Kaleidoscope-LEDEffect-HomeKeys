#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "LEDUtils.h"

namespace kaleidoscope {
    class LEDHomeKeys : public LEDMode {
    public:
        LEDHomeKeys(void) {}

        static cRGB non_home_key_color;
        static cRGB index_finger_color;
        static cRGB non_index_fingers_color;
        static cRGB thumb_color;

    protected:
        void onActivate(void) final;

    private:

    };
}

extern kaleidoscope::LEDHomeKeys LEDHomeKeys;
