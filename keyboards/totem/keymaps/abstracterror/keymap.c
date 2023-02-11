#include QMK_KEYBOARD_H
#include <stdio.h>
#include "g/keymap_combo.h"
#include "keymap_extras/keymap_uk.h"
#include "totem.h"

#define TAB_NUM LT(_NUM, KC_TAB)
#define SFT_CAP TD(TD_SHIFT_CAPS)
#define SPC_FUN LT(_FUN, KC_SPC)
#define ZERO_FUN LT(_FUN, KC_0)
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

#define MHA(letter) MEH(KC_##letter)

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
        UK_Q,    UK_Z,    UK_X,    UK_C,    UK_D,    UK_V,       UK_K,    UK_H,    UK_COMM, UK_DOT,  UK_SLSH, UK_SCLN,

                                   KC_ESC,  TAB_NUM, KC_LSFT,    SPC_FUN, MO_SYM,  KC_ENT
    ),

    [_SYM] = LAYOUT(
                 UK_COLN, UK_PLUS, UK_UNDS, UK_DQUO, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, UK_EQL,  UK_MINS, UK_QUOT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        UK_COLN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                   _______, MO_TOP,  _______,    _______, _______, _______
    ),

    [_NUM] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, UK_4,    UK_5,    UK_6,    UK_SCLN,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, UK_1,    UK_2,    UK_3,    UK_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, UK_7,    UK_8,    UK_9,    UK_PIPE, UK_SCLN,

                                   _______, _______, _______,   ZERO_FUN, MO_TOP,  _______
    ),

    [_TOP] = LAYOUT(
                 UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC,    UK_CIRC, UK_AMPR, UK_ASTR, UK_GRV,  UK_TILD,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
        UK_EXLM, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UK_TILD,

                                   _______, _______, _______,    _______, _______, _______
    ),

    [_FUN] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_DEL,
                 KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_ESC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_F1,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_DEL,

                                   _______, _______, _______,    _______, _______, _______
    )
};
