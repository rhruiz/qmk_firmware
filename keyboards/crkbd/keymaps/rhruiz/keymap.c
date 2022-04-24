#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/kc_keys.h"
#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

#define KC_GBSP LCMD_T(KC_BSPC)
#define KC_ALT0 LALT_T(KC_0)
#define KC_SCTL LSFT(KC_LCTL)

// clang-format off
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25  \
  ) \
  LAYOUT_split_3x6_3_wrapper( \
/*  ,--------------------------------------.   ,--------------------------------------.*/ \
      KC_TAB ,   L01  , L02, L03, L04, L05 ,       R01  , R02, R03, R04, R05 , KC_BSPC, \
/*  |--------+--------+----+----+----+-----|   |--------+----+----+-----+----+--------|*/ \
      CTRLESC, HRL(L11, L12, L13, L14, L15),     HRR(R11, R12, R13, R14, R15), KC_QUOT, \
/*  |--------+--------+----+----+----+-----|   |--------+----+----+----+-----+--------|*/ \
      KC_LSFT,   L21  , L22, L23, L24, L25 ,       R21  , R22, R23, R24, R25 ,KC_TDSNU, \
/*  `--------+-----------------------------|   |-----------------------------+--------'*/ \
                   KC_LGUI, MO_LWR, CTL_SPC,     SFT_ENT, MO_RSE , ALT_BS               \
/*              `--------+--------+--------'   `--------+--------+--------'            */ \
  )

#define LAYOUT_kc( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT_split_3x6_3( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
                                  KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_base_wrapper(
      ________L_BL_R2________, ________R_BL_R2________,
      ________L_BL_R3________, ________R_BL_R3________,
      ________L_BL_R4________, ________R_BL_R4________
  ),

  [_COLEMAK] = LAYOUT_base_wrapper(
      _______L_COLE_R2_______, _______R_COLE_R2_______,
      _______L_COLE_R3_______, _______R_COLE_R3_______,
      _______L_COLE_R4_______, _______R_COLE_R4_______
  ),

  [_CODH] = LAYOUT_base_wrapper(
      _______L_CODH_R2_______, _______R_CODH_R2_______,
      _______L_CODH_R3_______, _______R_CODH_R3_______,
      _______L_CODH_R4_______, _______R_CODH_R4_______
  ),

  [_NORMAN] = LAYOUT_base_wrapper(
      _______L_NORM_R2_______, _______R_NORM_R2_______,
      _______L_NORM_R3_______, _______R_NORM_R3_______,
      _______L_NORM_R4_______, _______R_NORM_R4_______
  ),

  [_ISRT] = LAYOUT_base_wrapper(
      _______L_ISRT_R2_______, _______R_ISRT_R2_______,
      _______L_ISRT_R3_______, _______R_ISRT_R3_______,
      _______L_ISRT_R4_______, _______R_ISRT_R4_______
  ),

  [_GAME] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_TAB ,  ________L_BL_R2________ ,     ________R_BL_R2________ , KC_BSPC,
//|--------+--------------------------|  |--------------------------+--------|
    CTRLESC,  ________L_BL_R3________ ,     ________R_BL_R3________ , KC_ENT ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_LSFT,  ________L_BL_R4________ ,     ________R_BL_R4________ ,KC_TDSNU,
//`--------+--------------------------|  |--------------------------+--------'
             KC_GBSP,OSL_GLWR, SFT_SPC,    SFT_ENT, MO_RSE , ALT_BS
//         `--------+--------+--------'  `--------+--------+--------'
    ),

  [_GAMEFN1] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_TAB ,  _____NUMBERS_LEFT_____  ,     ________R_BL_R2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    KC_SCTL,  _____NUMBERS_RGHT_____  ,     ________R_BL_R3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    KC_LALT,  ____FUNCTIONS_LEFT____  ,     ________R_BL_R4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, KC_LSFT,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
    ),


  [_KEY_OVERRIDE] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------------------------.  ,-----------------------------------------------------.
    KC_GRV , _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_DEL ,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    KC_TILD, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_DQUO,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//`--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
                               _______, _______, _______,    _______, _______, _______
//                           `--------+--------+--------'  `--------+--------+--------'
    ),

  [_FN1] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_LWR_2________ ,     ________R_LWR_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_LWR_3________ ,     ________R_LWR_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_LWR_4________ ,     ________R_LWR_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, ALT_DEL
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  [_FN2] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_RSE_2________ ,     ________R_RSE_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_RSE_3________ ,     ________R_RSE_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_RSE_4________ ,     ________R_RSE_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
),

  [_CFG] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    QK_BOOT,  ________L_CFG_2________ ,     ________R_CFG_2________ , KC_MAKE,
//|--------+--------------------------|  |--------------------------+--------|
    TG_GAME,  ________L_CFG_3________ ,     ________R_CFG_3________ , TG_NUM ,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_CFG_4________ ,     ________R_CFG_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------------------------.  ,-----------------------------------------------------.
    _______, _______,  KC_NO , _______,  KC_NO , _______,    KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_MINS, _______,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, KC_MS_L, _______, KC_MS_R, _______,    KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS, TG_NUM ,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,    KC_COMM,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
//`--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
                               KC_BTN2, _______, KC_BTN1,    _______, _______, KC_ALT0
//                           `--------+--------+--------'  `--------+--------+--------'
    ),

  /* templates
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

  [_LAYER] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.  ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//`--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
                               _______, _______, _______,    _______, _______, _______
//                           `--------+--------+--------'  `--------+--------+--------'
  ),
  */
};
// clang-format on

const rhruiz_layers _base_layers[] PROGMEM = { _BL, _COLEMAK, _CODH, _NORMAN, _ISRT };
size_t _current_base_layer = 0;

void rhruiz_next_default_layer() {
    size_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);

    _current_base_layer = (_current_base_layer + 1) % count;
    rhruiz_layers layer = pgm_read_byte(_base_layers + _current_base_layer);
    default_layer_set(1 << layer);
}

void rhruiz_update_layer_colors(layer_state_t state) {
#ifdef COMBO_ENABLE
    if (layer_state_cmp(state, _GAME)) {
        combo_enable();
    } else {
        combo_disable();
    }
#endif
#ifndef OLED_ENABLE
    writePinHigh(D5);
    writePinHigh(B0);

    if (layer_state_cmp(state, _NUM)) {
        writePinLow(D5);
        writePinLow(B0);
    }
#endif
}

void keyboard_post_init_keymap() {
#ifdef OLED_ENABLE
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

#ifdef OLED_ENABLE
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
