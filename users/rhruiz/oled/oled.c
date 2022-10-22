#include "oled.h"
#include "rhruiz.h"

extern rhruiz_runtime_state runtime_state;

// clang-format off

#ifdef OLED_ROTATE

bool is_keyboard_left(void);

const char _layer_names[][6] PROGMEM = {
    [_BL] = "QWERT",
    [_COLEMAK] = "COLEM",
    [_CODH] = "CO-DH",
    [_FUNC] = "FUNC ",
};

void oled_pad_if(uint8_t size, bool cond) {
    if (cond) {
        for (uint8_t i = 0; i < size; i++) {
            oled_write_char(0x20, false);
        }
    }
}

void oled_write_padded_P(const char *str, bool inverse, uint8_t size) {
    oled_pad_if(size, is_keyboard_left());
    oled_write_P(str, inverse);
    oled_pad_if(size, !is_keyboard_left());
}
#else

const char _spacer[] PROGMEM = "          ";

static const char lc[][4][3] PROGMEM = {
    [_BL]      = {"\x20\x20", "\x20\x20", "\x20\x20", "\x20\x20"},
    [_FN1]     = {"\x20\x20", "\xb2\xb3", "\x92\x93", "\x20\x20"},
    [_FN2]     = {"\x20\x20", "\x92\x93", "\xb2\xb3", "\x20\x20"},
    [_CFG]     = {"\x80\x81", "\xa0\xa1", "\xc0\xc1", "\x80\x81"},
    [_NUM]     = {"\xae\xaf", "\xce\xcf", "\x20\x20", "\xd2\xd3"},
    [_GAME]    = {"\x20\x20", "\x82\x83", "\xa2\xa3", "\xc2\xc3"},
    [_GAMEFN1] = {"\x20\x20", "\xb0\xb1", "\xd0\xd1", "\x11\x11"},
};

static const char _game_layer_logo[][4] PROGMEM = {
    "\x20\x20\x20",
    "\x82\x83\x84",
    "\xa2\xa3\xa4",
    "\xc2\xc3\xc4",
};

#endif

// clang-format on

__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
#ifdef OLED_ROTATE
    return OLED_ROTATION_270;
#else
    return rotation;
#endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return oled_init_keymap(rotation); }

#ifdef OLED_ROTATE
void oled_clear_half_except(uint8_t lines) {
    for (uint8_t j = 0; j < (oled_max_lines() - 4 - lines) / 2; j++) {
        oled_write_char('\n', false);
    }
}

void oled_cond_write_P(bool cond, const char *when_true, const char *when_false) {
    if (cond) {
        oled_write_P(when_true, false);
    } else {
        oled_write_P(when_false, false);
    }
}

void oled_demux_cond_write_P(bool left, bool right, const char *when_none, const char *when_left, const char *when_right, const char *when_both) {
    const char *outs[4] = {when_none, when_right, when_left, when_both};

    oled_write_P(outs[(left << 1) + right], false);
}

bool rhruiz_render_oled(void) {
    layer_state_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _NUM:
            oled_clear_half_except(1);
            oled_write_padded_P(PSTR("\x88\x89\x8a"), false, 2);
            oled_clear_half_except(1);
            break;

        case _FN1:
        case _FN2:
            oled_clear_half_except(6);
            for (uint8_t i = 0; i < 6; i++) {
                oled_pad_if(3, is_keyboard_left());
                oled_write_char(0x8C - (layer - _FN1), i % 2 == 1);
                oled_write_char(0x8B + (layer - _FN1), i % 2 == 1);
                oled_pad_if(3, !is_keyboard_left());
            }
            oled_clear_half_except(6);
            break;

        case _CFG:
            oled_clear_half_except(6);
            oled_write_padded_P(PSTR("\xc6\xc7\xc6"), false, 2);
            oled_write_padded_P(PSTR("\xc7\xc6\xc6"), false, 2);
            oled_write_padded_P(PSTR("\xc6\xc6\xc7"), false, 2);
            oled_clear_half_except(6);

            oled_write_P(_layer_names[get_highest_layer(default_layer_state)], false);
            oled_write_P(runtime_state.nav_keys_index == 0 ? PSTR(" mac ") : PSTR(" win "), true);
            oled_write_char('\n', false);

            break;

        case _GAME:
        case _GAMEFN1:
            oled_clear_half_except(2);

            for (uint8_t i = 0; i < 2; i++) {
                if (is_keyboard_left()) oled_write_char(0x20 - (layer/_GAMEFN1), false);

                for (uint8_t chr = 0; chr < 4; chr++) {
                  oled_write_char(0xAC + i * 0x20 + chr - (layer - _GAME), false);
                }

                if (!is_keyboard_left()) oled_write_char(0x20 - (layer/_GAMEFN1), false);
            }

            oled_clear_half_except(2);
            break;

        case _FUNC:
            oled_clear_half_except(2);
            oled_write_P(PSTR("FUNC\n OSL\n"), false);
            oled_clear_half_except(2);
            break;

        default:
            oled_clear_half_except(0);
            oled_clear_half_except(0);

            break;
    }

    uint8_t mods = get_mods();

