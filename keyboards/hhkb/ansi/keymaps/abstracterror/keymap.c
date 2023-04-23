#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_uk.h"

/* Mod-taps (https://docs.qmk.fm/#/mod_tap)
 *
 * Specifically, home row mods.
 */
#define CTL_A   LCTL_T(UK_A)
#define ALT_S   LALT_T(UK_S)
#define GUI_D   LGUI_T(UK_D)
#define SFT_F   LSFT_T(UK_F)

#define SFT_J   LSFT_T(UK_J)
#define GUI_K   LGUI_T(UK_K)
#define ALT_L   LALT_T(UK_L)
#define CTL_SCL LCTL_T(UK_SCLN)

/* Key overrides (https://docs.qmk.fm/#/feature_key_overrides)
 *
 * Modify the UK 2/" key so that it sends @ instead of " when shifted.
 * Modify the UK 3/£ key so that it sends # instead of £ when shifted.
 * Modify the UK `/¬ key so that it sends ~ instead of ¬ when shifted.
 * Modify the UK '/@ key so that it sends " instead of @ when shifted.
 */
const key_override_t two_key_override   = ko_make_basic(MOD_MASK_SHIFT, UK_2,      UK_AT);
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

/* Layers (https://docs.qmk.fm/#/feature_layers)
 *
 * The space bar momentarily activates the _FN layer when held.
 */
enum layers {
    _BASE,
    _FN
};

#define FN_SPC LT(_FN, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
         KC_ESC,    UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0, UK_MINS,  UK_EQL, UK_BSLS,  UK_GRV,
         KC_TAB,    UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,    UK_Y,    UK_U,    UK_I,    UK_O,    UK_P, UK_LBRC, UK_RBRC,          KC_BSPC,
        KC_LCTL,   CTL_A,   ALT_S,   GUI_D,   SFT_F,    UK_G,    UK_H,   SFT_J,   GUI_K,   ALT_L, CTL_SCL, UK_QUOT,                    KC_ENT,
        KC_LSFT,    UK_Z,    UK_X,    UK_C,    UK_V,    UK_B,    UK_N,    UK_M, UK_COMM,  UK_DOT, UK_SLSH,                   KC_RSFT,  KC_MEH,
                 KC_LALT, KC_LGUI,                         FN_SPC,                       KC_RGUI, KC_RALT
    ),

    [_FN] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______,
        _______,    UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0, UK_MINS,  UK_EQL,           KC_DEL,
        KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,  KC_ESC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,                   _______, QK_BOOT,
                 _______, _______,                        _______,                       _______, _______
    ),
};

/* Per-key quick tap term (https://docs.qmk.fm/#/tap_hold?id=quick-tap-term) */
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_A:
        case ALT_S:
        case GUI_D:
        case SFT_F:
        case SFT_J:
        case GUI_K:
        case ALT_L:
        case CTL_SCL:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
