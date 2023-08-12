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
#include "os_detection.h"
#include "g/keymap_combo.h"
#include "keymap_extras/keymap_uk.h"
#include "tap_hold.h"

#define TAB_NUM LT(_NUM, KC_TAB)
#define SPC_SYM LT(_SYM, KC_SPC)
#define A_CTL   LCTL_T(UK_A)
#define S_SFT   LSFT_T(UK_S)
#define F_CMD   TD(TD_F_CMD)
#define J_CMD   TD(TD_J_CMD)
#define L_SFT   RSFT_T(UK_L)
#define SCN_CTL RCTL_T(UK_SCLN)
#define Z_SFT   LSFT_T(UK_Z)
#define DOT_SFT RSFT_T(UK_DOT)
#define HASH_FN TD(TD_HASH_FN)
#define NOHOLDS MO(_NOH)

enum layers {
    _BASE,
    _NOH,
    _SYM,
    _NUM,
    _FUN
};

enum custom_keycodes {
    CMD = SAFE_RANGE,
    LALT,
    LGUI,
    RALT,
    RGUI,
    FUN
};

enum tap_dances {
    TD_F_CMD,
    TD_J_CMD,
    TD_HASH_FN
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_F_CMD] = ACTION_TAP_DANCE_TAP_HOLD(UK_F, CMD),
    [TD_J_CMD] = ACTION_TAP_DANCE_TAP_HOLD(UK_J, CMD),
    [TD_HASH_FN] = ACTION_TAP_DANCE_TAP_HOLD(UK_HASH, FUN)
};

/* Key overrides (https://docs.qmk.fm/#/feature_key_overrides)
 *
 * Modify the UK 2/" key so that it sends @ instead of " when shifted.
 * Modify the UK 3/£ key so that it sends # instead of £ when shifted.
 * Modify the UK `/¬ key so that it sends ~ instead of ¬ when shifted.
 * Modify the UK '/@ key so that it sends " instead of @ when shifted.
 */
const key_override_t two_key_override   = ko_make_basic(MOD_MASK_SHIFT, UK_2,    UK_AT);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_3,    UK_HASH);
const key_override_t grave_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_GRV,  UK_TILD);
const key_override_t quote_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_QUOT, UK_DQUO);

const key_override_t **key_overrides = (const key_override_t *[]){
    &two_key_override,
    &three_key_override,
    &grave_key_override,
    &quote_key_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_space(
        KC_ESC,  KC_F12,                                               NOHOLDS, XXXXXXX,

        UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,    UK_Y,    UK_U,    UK_I,    UK_O,    UK_P,
        A_CTL,   S_SFT,   UK_D,    F_CMD,   UK_G,    UK_H,    J_CMD,   UK_K,    L_SFT,   SCN_CTL,
        Z_SFT,   UK_X,    UK_C,    UK_V,    UK_B,    UK_N,    UK_M,    UK_COMM, DOT_SFT,
        KC_LCTL, LALT,    LGUI,        TAB_NUM,        SPC_SYM,        RGUI,    RALT,    KC_RCTL
    ),

    [_NOH] = LAYOUT_split_space(
        _______, _______,                                              _______, _______,

        _______, _______, UK_E,    _______, _______, _______, _______, _______, _______, _______,
        UK_A,    UK_S,     _______, UK_F,   _______, _______, UK_J,    _______, UK_L,    UK_SCLN,
        UK_Z,    _______, _______, _______, _______, _______, _______, _______, UK_DOT,
        _______, _______, _______,     _______,         _______,       _______, _______, _______
    ),

    [_SYM] = LAYOUT_split_space(
        _______, KC_INS,                                              _______, _______,

        UK_COLN, UK_PLUS, UK_UNDS, UK_DQUO, _______, _______, UK_GRV,  UK_TILD, KC_BSPC, KC_DEL,
        KC_CAPS, UK_EQL,  UK_MINS, UK_QUOT, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        _______, _______, _______, UK_QUES, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        _______, _______, _______,     UK_SLSH,         _______,       _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_space(
        _______, _______,                                              _______, _______,

        _______, UK_DLR,  UK_PERC, UK_CIRC, _______, _______, UK_4,    UK_5,    UK_6,    UK_PIPE,
        _______, UK_EXLM, UK_AT,   HASH_FN, _______, _______, UK_1,    UK_2,    UK_3,    UK_BSLS,
        _______, UK_AMPR, UK_ASTR, _______, _______, _______, UK_7,    UK_8,    UK_9,
        _______, _______, _______,     _______,         UK_0,          _______, _______, _______
    ),

    [_FUN] = LAYOUT_split_space(
        _______, _______,                                              _______, _______,

        _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   _______,
        _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,
        _______, _______, _______,     KC_F11,          KC_F10,        _______, _______, _______
    ),

};

bool process_os_dependent_key(uint16_t keycode, bool pressed) {
    bool apple;
    uint8_t code;

    switch (detected_host_os()) {
    case OS_MACOS:
    case OS_IOS:
        apple = true;
        break;
    default:
        apple = false;
        break;
    }

    switch (keycode) {
    case CMD:
        code = apple ? KC_LGUI : KC_LCTL;
        break;
    case LALT:
        code = apple ? KC_LALT : KC_LGUI;
        break;
    case LGUI:
        code = apple ? KC_LGUI : KC_LALT;
        break;
    case RGUI:
        code = apple ? KC_RGUI : KC_RALT;
        break;
    case RALT:
        code = apple ? KC_RALT : KC_RGUI;
        break;
    default:
        return true;
    }

    if (pressed) {
        register_code(code);
    } else {
        unregister_code(code);
    }

    return false;
}

bool process_custom_keycode(uint16_t keycode, bool pressed) {
    switch (keycode) {
    case CMD:
    case LALT:
    case LGUI:
    case RGUI:
    case RALT:
        return process_os_dependent_key(keycode, pressed);
    case FUN:
        if (pressed) {
            layer_on(_FUN);
        } else {
            layer_off(_FUN);
        }
        return false;
    default:
        return true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    if (!process_custom_keycode(keycode, record->event.pressed)) {
        return false;
    }

    switch (keycode) {
    case F_CMD:
    case J_CMD:
    case HASH_FN:
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        return true;

    default:
        return true;
    }
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
    uint16_t code;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            code = tap_hold->hold;
        } else {
            code = tap_hold->tap;
        }

        if (process_custom_keycode(code, true)) {
            register_code16(code);
        }
        tap_hold->held = code;
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        if (process_custom_keycode(tap_hold->held, false)) {
            unregister_code16(tap_hold->held);
        }
        tap_hold->held = 0;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_setrgb (0x01,  0x00, 0x00);
        break;
    case _NUM:
        rgblight_setrgb (0x00,  0x00, 0x01);
        break;
    case _SYM:
        rgblight_setrgb (0x01,  0x01, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x01,  0x01, 0x01);
        break;
    }
    return state;
}
