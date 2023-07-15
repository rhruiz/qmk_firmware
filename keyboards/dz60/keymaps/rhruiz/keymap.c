#include QMK_KEYBOARD_H

#include "rhruiz.h"
#define KC__FN1 MO(_FN1)
#define KC__FN2 MO(_FN2)
#define _DELFN1 LT(_FN1, KC_DEL)

enum rhruiz_keys { KC_KBVSN = SAFE_RANGE };

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM fn1_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 2, 255, 255}, {7, 1, 2, 255, 255});

const rgblight_segment_t PROGMEM fn2_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 200, 255, 255}, {7, 1, 200, 255, 255});

const rgblight_segment_t PROGMEM cfg_colors[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 80, 255, 255}, {7, 1, 80, 255, 255});

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(fn1_colors, fn2_colors, cfg_colors);
#endif

// clang-format off

#define KC_CSPC LCTL_T(KC_SPACE)
#define CLLEFT MT(MOD_RGUI, KC_LEFT)
#define CLDOWN MT(MOD_RCTL, KC_DOWN)
#define CLUP MT(MOD_RSFT, KC_UP)
#define CLRIGHT LT(_NUM, KC_RIGHT)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT_wrapper(
		KC_GRV ,   _______L_QWER_R1_______, _______R_QWER_R1_______,  KC_MINS,  KC_EQL,   KC_BSLS,   KC_PIPE,
		KC_TAB ,   _______L_QWER_R2_______, _______R_QWER_R2_______,  KC_LBRC,  KC_RBRC,  KC_BSPC,
		CT_ESC ,   _______L_QWER_R3_______, _______R_QWER_R3_______,  KC_QUOT,  KC_ENT,
		KC_LSFT,   KC_NO,    _______L_QWER_R4_______, _______R_QWER_R4_______,  CLUP,     MO_RSE ,
		MO_LWR ,   KC_LALT,  KC_LGUI,  CT_SPC , MO_LWR ,  LT_RSE_ENT,  AT_BS  , CLLEFT,  KC_NO,  CLDOWN,   CLRIGHT
  ),

  [_NUM] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN1] = LAYOUT_wrapper(
		KC_GRV ,    ________L_LWR_1________  ,     ________R_LWR_1________  ,  KC_F11 ,  KC_F12 ,  _______,  KC_INS ,
		KC_CAPS,    ________L_LWR_2________  ,     ________R_LWR_2________  ,  _______,  _______,  KC_DEL ,
		_______,    ________L_LWR_3________  ,     ________R_LWR_3________  ,  _______,  KC_PENT,
		_______,  _______,    ________L_LWR_4________  ,     ________R_LWR_3________  ,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _DELFN1,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN2] = LAYOUT(
		KC_GRV ,   KC_SCRL,  KC_PAUS,  NV_MICT,  _______,  RGB_VAD,   RGB_VAI,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
		KC_CAPS,   KC_PIPE,  KC_LCBR,  KC_RCBR,  KC_UNDS,  KC_PLUS,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,   KC_BSLS,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_EQL ,   _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  KC_PENT,
		_______,   _______,  KC_EPIP,  KC_LPRN,  KC_RPRN,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,   _______,  _______,  _______,  _______,  _DELFN1,   _______,  _______,  _______,  _______,  _______
  ),

  [_CFG] = LAYOUT(
		_______,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW,  RGB_M_SN,  RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  _______,  RGB_SPD,  RGB_SPI,  KC_MAKE,  KC_KBVSN,
		_______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,   RGB_SAI,   RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  QK_BOOT,
		_______,  KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_EJCT,   _______,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,  _______,
		_______,  _______,  BL_TOGG,  BL_STEP,  BL_BRTG,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______
  ),
};

// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _CFG));
#endif

    return state;
}

void keyboard_post_init_keymap(void) {
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = _rgb_layers;
#endif
}
