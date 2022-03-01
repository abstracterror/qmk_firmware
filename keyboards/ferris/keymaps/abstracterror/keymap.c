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

#define MO_NUM MO(_NUM)
#define MO_SYM MO(_SYM)

#define SPC_FUN LT(_FUN, KC_SPC)

#define MO_TOP MO(_TOP)

#define A_LCTL LCTL_T(KC_A)
#define R_LSFT LSFT_T(KC_R)
#define S_LALT LALT_T(KC_S)
#define T_LGUI LGUI_T(KC_T)

#define N_RGUI RGUI_T(KC_N)
#define E_RALT RALT_T(KC_E)
#define I_RSFT RSFT_T(KC_I)
#define O_RCTL RCTL_T(KC_O)
#define SLS_MEH MEH_T(KC_SLSH)

enum layers {
    _BASE,
    _SYM,
    _NUM,
    _TOP,
    _FUN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       A_LCTL,  R_LSFT,  S_LALT,  T_LGUI,    KC_G,                         KC_M,  N_RGUI,  E_RALT,  I_RSFT,  O_RCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, SLS_MEH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           MO_NUM, KC_LSFT,    SPC_FUN,  MO_SYM
                                      //`-----------------'  `-----------------'
  ),

  [_SYM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _______, KC_LPRN, KC_RPRN, KC_DQUO, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_SCLN, KC_LCBR, KC_RCBR, KC_QUOT, _______,                      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, KC_LBRC, KC_RBRC, KC_COLN, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           MO_TOP, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [_NUM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_PLUS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,                      KC_MINS,    KC_1,    KC_2,    KC_3, KC_PIPE,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      KC_UNDS,    KC_7,    KC_8,    KC_9, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,       KC_0,  MO_TOP
                                      //`-----------------'  `-----------------'
  ),

  [_TOP] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR,  KC_GRV, KC_TILD,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        RESET, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
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
       KC_F10, KC_F11,  KC_F12,  _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______,  KC_TAB,    _______, _______
                                      //`-----------------'  `-----------------'
  ),
};
