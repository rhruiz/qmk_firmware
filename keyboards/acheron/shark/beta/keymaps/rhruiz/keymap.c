#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/kc_keys.h"

#define KC_ALT0 LALT_T(KC_0)
#define KC_GBSP LCMD_T(KC_BSPC)
#define KC_SCTL LSFT(KC_LCTL)
#define KC_SGFN1 LM(_GAMEFN1, MOD_LSFT)

#define LAYOUT_kc( \
  L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35  \
  ) \
  LAYOUT_ortho_4x12( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35  \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_kc_wrapper(
  //,-----------------------------------+-----------------------------------.
      TAB ,   ________L_BL_R2________   ,   ________R_BL_R2________   , BSPC,
  //|-----+-----------------------------+-----------------------------+-----|
      CESC,   ________L_BL_R3________   ,   ________R_BL_R3________   , QUOT,
  //|-----+-----------------------------+-----------------------------+-----|
      LSFT,   ________L_BL_R4________   ,   ________R_BL_R4________   ,TDSNU,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
      FNUM, ESC , TAB , LGUI, _FN1, _CSP, ENTS, _FN2, ALBS, RGUI, DEL , FNUM
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_COLEMAK] = LAYOUT_kc_wrapper(
  //,-----------------------------------+-----------------------------------.
      TAB ,   _______L_COLE_R2_______   ,   _______R_COLE_R2_______   , BSPC,
  //|-----+-----------------------------+-----------------------------+-----|
      CESC,   _______L_COLE_R3_______   ,   _______R_COLE_R3_______   , QUOT,
  //|-----+-----------------------------+-----------------------------+-----|
      LSFT,   _______L_COLE_R4_______   ,   _______R_COLE_R4_______   ,TDSNU,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
      FNUM, ESC , TAB , LGUI, _FN1, _CSP, ENTS, _FN2, ALBS, RGUI, DEL , FNUM
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_GAME] = LAYOUT_kc_wrapper(
  //,-----------------------------------+-----------------------------------.
      TAB ,   ________L_BL_R2________   ,   ________R_BL_R2________   , BSPC,
  //|-----+-----------------------------+-----------------------------+-----|
      CESC,  A  ,  S  ,  D  ,  F  ,  G  ,  H  ,  J  ,  K  ,  L  , SCLN, ENT ,
  //|-----+-----------------------------+-----------------------------+-----|
      LSFT,   ________L_BL_R4________   ,   ________R_BL_R4________   ,TDSNU,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
      FNUM, SCTL,SGFN1, GBSP,_GFN1, ESPC, ENTS, _FN2, ALBS, RGUI, DEL , FNUM
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_GAMEFN1] = LAYOUT_kc_wrapper(
  //,-----------------------------------+-----------------------------------.
      TAB ,   _____NUMBERS_LEFT_____    ,   _____NUMBERS_RGHT_____    , BSPC,
  //|-----+-----------------------------+-----------------------------+-----|
      SCTL,   _____NUMBERS_RGHT_____    ,  H  ,  J  ,  K  ,  L  , SCLN, ENT ,
  //|-----+-----------------------------+-----------------------------+-----|
      LALT,   ____FUNCTIONS_LEFT____    ,   ________R_BL_R4________   ,TDSNU,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
      FNUM,     ,     ,     ,     , LSFT, ENTS, _FN2, ALBS, RGUI, DEL , FNUM
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc(
  //,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
      GRV ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     , DEL ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
      TILD,     ,     ,     ,     ,     ,     ,     ,     ,     ,     , DQUO,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_FN1] = LAYOUT_kc_wrapper(
  //,-----+-----------------------------+-----------------------------+-----.
          ,   ________L_LWR_2________   ,   ________R_LWR_2________   ,     ,
  //|-----+-----------------------------+-----------------------------+-----|
          ,   ________L_LWR_3________   ,   ________R_LWR_3________   ,     ,
  //|-----+-----------------------------+-----------------------------+-----|
          ,   ________L_LWR_4________   ,   ________R_LWR_4________   ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     , ALDE,     ,     ,
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_FN2] = LAYOUT_kc_wrapper(
  //,-----+-----------------------------+-----------------------------+-----.
          ,   ________L_RSE_2________   ,   ________R_RSE_2________   ,     ,
  //|-----+-----------------------------+-----------------------------+-----|
          ,   ________L_RSE_3________   ,   ________R_RSE_3________   ,     ,
  //|-----+-----------------------------+-----------------------------+-----|
          ,   ________L_RSE_4________   ,   ________R_RSE_4________   ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_CFG] = LAYOUT_kc_wrapper(
  //,-----+-----------------------------+-----------------------------+-----.
      _RST,   ________L_CFG_2________   ,   ________R_CFG_2________   , MAKE,
  //|-----+-----------------------------+-----------------------------+-----|
      _TGM,   ________L_CFG_3________   ,   ________R_CFG_3________   , _TGN,
  //|-----+-----------------------------+-----------------------------+-----|
          ,   ________L_CFG_4________   ,   ________R_CFG_4________   ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  [_NUM] = LAYOUT_kc(
  //,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
          ,     ,  NO , MS_U,  NO , WH_D, ASTR,  7  ,  8  ,  9  , MINS,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     , MS_L, MS_D, MS_R, WH_U, SLSH,  4  ,  5  ,  6  , PLUS, _TGN,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     , COMM,  1  ,  2  ,  3  , DOT ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     , BTN2,     , BTN1,     ,     , ALT0,     ,     ,
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),

  /* template
  [_LAYWER] = LAYOUT_kc(
  //,-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----.
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //|-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
          ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
  //`-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
  ),
  */
};

const rhruiz_layers _base_layers[] PROGMEM = { _BL, _COLEMAK };
size_t _current_base_layer = 0;

#ifdef ENCODER_ENABLE
typedef enum {
    ENC_VOLUME, ENC_RGB_MOD, ENC_RGB_VAL, ENC_RGB_HUE, ENC_RGB_SAT
} RHRUIZ_ENCODER_MODE;

RHRUIZ_ENCODER_MODE _current_encoder_mode;

void _encoder_volume_up(void) {
    tap_code_delay(KC__VOLUP, 10);
}

void _encoder_volume_down(void) {
    tap_code_delay(KC__VOLDOWN, 10);
}

void (*rhruiz_encoder_handlers[][2]) (void) = {
    [ENC_VOLUME] = {&_encoder_volume_down, &_encoder_volume_up},
    [ENC_RGB_MOD] = {&rgblight_step_reverse, &rgblight_step},
    [ENC_RGB_VAL] = {&rgblight_decrease_val, &rgblight_increase_val},
    [ENC_RGB_HUE] = {&rgblight_decrease_hue, &rgblight_increase_hue},
    [ENC_RGB_SAT] = {&rgblight_decrease_sat, &rgblight_increase_sat},
};
#endif

void rhruiz_next_default_layer() {
    size_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);

    _current_base_layer = (_current_base_layer + 1) % count;
    rhruiz_layers layer = pgm_read_byte(_base_layers + _current_base_layer);
    default_layer_set(1 << layer);
#ifdef RGBLIGHT_LAYERS

    rgblight_blink_layer_repeat(_current_base_layer + 4, 200, 2);
#endif
}

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 137, 255, 255});
const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 200, 255, 255});
const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({2, 8, 80, 255, 255});
const rgblight_segment_t PROGMEM num_colors[] = RGBLIGHT_LAYER_SEGMENTS({11, 2, 0, 255, 255});
const rgblight_segment_t PROGMEM qwerty_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 21, 255, 255});
const rgblight_segment_t PROGMEM colemak_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 24, 180, 255, 255});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, cfg_colors, num_colors, qwerty_colors, colemak_colors);

void rhruiz_update_layer_colors(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(0, layer_state_cmp(state, _GAMEFN1));
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _CFG));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));

    if (biton32(state) < _FN1) {
        rhruiz_rgblight_reset();
        return;
    }
}
#endif

#ifdef ENCODER_ENABLE
bool rhruiz_process_record(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_CFG)) {
        switch(keycode) {
            case KC__VOLUP:
            case KC__VOLDOWN:
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
        }
    }

    return true;
}

bool encoder_update_user(uint8_t _index, bool clockwise) {
    int index = clockwise ? 1 : 0;
    void (*handler) (void) = *rhruiz_encoder_handlers[_current_encoder_mode][index];
    handler();

	return false;
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
