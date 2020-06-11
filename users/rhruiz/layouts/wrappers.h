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

// clang-format off
//                             .----+----+----+----+----.
#define ________L_BL_R1________  _____NUMBERS_LEFT_____
//                             |----+----+----+----+----|
#define ________L_BL_R2________   Q ,  W ,  E ,  R ,  T
//                             |----+----+----+----+----|
#define ________L_BL_R3________   A ,  S ,  D ,  F ,  G
//                             |----+----+----+----+----|
#define ________L_BL_R4________   Z ,  X ,  C ,  V ,  B
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________R_BL_R1________  _____NUMBERS_RGHT_____
//                             |----+----+----+----+----|
#define ________R_BL_R2________   Y ,  U ,  I ,  O ,  P
//                             |----+----+----+----+----|
#define ________R_BL_R3________   H ,  J ,  K ,  L ,SCLN
//                             |----+----+----+----+----|
#define ________R_BL_R4________   N ,  M ,COMM, DOT,SLSH
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________L_LWR_1________  ____FUNCTIONS_LEFT____
//                             |----+----+----+----+----|
#define ________L_LWR_2________  _____SYMBOLS_LEFT_____
//                             |----+----+----+----+----|
#define ________L_LWR_3________ BSLS,LBRC,RBRC,MINS, EQL
//                             |----+----+----+----+----|
#define ________L_LWR_4________ EPIP,    ,    ,    ,
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________R_LWR_1________  ____FUNCTIONS_RGHT____
//                             |----+----+----+----+----|
#define ________R_LWR_2________  _____SYMBOLS_RGHT_____
//                             |----+----+----+----+----|
#define ________R_LWR_3________ PLUS,UNDS,RPRN,LPRN,COLN
//                             |----+----+----+----+----|
#define ________R_LWR_4________     ,    , LT , GT ,QUES
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________L_RSE_1________ SLCK,PAUS,MISS,    ,
//                             |----+----+----+----+----|
#define ________L_RSE_2________  _____NUMBERS_LEFT_____
//                             |----+----+----+----+----|
#define ________L_RSE_3________ PIPE,LCBR,RCBR,MINS,PLUS
//                             |----+----+----+----+----|
#define ________L_RSE_4________ EPIP,_BCK,_FWD,BTN1,BTN2
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________R_RSE_1________  _____SYMBOLS_RGHT_____
//                             |----+----+----+----+----|
#define ________R_RSE_2________  _____NUMBERS_RGHT_____
//                             |----+----+----+----+----|
#define ________R_RSE_3________ EQL ,LEFT,DOWN, UP ,RGHT
//                             |----+----+----+----+----|
#define ________R_RSE_4________ ASTR,MS_L,MS_D,MS_U,MS_R
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________L_CFG_1________ SLCK,PAUS,MISS,RVAD,RVAI
//                             |----+----+----+----+----|
#define ________L_CFG_2________ RTOG,RMOD,    ,    ,RVAI
//                             |----+----+----+----+----|
#define ________L_CFG_3________ EPIP,_TAP,_TAN,    ,RHUI
//                             |----+----+----+----+----|
#define ________L_CFG_4________ _VUP,_VDN,MUTE,EJCT,RSAI
//                             `----+----+----+----+----'

//                             .----+----+----+----+----.
#define ________R_CFG_1________     ,    ,    ,    ,
//                             |----+----+----+----+----|
#define ________R_CFG_2________     ,_BOL,_SBT,_STP,_EOL
//                             |----+----+----+----+----|
#define ________R_CFG_3________     , _WL,PGDN,PGUP, _WR
//                             |----+----+----+----+----|
#define ________R_CFG_4________     ,    ,MRWD,MFFD,MPLY
//                             `----+----+----+----+----'
// clang-format on
