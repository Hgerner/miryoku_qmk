// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"
#include "keymap_swedish.h"

enum {
    TD_WS1 = 0,
    TD_WS2,
    TD_WS3,
    TD_WS4,
    TD_WS5,
    TD_WS6,
    TD_SCREEN1,
    TD_SCREEN2,
    TD_SCREEN3,
    TD_FOCUS_SWAP_MASTER,
};

enum custom_keycodes {
    QUOT_DQUO = SAFE_RANGE,
    PLUS_MINUS,
    ASTR_SLSH,
    COMM_EQL,
    SLSH_BSLS,
    KC_SYM_SLSH,
    MY_TILD,
    MY_CIRC,
    MY_GRV,
    MY_ACUT,
};

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case SE_A ... SE_Z:
    case SE_ARNG:
    case SE_ADIA:
    case SE_ODIA:
        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case SE_1 ... SE_0:
    case KC_BSPC:
    case KC_DEL:
    case SE_MINS:
    case SE_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    uint16_t shifted = 0;
    uint16_t regular = 0;
    static uint16_t sym_slsh_timer;

    qk_tap_dance_action_t *action;
    switch (keycode) {
        case TD(TD_WS1):
        case TD(TD_WS2):
        case TD(TD_WS3):
        case TD(TD_WS4):
        case TD(TD_WS5):
        case TD(TD_WS6):
        case TD(TD_SCREEN1):
        case TD(TD_SCREEN2):
        case TD(TD_SCREEN3):
        case TD(TD_FOCUS_SWAP_MASTER):
            // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        break;
        case QUOT_DQUO:
            if (!shifted) {
                regular = SE_QUOT; 
                shifted = SE_DQUO; 
            }
        case ASTR_SLSH:
            if (!shifted) {
                regular = SE_ASTR; 
                shifted = SE_SLSH; 
            }
        case PLUS_MINUS:
            if (!shifted) {
                regular = SE_PLUS; 
                shifted = SE_MINS; 
            }
        case COMM_EQL:
            if (!shifted) {
                regular = SE_COMM; 
                shifted = SE_EQL; 
            }
            const uint8_t mods = get_mods();
            if (record->event.pressed) {
                if ((mods) & MOD_MASK_SHIFT) {
                    unregister_code16(KC_LSFT);
                    tap_code16(shifted); 
                    register_code16(KC_LSFT);
                }
                else {
                    tap_code16(regular);
                }
            }
            break;
        case MY_TILD:
            tap_code16(SE_TILD);
            break;
        case MY_CIRC:
            tap_code16(SE_CIRC);
            break;
        case MY_GRV:
            tap_code16(SE_GRV);
            break;
        case MY_ACUT:
            tap_code16(SE_ACUT);
            break;

        case KC_SYM_SLSH:
            if (!shifted) {
                regular = SE_SLSH;
                shifted = SE_BSLS;
            }
            if(record->event.pressed){
                sym_slsh_timer = timer_read();
                layer_on(U_SYM2);
            } else {
                layer_off(U_SYM2);
                if (timer_elapsed(sym_slsh_timer) < TAPPING_TERM) {
                    if (!shifted) {
                        regular = SE_SLSH;
                        shifted = SE_BSLS;
                    }
                    const uint8_t mods = get_mods();
                    if ((mods) & MOD_MASK_SHIFT) {
                        unregister_code16(KC_LSFT);
                        tap_code16(shifted);
                        register_code16(KC_LSFT);
                    }
                    else {
                        tap_code16(regular);
                    }
                }
            }
        return false;

            return false;
        break;
    }
   
    return true;
}

void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_WS1] = ACTION_TAP_DANCE_TAP_HOLD(WS1, WS1_SFT),
    [TD_WS2] = ACTION_TAP_DANCE_TAP_HOLD(WS2, WS2_SFT),
    [TD_WS3] = ACTION_TAP_DANCE_TAP_HOLD(WS3, WS3_SFT),
    [TD_WS4] = ACTION_TAP_DANCE_TAP_HOLD(WS4, WS4_SFT),
    [TD_WS5] = ACTION_TAP_DANCE_TAP_HOLD(WS5, WS5_SFT),
    [TD_WS6] = ACTION_TAP_DANCE_TAP_HOLD(WS6, WS6_SFT),
    [TD_SCREEN1] = ACTION_TAP_DANCE_TAP_HOLD(SCREEN1_GO, SCREEN1_MOVE),
    [TD_SCREEN2] = ACTION_TAP_DANCE_TAP_HOLD(SCREEN2_GO, SCREEN2_MOVE),
    [TD_SCREEN3] = ACTION_TAP_DANCE_TAP_HOLD(SCREEN3_GO, SCREEN3_MOVE),
    [TD_FOCUS_SWAP_MASTER] = ACTION_TAP_DANCE_TAP_HOLD(MASTER_FOCUS, MASTER_SWAP),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};




#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
