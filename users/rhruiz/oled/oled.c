#include "oled.h"
#include "rhruiz.h"

static uint32_t oled_timer = 0;

// clang-format off

#ifdef OLED_ROTATE

bool is_keyboard_left(void);

static const char _game_layer_logo[][5] PROGMEM = {"\xa8\xa9\xaa\xab", "\xc8\xc9\xca\xcb"};

static const char _raise_layer_logo[3] PROGMEM = {"\x90\x91"};

static const char _lower_layer_logo[3] PROGMEM = {"\x91\x90"};

void oled_write_padded_P(const char *str, bool inverse, uint8_t size) {
    for (uint8_t i = 0; is_keyboard_left() && i < size; i++) {
        oled_write_P(PSTR("\x20"), false);
    }

    oled_write_P(str, inverse);

    for (uint8_t i = 0; !is_keyboard_left() && i < size; i++) {
        oled_write_P(PSTR("\x20"), false);
    }
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
        oled_write("\n", false);
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

void rhruiz_render_oled(void) {
    layer_state_t layer = biton32(layer_state);

    switch (layer) {
        case _NUM:
            oled_clear_half_except(1);
            oled_write_padded_P(PSTR("\x88\x89\x8a"), false, 2);
            oled_clear_half_except(1);
            break;

        case _FN1:
            oled_clear_half_except(6);
            for (uint8_t i = 0; i < 3; i++) {
                oled_write_padded_P(_lower_layer_logo, false, 3);
                oled_write_padded_P(_lower_layer_logo, true, 3);
            }

            oled_clear_half_except(6);
            break;

        case _FN2:
            oled_clear_half_except(6);
            for (uint8_t i = 0; i < 3; i++) {
                oled_write_padded_P(_raise_layer_logo, false, 3);
                oled_write_padded_P(_raise_layer_logo, true, 3);
            }

            oled_clear_half_except(6);
            break;

        case _CFG:
            oled_clear_half_except(3);
            oled_write_padded_P(PSTR("\xcc\xcd\xcc"), false, 2);
            oled_write_padded_P(PSTR("\xcd\xcc\xcc"), false, 2);
            oled_write_padded_P(PSTR("\xcc\xcc\xcd"), false, 2);
            oled_clear_half_except(3);

            char buf[4] = {0x20, 0x20, 0x0a, 0x0};

            for (uint8_t i = 0; i < 2; i++) {
                uint8_t digit = (oled_get_brightness() >> 4*i) & 0xf;
                buf[1-i] = digit + (digit > 9 ? 55 : 48);
            }

            oled_write(buf, false);

            break;

        case _GAMEFN1:
            oled_clear_half_except(2);

            for (uint8_t i = 0; i < 2; i++) {
                if (is_keyboard_left()) oled_write("\x1f", false);

                oled_write_P(_game_layer_logo[i], false);

                if (!is_keyboard_left()) oled_write("\x1f", false);
            }

            oled_clear_half_except(2);
            break;

        case _GAME:
            oled_clear_half_except(2);
            oled_write_padded_P(_game_layer_logo[0], false, 1);
            oled_write_padded_P(_game_layer_logo[1], false, 1);
            oled_clear_half_except(2);
            break;

        default:
            oled_clear_half_except(0);
            oled_clear_half_except(0);
            break;
    }

    uint8_t mods = get_mods();

    oled_cond_write_P(mods & MOD_MASK_GUI, PSTR("\x80\x81"), PSTR("\x20\x20"));
    oled_demux_cond_write_P(mods & MOD_MASK_GUI, mods & MOD_MASK_SHIFT, PSTR("\x20"), PSTR("\xc0"), PSTR("\xc4"), PSTR("\xc2"));
    oled_cond_write_P(mods & MOD_MASK_SHIFT, PSTR("\x86\x87"), PSTR("\x20\x20"));

    oled_cond_write_P(mods & MOD_MASK_GUI, PSTR("\xa0\xa1"), PSTR("\x20\x20"));
    oled_demux_cond_write_P(mods & MOD_MASK_GUI, mods & MOD_MASK_SHIFT, PSTR("\x20"), PSTR("\xc1"), PSTR("\xc5"), PSTR("\xc3"));
    oled_cond_write_P(mods & MOD_MASK_SHIFT, PSTR("\xa6\xa7"), PSTR("\x20\x20"));

    oled_cond_write_P(mods & MOD_MASK_CTRL, PSTR("\x84\x85"), PSTR("\x20\x20"));
    oled_demux_cond_write_P(mods & MOD_MASK_CTRL, mods & MOD_MASK_ALT, PSTR("\x20"), PSTR("\xc0"), PSTR("\xc4"), PSTR("\xc2"));
    oled_cond_write_P(mods & MOD_MASK_ALT, PSTR("\x82\x83"), PSTR("\x20\x20"));

    oled_cond_write_P(mods & MOD_MASK_CTRL, PSTR("\xa4\xa5"), PSTR("\x20\x20"));
    oled_demux_cond_write_P(mods & MOD_MASK_CTRL, mods & MOD_MASK_ALT, PSTR("\x20"), PSTR("\xc1"), PSTR("\xc5"), PSTR("\xc3"));
    oled_cond_write_P(mods & MOD_MASK_ALT, PSTR("\xa2\xa3"), PSTR("\x20\x20"));
}
#else
void rhruiz_render_oled(void) {
    layer_state_t layer = biton32(layer_state);

    switch (layer) {
        case _FN1:
        case _FN2:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);

                for (uint8_t j = 0; j < 3; j++) {
                    oled_write_P(lc[layer][i], false);
                }

                oled_write("\n", false);
            }

            break;

        case _CFG:
            for (uint8_t i = 0; i < 4; i++) {
                for (uint8_t j = 0; j < 10; j++) {
                    oled_write_P(lc[layer][i], false);
                }

                oled_write("\n", false);
            }
            break;

        case _GAME:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_P(_game_layer_logo[i], false);
                oled_write("\n", false);
            }
            break;

        case _GAMEFN1:
            oled_write_P(_spacer, false);
            oled_write_P(lc[layer][3], false);
            oled_write("\n", false);

            for (uint8_t i = 1; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_P(_game_layer_logo[i], false);
                oled_write("\n", false);
            }
            break;

        default:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_ln_P(lc[layer][i], false);
            }

            break;
    }
}
#endif

void rhruiz_oled_activity(void) { oled_timer = timer_read32(); }

__attribute__((weak)) void oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed32(oled_timer) > OLED_TIMEOUT) {
            oled_off();
            return;
        } else {
            oled_on();
        }
    }

    rhruiz_render_oled();
}

void suspend_power_down_user(void) { oled_off(); }

void suspend_wakeup_init_user(void) { oled_on(); }
