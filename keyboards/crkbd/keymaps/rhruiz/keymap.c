#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/kc_keys.h"

#define KC_ZALT LALT_T(KC_Z)

#undef ________L_BL_R4________
#define ________L_BL_R4________ ZALT, X, C, V, B

#define KC_ALDE LALT_T(KC_DEL)
#define KC_ALT0 LALT_T(KC_0)

#ifdef TAP_DANCE_ENABLE
// tap dances
enum {
    TD_RSHIFT_NUM,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _NUM),
};

#    define KC_TDSNU TD(TD_RSHIFT_NUM)
#else
#    define KC_TDSNU KC_RSFT
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
      TAB ,   ________L_BL_R2________   ,                        ________R_BL_R2________   , BSPC,
  //|-----+-----------------------------|                    |-----------------------------+-----|
      CESC,   ________L_BL_R3________   ,                        ________R_BL_R3________   , QUOT,
  //|-----+-----------------------------|                    |-----------------------------+-----|
      LSFT,   ________L_BL_R4________   ,                        ________R_BL_R4________   ,TDSNU,
  //|-----+-----------------+-----+-----+-----|  |-----+-----+-----+-----------------------+-----|
                              LGUI, _FN1, _CSP,    ENTS, _FN2, ALBS
                          //`-----------------'  `-----------------'
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     , DEL ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     , DQUO,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
    ),

  [_FN1] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
      TILD,   ________L_LWR_2________   ,                        ________R_LWR_2________   ,     ,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_LWR_3________   ,                        ________R_LWR_3________   ,     ,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_LWR_4________   ,                        ________R_LWR_4________   ,     ,
  //|-----+-----------------+-----+-----+-----|  |-----+-----+-----+-----------------------+-----|
                                  ,     ,     ,        ,     , ALDE
                          //`-----------------'  `-----------------'
    ),

  [_FN2] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
      GRV ,   ________L_RSE_2________   ,                        ________R_RSE_2________   ,     ,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_RSE_3________   ,                        ________R_RSE_3________   ,     ,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_RSE_4________   ,                        ________R_RSE_4________   ,     ,
  //|-----+-----------------+-----+-----+-----|  |-----+-----+-----+-----------------------+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
  ),

  [_CFG] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
      _RST,   ________L_CFG_2________   ,                        ________R_CFG_2________   , MAKE,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_CFG_3________   ,                        ________R_CFG_3________   , _TGN,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_CFG_4________   ,                        ________R_CFG_4________   ,     ,
  //|-----+-----------------+-----+-----+-----|  |-----+-----+-----+-----------------------+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
  ),

  [_NUM] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
          ,     , BTN1, MS_U, BTN2, WH_D,                      ASTR,  7  ,  8  ,  9  , MINS,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     , MS_L, MS_D, MS_R, WH_U,                      SLSH,  4  ,  5  ,  6  , PLUS, _TGN,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                      COMM,  1  ,  2  ,  3  , DOT ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     , ALT0
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
#ifdef OLED_DRIVER_ENABLE

void rhruiz_update_layer_colors(layer_state_t state) {
    writePinHigh(D5);
    writePinHigh(B0);

    if (layer_state_cmp(state, _NUM)) {
        writePinLow(D5);
        writePinLow(B0);
    }
}
#endif
