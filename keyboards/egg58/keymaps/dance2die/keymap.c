// Copyright 2022 Travis Mick (@tmick0)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "egg58.h"

enum layer_names {
  _BASE,
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( \
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,         KC_5,              KC_6,          KC_7,    KC_8,       KC_9,           KC_0,          KC_MINS, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,              KC_Y,          KC_U,    KC_I,       KC_O,           KC_P,          KC_EQL, \
  KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,         KC_G,              KC_H,          KC_J,    KC_K,       KC_L,           KC_SCLN,       KC_RSFT, \
  KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,              KC_N,          KC_M,    KC_COMM,    KC_DOT,         KC_SLSH,       KC_BSLS, \
            KC_LGUI, KC_LALT, KC_SPC,  KC_BACKSPACE, MO(1),             MO(1),         KC_ENT,  KC_SPC,     KC_RBRC,        KC_BSLS \
),

[_FN] = LAYOUT( \
  KC_GRV,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                KC_F6,         KC_F7,   KC_F8,      KC_F9,          KC_F10,        KC_F11, \
  KC_CAPS,    KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_VOLU,              KC_QUOT,  LSFT(KC_LBRC),KC_INS,     LSFT(KC_RBRC),  KC_PSCR,       KC_F12, \
  KC_TRNS,    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,              LSFT(KC_QUOT), RGB_TOG, RGB_MOD,    RGB_HUI,        RGB_VAI,       KC_TRNS, \
  KC_TRNS,    KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_MUTE,              LSFT(KC_MINS), KC_LBRC, KC_KP_PLUS, KC_RBRC,        KC_KP_MINUS,   KC_RGHT, \
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_DEL,        KC_TRNS, KC_LEFT,    KC_UP,          KC_DOWN \
)};
