// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once


// SPLIT 3x6
#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
QUOT_DQUO,    SE_Q,              SE_W,              SE_F,               SE_P,               SE_B,              SE_J,                  SE_L,               SE_U,               SE_Y,          QUOT_DQUO,          SE_ARNG, \
U_NP,         LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),       LSFT_T(KC_T),       SE_G,              SE_M,                  RSFT_T(KC_N),       LCTL_T(KC_E),       LALT_T(KC_I),  LGUI_T(KC_O),       SE_ADIA, \
U_NP,         LT(U_WM,KC_Z),     ALGR_T(KC_X),      SE_C,               LT(U_NUM_FLIP, SE_D),               SE_V,              SE_K,                  LT(U_SYM2, SE_H),               KC_COMM,            SE_DOT,        KC_SYM_SLSH,            SE_ODIA, \
                                                    LT(U_SYM3, KC_ESC), LT(U_NAV,KC_SPC),   LT(U_NUM_FLIP, KC_TAB),LT(U_FUN, KC_ENT), LT(U_SYM,KC_BSPC),  LT(U_SYM2, KC_DEL)


#define MIRYOKU_ALTERNATIVES_BASE_QWERTY \
U_NP, KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                U_NP, \
U_NP, LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),     U_NP, \
U_NP, LT(U_WM,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_WM,KC_SLSH),U_NP, \
                                            LT(U_NUM_FLIP, KC_ESC),            LT(U_NAV,KC_SPC),  LT(U_NUM_FLIP, KC_TAB),LT(U_SYM2, KC_ENT), LT(U_SYM,KC_BSPC),  LT(U_FUN, KC_DEL)


#define MIRYOKU_ALTERNATIVES_NAV \
U_NP, RESET,             U_NP,      DF(U_EXTRA),       DF(U_BASE),        U_NA,              U_NP,              SE_ARNG,           U_NP,    U_NP,           SE_QUES,                  U_NP, \
U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_CAPS,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,                  U_NP, \
U_NP, U_NA,              KC_ALGR,           DF(U_NUM_FLIP),    DF(U_NAV),         U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,                   U_NP, \
                                            U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL

#define MIRYOKU_ALTERNATIVES_NUM \
U_NP, KC_LBRC,           SE_7,              SE_8,              SE_9,              KC_RBRC,           U_NA,              DF(U_BASE),        U_NP,              U_NP,              RESET,                    U_NP, \
U_NP, KC_SCLN,           SE_4,              SE_5,              SE_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,                  U_NP, \
U_NP, KC_GRV,            SE_1,              SE_2,              SE_3,              KC_BSLS,           U_NA,              DF(U_NUM_FLIP),         DF(U_NAV),         KC_ALGR,           U_NA,                     U_NP, \
                                            SE_0,              SE_0,              KC_DOT,            U_NA,              U_NA,              U_NA

#define MIRYOKU_ALTERNATIVES_NUM_FLIP \
U_NP, RESET,             U_NP,              U_NP,              DF(U_BASE),        U_NA,              PLUS_MINUS,        SE_7,              SE_8,              SE_9,              SE_0,                     U_NP, \
U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              ASTR_SLSH,         SE_4,              SE_5,              SE_6,              SE_0,                     U_NP, \
U_NP, SE_DOT,            SE_COMM,           DF(U_NAV),         DF(U_NUM_FLIP),    U_NA,              COMM_EQL,          SE_1,              SE_2,              SE_3,              SE_DOT,                   U_NP, \
                                            U_NA,              U_NA,              KC_MINS,           KC_ENT,            KC_BSPC,           SE_0   

#define MIRYOKU_ALTERNATIVES_WM \
U_NP, U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,              TD(TD_WS1),       TD(TD_WS2),        TD(TD_WS3),        TD(TD_WS4),       TD(TD_WS5),                 U_NP, \
U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,               LGUI(LCTL(SE_M)), TD(TD_FOCUS_SWAP_MASTER),     LGUI(LCTL(KC_DOWN)),     LGUI(LCTL(KC_UP)),      LGUI(LCTL(KC_RGHT)),U_NP, \
U_NP, U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,              LGUI(LCTL(SE_K)), TD(TD_SCREEN1),    TD(TD_SCREEN2),    TD(TD_SCREEN3),   KC_END,                     U_NP, \
                                            LGUI(LCTL(KC_ESC)),LGUI(LCTL(KC_SPC)),LGUI(LCTL(KC_TAB)), LGUI(LCTL(KC_ENT)),     LGUI(LCTL(KC_BSPC)),     LGUI(LCTL(KC_DEL))

#define MIRYOKU_ALTERNATIVES_FUN \
U_NP, KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              DF(U_BASE),        U_NP,              U_NP,              RESET,                    U_NP, \
U_NP, KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,                  U_NP, \
U_NP, KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              DF(U_FUN),         U_NP,              KC_ALGR,           U_NA,                     U_NP, \
                                            KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA


#define MIRYOKU_ALTERNATIVES_SYM \
U_NP,       SE_PERC,     SE_AMPR,           SE_LCBR,           SE_RCBR,           SE_AT,             U_NP,              SE_ASTR,           SE_UNDS,           SE_SLSH,           U_NP,                     U_NP,     \
U_NP,       SE_PIPE,     SE_ASTR,           SE_LPRN,           SE_RPRN,           SE_EQL,            U_NP,              SE_PLUS,           SE_MINS,           SE_HASH,           SE_DLR,                   U_NP,     \
U_NP,       SE_HASH,     MY_TILD,           SE_LBRC,           SE_RBRC,           SE_EXLM,           U_NP,              SE_EXLM,           SE_EQL,            U_NP,              SE_QUES,                  U_NP,     \
                         KC_SPACE,          SE_COLN,           SE_SCLN,           U_NA,              U_NA,              KC_RALT


#define MIRYOKU_ALTERNATIVES_SYM2 \
U_NP,       SE_PND,      MY_ACUT,              MY_CIRC,              MY_GRV,            MY_GRV,            U_NP,              U_NP,              U_NP,              U_NP,              U_NP,                     U_NP,     \
U_NP,       SE_DLR,      SE_LABK,           SE_MINS,           SE_RABK,           MY_ACUT,           U_NP,              U_NP,              U_NP,              U_NP,              U_NP,                     U_NP,     \
U_NP,       SE_EURO,     SE_QUES,              SE_EXLM,           SE_EQL,           MY_CIRC,           U_NP,              U_NP,              U_NP ,             U_NP,              U_NP,                     U_NP,     \
                                            U_NA,              SE_BSLS,           SE_SLSH,           U_NA,              U_NA,              KC_RALT


#define MIRYOKU_ALTERNATIVES_SYM3 \
U_NP,       U_NP,        U_NP,              U_NP,              U_NP,              U_NP,              SE_ARNG,              SE_PND,            U_NP,              SE_HASH,          SE_GRV,                   U_NP,     \
U_NP,       U_NP,        U_NP,              U_NP,              U_NP,              U_NP,              SE_ADIA,              SE_LABK,           SE_RABK,           SE_PERC,          SE_ACUT,                  U_NP,     \
U_NP,       U_NP,        U_NP,              U_NP,              U_NP,              U_NP,              SE_ODIA,              SE_EURO,           SE_TILD,           U_NP,             SE_CIRC,                  U_NP,     \
                                            U_NA,              SE_BSLS,           SE_SLSH,           KC_SPACE,             KC_BSPC,           KC_RALT
