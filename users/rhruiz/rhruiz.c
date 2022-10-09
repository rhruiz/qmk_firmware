#include <stdio.h>
#include "quantum.h"
#include "rhruiz.h"

#define _rhI(x) __rhI(x)
#define __rhI(x) #x
#define lambda(return_type, function_body) \
({ \
      return_type __fn__ function_body \
          __fn__; \
})

rhruiz_runtime_state runtime_state = {
    .nav_keys_index = 0,
    .is_window_switcher_active = false,
    .base_layer = 0,
#ifdef SPLIT_KEYBOARD
    .needs_runtime_state_sync = false,
#   ifdef CAPS_WORD_ENABLE
    .caps_word_enabled = false,
#   endif
#endif
};

#ifdef SPLIT_KEYBOARD
typedef struct _master_to_slave_t {
    size_t nav_keys_index;
#   ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#   endif
} master_to_slave_t;
#endif

#define NUM_NAV_KEYS_OSES 2

const uint16_t nav_keys[][NUM_NAV_KEYS_OSES] PROGMEM = {
    [NV_NWIN - NV_START] =  {LCMD(KC_GRV), LALT(KC_TAB)},
    [NV_SCTP - NV_START] =  {LCMD(KC_UP), LGUI(KC_HOME)},
    [NV_SCBT - NV_START] =  {LCMD(KC_DOWN), LGUI(KC_END)},
    [NV_EOL  - NV_START] =  {LCMD(KC_RIGHT), KC_END},
    [NV_BOL  - NV_START] =  {LCMD(KC_LEFT), KC_HOME},
    [NV_WLFT - NV_START] =  {LALT(KC_LEFT), LCTL(KC_LEFT)},
    [NV_WRGH - NV_START] =  {LALT(KC_RIGHT), LCTL(KC_RGHT)},
    [NV_BCK  - NV_START] =  {LCMD(KC_LBRC), LALT(KC_LEFT)},
    [NV_FWD  - NV_START] =  {LCMD(KC_RBRC), LALT(KC_RGHT)},
    [NV_TAN  - NV_START] =  {LCMD(KC_RCBR), LCTL(KC_TAB)},
    [NV_TAP  - NV_START] =  {LCMD(KC_LCBR), LCTL(LSFT(KC_TAB))},
    [NV_MICT - NV_START] =  {LCTL(KC_UP), LGUI(KC_TAB)},
    [NV_COPY - NV_START] =  {LGUI(KC_C), LCTL(KC_C)},
    [NV_PSTE - NV_START] =  {LGUI(KC_V), LCTL(KC_V)},
};

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _NUM),
};

#endif
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) void housekeeping_task_keymap(void) {}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) void matrix_init_keymap(void) {}

bool shifted(uint8_t mods) {
    return mods & MOD_MASK_SHIFT;
}

const rhruiz_layers _base_layers[] PROGMEM = { BASE_LAYERS };

void next_default_layer(void) {
    size_t count = sizeof(_base_layers)/sizeof(_base_layers[0]);

    runtime_state.base_layer = (runtime_state.base_layer + 1) % count;
    rhruiz_layers layer = pgm_read_byte(_base_layers + runtime_state.base_layer);
    default_layer_set(1 << layer);
}

void next_nav_keys(void) {
    runtime_state.nav_keys_index = (runtime_state.nav_keys_index + 1) % NUM_NAV_KEYS_OSES;
#ifdef SPLIT_KEYBOARD
    if (is_keyboard_master()) {
        runtime_state.needs_runtime_state_sync = true;
    }
#endif
}

void without_mods(void block(uint8_t)) {
    uint8_t mods = mod_config(get_mods());
    clear_mods();
#ifndef NO_ACTION_ONESHOT
    mods |= mod_config(get_oneshot_mods());
    clear_oneshot_mods();
#endif
    block(mods);
    set_mods(mods);
}

void stop_window_switcher(void) {
    if (runtime_state.is_window_switcher_active) {
        unregister_code(runtime_state.nav_keys_index == 0 ? KC_LCMD : KC_LALT);
        runtime_state.is_window_switcher_active = false;
    }
}

void window_switcher(bool pressed) {
    void (*handler)(uint16_t) = pressed ? register_code16 : unregister_code16;

    if (pressed) {
        runtime_state.is_window_switcher_active = true;
        handler(runtime_state.nav_keys_index == 0 ? KC_LCMD : KC_LALT);
    }

    handler(KC_TAB);
}

uint16_t get_nav_code(uint16_t keycode) {
    return pgm_read_word(&(nav_keys[keycode - NV_START][runtime_state.nav_keys_index]));
}

