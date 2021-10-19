/* Copyright 2021 @ Grayson Carr
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

#pragma once

#define ENCODERS_PAD_A { B7 }
#define ENCODERS_PAD_B { E6 }
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 4

/* RGB Matrix Configuration */
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define CAPS_LOCK_INDICATOR_COLOR RGB_RED
#    define CAPS_LOCK_INDICATOR_LIGHT_ALPHAS
#    define FN_LAYER_TRANSPARENT_KEYS_OFF
#endif
#define TAPPING_TERM 200
#define RGB_MATRIX_KEYPRESSES
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
