/*
OLED 32x128 - 6x8 font

+-----+     +-----+     +-----+     +-----+
| N⌂  |     | N⌂  |     | N⌂  |     | N⌂  |
| ⇧⌂  |     | ⇧⌂  |     | ⇪⌂  |     | ⇧⌂  |
|     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |
| /\  |     | \/  |     | /\  |     | |+| |
| /\  |     | \/  |     | \/  |     | +|| |
| /\  |     | \/  |     | /\  |     | ||+ |
| /\  |     | \/  |     | \/  |     |     |
| /\  |     | \/  |     | /\  |     |     |
| /\  |     | \/  |     | \/  |     |CO DH|
|     |     |     |     |     |     | mac |
|     |     |     |     |     |     |     |
|⌘⌘ ⇧⇧|     |⌘⌘ ⇧⇧|     |⌘⌘ ⇧⇧|     |⌘⌘ ⇧⇧|
|⌘⌘ ⇧⇧|     |⌘⌘ ⇧⇧|     |⌘⌘ ⇧⇧|     |⌘⌘ ⇧⇧|
|⌃⌃ ⌥⌥|     |⌃⌃ ⌥⌥|     |⌃⌃ ⌥⌥|     |⌃⌃ ⌥⌥|
|⌃⌃ ⌥⌥|     |⌃⌃ ⌥⌥|     |⌃⌃ ⌥⌥|     |⌃⌃ ⌥⌥|
+-----+     +-----+     +-----+     +-----+

*/

bool is_keyboard_left(void);

const char _layer_names[][6] PROGMEM = {
    [_QWER] = "QWERT",
    [_CODH] = "CO-DH",
    [_FUNC] = "FUNC ",
    [_GAME] = "GAME ",
};

void oled_wear_save_pad(uint8_t size, bool cond) {
    if (cond ^ ((timer_read() / 10000) % 2 == 0)) {
        for (uint8_t i = 0; i < size; i++) {
            oled_write_char(0x20, false);
        }
    }
}

void oled_write_padded_P(const char *str, bool inverse, uint8_t size) {
    oled_wear_save_pad(size, is_keyboard_left());
    oled_write_P(str, inverse);
    oled_wear_save_pad(size, !is_keyboard_left());
}

void oled_clear_half_except(uint8_t lines) {
    for (uint8_t j = 0; j < (oled_max_lines() - 6 - lines) / 2; j++) {
        oled_write_char('\n', false);
    }
}

void render_mod_pair(uint8_t offset, uint8_t mid_offset, bool left, bool right) {
    oled_write_char(left ? offset : 0x20, false);
    oled_write_char(left ? offset + 1 : 0x20, false);

    uint8_t any = (left << 1) | right;
    oled_write_char(any ? 0xc0 + mid_offset + any - 1 : 0x20, false);

    oled_write_char(right ? offset + 2 : 0x20, false);
    oled_write_char(right ? offset + 3 : 0x20, false);
}

bool rhruiz_render_oled(void) {
    if (
#ifdef CAPS_WORD_ENABLE
#   ifdef SPLIT_KEYBOARD
    caps_word_enabled() ||
#   else
    is_caps_word_on() ||
#   endif
#endif
    host_keyboard_led_state().caps_lock
    ) {
        oled_write_padded_P(PSTR("\x8D\x8E\x8A"), false, 2);
    } else {
        oled_write_char('\n', false);
    }

    if (IS_LAYER_ON(_NUM)) {
        oled_write_padded_P(PSTR("\x88\x89\x8a"), false, 2);
    } else {
        oled_write_char('\n', false);
    }

    layer_state_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _FN1:
        case _FN2:
            oled_clear_half_except(6);
            for (uint8_t i = 0; i < 6; i++) {
                oled_wear_save_pad(3, is_keyboard_left());
                oled_write_char(0x8C - (layer - _FN1), i % 2 == 1);
                oled_write_char(0x8B + (layer - _FN1), i % 2 == 1);
                oled_wear_save_pad(3, !is_keyboard_left());
            }
            oled_clear_half_except(6);
            break;

        case _AUG:
            oled_clear_half_except(6);
            for (uint8_t i = 0; i < 3; i++) {
                oled_write_padded_P(PSTR("\x8B\x8C"), false, 3);
                oled_write_padded_P(PSTR("\x8C\x8B"), true, 3);
            }
            oled_clear_half_except(6);
            break;

        case _CFG:
            oled_clear_half_except(8);
            oled_write_padded_P(PSTR("\xc6\xc7\xc6"), false, 2);
            oled_write_padded_P(PSTR("\xc7\xc6\xc6"), false, 2);
            oled_write_padded_P(PSTR("\xc6\xc6\xc7"), false, 2);
            oled_clear_half_except(8);

            oled_write_char('\n', false);
            oled_write_char('\n', false);

            if (IS_LAYER_ON(_GAME)) {
                oled_write_P(_layer_names[_GAME], false);
            } else {
                oled_write_P(_layer_names[get_highest_layer(default_layer_state)], false);
            }

            oled_write_P(nav_keys_index() == 0 ? PSTR(" mac ") : PSTR(" win "), nav_keys_index() % 2 == 0);
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
    mods = (mods | (mods >> 4)) & 0b00001111;

    render_mod_pair(0x80, 0, mods & MOD_LGUI, mods & MOD_LSFT);
    render_mod_pair(0xa0, 3, mods & MOD_LGUI, mods & MOD_LSFT);
    render_mod_pair(0x84, 0, mods & MOD_LCTL, mods & MOD_LALT);
    render_mod_pair(0xa4, 3, mods & MOD_LCTL, mods & MOD_LALT);

    return false;
}
