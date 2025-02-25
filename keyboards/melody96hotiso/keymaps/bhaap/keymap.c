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
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    BR
};

enum tapdance_keycodes {
    TD_RSFT_CAPS,
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_CAPP LGUI(LSFT(KC_4))
#define KC_SPOT LGUI(KC_SPC)
#define KC_MSS LGUI(LSFT(LALT(KC_L)))

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case BR:
            if (record->event.pressed) {
                // when keycode BR is pressed
                SEND_STRING("Best regards,"SS_DOWN(X_LSFT)SS_TAP(X_ENT)SS_UP(X_LSFT)"Johan Leirnes");
            } else {
                // when keycode BR is released
            }
            return false;
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_ESC,  KC_BRID,   KC_BRIU, KC_MCTL, KC_SPOT, KC_F5,KC_POWER, KC_MPRV, KC_MPLY,   KC_MNXT,   KC__VOLDOWN,  KC__VOLUP,  KC__MUTE,  KC_CAPP,  KC_DEL,  KC_INS,  KC_EJCT, BR, KC_MSS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  MO(1),            KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_ENT,     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_BSPC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_RSFT_CAPS),        KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LALT,   KC_LGUI,                       KC_SPC,                                KC_RGUI, KC_RALT, MO(2), KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT),
    LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   TG(4),    _______, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             DM_PLY1, DM_PLY2, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, DM_REC1, DM_REC2, _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______, _______, _______, _______, RESET),
    LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_DEL,  KC_INS,  KC_MYCM, BR, KC_SLEP,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  MO(3),            KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_ENT,     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_BSPC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_RSFT_CAPS),        KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT, KC_RGUI, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT),
    LAYOUT(
        _______,   KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY,    _______, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             DM_PLY1, DM_PLY2, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______,        KC__VOLUP, DM_REC1, DM_REC2, _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, KC_MPRV, KC__VOLDOWN, KC_MNXT, _______, _______, RESET),
    LAYOUT(
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______,   KC_Q,  KC_W,  KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,   _______,    _______, _______, _______, _______,
        _______,   KC_A,  KC_R,  KC_S,    KC_T,    KC_B,    KC_M,    KC_N,    KC_E,    KC_I,     KC_O,     KC_QUOT,  KC_NUHS,             _______, _______, _______, _______,
        _______,   KC_Z,  KC_X,  KC_C,    KC_D,    KC_V,    KC_NUBS, KC_K,    KC_H, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______, _______, _______, _______, _______)
};
