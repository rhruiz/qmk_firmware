#include <stdio.h>
#include "quantum.h"
#include "rhruiz.h"

#define _rhI(x) __rhI(x)
#define __rhI(x) #x

__attribute__((weak)) void rhruiz_update_layer_colors(layer_state_t state) {}

__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t state) { return rhruiz_layer_state_set_user(state); }

__attribute__((weak)) bool rhruiz_process_record(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) void matrix_init_keymap(void) {}

__attribute__((weak)) bool rhruiz_is_layer_indicator_led(uint8_t index) {
#ifdef RGBLIGHT_ENABLE
    return index == 0 || index == RGBLED_NUM / 2 - 1;
#else
    return false;
#endif
}

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSHIFT_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _NUM),
};

#endif
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef HOME_ROW_MODS
        case SFT_T(KC_S):
        case SFT_T(KC_L):
        case CTL_T(KC_A):
        case CTL_T(KC_SCLN):
            return TAPPING_TERM + 50;
#endif
#ifdef TAP_DANCE_ENABLE
        case TD(TD_RSHIFT_NUM):
            return TAPPING_TERM + 50;
#endif
        default:
            return TAPPING_TERM;
    }
}

void rhruiz_send_make_args(bool should_flash, bool parallel) {
    SEND_STRING("qmk ");

    if (should_flash) {
        SEND_STRING("flash");
    } else {
        SEND_STRING("compile");
    }

    SEND_STRING(" -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);

    if (parallel) {
        SEND_STRING(" -j8");
    }
#ifndef OLED_ENABLE
    SEND_STRING(" -e OLED_ENABLE=no");
#else
#    ifdef OLED_ROTATE
    SEND_STRING(" -e OLED_ROTATE=yes");
#    endif
#endif
}

void rhruiz_send_make(bool should_flash, bool parallel) {
#ifndef BOOTLOADER_CATERINA
#    ifdef RAW_ENABLE
    if (should_flash) {
        rhruiz_send_make_args(false, parallel);
        SEND_STRING(" && VID=" _rhI(VENDOR_ID) " PID=" _rhI(PRODUCT_ID));
        SEND_STRING(" ~/dev/keyboard/hid_send/hid_send bootloader && ");
    }
#    endif
#endif
    rhruiz_send_make_args(should_flash, parallel);
}

bool is_alt_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(_FN2):
            if (!record->event.pressed) {
                if (is_alt_tab_active) {
                    unregister_code(KC_LCMD);
                    is_alt_tab_active = false;
                }
            }

            break;

        case KC_CTAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LCMD);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case KC_EPIP:
            if (!record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    SEND_STRING(" { || }");
                    tap_code(KC_LEFT);
                    tap_code(KC_LEFT);
                    tap_code(KC_LEFT);
                } else {
                    SEND_STRING("|> ");
                }

                return true;
            }

            break;

        case KC_MAKE:
            if (!record->event.pressed) {
                uint8_t temp_mod = mod_config(get_mods());
                clear_mods();
#ifndef NO_ACTION_ONESHOT
                uint8_t temp_osm = mod_config(get_oneshot_mods());
                clear_oneshot_mods();
#else
                uint8_t temp_osm = 0U;
#endif

                bool should_flash = ((temp_mod | temp_osm) & MOD_MASK_SHIFT);
                bool parallel     = (temp_mod | temp_osm) & MOD_MASK_CTRL;

                rhruiz_send_make(should_flash, parallel);

                SEND_STRING(SS_TAP(X_ENTER));
                set_mods(temp_mod);
            }
            break;
    }
#ifdef OLED_ENABLE

    rhruiz_oled_activity();
#endif

    return rhruiz_process_record(keycode, record);
}

void matrix_init_user(void) {
#ifdef PRO_MICRO
    setPinOutput(B0);
    setPinOutput(D5);
    writePinHigh(D5);
    writePinHigh(B0);
#endif
    matrix_init_keymap();
}

void keyboard_post_init_user() {
    /* TODO: revisit this check if flashed promicros with dfu */
#ifdef BOOTLOADER_CATERINA
    setPinOutput(B0);
    writePinHigh(B0);

    setPinOutput(D5);
    writePinHigh(D5);
#endif
    keyboard_post_init_keymap();
}

layer_state_t rhruiz_layer_state_set_user(layer_state_t state) {
    static layer_state_t last_state = 0;

    if (state != last_state) {
        state = update_tri_layer_state(state, _FN1, _FN2, _CFG);
        state = update_tri_layer_state(state, _ALT_FN1, _ALT_FN2, _ALT_CFG);

        switch (biton32(state)) {
            case _BL:
            case _KEY_OVERRIDE:
                state = state & ~(1UL << _KEY_OVERRIDE);
                break;

            case _GAMEFN1:
                state = update_tri_layer_state(state, _GAMEFN1, _FN2, _CFG);

            case _FN1:
            case _FN2:
            case _ALT_FN1:
            case _ALT_FN2:
                state = state | (1UL << _KEY_OVERRIDE);
                break;

            default:
                break;
        }

        rhruiz_update_layer_colors(state);

        last_state = state;
    }

    return state;
}

void rhruiz_rgblight_reset(void) {
#if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_LAYERS)
    rgblight_config_t eeprom_config;
    eeprom_config.raw = eeconfig_read_rgblight();

    if (!eeprom_config.enable) {
        rgblight_disable_noeeprom();
    }

    rgblight_mode_noeeprom(eeprom_config.mode);
    rgblight_sethsv_noeeprom(eeprom_config.hue, eeprom_config.sat, eeprom_config.val);
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

    bool rgbmode = rgblight_get_mode();

    for (uint8_t i = RGBLED_NUM; i-- > 0;) {
        if (rhruiz_is_layer_indicator_led(i)) {
            sethsv(hue, sat, eeprom_config.val, (LED_TYPE *)&ledp[i]);
        } else {
            if (rgbmode == false) {
                sethsv(0, 0, 0, (LED_TYPE *)&ledp[i]);
            }
        }
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
