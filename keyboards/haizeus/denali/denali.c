#include "denali.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
    }, {
        // LED Index to Physical Position
        {13, 15}, {35, 15}, {57, 15}, {79, 15}, {101, 15}, {123, 15}, {145, 15}, {167, 15}, {189, 15}, {211, 15}, // UNDERGLOW
        {211, 45}, {189, 45}, {167, 45}, {145, 45}, {123, 45}, {101, 45}, {79, 45}, {57, 45}, {35, 45}, {13, 45} // UNDERGLOW

    }, {
        // LED Index to Flag
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,// UNDERGLOW
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2 // UNDERGLOW
    }
};
#endif