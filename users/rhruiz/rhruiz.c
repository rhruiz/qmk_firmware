#include "print.h"
#include "quantum.h"
#include "rhruiz.h"

rhruiz_runtime_state runtime_state;

void reset_runtime_state() {
    runtime_state = (rhruiz_runtime_state) {
        .nav_keys_index = 0,
        .is_window_switcher_active = false,
        .base_layer = 0,
#ifdef SPLIT_KEYBOARD
        .needs_runtime_state_sync = false,
#   ifdef CAPS_WORD_ENABLE
        .caps_word_enabled = false,
#   endif
#endif
#ifdef OLED_ENABLE
        .oled_timer = timer_read(),
#endif
    };
}

#ifdef SPLIT_KEYBOARD
typedef struct _master_to_slave_t {
    size_t nav_keys_index;
#   ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#   endif
} master_to_slave_t;
#endif

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _NUM),
};

#endif

const rhruiz_layers _base_layers[] PROGMEM = { BASE_LAYERS };

void next_default_layer(rhruiz_runtime_state *state) {
    uint8_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);
    layer_state_t mask = (layer_state_t)~(1 << (MAX_LAYER - 1));

    state->base_layer = (state->base_layer + 1) % count;

    rhruiz_layers layer = pgm_read_byte(_base_layers + state->base_layer);
    default_layer_set(1 << (layer & mask));
}

#ifdef SPLIT_KEYBOARD
void sync_runtime_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *mstate = (const master_to_slave_t*)in_data;
    runtime_state.nav_keys_index = mstate->nav_keys_index;
#   ifdef CAPS_WORD_ENABLE
    runtime_state.caps_word_enabled = mstate->caps_word_enabled;
#   endif
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    rhruiz_oled_activity();

#endif
    if (!(process_record_keymap(keycode, record)
        && process_record_nav(keycode, record, &runtime_state)
        && process_record_macros(keycode, record))) {
        return false;
    }

    switch (keycode) {
        case KC_LAYO:
            if (record->event.pressed) {
                next_default_layer(&runtime_state);
            }
            return false;

    }

    return true;
}

void keyboard_post_init_user() {
    reset_runtime_state();
#if defined(BOOTLOADER_CATERINA) || defined(PRO_MICRO)
    setPinOutput(B0);
    writePinHigh(B0);

    setPinOutput(D5);
    writePinHigh(D5);
#endif
#ifdef SPLIT_KEYBOARD
    transaction_register_rpc(USER_SYNC_RUNTIME_STATE, sync_runtime_state_handler);
#endif
    keyboard_post_init_keymap();
}

void matrix_init_user(void) {
    matrix_init_keymap();
}

void matrix_scan_user(void) {
    matrix_scan_keymap();
}

#if defined(SPLIT_KEYBOARD) && defined(CAPS_WORD_ENABLE)
void caps_word_set_user(bool active) {
    runtime_state.caps_word_enabled = active;
    runtime_state.needs_runtime_state_sync = true;
}
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
    runtime_state.base_layer = get_highest_layer(state);
#ifdef SPLIT_KEYBOARD
    runtime_state.needs_runtime_state_sync = true;
#endif

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_is(_GAME)) {
        state = update_tri_layer_state(state, _GAMEFN1, _FN2, _CFG);
    } else {
        state = update_tri_layer_state(state, _FN1, _FN2, _CFG);
    }

    state = layer_state_set_keymap(state);

    return state;
}

void housekeeping_task_user(void) {
#ifdef SPLIT_KEYBOARD
    if (runtime_state.needs_runtime_state_sync) {
        master_to_slave_t m2s = {
            runtime_state.nav_keys_index,
#    ifdef CAPS_WORD_ENABLE
            runtime_state.caps_word_enabled
#    endif
        };

        if (transaction_rpc_send(USER_SYNC_RUNTIME_STATE, sizeof(m2s), &m2s)) {
            runtime_state.needs_runtime_state_sync = false;
        } else {
            dprintf("sync tx failed");
        }
    }
#endif

#ifdef BLINK_LED_PIN
    blink_led_task();
#endif

    housekeeping_task_keymap();
}
