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

#define NUM OSL(_NUM)
#define SYM OSL(_SYM)
#define FUN MO(_FUN)
#define SPC_NAV LT(_NAV, KC_SPC)

#define A_LCTL LCTL_T(KC_A)
#define R_LALT LALT_T(KC_R)
#define S_LGUI LGUI_T(KC_S)
#define T_LSFT LSFT_T(KC_T)

#define N_RSFT RSFT_T(KC_N)
#define E_RGUI RGUI_T(KC_E)
#define I_RALT RALT_T(KC_I)
#define O_RCTL RCTL_T(KC_O)

enum layers {
    _BASE,
    _NUM,
    _SYM,
    _FUN,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       A_LCTL,  R_LALT,  S_LGUI,  T_LSFT,    KC_G,                         KC_M,  N_RSFT,  E_RGUI,  I_RALT,  O_RCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                              NUM, KC_LSFT,    SPC_NAV,     SYM
                                      //`-----------------'  `-----------------'
  ),

  [_NUM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      KC_MINS,    KC_4,    KC_5,    KC_6,  KC_DOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______,    KC_1,    KC_2,    KC_3, KC_COMM,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______,     FUN
                                      //`-----------------'  `-----------------'
  ),

  [_SYM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_GRV,  KC_EQL, KC_MINS, KC_QUOT, KC_SCLN,                      _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TILD, KC_PLUS, KC_UNDS, KC_DQUO, KC_COLN,                      _______, _______, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                              FUN, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [_FUN] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______, _______, _______,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        RESET, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [_NAV] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_TAB, _______, _______, _______, _______,                      _______, _______, _______, _______,  KC_DEL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,  KC_ESC,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),
};
