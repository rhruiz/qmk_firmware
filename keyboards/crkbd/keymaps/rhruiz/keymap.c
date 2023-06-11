#include QMK_KEYBOARD_H
#include "rhruiz.h"
#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

// clang-format off
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

#ifdef LOCK_LAYERS
#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25  \
  ) \
  LAYOUT_split_3x6_3_wrapper( \
/*  ,--------------------------------------.   ,--------------------------------------.*/ \
      KC_TAB ,   L01  , L02, L03, L04, L05 ,       R01  , R02, R03, R04, R05 , KC_BSPC, \
/*  |--------+--------+----+----+----+-----|   |--------+----+----+-----+----+--------|*/ \
      CT_ESC , HRL(L11, L12, L13, L14, L15),     HRR(R11, R12, R13, R14, R15), KC_QUOT, \
/*  |--------+--------+----+----+----+-----|   |--------+----+----+----+-----+--------|*/ \
      KC_LSFT,   L21  , L22, L23, L24, L25 ,       R21  , R22, R23, R24, R25 , TD_SNU , \
/*  `--------+-----------------------------|   |-----------------------------+--------'*/ \
                  KC_LGUI, KC_LGUI, CT_SPC ,     ST_ENT , TO_LWR , KC_LALT              \
/*              `--------+--------+--------'   `--------+--------+--------'            */ \
  )
#else
#define LAYOUT_base( \
    L01, L02, L03, L04, L05, R01, R02, R03, R04, R05, \
    L11, L12, L13, L14, L15, R11, R12, R13, R14, R15, \
    L21, L22, L23, L24, L25, R21, R22, R23, R24, R25  \
  ) \
  LAYOUT_split_3x6_3_wrapper( \
/*  ,--------------------------------------.   ,--------------------------------------.*/ \
      KC_TAB ,   L01  , L02, L03, L04, L05 ,       R01  , R02, R03, R04, R05 , KC_BSPC, \
/*  |--------+--------+----+----+----+-----|   |--------+----+----+-----+----+--------|*/ \
      CT_ESC , HRL(L11, L12, L13, L14, L15),     HRR(R11, R12, R13, R14, R15), KC_QUOT, \
/*  |--------+--------+----+----+----+-----|   |--------+----+----+----+-----+--------|*/ \
      KC_LSFT,   L21  , L22, L23, L24, L25 ,       R21  , R22, R23, R24, R25 , TD_SNU , \
/*  `--------+-----------------------------|   |-----------------------------+--------'*/ \
                  KC_LGUI, MO_LWR , CT_SPC ,     ST_ENT , MO_RSE , KC_LALT              \
/*              `--------+--------+--------'   `--------+--------+--------'            */ \
  )
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_base_wrapper(
      ________L_BL_R2________, ________R_BL_R2________,
      ________L_BL_R3________, ________R_BL_R3________,
      ________L_BL_R4________, ________R_BL_R4________
  ),

  [_CODH] = LAYOUT_base_wrapper(
      _______L_CODH_R2_______, _______R_COLE_R2_______,
      _______L_CODH_R3_______, _______R_COLE_R3_______,
      _______L_CODH_R4_______, _______R_COLE_R4_______
  ),

  [_GAME] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_TAB ,  ________L_BL_R2________ ,     ________R_BL_R2________ , KC_BSPC,
//|--------+--------------------------|  |--------------------------+--------|
    CT_ESC ,  ________L_BL_R3________ ,     ________R_BL_R3________ , KC_ENT ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_LSFT,  ________L_BL_R4________ ,     ________R_BL_R4________ , TD_SNU ,
//`--------+--------------------------|  |--------------------------+--------'
              GT_BS ,OSL_GLWR, ST_SPC ,    ST_ENT , MO_RSE ,  AT_BS
//         `--------+--------+--------'  `--------+--------+--------'
    ),

  [_GAMEFN1] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------------------------.
    KC_TAB ,  _____NUMBERS_LEFT_____  ,    _______, _______,  KC_UP , _______, _______, _______,
