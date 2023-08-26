#include "quantum.h"
#include "rhruiz.h"

uint16_t copy_paste_timer;
bool is_window_switcher_active;

const uint16_t nav_keys[][NUM_NAV_KEYS_OSES] PROGMEM = {
    [NV_NWIN - NV_START] = {LCMD(KC_GRV), LALT(KC_TAB)},
    [NV_SCTP - NV_START] = {LCMD(KC_UP), LGUI(KC_HOME)},
    [NV_SCBT - NV_START] = {LCMD(KC_DOWN), LGUI(KC_END)},
    [NV_EOL  - NV_START] = {LCMD(KC_RIGHT), KC_END},
    [NV_BOL  - NV_START] = {LCMD(KC_LEFT), KC_HOME},
    [NV_WLFT - NV_START] = {LOPT(KC_LEFT), LCTL(KC_LEFT)},
    [NV_WRGH - NV_START] = {LOPT(KC_RIGHT), LCTL(KC_RGHT)},
    [NV_BCK  - NV_START] = {LCMD(KC_LBRC), LALT(KC_LEFT)},
    [NV_FWD  - NV_START] = {LCMD(KC_RBRC), LALT(KC_RGHT)},
    [NV_TAN  - NV_START] = {LCMD(KC_RCBR), LCTL(KC_TAB)},
    [NV_TAP  - NV_START] = {LCMD(KC_LCBR), LCTL(LSFT(KC_TAB))},
    [NV_MICT - NV_START] = {LCTL(KC_UP), LGUI(KC_TAB)},
    [NV_COPY - NV_START] = {LCMD(KC_C), LCTL(KC_C)},
    [NV_PSTE - NV_START] = {LCMD(KC_V), LCTL(KC_V)},
    [NV_SCSH - NV_START] = {SCMD(KC_3), KC_PSCR},
    [NV_WSCH - NV_START] = {SCMD(KC_4), SGUI(KC_S)},
    [NV_WSWT - NV_START] = {KC_LGUI, KC_LALT},
};

uint16_t get_nav_code(uint16_t keycode) {
    return pgm_read_word(&(nav_keys[keycode - NV_START][nav_keys_index()]));
}

void next_nav_keys(void) {
    set_nav_keys_index((nav_keys_index() + 1) % NUM_NAV_KEYS_OSES);
#ifdef BLINK_LED_PIN
    blink_led(100 + 50 * nav_keys_index(), 6 - nav_keys_index() * 4);
#endif
#ifdef SPLIT_KEYBOARD
    if (is_keyboard_master()) {
        set_needs_runtime_state_sync(true);
    }
#endif
}

void perform_copy_paste(keyrecord_t *record) {
    if (record->event.pressed) {
        copy_paste_timer = timer_read();
    } else {
        if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
            tap_code16(get_nav_code(NV_COPY));
        } else {
            tap_code16(get_nav_code(NV_PSTE));
        }
    }
}

void perform_nav_key(uint16_t keycode, keyrecord_t *record) {
    uint16_t nav_keycode = get_nav_code(keycode);

    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;
    handler(nav_keycode);
}

void window_switcher(keyrecord_t *record) {
    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;

    if (record->event.pressed) {
        is_window_switcher_active = true;
        handler(get_nav_code(NV_WSWT));
    }

    handler(KC_TAB);
}

layer_state_t default_layer_state_set_user_nav(layer_state_t state) {
    if (state < FIRST_NON_BASE_LAYER && is_window_switcher_active) {
        unregister_code(get_nav_code(NV_WSWT));
        is_window_switcher_active = false;
    }

    return state;
}

bool process_record_nav(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CTAB:
            window_switcher(record);
            break;

        case NV_START ... NV_END:
            perform_nav_key(keycode, record);
            break;

        case KC_CCCP:
            perform_copy_paste(record);
            break;

        case KC_NOS:
            if (record->event.pressed) {
                next_nav_keys();
            }
            break;

        default:
            return true;
    }

    return false;
}
