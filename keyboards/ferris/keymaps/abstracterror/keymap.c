/*
Copyright 2022 @abstracterror

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
#include "g/keymap_combo.h"
#include "keymap_extras/keymap_uk.h"

#define TAB_NUM LT(_NUM, KC_TAB)
#define SFT_CAP TD(TD_SHIFT_CAPS)
#define SPC_FUN LT(_FUN, KC_SPC)
#define ZERO_FUN LT(_FUN, KC_0)
#define MO_SYM MO(_SYM)

#define MO_TOP MO(_TOP)

#define A_LCTL LCTL_T(UK_A)
#define R_LSFT LSFT_T(UK_R)
#define S_LGUI LGUI_T(UK_S)
#define T_LALT LALT_T(UK_T)

#define N_LALT LALT_T(UK_N)
#define E_LGUI LGUI_T(UK_E)
#define I_LSFT LSFT_T(UK_I)
#define O_LCTL LCTL_T(UK_O)

#define MHA(letter) MEH(KC_##letter)

enum layers {
    _BASE,
    _SYM,
    _NUM,
    _TOP,
    _FUN
};

enum dances {
    TD_SHIFT_CAPS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         UK_Q,    UK_W,    UK_F,    UK_P,    UK_B,                         UK_J,    UK_L,    UK_U,    UK_Y, KC_BSPC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       A_LCTL,  R_LSFT,  S_LGUI,  T_LALT,    UK_G,                         UK_M,  N_LALT,  E_LGUI,  I_LSFT,  O_LCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         UK_Z,    UK_X,    UK_C,    UK_D,    UK_V,                         UK_K,    UK_H, UK_COMM,  UK_DOT, UK_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          TAB_NUM, SFT_CAP,    SPC_FUN,  MO_SYM
                                      //`-----------------'  `-----------------'
  ),

  [_SYM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      UK_COLN, UK_PLUS, UK_UNDS, UK_DQUO, XXXXXXX,                       MHA(J),  MHA(L),  MHA(U),  MHA(Y), XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,  UK_EQL, UK_MINS, UK_QUOT, XXXXXXX,                      XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           MO_TOP, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [_NUM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       MHA(Q),  MHA(W),  MHA(F),  MHA(P),  MHA(B),                      XXXXXXX,    UK_4,    UK_5,    UK_6, UK_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,                      XXXXXXX,    UK_1,    UK_2,    UK_3, UK_BSLS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    UK_7,    UK_8,    UK_9, UK_PIPE,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,   ZERO_FUN,  MO_TOP
                                      //`-----------------'  `-----------------'
  ),

  [_TOP] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      UK_EXLM,   UK_AT, UK_HASH,  UK_DLR, UK_PERC,                      UK_CIRC, UK_AMPR, UK_ASTR,  UK_GRV, UK_TILD,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, XXXXXXX,                      XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [_FUN] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_DEL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,  KC_ESC,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F10, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),
};

static bool caps_lock = false;

void led_set_kb(uint8_t usb_led) {
    caps_lock = host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
}

void dance_shift_caps_finished(qk_tap_dance_state_t* state, void* user_data) {
    if (!caps_lock && state->count == 1) {
        register_code(KC_LSFT);
    } else {
        tap_code(KC_CAPS);
    }
}

void dance_shift_caps_reset(qk_tap_dance_state_t* state, void* user_data) {
    if (!caps_lock && state->count == 1) {
        unregister_code(KC_LSFT);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shift_caps_finished, dance_shift_caps_reset)
};
