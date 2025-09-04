#include "quantum.h"

#if defined(RGBLIGHT_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
// Do a little 2.5 seconds display of the different colors
// Use the deferred executor so the LED flash dance does not
// stop us from using the keyboard.
// https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-executor-registration
uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(250 - (timer_read() / 10), 230, 70);

    if (timer_read() >= 2500) {
        // Finished, reset to user chosen led color
        rgblight_reload_from_eeprom();
        return 0;
    } else {
        return 50;
    }
}
#endif

void keyboard_post_init_kb(void) {
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

#if defined(RGBLIGHT_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
    // Flash a little on start
    defer_exec(50, flash_led, NULL);
#endif

    keyboard_post_init_user();
}

// Make the builtin RGB led show different colors per layer:
// This seemed like a good idea but turned out pretty annoying,
// to me at least... Uncomment the lines below to enable
/*
uint8_t get_hue(uint8_t layer) {
    switch (layer) {
        case 6:
            return 169;
        case 5:
            return 43;
        case 4:
            return 85;
        case 3:
            return 120;
        case 2:
            return 180;
        case 1:
            return 220;
        default:
            return 0;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();
    uint8_t hue = get_hue(get_highest_layer(state));
    rgblight_sethsv(hue, sat, val);
    return state;
}
*/
