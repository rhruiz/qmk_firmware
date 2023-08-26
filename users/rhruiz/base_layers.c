#include "rhruiz.h"

const rhruiz_layers _base_layers[] PROGMEM = { BASE_LAYERS };

uint8_t base_layer = 0;

layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);

    uint8_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);
    uint8_t highest_layer = get_highest_layer(state);

    for (uint8_t i = 0; i < count; i++) {
        if (highest_layer == pgm_read_byte(_base_layers + i)) {
            base_layer = i;
            break;
        }
    }
#ifdef SPLIT_KEYBOARD

    set_needs_runtime_state_sync(true);
#endif

    return state;
}

void default_layer_by_index(uint8_t index) {
    rhruiz_layers layer = pgm_read_byte(_base_layers + index);
    layer_state_t mask = (layer_state_t)~(1 << (MAX_LAYER - 1));
#ifdef BLINK_LED_PIN
    blink_led(200/(index+1), index + 1);
#endif

    default_layer_set(1 << (layer & mask));
}

void next_default_layer() {
    uint8_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);
    default_layer_by_index((base_layer + 1) % count);
}
