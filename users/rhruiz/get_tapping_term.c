#include "quantum.h"
#include "rhruiz.h"

#define IS_MODT(mod, kc) (kc & MT(mod & 0x0F, KC_NO) & ~QK_MOD_TAP) >> 8 > 0

#ifdef HOME_ROW_MODS
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->event.key.row < MATRIX_ROWS - 1 && (IS_MODT(MOD_LCTL, keycode) || IS_MODT(MOD_LSFT, keycode))) {
                return TAPPING_TERM + 50;
            }
    }

    return TAPPING_TERM;
}
#endif
