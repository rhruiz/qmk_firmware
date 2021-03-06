#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/kc_keys.h"
#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

// clang-format off
#define LAYOUT_kc( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT_split_3x6_3( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
                                            KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )

#define KC_ZALT LALT_T(KC_Z)
#define KC_GBSP LCMD_T(KC_BSPC)

#ifndef HOME_ROW_MODS
#    undef ________L_BL_R4________
#    define ________L_BL_R4________ ZALT, X, C, V, B
#endif

#define KC_ALT0 LALT_T(KC_0)

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

  [_GAME] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
      TAB ,   ________L_BL_R2________   ,                        ________R_BL_R2________   , BSPC,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      CESC,  A  ,  S  ,  D  ,  F  ,  G  ,                       H  ,  J  ,  K  ,  L  , SCLN, ENT ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      LSFT,   ________L_BL_R4________   ,                        ________R_BL_R4________   ,TDSNU,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                              GBSP,_GFN1, ESPC,        ,     ,
                          //`-----------------'  `-----------------'
    ),

  [_GAMEFN1] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
      TAB ,   _____NUMBERS_LEFT_____    ,                        ________R_BL_R2________   , BSPC,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      ESC ,   _____NUMBERS_RGHT_____    ,                       H  ,  J  ,  K  ,  L  , SCLN, ENT ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      LSFT,   ________L_BL_R4________   ,                        ________R_BL_R4________   ,TDSNU,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
    ),


  [_KEY_OVERRIDE] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
      GRV ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     , DEL ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
      TILD,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     , DQUO,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,                          ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
    ),

  [_FN1] = LAYOUT_kc_wrapper(
  //,-----------------------------------.                    ,-----------------------------------.
          ,   ________L_LWR_2________   ,                        ________R_LWR_2________   ,     ,
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
          ,   ________L_RSE_2________   ,                        ________R_RSE_2________   ,     ,
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
      _TGM,   ________L_CFG_3________   ,                        ________R_CFG_3________   , _TGN,
  //|-----+-----------------------------|                    |-----------------------------+-----|
          ,   ________L_CFG_4________   ,                        ________R_CFG_4________   ,     ,
  //|-----+-----------------+-----+-----+-----|  |-----+-----+-----+-----------------------+-----|
                                  ,     ,     ,        ,     ,
                          //`-----------------'  `-----------------'
  ),

  [_NUM] = LAYOUT_kc(
  //,-----------------------------------.                    ,-----------------------------------.
          , BTN2,  NO , MS_U,  NO , WH_D,                      ASTR,  7  ,  8  ,  9  , MINS,     ,
  //|-----+-----+-----+-----+-----+-----|                    |-----+-----+-----+-----+-----+-----|
          , BTN1, MS_L, MS_D, MS_R, WH_U,                      SLSH,  4  ,  5  ,  6  , PLUS, _TGN,
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

void rhruiz_update_layer_colors(layer_state_t state) {
#ifdef COMBO_ENABLE
    if (layer_state_cmp(state, _GAME)) {
        combo_enable();
    } else {
        combo_disable();
    }
#endif
#ifndef OLED_DRIVER_ENABLE
    writePinHigh(D5);
    writePinHigh(B0);

    if (layer_state_cmp(state, _NUM)) {
        writePinLow(D5);
        writePinLow(B0);
    }
#endif
}

void keyboard_post_init_keymap() {
#ifdef OLED_DRIVER_ENABLE
    oled_set_brightness(0x0);
    setPinOutput(B0);
    setPinOutput(D5);
    writePinHigh(B0);
    writePinHigh(D5);
#endif
#ifdef COMBO_ENABLE
    combo_disable();
#endif
}

#ifdef OLED_DRIVER_ENABLE
bool rhruiz_process_record(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_EJCT:
            if (record->event.pressed) {
                oled_set_brightness(oled_get_brightness() + ((get_mods() & MOD_MASK_SHIFT) ? -0x08 : 0x08));
            }
            return false;
    }
    return true;
}
#endif
