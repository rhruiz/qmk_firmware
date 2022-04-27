#include QMK_KEYBOARD_H
#include "rhruiz.h"

// vi: colorcolumn=0

// clang-format off

#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_base( \
    A2, A3, A4, A5, A6, A7, A8, A9, A10, A11,     \
    B2, B3, B4, B5, B6, B7, B8, B9, B10, B11,     \
    C2, C3, C4, C5, C6, C7,     C9, C10, C11, C12 \
  ) \
    LAYOUT_wrapper( \
/*,--------+----+----+----+----+----+----+----+----+----+----+--------+------------------. */ \
    KC_TAB ,  A2 ,  A3 ,  A4 ,  A5 ,  A6 ,  A7 ,  A8 ,  A9 ,  A10,  A11, KC_BSLS, KC_ESC ,  \
/*|--------`-----`-----`-.---`-.---`--.--`.----`-.---`-.---`--.--`-.---`--------`--------+ */ \
    CT_ESC  ,  B2 ,  B3 ,  B4 ,  B5 ,  B6 ,  B7 ,  B8 ,  B9 , B10 , B11 ,     KC_ENT    ,  \
/*|----------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`---------------+  */ \
    KC_LSFT    ,  C2 ,  C3 ,  C4 ,  C5 ,  C6 ,  C7 ,  C9 , C10 , C11 , C12 ,   KC_RSFT   ,  \
/*|------------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------------+ */ \
    KC_LCTL, KC_LALT, KC_LGUI, LT_LWR_SPC , LT_RSE_ENT, AT_BS , KC_RGUI, MO_LWR , TG_NUM    \
/*`--------+--------+--------+------------+-----------+-------+--------+--------+--------' */ \
    )

#define LAYOUT_mine( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
    K10  , K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A,    K1B, \
    K20    , K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  K2B, \
    K30 , K31, K32 ,     K33    ,    K34    , K35 , K36,  K37 , K38  \
    ) \
    LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
    K10  , K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A,    K1B, \
    K20    , K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  K2B, \
    K30, K31, K32, KC_NO,   K33   ,   K34   , K35 , K36,  K37 , K38  \
    )

#define LAYOUT_wrapper(...) LAYOUT_mine(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_base_wrapper(
    ________L_BL_R2________, ________R_BL_R2________,
    ________L_BL_R3________, ________R_BL_R3________,
    ________L_BL_R4________, ________R_BL_R4________
  ),

  [_KEY_OVERRIDE] = LAYOUT_mine(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------+
    _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_DQUO    ,
//|----------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------+
    _______     , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______   ,
//|-------------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`------------+
    _______  , _______,  _______  ,       _______       ,       _______       ,  _______ , _______,  _______ , _______
//`----------+--------+-----------+---------------------+---------------------+----------+--------+----------+---------'
  ),

  [_FN1] = LAYOUT_wrapper(
//,--------+---------------------------------------------------------+--------+--------.
    KC_TILD,   ________L_LWR_2________  ,   ________R_LWR_2________  , KC_UNDS, KC_PLUS,
//|--------`----------------------------`----------------------------`--------`--------+
    _______  ,   ________L_LWR_3________  ,   ________R_LWR_3________  ,    KC_COLN    ,
//|----------`----------------------------`----------------------------`---------------+
    _______     ,   ________L_LWR_4________  ,   ________R_LWR_4________  ,  _______   ,
//|-------------`----------------------------`----------------------------`------------+
    _______  , _______, _______, _______, _______,  _______, _______, _______, _______
//`----------+--------+--------+--------+--------+---------+--------+--------+---------'
  ),

  [_FN2] = LAYOUT_wrapper(
//,--------+---------------------------------------------------------+--------+--------.
    KC_GRV ,   ________L_RSE_2________  ,   ________R_RSE_2________  , KC_MINS, KC_EQL ,
//|--------`----------------------------`----------------------------`--------`--------+
    _______  ,   ________L_RSE_3________  ,   ________R_RSE_3________  ,    KC_COLN    ,
//|----------`----------------------------`----------------------------`---------------+
    _______     ,   ________L_RSE_4________  ,   ________R_RSE_4________  ,  _______   ,
//|-------------`----------------------------`----------------------------`------------+
    _______  , _______, _______, _______, _______,  _______, _______, _______, _______
//`----------+--------+--------+--------+--------+---------+--------+--------+---------'
  ),

  [_CFG] = LAYOUT_wrapper(
//,--------+---------------------------------------------------------+--------+--------.
    KC_MAKE,   ________L_CFG_2________  ,   ________R_CFG_2________  , KC_F11 , KC_F12 ,
//|--------`----------------------------`----------------------------`--------`--------+
    _______  ,   ________L_CFG_3________  ,   ________R_CFG_3________  ,    KC_COLN    ,
//|----------`----------------------------`----------------------------`---------------+
    _______     ,   ________L_CFG_4________  ,   ________R_CFG_4________  ,  _______   ,
//|-------------`----------------------------`----------------------------`------------+
    _______  , _______, _______, _______, _______,  _______, _______, _______, _______
//`----------+--------+--------+--------+--------+---------+--------+--------+---------'
  ),

  [_NUM] = LAYOUT_wrapper(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
    _______, KC_BTN2,  KC_NO , KC_MS_U,  KC_NO , KC_WH_D, KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_MINS, _______, _______,
//|--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------+
    _______  , KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS,     _______   ,
//|----------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------+
    _______     , _______, _______, _______, _______, _______, _______,  KC_1  ,  KC_2  ,  KC_3  , _______,  _______   ,
//|-------------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`------------+
    _______  , _______,  _______  ,       _______       ,       _______       ,   KC_0   , KC_DOT , KC_COMMA , TG_NUM
//`----------+--------+-----------+---------------------+---------------------+----------+--------+----------+---------'
  )

  /* templates
 //,----+----+----+----+----+----+----+----+----+----+----+----+----.
        ,    ,    ,    ,    ,    ,    ,     ,   ,    ,    ,    ,    ,
 //|----`----`----`----`----`----`----`----`----`----`----`----`----+
         ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,        ,
 //|-----`----`----`----`----`----`----`----`----`----`----`--------+
           ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,      ,
 //|-------`----`----`----`----`----`----`----`----`----`----`------+
         ,    ,     ,             ,        ,     ,     ,     ,
 //`-----+----+-----+-------------+--------+-----+-----+-----+------'

  [_LAYER] = LAYOUT_mine(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------+
    _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______    ,
//|----------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------+
    _______     , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______   ,
//|-------------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`------------+
    _______  , _______,  _______  ,       _______       ,       _______       ,  _______ , _______,  _______ , _______
//`----------+--------+-----------+---------------------+---------------------+----------+--------+----------+---------'
  ),
   */
};

// clang-format on
