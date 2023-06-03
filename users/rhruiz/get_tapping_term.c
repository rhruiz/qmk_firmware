#include "quantum.h"
#include "rhruiz.h"

#define IS_MODT(mod, kc) (kc & MT(mod & 0x0F, KC_NO) & ~QK_MOD_TAP) >> 8 > 0

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef HOME_ROW_MODS
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->event.key.row < MATRIX_ROWS - 1 && (IS_MODT(MOD_LCTL, keycode) || IS_MODT(MOD_LSFT, keycode))) {
                return TAPPING_TERM + 50;
            }

#endif
#ifdef TAP_DANCE_ENABLE
        case TD(TD_RSHIFT_NUM):
            return TAPPING_TERM + 50;
#endif
    }

    return TAPPING_TERM;
}
