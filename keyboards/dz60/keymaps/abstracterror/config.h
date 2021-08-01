#pragma once

// Prevent rolls from home row modifier keys from activating the modifier.
#define IGNORE_MOD_TAP_INTERRUPT

// Prevent auto-repeat on tap-hold of home row modifiers.
// This allows use as a modifier immediately after a tap.
// See `get_tapping_force_hold` in keymap.c.
#define TAPPING_FORCE_HOLD_PER_KEY

// Treat hold and release without pressing another key as a tap. This prevents
// dropped letters when a key is accidentally held for longer than the tapping
// term.
#define RETRO_TAPPING
