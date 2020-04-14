#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "rhruiz_kc_keys.h"

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

  [_BL] = LAYOUT_kc(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    TAB , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
    CESC , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,  QUOT  ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH, RSFT ,
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

  [_FN1] = LAYOUT_kc(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    GRV , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         ,BSLS,LBRC,RBRC,MINS,PLUS,LEFT,DOWN, UP ,RGHT,COLN,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           ,    ,    ,    ,    ,    ,    ,    ,    ,    , UP ,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     , ,           ,        ,     , LEFT, DOWN, RIGHT
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_FN2] = LAYOUT_kc(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    TILD,EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,PLUS,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         ,PIPE,LCBR,RCBR,UNDS,EQL , XXX,LEFT,DOWN, UP ,RGHT,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           ,    ,    ,    ,    ,    ,    ,    , LT , GT ,QUES,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
        ,     ,     , ,           ,        ,     ,     ,     ,
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'
  ),

  [_CFG] = LAYOUT_kc(
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
    MAKE, F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 , F10, F11, F12,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
           ,_VUP,_VDN,MUTE,EJCT,    ,    , _WL,PGDN,PGUP, _WR, _RST ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
           ,    ,    ,    ,    ,    ,    ,    ,MRWD,MPLY,MFFD,      ,
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
