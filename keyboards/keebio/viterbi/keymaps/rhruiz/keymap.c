#include QMK_KEYBOARD_H
#include "rhruiz.h"

// clang-format off

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},

    {{6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}}
};
#endif

// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (state & (1 << _NUM)) {
        writePinLow(D5);
#ifndef CONVERT_TO_PROTON_C
        writePinLow(B0);
#endif
    } else {
        writePinHigh(D5);
#ifndef CONVERT_TO_PROTON_C
        writePinHigh(B0);
#endif
    }

    return state;
}

#include "layouts/ortho_5x14.c"
