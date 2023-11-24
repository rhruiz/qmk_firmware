
const char _spacer[] PROGMEM = "          ";

static const char lc[][4][3] PROGMEM = {
    [_QWER]    = {"\x20\x20", "\x20\x20", "\x20\x20", "\x20\x20"},
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

__attribute__((weak)) bool oled_task_user(void) {
    if (!oled_task_keymap()) {
        return false;
    }

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

        case _AUG:
            oled_write_P("AUG\n", false);
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
