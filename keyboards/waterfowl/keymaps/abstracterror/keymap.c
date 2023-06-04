/*
Copyright 2023 @abstracterror

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "os_detection.h"
#include "g/keymap_combo.h"
#include "keymap_extras/keymap_uk.h"

#define TAB_NUM LT(_NUM, KC_TAB)
#define SPC_FN LT(_FUN, KC_SPC)
#define ZERO_FN LT(_FUN, KC_0)
#define MO_SYM MO(_SYM)

#define MO_TOP MO(_TOP)

#define A_CTL LCTL_T(UK_A)
#define R_SFT LSFT_T(UK_R)
#define S_GUI LGUI_T(UK_S)
#define T_ALT LALT_T(UK_T)

#define N_ALT LALT_T(UK_N)
#define E_GUI LGUI_T(UK_E)
#define I_SFT LSFT_T(UK_I)
#define O_CTL LCTL_T(UK_O)

#define ESC_MEH MT(MOD_LSFT | MOD_LCTL | MOD_LGUI, KC_ESC)

enum layers {
    _BASE,
    _SYM,
    _NUM,
    _TOP,
    _FUN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        UK_Q,    UK_W,    UK_F,    UK_P,    UK_B,       UK_J,    UK_L,    UK_U,    UK_Y,    KC_BSPC,
        A_CTL,   R_SFT,   S_GUI,   T_ALT,   UK_G,       UK_M,    N_ALT,   E_GUI,   I_SFT,   O_CTL,
        UK_Z,    UK_X,    UK_C,    UK_D,    UK_V,       UK_K,    UK_H,    UK_COMM, UK_DOT,  UK_SLSH,

        XXXXXXX, ESC_MEH, TAB_NUM, KC_LSFT, KC_CAPS,    KC_MPLY, SPC_FN,  MO_SYM,  KC_ENT,  XXXXXXX
    ),

    [_SYM] = LAYOUT(
        UK_COLN, UK_PLUS, UK_UNDS, UK_DQUO, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UK_EQL,  UK_MINS, UK_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, _______, MO_TOP,  _______, _______,    _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, UK_4,    UK_5,    UK_6,    UK_SCLN,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, UK_1,    UK_2,    UK_3,    UK_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, UK_7,    UK_8,    UK_9,    UK_PIPE,

        _______, _______, _______, _______, _______,    _______, ZERO_FN, MO_TOP,  _______, _______
    ),

    [_TOP] = LAYOUT(
        UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC,    UK_CIRC, UK_AMPR, UK_ASTR, UK_GRV,  UK_TILD,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,    XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX,

        _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_FUN] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_DEL,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,

        _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    )
};


bool host_os_is_apple(void) {
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            return true;
        default:
            return false;
    }
}


#ifdef ENCODER_ENABLE

bool task_switching = false;

// Taps the OS-appropriate keypress for undo or redo.
void tap_undo_redo(bool redo) {
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            tap_code16(redo ? S(A(KC_Z)) : A(KC_Z));
            break;
        case OS_LINUX:
            // from the GNOME HIG
            tap_code16(redo ? S(C(KC_Z)) : C(KC_Z));
            break;
        case OS_WINDOWS:
            tap_code16(redo ? C(KC_Y) : C(KC_Z));
            break;
        case OS_UNSURE:
            // do nothing?
            break;
    }
}

// Begins task switching, if not already started.
void ensure_task_switching(void) {
    if (!task_switching) {
        task_switching = true;
        register_code(KC_LALT);
    }
}

// Switches to the next task in the specified direction.
void select_next_task(bool forwards) {
    ensure_task_switching();
    if (!forwards) {
        register_code(KC_LSFT);
    }
    tap_code(KC_TAB);
    if (!forwards) {
        unregister_code(KC_LSFT);
    }
}

// Ends task switching. If the user pressed the Escape key, then it is
// passed through to the OS; otherwise, the keypress is swallowed.
void end_task_switching(uint16_t keycode) {
    task_switching = false;
    if (keycode == KC_ESC || keycode == ESC_MEH) {
        tap_code(KC_ESC);
    }
    unregister_code(KC_LALT);
}

// Processes a keypress during task switching.
bool process_task_switching_keypress(uint16_t keycode) {
    if (!host_os_is_apple()) {
        end_task_switching(keycode);
        return false;
    }

    switch (keycode) {
        case KC_H:
        case KC_Q:
            // Pass these through to the OS, without ending task switching.
            // This allows the user to easily hide or quit multiple tasks.
            return true;
        case KC_D:
            // We support D as a more convenient alternative to H, because it
            // is on the opposite hand from the encoder.
            tap_code(KC_H);
            return false;
        default:
            end_task_switching(keycode);
            return false;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        // left knob
        tap_undo_redo(clockwise);
    } else if (index == 3) {
        // right knob
        if (get_mods() != MOD_BIT(KC_LSFT)) {
            select_next_task(clockwise);
        } else {
            tap_code16(clockwise ? A(UK_GRV) : S(A(UK_GRV)));
        }
    } else if (index == 2) {
        // right roller
        tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
    } else {
        return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (task_switching && record->event.pressed) {
        return process_task_switching_keypress(keycode);
    }
    return true;
}

#endif


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (!is_keyboard_left()) {
        return true;
    }

    oled_write_P(PSTR("LAYER:\n"), false);
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("DEFAULT\n\n\n\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBOLS\n\n\n\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMBERS\n\n\n\n"), false);
            break;
        case _TOP:
            oled_write_P(PSTR("TOP\n\n\n\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("FUNCTION\n\n\n\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n\n\n\n"), false);
            break;
    }

    return false;
}
#endif
