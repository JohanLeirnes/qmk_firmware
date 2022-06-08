/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

// clang-format off

enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_MISSION_CONTROL = USER00,
#else
    KC_MISSION_CONTROL = SAFE_RANGE,
#endif
    KC_LAUNCHPAD,
    TWCH,
    GGEZ,
    COLEMAK = SAFE_RANGE,
    QWERTY,
    GAME
};

enum tapdance_keycodes {
  TD_LSFT_CAPS,
};


#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_CAPP LGUI(LSFT(KC_4))
#define MACLOCK LGUI(LCTL(KC_Q))

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_4x6_5(
    KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,			            KC_MINS ,KC_6, KC_7, KC_8,    KC_9,   KC_0,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G,			            KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,  KC_LBRC,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_B,	                KC_M, KC_N, KC_E,    KC_I,   KC_O,     KC_QUOT,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_LCTL, KC_Z, KC_X, KC_C, KC_D, KC_V,                  KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,  KC_CAPP,
//-------------------------------------------------//-----------------------------------------------------------//
                        KC_LGUI, KC_SPC, MO(3),		     MO(4),  TD(TD_LSFT_CAPS), KC_ENT,
                                 KC_BSLS,  KC_PSLS,      KC_HOME, KC_END
  ),

  [1] = LAYOUT_split_4x6_5(
    KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,			            KC_MINS ,KC_6, KC_7, KC_8,    KC_9,   KC_0,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,			            KC_Y, KC_U, KC_I,    KC_O,   KC_P,  KC_LBRC,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G,	                KC_H, KC_J, KC_K,    KC_L,   KC_QUOT, KC_SCLN,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_CAPP,
//-------------------------------------------------//-----------------------------------------------------------//
                        KC_LGUI, KC_SPC, MO(3),		     MO(4),  TD(TD_LSFT_CAPS), KC_ENT,
                                 KC_BSLS,  KC_PSLS,      KC_HOME, KC_END
  ),

  [2] = LAYOUT_split_4x6_5(
    KC_ESC, KC_GRV,  KC_1, KC_2, KC_3, KC_4,			        KC_MINS ,KC_6, KC_7, KC_8,    KC_9,   KC_0,
//-------------------------------------------------//-----------------------------------------------------------//
    _______, KC_TAB,  KC_Q, KC_W, KC_E, KC_R, 			      KC_Y, KC_U, KC_I,    KC_O,   KC_P,  KC_LBRC,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_F5, KC_G, KC_A, KC_S, KC_D, KC_F,   	              KC_H, KC_J, KC_K,    KC_L,   KC_QUOT, KC_SCLN,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_F6, KC_LCTL, KC_Z, KC_X, KC_C, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_CAPP,
//-------------------------------------------------//-----------------------------------------------------------//
                        KC_LGUI, KC_SPC, MO(3),		     MO(4),  TD(TD_LSFT_CAPS), KC_ENT,
                                 KC_BSLS,  KC_PSLS,      KC_HOME, KC_END
  ),

  [3] = LAYOUT_split_4x6_5(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,			  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  MACLOCK,
//---------------------------------------------------------//-----------------------------------------------------------//
    RESET,   _______, _______, _______, _______, KC_LBRC,			  KC_RBRC, KC_P7,   KC_P8,   KC_P9,   _______,  KC_PLUS,
//---------------------------------------------------------//-----------------------------------------------------------//
    _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LPRN,	      KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS,  KC_PIPE,
//---------------------------------------------------------//-----------------------------------------------------------//
    _______, _______, _______, COLEMAK, QWERTY, GAME,           _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,   KC_UNDS,
//---------------------------------------------------------//-----------------------------------------------------------//
                               KC_LCTL, KC_HOME, KC_TRNS,		    KC_TRNS, KC_RALT, KC_RGUI,
                                        KC_SPC,  KC_BSPC,       KC_RCTL, KC_ENT
  ),

  [4] = LAYOUT_split_4x6_5(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,			      KC_F11,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______, KC_UP,    _______, KC_LBRC,			  KC_RBRC, _______, KC_NLCK, KC_INS,  KC_SLCK,  KC_MUTE,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______,KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,	      KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______,  KC_VOLU,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______,  _______, _______, _______,        _______, _______, _______, _______, _______,  KC_VOLD,
//---------------------------------------------------------//--------------------------------------------------------------//
                               KC_LCTL, KC_HOME, KC_TRNS,		    KC_TRNS, KC_RALT, RESET,
                                        KC_SPC,  KC_BSPC,       KC_RCTL, KC_ENT
  ),
};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TWCH:
            if (record->event.pressed) {
              // when TWCH is pressed
              SEND_STRING("Good game, well played. This game was streamed on twitch #v0idgrim. If you would like, please come and watch!"SS_TAP(X_ENT));
            } else {
              // when TWCH is released
            }
            return false;  // Skip all further processing of this key
        case GGEZ:
            if (record->event.pressed) {
              // when GGEZ is pressed
              SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_ENT)SS_UP(X_LSFT)"GG EZ SUCKERS!"SS_TAP(X_ENT));
            } else {
              // when GGEZ is released
            }
            return false;  // Skip all further processing of this key
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case COLEMAK:
            if (record->event.pressed) {
            set_single_persistent_default_layer(0);
            } else {
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
            set_single_persistent_default_layer(1);
            } else {
            }
            return false;
        case GAME:
            if (record->event.pressed) {
            set_single_persistent_default_layer(2);
            } else {
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}
