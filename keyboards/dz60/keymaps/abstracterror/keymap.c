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


// layer tap names
#define FN_SPC LT(_FN, KC_SPC)
#define SY_SPC LT(_SY, KC_SPC)
#define NM_BSPC LT(_NM, KC_BSPC)
#define SY_BSPC LT(_SY, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DF] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, LCTL_A,  LALT_S,  LGUI_D,  LSFT_F,  KC_G,    KC_H,    RSFT_J,  RGUI_K,  RALT_L,  RCTL_SC, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI,                   NM_BSPC, KC_ENT,  FN_SPC,           KC_RGUI, KC_RALT, XXXXXXX, MO(_CT), KC_RCTL
    ),

    [_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_INS,  _______, _______,
        _______, _______, _______,                   SY_BSPC, _______, _______,          _______, _______, _______, _______, _______
    ),

    [_NM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,          _______,
        _______, _______, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______,
        _______, _______, _______,                   _______, _______, SY_SPC,           _______, _______, _______, _______, _______
    ),

    [_SY] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______, _______, _______,
        _______, KC_UNDS, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_PLUS, _______,          _______,
        _______, _______, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),

    [_CT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
        _______, AG_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
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