//|--------+--------------------------|  |--------------------------------------------+--------|
    S_LCTL ,  _____NUMBERS_RGHT_____  ,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
//|--------+--------------------------|  |--------------------------------------------+--------|
    KC_LALT,  ____FUNCTIONS_LEFT____  ,    _______, _______,  KC_LT ,  KC_GT , KC_QUES, _______,
//`--------+--------------------------|  |--------------------------------------------+--------'
             _______, _______, KC_LSFT,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
    ),

  [_FN1] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_GRV ,  ________L_LWR_2________ ,     ________R_LWR_2________ , KC_DEL ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_TILD,  ________L_LWR_3________ ,     ________R_LWR_3________ , KC_DQUO,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_LWR_4________ ,     ________R_LWR_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
#ifdef LOCK_LAYERS
             _______,  TO_BL , _______,    _______, TO_AUG , _______
#else
             _______, _______, _______,    _______, _______, _______
#endif
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  [_FN2] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    KC_GRV ,  ________L_RSE_2________ ,     ________R_RSE_2________ , KC_DEL ,
//|--------+--------------------------|  |--------------------------+--------|
    KC_TILD,  ________L_RSE_3________ ,     ________R_RSE_3________ , KC_DQUO,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_RSE_4________ ,     ________R_RSE_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
#ifdef LOCK_LAYERS
             _______,  TO_BL , _______,    _______, TO_LWR , _______
#else
             _______, _______, _______,    _______, _______, _______
#endif
//         `--------+--------+--------'  `--------+--------+--------'
),

  [_AUG] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_AUG_2________ ,     ________R_AUG_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_AUG_3________ ,     ________R_AUG_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_AUG_4________ ,     ________R_AUG_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
#ifdef LOCK_LAYERS
             _______,  TO_BL , _______,    _______, TO_LWR , _______
#else
             _______, _______, _______,    _______, _______, _______
#endif
//         `--------+--------+--------'  `--------+--------+--------'
),

  [_CFG] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_CFG_2________ ,     ________R_CFG_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_CFG_3________ ,     ________R_CFG_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_CFG_4________ ,     ________R_CFG_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_NUM_2________ ,     ________R_NUM_1________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_NUM_3________ ,     ________R_NUM_2________ , TG_NUM ,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_NUM_4________ ,     ________R_NUM_3________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             KC_BTN2, _______, KC_BTN1,    _______,LT_RSE_0, AT_TAB
//         `--------+--------+--------'  `--------+--------+--------'
    ),

  [_FUNC] = LAYOUT_split_3x6_3_wrapper(
//,-----------------------------------.  ,-----------------------------------.
    _______,  ________L_FUN_2________ ,     ________R_FUN_2________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_FUN_3________ ,     ________R_FUN_3________ , _______,
//|--------+--------------------------|  |--------------------------+--------|
    _______,  ________L_FUN_4________ ,     ________R_FUN_4________ , _______,
//`--------+--------------------------|  |--------------------------+--------'
             _______, _______, _______,    _______, _______, _______
//         `--------+--------+--------'  `--------+--------+--------'
  ),

  /* templates
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

layer_state_t layer_state_set_keymap(layer_state_t state) {
#ifdef COMBO_ENABLE
    if (layer_state_cmp(state, _GAME)) {
        combo_enable();
    } else {
        combo_disable();
    }
#endif
    writePin(D5, !layer_state_cmp(state, _NUM));

    return state;
}

void housekeeping_task_keymap(void) {
    if (!is_keyboard_master()) {
        writePin(D5, !layer_state_cmp(layer_state, _NUM));
    }
}

void keyboard_post_init_keymap() {
#if defined(CONVERT_TO_PROMICRO_RP2040) && defined(RGBLIGHT_ENABLE)
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
#endif
#ifdef COMBO_ENABLE
    combo_disable();
#endif
}
