#include QMK_KEYBOARD_H
#include "rhruiz.h"

#define LAYOUT_ortho_4x12_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
#define LAYOUT_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
/*  ,--------+--------------------------------------------+--------------------------------------------+--------. */ \
      KC_TAB ,   K01  ,   K02  ,   K03  ,   K04  ,   K05  ,   K06  ,   K07  ,   K08  ,   K09  ,   K0A  , KC_BSPC,  \
/*  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------| */ \
      CT_ESC , HRL(K11,   K12  ,   K13  ,   K14  ,   K15) , HRR(K16,   K17  ,   K18  ,   K19  ,   K1A) , KC_QUOT,  \
/*  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------| */ \
      KC_LSFT,   K21  ,   K22  ,   K23  ,   K24  ,   K25  ,   K26  ,   K27  ,   K28  ,   K29  ,   K2A  , TD_SNU ,  \
/*  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------| */ \
      MO_NUM , KC_ESC , KC_TAB , KC_LGUI, MO_LWR , CT_SPC , ST_ENT , MO_RSE , KC_RALT, KC_RGUI, KC_DEL , MO_NUM    \
/*  `--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------' */ \
  )


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT_base_wrapper(
     _______L_QWER_R2_______, _______R_QWER_R2_______,
     _______L_QWER_R3_______, _______R_QWER_R3_______,
     _______L_QWER_R4_______, _______R_QWER_R4_______
  ),

  [_CODH] = LAYOUT_base_wrapper(
     _______L_CODH_R2_______, _______R_COLE_R2_______,
     _______L_CODH_R3_______, _______R_COLE_R3_______,
     _______L_CODH_R4_______, _______R_COLE_R4_______
  ),

  [_GAME] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    KC_TAB ,           _______L_QWER_R2_______          ,           _______R_QWER_R2_______          , KC_BSPC,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    CT_ESC ,           _______L_QWER_R3_______          ,           _______R_QWER_R3_______          , KC_ENT ,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT,           _______L_QWER_R4_______          ,           _______R_QWER_R4_______          , TD_SNU ,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    MO_NUM , S_LCTL , LM_GLWR,  GT_BS ,OSL_GLWR, ST_SPC , ST_ENT , MO_RSE ,  AT_BS , KC_RGUI, KC_DEL , MO_NUM
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_GAMEFN1] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    KC_TAB ,           _____NUMBERS_LEFT_____           ,           _____NUMBERS_RGHT_____           , KC_BSPC,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    S_LCTL ,           _____NUMBERS_RGHT_____           ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_ENT ,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    KC_LALT,           ____FUNCTIONS_LEFT____           ,           _______R_QWER_R4_______          , TD_SNU ,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    MO_NUM , _______, _______, _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FN1] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    KC_GRV ,           ________L_LWR_2________          ,           ________R_LWR_2________          , KC_DEL ,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    KC_TILD,           ________L_LWR_3________          ,           ________R_LWR_3________          , KC_DQUO,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_LWR_4________          ,           ________R_LWR_4________          , _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, AT_DEL , _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FN2] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    KC_GRV ,           ________L_RSE_2________          ,           ________R_RSE_2________          , KC_DEL ,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    KC_TILD,           ________L_RSE_3________          ,           ________R_RSE_3________          , KC_DQUO,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_RSE_4________          ,           ________R_RSE_4________          , _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_AUG] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    KC_GRV ,           ________L_AUG_2________          ,           ________R_AUG_2________          , KC_DEL ,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    KC_TILD,           ________L_AUG_3________          ,           ________R_AUG_3________          , KC_DQUO,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_AUG_4________          ,           ________R_AUG_4________          , _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_CFG] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    _______,           ________L_CFG_2________          ,           ________R_CFG_2________          , _______,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_CFG_3________          ,           ________R_CFG_3________          , _______,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_CFG_4________          ,           ________R_CFG_4________          , _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FUNC] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    _______,           ________L_FUN_2________          ,           ________R_FUN_2________          , _______,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_FUN_3________          ,           ________R_FUN_3________          , _______,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______,           ________L_FUN_4________          ,           ________R_FUN_4________          , _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  [_NUM] = LAYOUT_ortho_4x12_wrapper(
//,--------+--------------------------------------------+--------------------------------------------+--------.
    _______, _______,  KC_NO , KC_MS_U,  KC_NO , KC_WH_D, KC_SLSH,  KC_7  ,  KC_8  ,  KC_9  , KC_MINS, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_ASTR,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS, TG_NUM ,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, KC_COMM,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
//|--------+--------------------------------------------+--------------------------------------------+--------|
    _______, _______, _______, KC_BTN2, _______, KC_BTN1, _______,LT_RSE_0, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),

  /* templates
  [_LAYER] = LAYOUT_ortho_4x12_wrapper(
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//`--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  */
};


