#pragma once
#include "quantum.h"

// layers: mo
#define MO_LWR MO(_FN1)
#define MO_RSE MO(_FN2)
#define MO_NUM MO(_NUM)
#define MO_CFG MO(_CFG)

// layers: osl
#define OSL_GLWR OSL(_GAMEFN1)
#define OSL_RSE OSL(_FN2)
#define OSL_FUN OSL(_FUNC)

// layers: default
#define DF_BL DF(_BL)

// layers + mods
#define LM_GLWR LM(_GAMEFN1, MOD_LSFT)

// layer tap
#define LT_LWR_SPC LT(_FN1, KC_SPC)
#define LT_RSE_ENT LT(_FN2, KC_ENTER)
#define LT_RSE_0 LT(_FN2, KC_0)

// layer toggle
#define TG_NUM TG(_NUM)
#define TG_GAME TG(_GAME)

// mod taps
#define ST_SPC LSFT_T(KC_SPACE)
#define ST_ENT LSFT_T(KC_ENTER)
#define CT_SPC LCTL_T(KC_SPACE)
#define CT_ESC LCTL_T(KC_ESC)
#define AT_BS RALT_T(KC_BSPC)
#define AT_0 RALT_T(KC_0)
#define AT_DEL LALT_T(KC_DEL)
#define GT_BS LGUI_T(KC_BSPC)

// mod + key
#define S_TAB LSFT(KC_TAB)
#define S_LCTL LSFT(KC_LCTL)

// mac media
#define KC__VUP KC__VOLUP
#define KC__VDN KC__VOLDOWN

