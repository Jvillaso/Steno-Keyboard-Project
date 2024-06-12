/*
Copyright 2024 Joshua A. Villasol

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(KC_S),     LCA(KC_S),  LCTL(LSFT(KC_C)),   TO(1),
        KC_MPLY,        KC_MRWD,    KC_MFFD,            LALT(KC_RBRC),
        KC_Q,           KC_U,       KC_N,               LALT(KC_LBRC),
        KC_M,           KC_J,       KC_G,               KC_I,
        KC_P,           KC_E,       KC_B,               KC_R,
        LCTL(KC_Z),     KC_SPC
    ),

    [1] = LAYOUT(
        QK_RBT,     QK_BOOT,    KC_NO,  TO(1),
        KC_NO,      KC_NO,      KC_NO,  KC_NO,
        KC_NO,      KC_NO,      KC_NO,  KC_NO,
        KC_NO,      KC_NO,      KC_NO,  KC_NO,
        KC_NO,      KC_NO,      KC_NO,  KC_NO,
        KC_NO,      KC_NO
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) //Rotary encoder turning
{    
    switch(index)
    {
        case 0:
            if (clockwise) { tap_code(KC_W); } else { tap_code(KC_S); }
            break;
        
        case 1:
            if (clockwise) { tap_code(KC_A); } else { tap_code(KC_D); }
            break;
    }
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) //Rotary encoder switch
{
    switch(index)
    {
        case 0:
            if(active) { tap_code(KC_X); }
            break;

        case 1:
            if(active) { tap_code(KC_C); }
            break;
    }
   return true; 
}