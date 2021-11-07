/* Copyright 2021 Johan Leirnes
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    PSCR,
    BR
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PSCR:
        if (record->event.pressed) {
            // when keycode PSCR is pressed
            SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LGUI)"4");
        } else {
            // when keycode PSCR is released
            SEND_STRING(SS_UP(X_LSFT)SS_UP(X_LGUI));
        }
        break;
    case BR:
        if (record->event.pressed) {
            // when keycode BR is pressed
            SEND_STRING("Best regards,"SS_DOWN(X_LSFT)SS_TAP(X_ENT)SS_UP(X_LSFT)"Johan Leirnes");
        } else {
            // when keycode BR is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_DEL,  KC_INS,  KC_PSCR, BR, KC_POWER,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_ENT,     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_LCAP,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       LT(1, KC_SPC),                        KC_RALT, KC_RGUI, DF(2), KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT),
    LAYOUT(
        _______,   KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY,    _______, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             DM_PLY1, DM_PLY2, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, KC__MUTE, _______, _______, _______, _______,        KC__VOLUP, DM_REC1, DM_REC2, _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, KC_MPRV, KC__VOLDOWN, KC_MNXT, _______, _______, RESET),
    LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_DEL,  KC_INS,  KC_PSCR, BR, KC_POWER,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,   KC_ENT,     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_LCAP,       KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   KC_QUOT, KC_NUHS,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       LT(1, KC_SPC),                        KC_RALT, KC_RGUI, DF(0), KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT),
};