void perform_nav_key(uint16_t keycode, bool pressed) {
    uint16_t nav_keycode = get_nav_code(keycode);

    void (*handler)(uint16_t) = pressed ? register_code16 : unregister_code16;
    handler(nav_keycode);
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

void send_make_args(bool should_flash, bool parallel) {
    SEND_STRING("qmk ");

    if (should_flash) {
        SEND_STRING("flash");
    } else {
        SEND_STRING("compile");
    }

    SEND_STRING(" -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);

    if (parallel) {
        SEND_STRING(" -j 8");
    }
#ifdef OLED_ENABLE

    SEND_STRING(" -e OLED_ENABLE=yes");
#    ifdef OLED_ROTATE
    SEND_STRING(" -e OLED_ROTATE=yes");
#    endif
#endif
}

void send_make(bool should_flash, bool parallel) {
#ifndef BOOTLOADER_CATERINA
#    ifdef RAW_ENABLE
    if (should_flash) {
        send_make_args(false, parallel);
        SEND_STRING(" && VID=" _rhI(VENDOR_ID) " PID=" _rhI(PRODUCT_ID));
        SEND_STRING(" ~/dev/keyboard/hid_send/hid_send bootloader && ");
    }
#    endif
#endif
    send_make_args(should_flash, parallel);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_RSE_ENT:
        case MO_RSE:
            if (!record->event.pressed) {
                stop_window_switcher();
            }
            break;

        case KC_CTAB:
            window_switcher(record->event.pressed);
            break;

        case NV_START ... NV_END:
            perform_nav_key(keycode, record->event.pressed);
            break;

        case KC_CCCP:
            if (record->event.pressed) {
                runtime_state.copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(runtime_state.copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(get_nav_code(NV_COPY));
                } else {
                    tap_code16(get_nav_code(NV_PSTE));
                }
            }
            break;

        case KC_NOS:
            if (record->event.pressed) {
                next_nav_keys();
            }
            break;

        case KC_LAYO:
            if (record->event.pressed) {
                next_default_layer();
            }
            break;

        case KC_ARRW:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                   if (shifted(mods)) {
                       SEND_STRING("<- ");
                   } else {
                       SEND_STRING("->");
                   }
                }));

                return true;
            }
            break;

        case KC_FARW:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                    if (shifted(mods)) {
                        SEND_STRING("<> ");
                    } else {
                        SEND_STRING("=> ");
                    }
                }));

                return true;
            }
            break;


        case KC_EPIP:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                    if (shifted(mods)) {
                        SEND_STRING(" { || }" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                    } else {
                        SEND_STRING("|> ");
                    }
                }));

                return true;
            }
            break;

        case KC_PDIR:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t _mods) {
                    SEND_STRING("../");
                }));
                return true;
            }

            break;

        case KC_MAKE:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                    bool should_flash = shifted(mods);
                    bool parallel = mods & MOD_MASK_CTRL;

                    send_make(should_flash, parallel);

                    SEND_STRING(SS_TAP(X_ENTER));
                }));
            }
            break;
    }
#ifdef OLED_ENABLE

    rhruiz_oled_activity();
#endif

    return process_record_keymap(keycode, record);
}

void matrix_init_user(void) {
    matrix_init_keymap();
}

void keyboard_post_init_user() {
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

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_is(_GAME)) {
        state = update_tri_layer_state(state, _GAMEFN1, _FN2, _CFG);
    } else {
        state = update_tri_layer_state(state, _FN1, _FN2, _CFG);
    }

    state = layer_state_set_keymap(state);

    return state;
}

void rhruiz_rgblight_reset(void) {
#if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_LAYERS)
    rgblight_reload_from_eeprom();
#endif
}

void rhruiz_change_leds_to(uint16_t hue, uint8_t sat) {
#ifdef RGBLIGHT_ENABLE
    rgblight_config_t eeprom_config;
    eeprom_config.raw = eeconfig_read_rgblight();
    LED_TYPE *ledp;

#    ifdef RGBLIGHT_LED_MAP
    LED_TYPE led0[RGBLED_NUM];
    for (uint8_t i = 0; i < RGBLED_NUM; i++) {
        led0[i] = led[pgm_read_byte(&led_map[i])];
    }
    ledp = led0;
#    else
    ledp = led;
#    endif

    for (uint8_t i = RGBLED_NUM; i-- > 0;) {
        sethsv(hue, sat, eeprom_config.val, (LED_TYPE *)&ledp[i]);
    }

#    ifdef RGBW
    ws2812_setleds_rgbw(ledp, RGBLED_NUM);
#    else
    ws2812_setleds(ledp, RGBLED_NUM);
#    endif
#endif
}

void matrix_scan_user(void) {
    matrix_scan_keymap();
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

    housekeeping_task_keymap();
}

#if defined(SPLIT_KEYBOARD) && defined(CAPS_WORD_ENABLE)
void caps_word_set_user(bool active) {
    runtime_state.caps_word_enabled = active;
    runtime_state.needs_runtime_state_sync = true;
}
#endif