#ifdef CAPS_WORD_ENABLE
    if (
#   ifdef SPLIT_KEYBOARD
    runtime_state.caps_word_enabled
#   else
    is_caps_word_on()
#   endif
    ) {
        oled_write_P(PSTR("\x20\xc4\x86\x87\x20"), false);
        oled_write_P(PSTR("\x20\xc5\xa6\xa7\x20"), false);
    } else {
#endif
        oled_cond_write_P(mods & MOD_MASK_GUI, PSTR("\x80\x81"), PSTR("\x20\x20"));
        oled_demux_cond_write_P(mods & MOD_MASK_GUI, mods & MOD_MASK_SHIFT, PSTR("\x20"), PSTR("\xc0"), PSTR("\xc4"), PSTR("\xc2"));
        oled_cond_write_P(mods & MOD_MASK_SHIFT, PSTR("\x86\x87"), PSTR("\x20\x20"));

        oled_cond_write_P(mods & MOD_MASK_GUI, PSTR("\xa0\xa1"), PSTR("\x20\x20"));
        oled_demux_cond_write_P(mods & MOD_MASK_GUI, mods & MOD_MASK_SHIFT, PSTR("\x20"), PSTR("\xc1"), PSTR("\xc5"), PSTR("\xc3"));
        oled_cond_write_P(mods & MOD_MASK_SHIFT, PSTR("\xa6\xa7"), PSTR("\x20\x20"));
#ifdef CAPS_WORD_ENABLE
    }
#endif

    oled_cond_write_P(mods & MOD_MASK_CTRL, PSTR("\x84\x85"), PSTR("\x20\x20"));
    oled_demux_cond_write_P(mods & MOD_MASK_CTRL, mods & MOD_MASK_ALT, PSTR("\x20"), PSTR("\xc0"), PSTR("\xc4"), PSTR("\xc2"));
    oled_cond_write_P(mods & MOD_MASK_ALT, PSTR("\x82\x83"), PSTR("\x20\x20"));

    oled_cond_write_P(mods & MOD_MASK_CTRL, PSTR("\xa4\xa5"), PSTR("\x20\x20"));
    oled_demux_cond_write_P(mods & MOD_MASK_CTRL, mods & MOD_MASK_ALT, PSTR("\x20"), PSTR("\xc1"), PSTR("\xc5"), PSTR("\xc3"));
    oled_cond_write_P(mods & MOD_MASK_ALT, PSTR("\xa2\xa3"), PSTR("\x20\x20"));

    return false;
}
#else
bool rhruiz_render_oled(void) {
    layer_state_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _FN1:
        case _FN2:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);

                for (uint8_t j = 0; j < 3; j++) {
                    oled_write_P(lc[layer][i], false);
                }

                oled_write_char('\n', false);
            }

            break;

        case _CFG:
            for (uint8_t i = 0; i < 4; i++) {
                for (uint8_t j = 0; j < 10; j++) {
                    oled_write_P(lc[layer][i], false);
                }

                oled_write_char('\n', false);
            }
            break;

        case _GAME:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_P(_game_layer_logo[i], false);
                oled_write_char('\n', false);
            }
            break;

        case _GAMEFN1:
            oled_write_P(_spacer, false);
            oled_write_P(lc[layer][3], false);
            oled_write_char('\n', false);

            for (uint8_t i = 1; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_P(_game_layer_logo[i], false);
                oled_write_char('\n', false);
            }
            break;

        default:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_P(lc[layer][i], false);
                oled_write_char('\n', false);
            }

            break;
    }

    return false;
}
#endif

void rhruiz_oled_activity(void) { runtime_state.oled_timer = timer_read(); }

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed(runtime_state.oled_timer) > OLED_TIMEOUT) {
            oled_off();
            return false;
        } else {
            oled_on();
        }
    }

    return rhruiz_render_oled();
}

void suspend_power_down_user(void) { oled_off(); }

void suspend_wakeup_init_user(void) { oled_on(); }
