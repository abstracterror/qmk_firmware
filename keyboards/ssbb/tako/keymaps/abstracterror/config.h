#define COMBO_TERM 60

// Calibration
#undef EC_LOW_THRESHOLD_LEFT
#undef EC_LOW_THRESHOLD_RIGHT
#undef EC_HIGH_THRESHOLD_LEFT
#undef EC_HIGH_THRESHOLD_RIGHT

// clang-format off

// reading at which a key becomes pressed
#define EC_HIGH_THRESHOLD_LEFT { \
    { 560, 680, 160, 410, 635 }, \
    { 470, 600, 230, 280, 550 }, \
    { 660, 500, 410, 130, 320 }, \
    {   0,   0,   0, 700, 200 }  \
}

// reading at which a key becomes released
#define EC_LOW_THRESHOLD_LEFT {  \
    { 610, 730, 210, 460, 685 }, \
    { 520, 650, 280, 330, 600 }, \
    { 710, 550, 460, 180, 370 }, \
    {   0,   0,   0, 750, 250 }  \
}

// reading at which a key becomes pressed
#define EC_HIGH_THRESHOLD_RIGHT { \
    { 216, 319, 743, 642, 428 }, \
    { 425, 794, 516, 190, 378 }, \
    { 214, 247, 503, 584, 168 }, \
    {   0,   0,   0, 478, 880 }  \
}

// reading at which a key becomes released;
#define EC_LOW_THRESHOLD_RIGHT {  \
    { 266, 369, 793, 692, 478 }, \
    { 475, 844, 566, 240, 428 }, \
    { 264, 297, 553, 634, 218 }, \
    {   0,   0,   0, 528, 920 }  \
}
// clang-format on
