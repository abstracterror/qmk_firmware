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
