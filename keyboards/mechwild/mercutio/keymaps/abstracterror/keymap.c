/* Copyright 2021 Kyle McCreery
 * Copyright 2021 drew@abstracterror.com
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

// layer names
#define _DF 0
#define _FN 1
#define _NM 2
#define _SY 3
#define _CT 4

// mod tap names
#define LCTL_A  LCTL_T(KC_A)
#define LALT_S  LALT_T(KC_S)
#define LGUI_D  LGUI_T(KC_D)
#define LSFT_F  LSFT_T(KC_F)

#define RSFT_J  RSFT_T(KC_J)
#define RGUI_K  RGUI_T(KC_K)
#define RALT_L  RALT_T(KC_L)
#define RCTL_SC RCTL_T(KC_SCLN)

#define RSFT_SL RSFT_T(KC_SLSH)

// layer tap names
#define FN_SPC LT(_FN, KC_SPC)
#define NM_ENT LT(_NM, KC_ENT)
#define NM_ESC LT(_NM, KC_ESC)
#define SY_BSPC LT(_SY, KC_BSPC)
#define SY_DEL LT(_SY, KC_DEL)

// layers with mods
#define CT_LCTL LM(_CT, MOD_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DF] = LAYOUT_all(
                                                                                                                    KC_MUTE,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_CAPS,          LCTL_A,  LALT_S,  LGUI_D,  LSFT_F,  KC_G,    KC_H,    RSFT_J,  RGUI_K,  RALT_L,  RCTL_SC, KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_SL,
        KC_LCTL, KC_LALT, KC_LGUI,          SY_BSPC,          NM_ENT,           FN_SPC,           KC_RGUI, KC_RALT, CT_LCTL
    ),

    [_FN] = LAYOUT_all(
                                                                                                                    _______,
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
        _______,          KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  _______,
        _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______, _______, KC_INS,
        _______, _______, _______,          SY_DEL,           NM_ESC,           _______,          _______, _______, _______
    ),

    [_NM] = LAYOUT_all(
                                                                                                                    _______,
        KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______,          KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_BSLS,
        _______, _______, _______,          _______,          _______,          KC_0,             _______, _______, _______
    ),

    [_SY] = LAYOUT_all(
                                                                                                                    _______,
        KC_ESC,           _______, _______, _______, _______, _______, _______, KC_DQUO, KC_GRV,  KC_LCBR, KC_RCBR, _______,
        _______,          KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, _______, KC_QUOT, KC_TILD, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______
    ),

    [_CT] = LAYOUT_all(
                                                                                                                    _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______
    )
};


// Per-key tapping force hold.
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

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

static void render_name(void) {
    static const char PROGMEM mercutio_name[] = {
        0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x95, 0xB5, 0x96, 0xD5, 0xB6, 0xB6,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(mercutio_name, false);
}

void oled_task_user(void) {
    render_name();
}
#endif
