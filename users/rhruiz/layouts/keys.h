#pragma once
#include "quantum/quantum_keycodes.h"

typedef enum rhruiz_layers { _QWER, _CODH, _GAME, _NUM, _FN1, _FN2, _GAMEFN1, _AUG, _CFG, _FUNC } rhruiz_layers;

typedef enum custom_keycodes {
    // macro keys
    KC_MAKE = QK_USER,
    KC_EPIP,
    KC_FARW,
    KC_ARRW,
    KC_PDIR,
    KC_TQUO,
    KC_CCCP,
    // config keys
    KC_LAYO,
    KC_LAY0,
    KC_LAY1,
    KC_NOS,
    // window switcher
    KC_CTAB,
    // os independent nav keys
    NV_START,
    NV_NWIN = NV_START, // next window
    NV_SCTP, // scroll to bottom
    NV_SCBT, // scroll to top
    NV_EOL,
    NV_BOL,
    NV_WLFT, // word left
    NV_WRGH, // word right
    NV_BCK,
    NV_FWD,
    NV_TAN, // next tab
    NV_TAP, // previous tab
    NV_MICT,  // mission control
    NV_COPY,
    NV_PSTE,
    NV_SCSH, // screenshot
    NV_WSCH, // window screenshot
    NV_WSWT, // window switcher key
    NV_END = NV_WSWT,
    USER_SAFE_RANGE
} rhruiz_keycodes;


// layers: mo

#if defined(TRI_LAYER_ENABLE)
#    define MO_LWR TL_LOWR
#    define MO_RSE TL_UPPR
#else
#    define MO_LWR MO(_FN1)
#    define MO_RSE MO(_FN2)
#endif
#define MO_NUM MO(_NUM)
#define MO_CFG MO(_CFG)
#define MO_AUG MO(_AUG)

// layers: osl
#define OSL_GLWR OSL(_GAMEFN1)
#define OSL_LWR OSL(_FN1)
#define OSL_RSE OSL(_FN2)
#define OSL_AUG OSL(_AUG)
#define OSL_FUN OSL(_FUNC)

// layers: default
#define DF_BL DF(_QWER)

// layers + mods
#define LM_GLWR LM(_GAMEFN1, MOD_LSFT)

// layer tap
#define LT_LWR_SPC LT(_FN1, KC_SPC)
#define LT_RSE_ENT LT(_FN2, KC_ENTER)
#define LT_RSE_0 LT(_FN2, KC_0)

// layer toggle
#define TG_NUM TG(_NUM)
#define TG_GAME TG(_GAME)
#define TG_CFG TG(_CFG)
#define TG_LWR TG(_FN1)
#define TG_RSE TG(_FN2)
#define TG_AUG TG(_AUG)

// layer TO
#define TO_BL TO(_CODH)
#define TO_NUM TO(_NUM)
#define TO_GAME TO(_GAME)
#define TO_CFG TO(_CFG)
#define TO_LWR TO(_FN1)
#define TO_RSE TO(_FN2)
#define TO_AUG TO(_AUG)

// mod taps
#define ST_SPC LSFT_T(KC_SPACE)
#define ST_ENT LSFT_T(KC_ENTER)
#define CT_SPC LCTL_T(KC_SPACE)
#define CT_ESC LCTL_T(KC_ESC)
#define AT_BS RALT_T(KC_BSPC)
#define AT_DEL LALT_T(KC_DEL)
#define AT_DOT LALT_T(KC_DOT)
#define AT_TAB LALT_T(KC_TAB)
#define GT_BS LGUI_T(KC_BSPC)

// mod + key
#define S_TAB LSFT(KC_TAB)
#define S_LCTL LSFT(KC_LCTL)
#define A_SPACE LALT(KC_SPACE)
