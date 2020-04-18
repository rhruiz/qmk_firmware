#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "rhruiz_kc_keys.h"

#ifndef OLED_DRIVER_ENABLE
extern volatile bool isLeftHand;
#endif

#define KC__ALTZ LALT_T(KC_Z)
#define KC__GSLS RGUI_T(KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
      TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,                       Y  ,  U  ,  I  ,  O  ,  P  , BSPC,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      CESC,  A  ,  S  ,  D  ,  F  ,  G  ,                       H  ,  J  ,  K  ,  L  , SCLN, QUOT,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      LSFT,_ALTZ,  X  ,  C  ,  V  ,  B  ,                       N  ,  M  , COMM, DOT ,_GSLS, RSFT,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                              LGUI, _FN1, SPC ,    ENT , _FN2, ALBS
                          //`-----------------'  `-----------------'
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     , DEL ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     , DQUO,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          , XXX , LPRN, RPRN,     ,     ,                      EPIP,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
    ),

  [_FN1] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
       GRV,  1  ,  2  ,  3  ,  4  ,  5  ,                       6  ,  7  ,  8  ,  9  ,  0  ,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          , BSLS, LBRC, RBRC,MINUS, PLUS,                      LEFT, DOWN,  UP ,RIGHT, COLN,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
    ),

  [_FN2] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
      TILD, EXLM,  AT , HASH, DLR , PERC,                      CIRC, AMPR, ASTR, LPRN, RPRN,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          , PIPE, LCBR, RCBR, UNDS, EQL ,                      XXX , LEFT, DOWN,  UP ,RIGHT,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,  LT ,  GT , QUES,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
  ),

  [_CFG] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
      _RST, RTOG, RMOD,     , RSAI, RVAD,                          , _BOL, _SBT, _STP, _EOL, MAKE,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          , _VUP, _VDN, MUTE, RHUI, RHUD,                          , _WL , PGDN, PGUP, _WR , _TGN,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     , RSAI, RSAD,                          ,     , MRWD, MFFD, MPLY,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
  ),

  [_NUM] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
          , BTN1, MS_U, BTN2, WH_D,     ,                       7  ,  8  ,  9  , ASTR,     ,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          , MS_L, MS_D, MS_R, WH_U,     ,                       4  ,  5  ,  6  , PLUS,     , _TGN,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                       1  ,  2  ,  3  , MINS,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,  0  , DOT
                          //`-----------------'  `-----------------'
    ),

  /* template
  [_LAYER] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
    ),
  */
};
// clang-format on

void matrix_init_keymap(void) {
    setPinOutput(B0);
    setPinOutput(D5);
    writePinHigh(D5);
    writePinHigh(B0);
}
