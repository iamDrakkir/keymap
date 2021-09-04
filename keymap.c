/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_swedish.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _NUM,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  NUM,
  BACKLIT
};

// Left-hand home row mods
#define HOME_A LGUI_T(SE_A)
#define HOME_R LALT_T(SE_R)
#define HOME_S LSFT_T(SE_S)
#define HOME_T LCTL_T(SE_T)

// Right-hand home row mods
#define HOME_N RCTL_T(SE_N)
#define HOME_E RSFT_T(SE_E)
#define HOME_I LALT_T(SE_I)
#define HOME_O RGUI_T(SE_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  SE_GRV,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    KC_BSPC,
  KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    KC_DEL,
  KC_ESC,  SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_COMM, SE_DOT,  KC_SLSH, KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |  NUM |Lower |    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  SE_GRV,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    KC_BSPC,
  KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_B,    SE_J,    SE_L,    SE_U,    SE_Y,    SE_SCLN, KC_DEL,
  KC_ESC,HOME_A,  HOME_R,  HOME_S,  HOME_T,    SE_G,    SE_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O,    KC_QUOT,
  KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_K,    SE_H,    SE_COMM, SE_DOT,  KC_UP,   KC_ENT,
  KC_LCTL, KC_LGUI, KC_LALT, NUM,    LOWER,    KC_SPC,  KC_SPC,  RAISE,   SE_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   `  |   ´  |   (  |   )  |   -  |   _  |   Å  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |   $  |   =  |   {  |   }  |   *  |   Ö  |   Ä  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   \  |   /  |   [  |   ]  |   ¨  |   '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   ?  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,  SE_GRV, SE_ACUT, SE_LPRN, SE_RPRN, SE_MINS, SE_UNDS, SE_ARNG,
  _______, _______, _______, _______, _______,  SE_DLR,  SE_EQL, SE_LCBR, SE_RCBR, SE_ASTR, SE_ODIA, SE_ADIA,
  _______, _______, _______, _______, _______, SE_BSLS, SE_SLSH, SE_LBRC, SE_RBRC, SE_DQUO, SE_QUOT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, SE_QUES, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   £  |  $   |   €  |      |   {  |   [  |   ]  |   }  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |  $   |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Pg Up| Vol+ | Pg Dn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, SE_EXLM,   SE_AT,  SE_PND,  SE_DLR, SE_EURO, _______, SE_LCBR, SE_LBRC, SE_RBRC, SE_RCBR, SE_BSLS,
  _______, SE_EXLM,   SE_AT, SE_HASH,  SE_DLR, SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_VOLU, KC_PGUP,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
),

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   /  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |   ,  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_SLSH, SE_ASTR, _______,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______, _______,    SE_7,    SE_8,    SE_9, SE_MINS,
  _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______, _______,    SE_4,    SE_5,    SE_6, SE_PLUS,
  _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______,    SE_1,    SE_2,    SE_3, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    SE_0, SE_COMM,  SE_DOT,  SE_EQL
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,  RESET,    DEBUG, _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______,  KC_DEL,
  _______, _______,  MU_MOD,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
  _______,  MUV_DE,  MUV_IN,   MU_ON,  MU_OFF,   MI_ON,  MI_OFF, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case NUM:
          if (record->event.pressed) {
            layer_on(_NUM);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_NUM);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
