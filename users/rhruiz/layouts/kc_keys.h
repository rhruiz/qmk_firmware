#include "quantum.h"

#define CTL_SPC LCTL_T(KC_SPACE)
#define ALT_BS RALT_T(KC_BSPC)
#define ALT_DEL LALT_T(KC_DEL)

#define MO_LWR MO(_FN1)
#define MO_RSE MO(_FN2)
#define MO_NUM MO(_NUM)
#define MO_CFG MO(_CFG)
#define OSL_GLWR OSL(_GAMEFN1)
#define TG_NUM TG(_NUM)
#define TG_GAME TG(_GAME)
#define SFT_SPC LSFT_T(KC_SPACE)
#define SFT_ENT LSFT_T(KC_ENTER)
#define STAB LSFT(KC_TAB)

#define NXT_WIN LCMD(KC_GRV)
#define KC__STP LCMD(KC_UP)
#define KC__SBT LCMD(KC_DOWN)
#define KC__EOL LCMD(KC_RIGHT)
#define KC__BOL LCMD(KC_LEFT)
#define KC__WL LALT(KC_LEFT)
#define KC__WR LALT(KC_RIGHT)
#define KC__BCK LCMD(KC_LBRC)
#define KC__FWD LCMD(KC_RBRC)
#define KC__TAN LCMD(KC_RCBR)
#define KC__TAP LCMD(KC_LCBR)
#define KC__NXW LCMD(KC_TAB)


#define KC_XXX KC_NO
#define KC__DLO DF(_BL)
#define KC__ALO DF(_ALT_BL)
#define KC_OFN2 OSL(_FN2)
#define KC_AFN1 MO(_ALT_FN1)
#define KC_AFN2 MO(_ALT_FN2)

#define KC_TGAN TG(_ALT_NUM)
#define KC_SFN1 SPCFN1
#define KC_BFN2 BKSFN2
#define KC_EFN2 LT(_FN2, KC_ENTER)
#define KC_TFN2 LT(_FN2, KC_TAB)

#define KC__VUP KC__VOLUP
#define KC__VDN KC__VOLDOWN

#ifdef AUDIO_ENABLE
#    define KC__CUP CLICKY_UP
#    define KC__CDN CLICKY_DOWN
#    define KC__CTG CLICKY_TOGGLE
#    define KC_MUTG MU_TOG
#else
#    define KC__CUP KC_TRNS
#    define KC__CDN KC_TRNS
#    define KC__CTG KC_TRNS
#    define KC_MUTG KC_TRNS
#endif
