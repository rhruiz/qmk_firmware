#pragma once

#define LAYOUT_kc_wrapper(...) LAYOUT_kc(__VA_ARGS__)

#define KC__F1 KC_F1
#define KC__F2 KC_F2
#define KC__F3 KC_F3
#define KC__F4 KC_F4
#define KC__F5 KC_F5
#define KC__F6 KC_F6
#define KC__F7 KC_F7
#define KC__F8 KC_F8
#define KC__F9 KC_F9
#define KC__F10 KC_F10

#ifdef HOME_ROW_MODS
#    define KC__LALT_T(k) LALT_T(k)
#    define KC__LSFT_T(k) LSFT_T(k)
#    define KC__LCTL_T(k) LCTL_T(k)
#    define KC__LGUI_T(k) LGUI_T(k)
#    define HRL(k1, k2, k3, k4, k5) _LCTL_T(KC_##k1), _LSFT_T(KC_##k2), _LALT_T(KC_##k3), _LGUI_T(KC_##k4), k5
#    define HRR(k1, k2, k3, k4, k5) k1, _LGUI_T(KC_##k2), _LALT_T(KC_##k3), _LSFT_T(KC_##k4), _LCTL_T(KC_##k5)
#else
#    define HRL(k1, k2, k3, k4, k5) k1, k2, k3, k4, k5
#    define HRR(k1, k2, k3, k4, k5) k1, k2, k3, k4, k5
#endif

// clang-format off
//                            .----+----+----+----+----.
#define _____NUMBERS_LEFT_____   1 ,  2 ,  3 ,  4 ,  5
//                            |----+----+----+----+----|
#define _____NUMBERS_RGHT_____   6 ,  7 ,  8 ,  9 ,  0
//                            |----+----+----+----+----|
#define ____FUNCTIONS_LEFT____  _F1, _F2, _F3, _F4, _F5
//                            |----+----+----+----+----|
#define ____FUNCTIONS_RGHT____  _F6, _F7, _F8, _F9,_F10
//                            |----+----+----+----+----|
#define _____SYMBOLS_LEFT_____ EXLM, AT ,HASH, DLR,PERC
//                            |----+----+----+----+----|
#define _____SYMBOLS_RGHT_____ CIRC,AMPR,ASTR,LPRN,RPRN
//                            `----+----+----+----+----'

//                                 .------------------------.
#define ________L_BL_R1________      _____NUMBERS_LEFT_____
//                                 |----+----+----+----+----|
#define ________L_BL_R2________       Q ,  W ,  E ,  R ,  T
//                                 |----+----+----+----+----|
#define ________L_BL_R3________ HRL(  A ,  S ,  D ,  F ,  G )
//                                 |----+----+----+----+----|
#define ________L_BL_R4________       Z ,  X ,  C ,  V ,  B
//                                 `----+----+----+----+----'

//                                 .------------------------.
#define ________R_BL_R1________      _____NUMBERS_RGHT_____
//                                 |----+----+----+----+----|
#define ________R_BL_R2________       Y ,  U ,  I ,  O ,  P
//                                 |----+----+----+----+----|
#define ________R_BL_R3________ HRR(  H ,  J ,  K ,  L ,SCLN)
//                                 |----+----+----+----+----|
#define ________R_BL_R4________       N ,  M ,COMM, DOT,SLSH
//                                 `----+----+----+----+----'

//                                 .------------------------.
#define ________L_LWR_1________      ____FUNCTIONS_LEFT____
//                                 |----+----+----+----+----|
#define ________L_LWR_2________     EXLM,LCBR,RCBR, DLR,PERC
//                                 |----+----+----+----+----|
#define ________L_LWR_3________     HASH,LBRC,RBRC,MINS,UNDS
//                                 |----+----+----+----+----|
#define ________L_LWR_4________      AT ,LPRN,RPRN, EQL,PLUS
//                                 `----+----+----+----+----'

//                                 .------------------------.
#define ________R_LWR_1________      ____FUNCTIONS_RGHT____
//                                 |----+----+----+----+----|
#define ________R_LWR_2________         ,EPIP,ASTR,BSLS,
//                                 |----+----+----+----+----|
#define ________R_LWR_3________      GRV,AMPR,PIPE,CIRC,QUOT
//                                 |----+----+----+----+----|
#define ________R_LWR_4________         ,    ,TILD, GRV,QUES
//                                 `----+----+----+----+----'

//                                 .------------------------.
#define ________L_RSE_1________     SLCK,PAUS,MISS,    ,
//                                 |----+----+----+----+----|
#define ________L_RSE_2________      _____NUMBERS_LEFT_____
//                                 |----+----+----+----+----|
#define ________L_RSE_3________     _WN,_TAP,_TAN, TAB,
//                                 |----+----+----+----+----|
#define ________L_RSE_4________     CTAB,_BCK,_FWD, ESC,
//                                 `----+----+----+----+----'

//                                 .------------------------.
#define ________R_RSE_1________      _____SYMBOLS_RGHT_____
//                                 |----+----+----+----+----|
#define ________R_RSE_2________      _____NUMBERS_RGHT_____
//                                 |----+----+----+----+----|
#define ________R_RSE_3________     PLUS,LEFT,DOWN, UP ,RGHT
//                                 |----+----+----+----+----|
#define ________R_RSE_4________     MINS,ASTR,COMM, DOT,SLSH
//                                 `----+----+----+----+----'

//                                 .----+----+----+----+----.
#define ________L_CFG_1________     SLCK,PAUS,MISS,RVAD,RVAI
//                                 |----+----+----+----+----|
#define ________L_CFG_2________     RTOG,RMOD,RSAI,RVAI,RHUI
//                                 |----+----+----+----+----|
#define ________L_CFG_3________         ,    ,    ,    ,
//                                 |----+----+----+----+----|
#define ________L_CFG_4________     _VUP,_VDN,MUTE,EJCT,
//                                 `----+----+----+----+----'

//                                 .----+----+----+----+----.
#define ________R_CFG_1________         ,    ,    ,    ,
//                                 |----+----+----+----+----|
#define ________R_CFG_2________         ,_BOL,_SBT,_STP,_EOL
//                                 |----+----+----+----+----|
#define ________R_CFG_3________         , _WL,PGDN,PGUP, _WR
//                                 |----+----+----+----+----|
#define ________R_CFG_4________         ,    ,MRWD,MFFD,MPLY
//                                 `----+----+----+----+----'
// clang-format on
