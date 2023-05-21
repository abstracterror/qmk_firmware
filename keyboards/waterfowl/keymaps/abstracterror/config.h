#pragma once

// Elite-C can use VBUS detection.
#undef SPLIT_USB_DETECT

// Handedness is defined by an EEPROM flag.
#define EE_HANDS

// Prevent rolls from home row modifier keys from activating the modifier.
#define IGNORE_MOD_TAP_INTERRUPT

// Prevent auto-repeat on tap-hold of home row modifiers.
// This allows use as a modifier immediately after a tap.
// See `get_tapping_force_hold` in keymap.c
#define TAPPING_FORCE_HOLD_PER_KEY

// Redefine encoder resolutions to prevent knobs sending double presses.
#undef ENCODER_RESOLUTIONS
#define ENCODER_RESOLUTIONS { 4, 4 }

// Redefine encoder pins to get directions that I expect.
#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { B5, B3 }
#define ENCODERS_PAD_B { B4, B2 }

// Flip encoder directions for the right-hand side.
#define ENCODERS_PAD_A_RIGHT { B4, B2 }
#define ENCODERS_PAD_B_RIGHT { B5, B3 }
