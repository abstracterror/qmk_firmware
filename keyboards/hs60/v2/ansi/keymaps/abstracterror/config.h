#pragma once

// Prevent rolls from home row modifier keys from activating the modifier.
#define IGNORE_MOD_TAP_INTERRUPT

// Prevent auto-repeat on tap-hold of home row modifiers.
// This allows use as a modifier immediately after a tap.
// See `get_tapping_force_hold` in keymap.c.
#define TAPPING_FORCE_HOLD_PER_KEY

#undef RGB_BACKLIGHT_CAPS_LOCK_INDICATOR
#define RGB_BACKLIGHT_CAPS_LOCK_INDICATOR { .color = { .h = 0, .s = 255 }, .index = 254 }
