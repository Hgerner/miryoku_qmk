// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "miryoku_babel/miryoku_layer_selection.h"
#include "miryoku_babel/miryoku_layer_list.h"

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

#define MIRYOKU_CLIPBOARD_WIN

#if !defined (MIRYOKU_MAPPING)
  #define MIRYOKU_MAPPING LAYOUT_split_3x6_3
#endif

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define WS1 LGUI(KC_1)
#define WS2 LGUI(KC_2)
#define WS3 LGUI(KC_3)
#define WS4 LGUI(KC_4)
#define WS5 LGUI(KC_5)
#define WS6 LGUI(KC_6)

#define WS1_SFT LGUI(LSFT(KC_1))
#define WS2_SFT LGUI(LSFT(KC_2))
#define WS3_SFT LGUI(LSFT(KC_3))
#define WS4_SFT LGUI(LSFT(KC_4))
#define WS5_SFT LGUI(LSFT(KC_5))
#define WS6_SFT LGUI(LSFT(KC_6))

#define SCREEN1_GO LGUI(LSFT(LCTL(KC_1)))
#define SCREEN2_GO LGUI(LSFT(LCTL(KC_2)))
#define SCREEN3_GO LGUI(LSFT(LCTL(KC_3)))

#define SCREEN1_MOVE LGUI(LSFT(LALT(LCTL(KC_1))))
#define SCREEN2_MOVE LGUI(LSFT(LALT(LCTL(KC_2))))
#define SCREEN3_MOVE LGUI(LSFT(LALT(LCTL(KC_3))))

#define MASTER_FOCUS LGUI(LCTL(KC_LEFT))
#define MASTER_SWAP  LGUI(LCTL(KC_BSPC))

#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO KC_AGIN
  #define U_PST KC_PSTE
  #define U_CPY KC_COPY
  #define U_CUT KC_CUT
  #define U_UND KC_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)
#endif
