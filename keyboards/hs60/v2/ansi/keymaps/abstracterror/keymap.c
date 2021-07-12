/* Copyright 2021 drew@abstracterror.com @abstracterror
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
#include QMK_KEYBOARD_H

// Layer names
#define _DF 0
#define _FN 1
#define _NM 2
#define _CT 3

// Layer tap names
#define FN_SPC  LT(_FN, KC_SPACE)
#define NUM_H   LT(_NM, KC_H)

// Mod tap names
#define HYPCAPS HYPR_T(KC_CAPS)

#define LCTL_A  LCTL_T(KC_A)
#define LALT_S  LALT_T(KC_S)
#define LGUI_D  LGUI_T(KC_D)
#define LSFT_F  LSFT_T(KC_F)

#define RSFT_J  RSFT_T(KC_J)
#define RGUI_K  RGUI_T(KC_K)
#define RALT_L  RALT_T(KC_L)
#define RCTL_SC RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _DF: default layer */
[_DF] = LAYOUT_60_ansi(
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    HYPCAPS,  LCTL_A,   LALT_S,   LGUI_D,   LSFT_F,   KC_G,     NUM_H,    RSFT_J,   RGUI_K,   RALT_L,   RCTL_SC,  KC_QUOT,            KC_ENT,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
    KC_LCTL,  KC_LALT,  KC_LGUI,                                FN_SPC,                                 KC_RGUI,  KC_RALT,  MO(_FN),  KC_RCTL),

/* Keymap _FN: function layer */
[_FN] = LAYOUT_60_ansi(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    _______,  _______,  AG_TOGG,  KC_END,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MNXT,  KC_MPLY,
    _______,  KC_HOME,  _______,  _______,  KC_PGDN,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  KC_PGUP,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  MO(_CT)),

/* Keymap _NM: numbers on left hand */
[_NM] = LAYOUT_60_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_7,     KC_8,     KC_9,     KC_0,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_4,     KC_5,     KC_6,     KC_0,     _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  KC_1,     KC_2,     KC_3,     KC_0,     _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

/* Keymap _KT: keyboard control features */
[_CT] = LAYOUT_60_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  S1_DEC,   S1_INC,   S2_DEC,   S2_INC,   _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            EF_DEC,   EF_INC,   H1_DEC,   H1_INC,   H2_DEC,   H2_INC,   BR_DEC,   BR_INC,   ES_DEC,   ES_INC,             _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_A:
        case LALT_S:
        case LGUI_D:
        case LSFT_F:
        case RSFT_J:
        case RGUI_K:
        case RALT_L:
        case RCTL_SC:
            return true;
        default:
            return false;
    }
}
