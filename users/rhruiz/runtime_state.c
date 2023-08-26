#include "rhruiz.h"

typedef struct _rhruiz_runtime_state {
    uint8_t nav_keys_index;
#ifdef SPLIT_KEYBOARD
    bool needs_runtime_state_sync;
#   ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#   endif
#endif
} rhruiz_runtime_state_t;

rhruiz_runtime_state_t runtime_state;


void reset_runtime_state(void) {
    runtime_state = (rhruiz_runtime_state_t) {
        .nav_keys_index = 0,
#ifdef SPLIT_KEYBOARD
        .needs_runtime_state_sync = false,
#   ifdef CAPS_WORD_ENABLE
        .caps_word_enabled = false,
#   endif
#endif
    };
}

bool needs_runtime_state_sync(void) {
    return runtime_state.needs_runtime_state_sync;
}

void set_needs_runtime_state_sync(bool value) {
    runtime_state.needs_runtime_state_sync = value;
}

void set_nav_keys_index(uint8_t value) {
    runtime_state.nav_keys_index = value;
}

uint8_t nav_keys_index(void) {
    return runtime_state.nav_keys_index;
}

#ifdef CAPS_WORD_ENABLE
void set_caps_word_enabled(bool enabled) {
    runtime_state.caps_word_enabled = enabled;
}

bool caps_word_enabled(void) {
    return runtime_state.caps_word_enabled;
}
#endif
