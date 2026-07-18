// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layer {
    _BASE,
    _NUM_SYM,
    _NAV,
    _MOU
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_setrgb (0x15,  0x00, 0x00);
        break;
    case _NAV:
        rgblight_setrgb (0x00,  0x00, 0x15);
        break;
    case _NUM_SYM:
        rgblight_setrgb (0x15,  0x15, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x15,  0x15, 0x15);
        break;
    }
  return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_space(
        KC_F13, KC_F14, MO(_NAV), MO(_MOU),
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
        LT(_NAV,KC_A),  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,   KC_K,  KC_L, KC_QUOT,
        MT(MOD_LSFT, KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMMA, MT(MOD_RSFT,KC_DOT),
        KC_LCTL, KC_LGUI, KC_LALT, MT(MOD_LCTL,KC_SPACE),  LT(_NUM_SYM,KC_SPACE),  KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_NUM_SYM] = LAYOUT_split_space(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_F, KC_G, KC_SCLN, KC_MINS, KC_EQL, KC_QUOT, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, DM_RSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, UG_NEXT, KC_TRNS, KC_TRNS, UG_VALU, KC_TRNS, KC_TRNS
    ),

    [_NAV] = LAYOUT_split_space(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_PGUP,
        KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_TRNS, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_MOU] = LAYOUT_split_space(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_HOME,MS_UP,KC_END,KC_PGUP,
        KC_TRNS,MS_BTN2,MS_BTN3,MS_BTN1,KC_TRNS,KC_TRNS,MS_LEFT,MS_DOWN,MS_RGHT,KC_PGDN,
        KC_TRNS,MS_ACL0,MS_ACL1,MS_ACL2,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
  ),
};
