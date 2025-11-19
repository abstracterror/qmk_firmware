#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
    KC_Q,   KC_W,       KC_E,     KC_R,    KC_T,   KC_MPLY,     KC_Y,      KC_U,        KC_I,     KC_O,     KC_P,
    KC_A,   KC_S,       KC_D,     KC_F,    KC_G,                KC_H,      KC_J,        KC_K,     KC_L,  KC_QUOT,
    KC_Z,   KC_X,       KC_C,     KC_V,    KC_B,                KC_N,      KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,
                     KC_LCTL,  KC_LALT,  KC_SPC,   KC_MUTE,  KC_BSPC,   KC_RGUI,     KC_RALT
  ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    //                  Encoder 1					Encoder 2
};
#endif