extern rhruiz_runtime_state runtime_state;

#ifdef ENCODER_ENABLE
typedef enum {
    ENC_VOLUME, ENC_RGB_MOD, ENC_RGB_VAL, ENC_RGB_HUE, ENC_RGB_SAT
} RHRUIZ_ENCODER_MODE;

RHRUIZ_ENCODER_MODE _current_encoder_mode;

void _encoder_volume_up(void) {
    tap_code_delay(KC_VOLU, 10);
}

void _encoder_volume_down(void) {
    tap_code_delay(KC_VOLD, 10);
}

void (*rhruiz_encoder_handlers[][2]) (void) = {
    [ENC_VOLUME] = {&_encoder_volume_down, &_encoder_volume_up},
    [ENC_RGB_MOD] = {&rgblight_step_reverse, &rgblight_step},
    [ENC_RGB_VAL] = {&rgblight_decrease_val, &rgblight_increase_val},
    [ENC_RGB_HUE] = {&rgblight_decrease_hue, &rgblight_increase_hue},
    [ENC_RGB_SAT] = {&rgblight_decrease_sat, &rgblight_increase_sat},
};
#endif

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 127, 255, 255});
const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 21, 255, 255});
const rgblight_segment_t PROGMEM aug_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 85, 255, 255});
const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 201, 255, 255});
const rgblight_segment_t PROGMEM num_colors[] = RGBLIGHT_LAYER_SEGMENTS({14, 8, 0, 255, 255});
const rgblight_segment_t PROGMEM fun_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 148, 255, 255});
const rgblight_segment_t PROGMEM caps_colors[] = RGBLIGHT_LAYER_SEGMENTS({14, 8, 201, 255, 255});

const rgblight_segment_t PROGMEM qwerty_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 43, 255, 255});
const rgblight_segment_t PROGMEM colemak_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 222, 255, 255});
const rgblight_segment_t PROGMEM colemak_dh_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 180, 255, 255});
const rgblight_segment_t PROGMEM mac_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 0, 0, 255});
const rgblight_segment_t PROGMEM win_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 148, 255, 255});


const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, aug_colors, cfg_colors, num_colors, fun_colors, caps_colors, qwerty_colors, colemak_colors, colemak_dh_colors, mac_colors, win_colors);

layer_state_t layer_state_set_keymap(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1) || layer_state_cmp(state, _GAMEFN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _AUG));
    rgblight_set_layer_state(3, layer_state_cmp(state, _CFG));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FUNC));

    if (layer_state_is(_GAME)) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_reload_from_eeprom();
    }

    return state;
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_CFG)) {
        switch(keycode) {
#ifdef RGBLIGHT_LAYERS
            case KC_LAYO:
                rgblight_blink_layer_repeat(runtime_state.base_layer + 7, 200, 2);
                break;

            case KC_NOS:
                rgblight_blink_layer_repeat(runtime_state.nav_keys_index + 10, 200, 2);
                break;
#endif

#ifdef ENCODER_ENABLE
            case KC_VOLU:
            case KC_VOLD:
            case KC_MUTE:
                _current_encoder_mode = ENC_VOLUME;
                return true;

            case RGB_MOD:
                _current_encoder_mode = ENC_RGB_MOD;
                return false;
            case RGB_VAI:
                _current_encoder_mode = ENC_RGB_VAL;
                return false;
            case RGB_HUI:
                _current_encoder_mode = ENC_RGB_HUE;
                return false;
            case RGB_SAI:
                _current_encoder_mode = ENC_RGB_SAT;
                return false;
#endif
        }
    }

    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t _index, bool clockwise) {
    int index = clockwise ? 1 : 0;
    void (*handler) (void) = *rhruiz_encoder_handlers[_current_encoder_mode][index];
    handler();

	return false;
}
#endif

#ifdef CAPS_WORD_ENABLE
void caps_word_set_keymap(bool active) {
    rgblight_set_layer_state(6, active);
}
#endif

void keyboard_post_init_keymap(void) {
#ifdef ENCODER_ENABLE
    _current_encoder_mode = ENC_VOLUME;
#endif
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = _rgb_layers;
#endif
}

void suspend_wakeup_init_keymap(void) {
    NVIC_SystemReset();
}
