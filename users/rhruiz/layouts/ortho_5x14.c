#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rhruiz.h"

#define KC__RST RESET
#define KC__FN1 MO(_FN1)
#define KC__FN2 MO(_FN2)
#define KC_SFN1 LT(_FN1, KC_SPC)
#define KC_RFN1 LT(_FN1, KC_RGHT)
#define KC_BFN2 BKSFN2
#define KC_CESC CTRLESC
#define KC_MISS MISCTRL
#define KC__VUP KC__VOLUP
#define KC__VDN KC__VOLDOWN
#define KC_ KC_TRNS
#define KC__TGN TG(_NUM)
#define KC__TGM TG(_GAME)
#define KC__TAN LCMD(KC_RCBR)
#define KC__TAP LCMD(KC_LCBR)

#ifdef RGBLIGHT_ENABLE
#    define KC_RVAD RGB_VAD
#    define KC_RVAI RGB_VAI
#    define KC_RTOG RGB_TOG
#    define KC_RMOD RGB_MOD
#    define KC_RHUI RGB_HUI
#    define KC_RHUD RGB_HUD
#    define KC_RSAI RGB_SAI
#    define KC_RSAD RGB_SAD
#else
#    define KC_RVAD KC_TRNS
#    define KC_RVAI KC_TRNS
#    define KC_RTOG KC_TRNS
#    define KC_RMOD KC_TRNS
#    define KC_RHUI KC_TRNS
#    define KC_RHUD KC_TRNS
#    define KC_RSAI KC_TRNS
#    define KC_RSAD KC_TRNS
#endif

// clang-format off
#ifndef LAYOUT_ortho_5x14_kc
#ifndef LAYOUT_ortho_5x14
#error keyboard must define LAYOUT_ortho_5x14
#endif

#define LAYOUT_ortho_5x14_kc( \
    L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46 \
    ) \
    LAYOUT_ortho_5x14( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##L06, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, KC_##R06, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L16, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, KC_##R16, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L26, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, KC_##R26, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L36, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, KC_##R36, \
        KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, KC_##L46, KC_##R40, KC_##R41, KC_##R42, KC_##R43, KC_##R44, KC_##R45, KC_##R46 \
    )
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
    GRV , 1   , 2   , 3   , 4   , 5   , MINS,    _TGN, 6   , 7   , 8   , 9   , 0   , EQL ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
    TAB , Q   , W   , E   , R   , T   , LBRC,    _TAN, Y   , U   , I   , O   , P   , QUOT,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
    CESC, A   , S   , D   , F   , G   , ENT ,    ENT , H   , J   , K   , L   , SCLN, ENT ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
    LSFT, Z   , X   , C   , V   , B   , PGDN,    EPIP, N   , M   , COMM, DOT , SLSH, RSFT,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
    _FN2, _FN1, LCTL, LALT, LGUI, SFN1, SFN1,    BFN2, BFN2, RGUI, LEFT, DOWN, UP  , RFN1
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_VIM_EMACS] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        , LEFT, DOWN, UP  , RGHT,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_GAME] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
        ,     ,     ,     ,     ,     , 6   ,    _TGM,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     , 7   ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     , BSPC,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_MOUSE] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_KEY_OVERRIDE] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
    TILD,     ,     ,     ,     ,     , UNDS,        ,     ,     ,     ,     ,     , PLUS,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     , RBRC,    _TAP,     , LPRN, RPRN,     ,     , DQUO,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     , PENT,    PENT,     ,     ,     ,     , COLN, DEL ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     , LT  , GT  , QUES,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     , MRWD, MPLY, MFFD,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_FN1] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
        , F1  , F2  , F3  , F4  , F5  , F11 ,    _TGM, F6  , F7  , F8  , F9  , F10 , F12 ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     , LCBR, RCBR, UNDS, EQL ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        , BSLS, LBRC, RBRC, MINS, PLUS,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_FN2] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
        , EXLM, AT  , HASH, DLR , PERC,     ,        , CIRC, AMPR, ASTR, LPRN, RPRN,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     , LBRC, RBRC, MINS, PLUS,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        , PIPE, LCBR, RCBR, UNDS, EQL ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_CFG] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
    ESC , SLCK, PAUS, MISS, RVAD, RVAI,     ,    MAKE,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
    _RST, RTOG, RMOD, RHUI, RHUD, RSAI, RSAD,        ,     ,     ,     ,     ,     , _RST,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        , _VUP, _VDN, MUTE, EJCT,     ,     ,        , HOME, PGDN, PGUP, END ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  ),

  [_NUM] = LAYOUT_ortho_5x14_kc(
 //,----+-----+-----+-----+-----+-----+-----.  ,-----+-----+-----+-----+-----+-----+-----.
        , 1   , 2   , 3   , 4   , 5   ,     ,        , 6   , 7   , 8   , 9   , 0   ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        , BTN1, MS_U, BTN2, WH_D,     ,     ,        ,     , 4   , 5   , 6   , PLUS,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        , MS_L, MS_D, MS_R, WH_U,     , WH_D,        , ASTR, 1   , 2   , 3   , MINS,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     , WH_U,        , EQL , 0   ,     ,     ,     ,     ,
 //|----+-----+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----+-----+
        ,     ,     ,     ,     ,     ,     ,        ,     ,     ,     ,     ,     ,
 //`----+-----+-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----+-----+-----'
  )
};

// clang-format on
