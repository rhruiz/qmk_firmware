#include "quantum.h"

#define KC_ KC_TRNS
#define KC_XXX KC_NO

#define KC_CESC CTRLESC
#define KC__CSP LCTL_T(KC_SPACE)

#define KC__DLO DF(_BL)
#define KC__ALO DF(_ALT_BL)

#define KC_OFN1 OSL(_FN1)
#define KC_OFN2 OSL(_FN2)
#define KC__FN1 MO(_FN1)
#define KC__FN2 MO(_FN2)
#define KC_AFN1 MO(_ALT_FN1)
#define KC_AFN2 MO(_ALT_FN2)
#define KC__CFG MO(_CFG)
#define KC_FNUM MO(_NUM)
#define KC__TGN TG(_NUM)
#define KC_TGAN TG(_ALT_NUM)
#define KC__TGM TG(_GAME)
#define KC_SFN1 SPCFN1
#define KC_BFN2 BKSFN2
#define KC_EFN2 LT(_FN2, KC_ENTER)
#define KC_TFN2 LT(_FN2, KC_TAB)
#define KC_ALBS RALT_T(KC_BSPC)
#define KC_ALDE LALT_T(KC_DEL)
#define KC__GFN1 OSL(_GAMEFN1)
#define KC_ESPC LSFT_T(KC_SPACE)
#define KC_STAB LSFT(KC_TAB)

#define KC__RST QK_BOOT
#define KC_MISS MISCTRL
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

#define KC_ENTS LSFT_T(KC_ENTER)

#define KC__WN LCMD(KC_GRV)
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
#    define KC_RVAD KC_NO
#    define KC_RVAI KC_NO
#    define KC_RTOG KC_NO
#    define KC_RMOD KC_NO
#    define KC_RHUI KC_NO
#    define KC_RHUD KC_NO
#    define KC_RSAI KC_NO
#    define KC_RSAD KC_NO
#endif
