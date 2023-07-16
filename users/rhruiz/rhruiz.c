#include "print.h"
#include "quantum.h"
#include "rhruiz.h"

rhruiz_runtime_state runtime_state;

/* space saving overrides */
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

void reset_runtime_state() {
    runtime_state = (rhruiz_runtime_state) {
        .nav_keys_index = 0,
#ifdef OS_DETECTION_ENABLE
        .host_os = OS_UNSURE,
#endif
        .is_window_switcher_active = false,
        .base_layer = 0,
#ifdef SPLIT_KEYBOARD
        .needs_runtime_state_sync = false,
#   ifdef CAPS_WORD_ENABLE
        .caps_word_enabled = false,
#   endif
#endif
    };
}

#ifdef SPLIT_KEYBOARD
typedef struct _master_to_slave_t {
    uint8_t nav_keys_index;
#   ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#   endif
} master_to_slave_t;
#endif

#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _NUM),
};

#endif

const rhruiz_layers _base_layers[] PROGMEM = { BASE_LAYERS };

void default_layer_by_index(uint8_t index) {
    rhruiz_layers layer = pgm_read_byte(_base_layers + index);
    layer_state_t mask = (layer_state_t)~(1 << (MAX_LAYER - 1));
#ifdef BLINK_LED_PIN
    blink_led(200/(index+1), index + 1);
#endif

    default_layer_set(1 << (layer & mask));
}

void next_default_layer(rhruiz_runtime_state *state) {
    uint8_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);
    default_layer_by_index((state->base_layer + 1) % count);
}

#ifdef SPLIT_KEYBOARD
void sync_runtime_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *mstate = (const master_to_slave_t*)in_data;

    runtime_state.nav_keys_index = mstate->nav_keys_index;
#   ifdef CAPS_WORD_ENABLE
    runtime_state.caps_word_enabled = mstate->caps_word_enabled;
#   endif
}

#    ifdef BLINK_LED_PIN
void blink_led_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const uint8_t *blink_data = (const uint8_t*)in_data;

    blink_led(blink_data[0], blink_data[1]);
}
#    endif
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(process_record_keymap(keycode, record)
        && process_record_nav(keycode, record, &runtime_state)
        && process_record_macros(keycode, record))) {
        return false;
    }

    switch (keycode) {
        case KC_LAY0:
            if (record->event.pressed) {
                default_layer_by_index(0);
            }
            return false;

        case KC_LAY1:
            if (record->event.pressed) {
                default_layer_by_index(1);
            }
            return false;

        case KC_LAYO:
            if (record->event.pressed) {
                next_default_layer(&runtime_state);
            }
            return false;

    }

    return true;
}

#ifdef OS_DETECTION_ENABLE
uint32_t os_detection(uint32_t trigger_time, void *cb_arg) {
    runtime_state.host_os = detected_host_os();

    if (runtime_state.host_os) {
        runtime_state.needs_runtime_state_sync = true;

        switch (runtime_state.host_os) {
            case OS_MACOS:
            case OS_IOS:
                runtime_state.nav_keys_index = 0;
                break;

            default:
                runtime_state.nav_keys_index = 1;
                break;
        }
    }

    return runtime_state.host_os ? 0 : 500;
}
#endif

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
#   ifdef BLINK_LED_PIN
    transaction_register_rpc(USER_SYNC_BLINK_LED, blink_led_handler);
#   endif
#endif

#ifdef OS_DETECTION_ENABLE
    if (is_keyboard_master()) {
        defer_exec(100, os_detection, NULL);
    }
#endif

#if defined(TRI_LAYER_ENABLE)
    set_tri_layer_layers(_FN1, _FN2, _AUG);
#endif

    keyboard_post_init_keymap();
}

void matrix_init_user(void) {
    matrix_init_keymap();
}

void matrix_scan_user(void) {
    matrix_scan_keymap();
}

#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
#   ifdef SPLIT_KEYBOARD
    runtime_state.caps_word_enabled = active;
    runtime_state.needs_runtime_state_sync = true;
#   endif

    caps_word_set_keymap(active);
}
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);

    uint8_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);
    uint8_t highest_layer = get_highest_layer(state);

    for (uint8_t i = 0; i < count; i++) {
        if (highest_layer == pgm_read_byte(_base_layers + i)) {
            runtime_state.base_layer = i;
            break;
        }
    }

#ifdef SPLIT_KEYBOARD
    runtime_state.needs_runtime_state_sync = true;
#endif

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_is(_GAME)) {
#if defined(TRI_LAYER_ENABLE)
        set_tri_layer_lower_layer(_GAMEFN1);
#else
        state = update_tri_layer_state(state, _GAMEFN1, _FN2, _AUG);
#endif
    } else {
#if defined(TRI_LAYER_ENABLE)
        set_tri_layer_lower_layer(_FN1);
#else
        state = update_tri_layer_state(state, _FN1, _FN2, _AUG);
#endif
    }

    state = default_layer_state_set_user_nav(state, &runtime_state);
    state = layer_state_set_keymap(state);

    return state;
}

void suspend_power_down_user(void) {
#if defined(OLED_ENABLE)
    oled_off();
#endif
    suspend_power_down_keymap();
}

void suspend_wakeup_init_user(void) {
#if defined(OLED_ENABLE)
    oled_on();
#endif
    suspend_wakeup_init_keymap();
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
