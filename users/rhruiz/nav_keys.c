#include "quantum.h"
#include "rhruiz.h"

#define NUM_NAV_KEYS_OSES 2

const uint16_t nav_keys[][NUM_NAV_KEYS_OSES] PROGMEM = {
    [NV_NWIN - NV_START] = {LCMD(KC_GRV), LALT(KC_TAB)},
    [NV_SCTP - NV_START] = {LCMD(KC_UP), LGUI(KC_HOME)},
    [NV_SCBT - NV_START] = {LCMD(KC_DOWN), LGUI(KC_END)},
    [NV_EOL  - NV_START] = {LCMD(KC_RIGHT), KC_END},
    [NV_BOL  - NV_START] = {LCMD(KC_LEFT), KC_HOME},
    [NV_WLFT - NV_START] = {LALT(KC_LEFT), LCTL(KC_LEFT)},
    [NV_WRGH - NV_START] = {LALT(KC_RIGHT), LCTL(KC_RGHT)},
    [NV_BCK  - NV_START] = {LCMD(KC_LBRC), LALT(KC_LEFT)},
    [NV_FWD  - NV_START] = {LCMD(KC_RBRC), LALT(KC_RGHT)},
    [NV_TAN  - NV_START] = {LCMD(KC_RCBR), LCTL(KC_TAB)},
    [NV_TAP  - NV_START] = {LCMD(KC_LCBR), LCTL(LSFT(KC_TAB))},
    [NV_MICT - NV_START] = {LCTL(KC_UP), LGUI(KC_TAB)},
    [NV_COPY - NV_START] = {LGUI(KC_C), LCTL(KC_C)},
    [NV_PSTE - NV_START] = {LGUI(KC_V), LCTL(KC_V)},
    [NV_WSWT - NV_START] = {KC_LGUI, KC_LALT},
};

uint16_t get_nav_code(uint16_t keycode, rhruiz_runtime_state *state) {
    return pgm_read_word(&(nav_keys[keycode - NV_START][state->nav_keys_index]));
}

void next_nav_keys(rhruiz_runtime_state *state) {
    state->nav_keys_index = (state->nav_keys_index + 1) % NUM_NAV_KEYS_OSES;
#ifdef SPLIT_KEYBOARD
    if (is_keyboard_master()) {
        state->needs_runtime_state_sync = true;
    }
#endif
}

void perform_copy_paste(keyrecord_t *record, rhruiz_runtime_state *state) {
    if (record->event.pressed) {
        state->copy_paste_timer = timer_read();
    } else {
        if (timer_elapsed(state->copy_paste_timer) > TAPPING_TERM) {
            tap_code16(get_nav_code(NV_COPY, state));
        } else {
            tap_code16(get_nav_code(NV_PSTE, state));
        }
    }
}

void perform_nav_key(uint16_t keycode, keyrecord_t *record, rhruiz_runtime_state *state) {
    uint16_t nav_keycode = get_nav_code(keycode, state);

    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;
    handler(nav_keycode);
}

void stop_window_switcher(keyrecord_t *record, rhruiz_runtime_state *state) {
    if (!record->event.pressed && state->is_window_switcher_active) {
        unregister_code(get_nav_code(NV_WSWT, state));
        state->is_window_switcher_active = false;
    }
}

void window_switcher(keyrecord_t *record, rhruiz_runtime_state *state) {
    void (*handler)(uint16_t) = record->event.pressed ? register_code16 : unregister_code16;

    if (record->event.pressed) {
        state->is_window_switcher_active = true;
        handler(get_nav_code(NV_WSWT, state));
    }

    handler(KC_TAB);
}

bool process_record_nav(uint16_t keycode, keyrecord_t *record, rhruiz_runtime_state *runtime_state) {
    switch (keycode) {
        case LT_RSE_ENT:
        case MO_RSE:
            stop_window_switcher(record, runtime_state);
            return true;

        case KC_CTAB:
            window_switcher(record, runtime_state);
            break;

        case NV_START ... NV_END:
            perform_nav_key(keycode, record, runtime_state);
            break;

        case KC_CCCP:
            perform_copy_paste(record, runtime_state);
            break;

        case KC_NOS:
            if (record->event.pressed) {
                next_nav_keys(runtime_state);
            }
            break;

        default:
            return true;
    }

    return false;
}
