#include "print.h"
#include "quantum.h"
#include "rhruiz.h"

/* space saving overrides */
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _NUM),
};

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(process_record_keymap(keycode, record)
        && process_record_nav(keycode, record)
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
                next_default_layer();
            }
            return false;

    }

    return true;
}

#ifdef OS_DETECTION_ENABLE
uint32_t os_detection(uint32_t trigger_time, void *cb_arg) {
    os_variant_t host_os = detected_host_os();

    if (host_os) {
#   ifdef SPLIT_KEYBOARD
        set_needs_runtime_state_sync(true);

#   endif
        switch (host_os) {
            case OS_MACOS:
            case OS_IOS:
                set_nav_keys_index(0);
                break;

            default:
                set_nav_keys_index(1);
                break;
        }

        return 0;
    }

    return 500;
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
    set_caps_word_enabled(active);
    set_needs_runtime_state_sync(true);
#   endif

    caps_word_set_keymap(active);
}
#endif

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

    state = default_layer_state_set_user_nav(state);
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
    sync_master_state_task();
#endif
#ifdef BLINK_LED_PIN
    blink_led_task();
#endif
    housekeeping_task_keymap();
}
