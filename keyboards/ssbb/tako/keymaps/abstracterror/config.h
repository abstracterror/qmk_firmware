// Tako can apparently use VBUS detection.
#undef SPLIT_USB_DETECT

// Workaround Windows RDP weirdness
#define DOUBLE_REPORT

#define RETRO_TAPPING
#define COMBO_TERM 60

// Calibration
#undef EC_LOW_THRESHOLD_LEFT
#undef EC_LOW_THRESHOLD_RIGHT
#undef EC_HIGH_THRESHOLD_LEFT
#undef EC_HIGH_THRESHOLD_RIGHT

// clang-format off

// reading at which a key becomes pressed
#define EC_HIGH_THRESHOLD_LEFT { \
    { 600, 675, 240, 440, 585 }, \
    { 480, 620, 225, 275, 565 }, \
    { 745, 480, 415, 285, 360 }, \
    {   0,   0,   0, 685, 200 }  \
}

// reading at which a key becomes released
#define EC_LOW_THRESHOLD_LEFT {  \
    { 850, 925, 490, 690, 860 }, \
    { 730, 870, 475, 525, 815 }, \
    { 995, 730, 665, 535, 610 }, \
    {   0,   0,   0, 915, 450 }  \
}

// reading at which a key becomes pressed
#define EC_HIGH_THRESHOLD_RIGHT { \
    { 230, 320, 800, 630, 395 },  \
    { 325, 735, 575, 310, 430 },  \
    { 220, 240, 565, 650, 175 },  \
    {   0,   0,   0, 465, 830 }   \
}

// reading at which a key becomes released;
#define EC_LOW_THRESHOLD_RIGHT { \
    { 480, 570, 950, 880, 645 }, \
    { 575, 985, 825, 560, 680 }, \
    { 470, 490, 815, 900, 425 }, \
    {   0,   0,   0, 715, 980 }  \
}
// clang-format on
