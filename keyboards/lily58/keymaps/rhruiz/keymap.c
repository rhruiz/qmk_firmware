#include QMK_KEYBOARD_H
#include "rhruiz.h"

#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define ___ KC_TRNS
#define KC__TGN TG_NUM

// clang-format off
#define LAYOUT_base( \
    L01, L02, L03, L04, L05,   R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15,   R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25,   R21, R22, R23, R24, R25, \
    L31, L32, L33, L34, L35,   R31, R32, R33, R34, R35  \
  ) \
  LAYOUT_wrapper( \
/*,--------------------------------------.                     ,--------------------------------------.*/ \
    KC_TILD,   L01  , L02, L03, L04, L05 ,                         R01  , R02, R03, R04, R05 , KC_ESC , \
/*|--------+--------+----+----+----+-----|                     |--------+----+----+-----+----+--------|*/ \
    KC_TAB ,   L11  , L12, L13, L14, L15 ,                         R11  , R12, R13, R14, R15 , KC_BSPC, \
/*|--------+--------+----+----+----+-----|                     |--------+----+----+-----+----+--------|*/ \
    CT_ESC , HRL(L21, L22, L23, L24, L25),                       HRR(R21, R22, R23, R24, R25), KC_QUOT, \
/*|--------+--------+----+----+----+-----|----------| |--------+--------+----+----+-----+----+--------|*/ \
    KC_LSFT,   L31  , L32, L33, L34, L35 ,  TG_GAME ,   TG_NUM ,   R31  , R32, R33, R34, R35 , KC_RSFT, \
/*`--------+---------------------------------------/   \---------------------------+---------+--------'*/ \
                 KC_LALT, KC_LGUI, MO_LWR, CT_SPC ,       ST_ENT , MO_RSE ,  AT_BS , KC_RGUI            \
/*            `--------+--------+----------------/       \--------+--------+--------+--------'         */ \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_base_wrapper(
     KC_NO, KC_B, KC_B, KC_T, KC_NO, KC_NO, KC_N, KC_H, KC_Y, KC_NO,
     ________L_BL_R2________, ________R_BL_R2________,
     ________L_BL_R3________, ________R_BL_R3________,
     ________L_BL_R4________, ________R_BL_R4________
  ),

  [_ALT_BL] = LAYOUT_base_wrapper(
     ________L_BL_R1________, ________R_BL_R1________,
     ________L_BL_R2________, ________R_BL_R2________,
     ________L_BL_R3________, ________R_BL_R3________,
     ________L_BL_R4________, ________R_BL_R4________
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc( \
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     , DEL ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     , DQUO,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,    ,           ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_FN1] = LAYOUT_wrapper(
// .--------+-------------------------------------.             .-----------------------------------+--------.
     KC_F11 , ___, KC_PLUS, KC_UNDS, KC_PERC, ___ ,               ___ , KC_GRV , KC_TILD, ___ , ___ , KC_F12 ,
// |--------+-------------------------------------|             |-----------------------------------+--------|
     KC_TILD,      ________L_LWR_2________        ,                    ________R_LWR_2________      , _______,
// |--------+-------------------------------------|             |-----------------------------------+--------|
     _______,      ________L_LWR_3________        ,                    ________R_LWR_3________      , _______,
// |--------+-------------------------------------|-----| |-----|-----------------------------------+--------|
     _______,      ________L_LWR_4________        , ___ ,   ___ ,      ________R_LWR_4________      , _______,
// `--------+------------------------------------/-----/   \-----\----------------------------------+--------'
                               ___ , ___ , ___  , ___ ,       ___ ,  ___ , AT_DEL , ___
//                           `-----+-----+----'/-----/       \-----\'----+--------+-----'
  ),

 [_FN2] = LAYOUT_wrapper(
// .--------+--------------------------------------.             .--------------------------------------+-----.
     KC_ESC , KC_SLCK, KC_PAUS, KC_PLUS, KC_5, ___ ,               ___ ,  KC_6  , KC_EQL , KC_ASTR, ___ , ___ ,
// |--------+--------------------------------------|             |--------------------------------------+-----|
     KC_GRV ,      ________L_RSE_2________         ,                       ________R_RSE_2________      , ___ ,
// |--------+--------------------------------------|             |--------------------------------------+-----|
     _______,      ________L_RSE_3________         ,                       ________R_RSE_3________      , ___ ,
// |--------+--------------------------------------|-----| |-----|--------------------------------------+-----|
     _______,      ________L_RSE_4________         , ___ ,   ___ ,         ________R_RSE_4________      , ___ ,
// `--------+-------------------------------------/-----/   \-----\-------------------------------------+-----'
                                ___ , ___ , ___  , ___ ,       ___ ,  ___ , ___ , ___
//                            `-----+-----+----'/-----/       \-----\'----+-----+-----'
 ),

  [_CFG] = LAYOUT_wrapper(
// .--------+------------------------.                   .------------------------+--------.
     KC_ESC , ________L_CFG_1________,                     ________R_CFG_1________, QK_BOOT,
// |--------+------------------------|                   |------------------------+--------|
     KC_CAPS, ________L_CFG_2________,                     ________R_CFG_2________, KC_MAKE,
// |--------+------------------------|                   |------------------------+--------|
     _______, ________L_CFG_3________,                     ________R_CFG_3________, DF_ALT ,
// |--------+------------------------|--------| |--------|------------------------+--------|
     _______, ________L_CFG_4________, TG_GAME,   TG_NUM , ________R_CFG_4________, _______,
// `--------+-----------------------/--------/   \--------\-----------------------+--------'
                  ___ , ___ , ___  , _______,       _______,  ___ , ___ , ___
//              `-----+-----+----'/--------/       \--------\'----+-----+-----'
  ),

  [_NUM] = LAYOUT_kc(
// .-----+-----------------------------.             .-----------------------------+-----.
         ,  1  ,  2  ,  3  ,  4  ,  5  ,                6  ,  7  ,  8  ,  9 ,   0  ,     ,
// |-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
         , BTN2,  NO , MS_U,  NO , WH_D,                NO ,  4  ,  5  ,  6  , PLUS,     ,
// |-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
         , BTN1, MS_L, MS_D, MS_R, WH_U,               ASTR,  1  ,  2  ,  3  , MINS,     ,
// |-----+-----+-----+-----+-----+-----|-----| |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,   _TGN, EQL ,  0  ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/   \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,           ,      ,     ,
//                `-----+-----+----'/-----/       \-----\'----+-----+-----'
  ),


  [_ALT_FN1] = LAYOUT_wrapper(
// .--------+-----------------------------.             .--------------------------------+-----.
     KC_TILD,   ________L_LWR_2________   ,                   ________R_LWR_2________    , ___ ,
// |--------+-----------------------------|             |--------------------------------+-----|
     _______,   ________L_LWR_3________   ,                   ________R_LWR_3________    , ___ ,
// |--------+-----------------------------|             |--------------------------------+-----|
     _______,   ________L_LWR_4________   ,                   ________R_LWR_4________    , ___ ,
// |--------+-----------------------------|-----| |-----|--------------------------------+-----|
     _______, ___ , ___ , ___ , ___ , ___ , ___,    ___ , ___ , AT_DEL , ___ , ___ , ___ , ___ ,
// `--------+----------------------------/-----/   \-----\-------------------------------+-----'
                       ___ , ___ , ___  , ___ ,       ___ ,  ___ , AT_DEL , ___
//                   `-----+-----+----'/-----/       \-----\'----+--------+-----'
  ),

 [_ALT_FN2] = LAYOUT_wrapper(
// .--------+-----------------------------.             .-----------------------------+-----.
     KC_ESC ,   ________L_RSE_2________   ,                 ________R_RSE_2________   , ___ ,
// |--------+-----------------------------|             |-----------------------------+-----|
     KC_GRV ,   ________L_RSE_3________   ,                 ________R_RSE_3________   , ___ ,
// |--------+-----------------------------|             |-----------------------------+-----|
     _______,   ________L_RSE_4________   ,                 ________R_RSE_4________   , ___ ,
// |--------+-----------------------------|-----| |-----|-----------------------------+-----|
     _______, ___ , ___ , ___ , ___ , ___ , ___,    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
// `--------+----------------------------/-----/   \-----\----------------------------+-----'
                       ___ , ___ , ___  , ___ ,       ___ ,  ___ , ___ , ___
//                   `-----+-----+----'/-----/       \-----\'----+-----+-----'
 ),

  [_ALT_CFG] = LAYOUT_wrapper(
// .--------+-----------------------------.                .-----------------------------+--------.
     KC_ESC ,   ________L_CFG_2________   ,                    ________R_CFG_2________   , KC_MAKE,
// |--------+-----------------------------|                |-----------------------------+--------|
     KC_CAPS,   ________L_CFG_3________   ,                    ________R_CFG_3________   , QK_BOOT,
// |--------+-----------------------------|                |-----------------------------+--------|
     _______,   ________L_CFG_4________   ,                    ________R_CFG_4________   ,  DF_BL ,
// |--------+-----------------------------|--------| |-----|-----------------------------+--------|
     _______, ___ , ___ , ___ , ___ , ___ , TG_GAME,   ___ , ___ , ___ , ___ , ___ , ___ , _______,
// `--------+----------------------------/--------/   \-----\----------------------------+--------'
                       ___ , ___ , ___  , _______,       ___ ,  ___ , ___ , ___
//                   `-----+-----+----'/--------/       \-----\'----+-----+-----'
  ),

  [_ALT_NUM] = LAYOUT_kc(
// .-----+-----------------------------.             .-----------------------------+-----.
         , BTN2,  NO , MS_U,  NO , WH_D,               ASTR,  7  ,  8  ,  9  , PLUS,     ,
// |-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
         , BTN1, MS_L, MS_D, MS_R, WH_U,               SLSH,  4  ,  5  ,  6  , MINS,     ,
// |-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,               COMM,  1  ,  2  ,  3  ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----| |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,       ,     ,     ,  0   , DOT,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/   \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,           ,      ,     ,
//                `-----+-----+----'/-----/       \-----\'----+-----+-----'
  ),

  [_GAME] = LAYOUT_wrapper(
// .--------+-----------------------------.                .-----------------------------+--------.
     KC_TILD,   ________L_BL_R1________   ,                    ________R_BL_R1________   , KC_ESC ,
// |--------+-----------------------------|                |-----------------------------+--------|
     KC_TAB ,   ________L_BL_R2________   ,                    ________R_BL_R2________   , KC_BSPC,
// |--------+-----------------------------|                |-----------------------------+--------|
     CT_ESC ,   ________L_BL_R3________   ,                    ________R_BL_R3________   , KC_QUOT,
// |--------+-----------------------------|--------| |-----|-----------------------------+--------|
     KC_LSFT,   ________L_BL_R4________   , KC_BSPC,   ___ ,   ________R_BL_R4________   , KC_RSFT,
// `--------+----------------------------/--------/   \-----\----------------------------+--------'
              KC_LALT, KC_LGUI, OSL_GLWR, ST_SPC ,       ___ , MO_RSE ,  AT_BS , KC_RGUI
//          `--------+--------+-------'/--------/       \-----\'------+--------+--------'
  ),

  [_GAMEFN1] = LAYOUT_wrapper(
// .-----+-----------------------------.                .-----+--------+--------+--------+--------+-----.
     ___ ,   _____NUMBERS_RGHT_____    ,                  ___ , _______, _______, _______, _______, ___ ,
// |-----+-----------------------------|                |-----+--------+--------+--------+--------+-----|
     ___ ,   ____FUNCTIONS_LEFT____    ,                  ___ , _______,  KC_UP , _______, _______, ___ ,
// |-----+-----------------------------|                |-----+--------+--------+--------+--------+-----|
     ___ ,   ____FUNCTIONS_RGHT____    ,                  ___ , KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN, ___ ,
// |-----+-----------------------------|--------| |-----|-----------------------------------------+-----|
     ___ , ___ , ___ , ___ , ___ , ___ , TG_GAME,   ___ , ___ , _______,  KC_LT ,  KC_GT , KC_QUES, ___ ,
// `-----+----------------------------/--------/   \-----\----------------------------------------+-----'
                    ___ , ___ , ___  , _______,       ___ ,  ___ , ___ , ___
//                `-----+-----+----'/--------/       \-----\'----+-----+-----'
  ),

/* template
// .-----+-----+-----+-----+-----+-----.             .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                   ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                   ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                   ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----| |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,       ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/   \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,           ,      ,     ,
//                `-----+-----+----'/-----/       \-----\'----+-----+-----'
*/
};
// clang-format on
