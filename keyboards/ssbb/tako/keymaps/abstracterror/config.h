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
    { 650, 650, 650, 650, 650 }, \
    { 650, 700, 650, 650, 650 }, \
    { 780, 650, 650, 650, 650 }, \
    {   0,   0,   0, 700, 250 }  \
}

// reading at which a key becomes released
#define EC_LOW_THRESHOLD_LEFT {  \
    { 950, 950, 950, 950, 950 }, \
    { 950,1000, 950, 950, 950 }, \
    {1000, 950, 950, 950, 950 }, \
    {   0,   0,   0,1000, 550 }  \
}

// reading at which a key becomes pressed
#define EC_HIGH_THRESHOLD_RIGHT { \
    { 650, 650, 650, 650, 730 },  \
    { 650, 860, 650, 650, 650 },  \
    { 660, 650, 730, 650, 650 },  \
    {   0,   0,   0, 650, 650 }   \
}

// reading at which a key becomes released;
#define EC_LOW_THRESHOLD_RIGHT { \
    { 950, 950, 950, 950,1000 }, \
    { 950,1000, 950, 950, 950 }, \
    { 960, 950,1000, 950, 950 }, \
    {   0,   0,   0, 950, 950 }  \
}
// clang-format on
