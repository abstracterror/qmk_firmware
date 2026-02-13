#include "ghost.h"

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
        {202, 45}, {179, 45}, {157, 45}, {134, 45}, {90, 45}, {67, 45}, {45, 45}, {22, 45}, // UNDERGLOW
        {22, 15}, {45, 15}, {67, 15}, {90, 15}, {134, 15}, {157, 15}, {179, 15}, {202, 15}  // UNDERGLOW

    }, {
        // LED Index to Flag
        2, 2, 2, 2, 2, 2, 2, 2, // UNDERGLOW
        2, 2, 2, 2, 2, 2, 2, 2  // UNDERGLOW
    }
};
#endif