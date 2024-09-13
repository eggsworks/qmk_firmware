// Copyright 2024 Travis Mick (@tmick0)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SCROLL,
    _NUM,
    _NAV,
    _FN,
};

#define M1(x) LSFT_T(x)
#define M2(x) LCTL_T(x)
#define M3(x) LGUI_T(x)
#define M4(x) LALT_T(x)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
                KC_Q,       KC_W,         KC_E,              KC_R, KC_T,                                       KC_Y,              KC_U,        KC_I,        KC_O,        KC_P,
   KC_LBRC, M1(KC_A),   M2(KC_S),     M3(KC_D),          M4(KC_F), KC_G,                                       KC_H,          M4(KC_J),    M3(KC_K),    M2(KC_L), M1(KC_SCLN), KC_BSPC,
            M2(KC_Z),   M3(KC_X),     M4(KC_C), LT(_SCROLL, KC_V), KC_B,                                       KC_N, LT(_SCROLL, KC_M),     KC_COMM,      KC_DOT,     KC_SLSH,
                                                       LT(_NUM, KC_SPC),                           LT(_NAV, KC_ENT)
),

[_NUM] = LAYOUT(
                KC_1,        KC_2,        KC_3,        KC_4,    KC_5,                                          KC_6,        KC_7,        KC_8,        KC_9,        KC_0,
KC_RBRC, M1(KC_EXLM),   M2(KC_AT), M3(KC_HASH),  M4(KC_DLR), KC_PERC,                                       KC_CIRC, M4(KC_AMPR), M3(KC_ASTR), M2(KC_LPRN), M1(KC_RPRN), KC_DEL,
               KC_F1,       KC_F2,       KC_F3,       KC_F4,   KC_F5,                                        KC_GRV,     KC_QUOT,     KC_MINS,     KC_EQL,     KC_BSLS,
                                                             MO(_FN),                                       XXXXXXX
),

[_NAV] = LAYOUT(
            KC_ESC,     KC_PGUP,       KC_UP,     KC_PGDN, KC_VOLU,                                         XXXXXXX,     XXXXXXX,      KC_INS,     XXXXXXX,     KC_PSCR,
  XXXXXXX, XXXXXXX,     KC_LEFT,     KC_DOWN,     KC_RGHT, KC_VOLD,                                         XXXXXXX, M4(XXXXXXX), M3(XXXXXXX), M2(XXXXXXX), M1(XXXXXXX), KC_DEL,
           XXXXXXX,     KC_HOME,      KC_ESC,      KC_END, KC_MUTE,                                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
                                                            KC_TAB,                                         _______
),

[_FN] = LAYOUT(
             KC_F1,       KC_F2,       KC_F3,       KC_F4,   KC_F5,                                           KC_F6,       KC_F7,       KC_F8,       KC_F9,      KC_F10,
   XXXXXXX, KC_F11,      KC_F12,     XXXXXXX,     XXXXXXX, XXXXXXX,                                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,                                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
                                                           XXXXXXX,                                         _______      
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static const uint16_t sh_modtaps[] = {M1(KC_EXLM), M2(KC_AT), M3(KC_HASH), M4(KC_DLR), M4(KC_AMPR), M3(KC_ASTR), M2(KC_LPRN), M1(KC_RPRN)};
    static const uint16_t tap_values[] = {KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN};
    if (record->tap.count && record->event.pressed) {
      for (int i = 0; i < sizeof(sh_modtaps) / sizeof(*sh_modtaps); ++i) {
        if (keycode == sh_modtaps[i]) {
          tap_code16(tap_values[i]);
          return false;
        }
      }
    }
    return true;
}
