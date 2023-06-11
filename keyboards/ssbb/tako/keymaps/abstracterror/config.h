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
    { 560, 680, 160, 410, 635 }, \
    { 470, 600, 230, 280, 550 }, \
    { 660, 500, 410, 130, 320 }, \
    {   0,   0,   0, 700, 200 }  \
}

// reading at which a key becomes released
#define EC_LOW_THRESHOLD_LEFT {  \
    { 810, 930, 410, 660, 885 }, \
    { 720, 850, 480, 530, 800 }, \
    { 910, 750, 660, 380, 570 }, \
    {   0,   0,   0, 950, 450 }  \
}

// reading at which a key becomes pressed
#define EC_HIGH_THRESHOLD_RIGHT { \
    { 216, 319, 743, 642, 428 },  \
    { 425, 794, 516, 190, 378 },  \
    { 214, 247, 503, 584, 168 },  \
    {   0,   0,   0, 478, 880 }   \
}

// reading at which a key becomes released;
#define EC_LOW_THRESHOLD_RIGHT { \
    { 466, 569, 993, 892, 678 }, \
    { 675, 944, 766, 440, 628 }, \
    { 464, 497, 753, 834, 418 }, \
    {   0,   0,   0, 728, 980 }  \
}
// clang-format on
