#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/kc_keys.h"

#define KC__M DF(_NUM)
#define KC__BL DF(_BL)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* template
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
        ,    ,    ,    ,    ,    ,    ,     ,   ,    ,    ,    ,    ,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     , ,           ,        ,     ,     ,     ,
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
    */

  [_BL] = LAYOUT_kc_wrapper(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    TAB , ________L_BL_R2________, ________R_BL_R2________,LBRC,RBRC,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
    CESC , ________L_BL_R3________, ________R_BL_R3________,  QUOT  ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
    LSFT   , ________L_BL_R4________, ________R_BL_R4________, RSFT ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
    _FN2 ,LALT,LGUI , ,   SFN1    ,  EFN2  , ALBS, RGUI, _FN1, _M
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
        ,    ,    ,    ,    ,    ,    ,     ,   ,    ,    ,    ,    ,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,  DQUO  ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           , XXX,LPRN,RPRN,    ,    ,EPIP,    ,    ,    ,    ,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     , ,           ,        ,     ,     ,     ,
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_FN1] = LAYOUT_kc_wrapper(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    GRV , ________L_LWR_2________, ________R_LWR_2________,UNDS,PLUS,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         , ________L_LWR_3________, ________R_LWR_3________,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           , ________L_LWR_4________, ________R_LWR_4________,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     , ,           ,        ,     ,     ,     ,
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_FN2] = LAYOUT_kc_wrapper(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    TILD, ________L_RSE_2________, ________R_RSE_2________,MINS,EQL ,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         , ________L_RSE_3________, ________R_RSE_3________,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           , ________L_RSE_4________, ________R_RSE_4________,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
        ,     ,     , ,           ,        ,     , LEFT, DOWN, RIGHT
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_CFG] = LAYOUT_kc_wrapper(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    MAKE, ____FUNCTIONS_LEFT____ , ____FUNCTIONS_LEFT____ , F11, F12,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
           , ________L_CFG_3________, ________R_CFG_3________, _RST ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
           , ________L_CFG_4________, ________R_CFG_4________,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     , ,           ,        ,     ,     ,     ,
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_NUM] = LAYOUT_kc(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
        ,    ,BTN1,MS_U,BTN2,WH_D,    , 7  , 8  , 9  ,MINS,    ,    ,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         ,    ,MS_L,MS_D,MS_R,WH_U,    , 4  , 5  , 6  ,PLUS,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           ,    ,    ,    ,    ,    ,ASTR, 1  , 2  , 3  ,    ,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     , ,           ,        , 0   , DOT , COMM, _BL
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  )
};

// clang-format on
