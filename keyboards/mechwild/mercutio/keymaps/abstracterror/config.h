/* Copyright 2021 drew@abstracterror.com
 * 
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 2 of the License, or 
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

#pragma once

/* Reduce OLED brightness */
#define OLED_BRIGHTNESS 5

/* Define custom font */
#define OLED_FONT_H "keyboards/mechwild/mercutio/lib/mercutiofont.c"

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
