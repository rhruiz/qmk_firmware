const char _spacer[] PROGMEM = "          ";

static const char lc[][4][3] PROGMEM = {
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

static const char arrow_up[] PROGMEM = "\x20\x89\x8a\x8b\x20\n\x8c\xbe\xbe\xbe\x90\n";
static const char arrow_down0[] PROGMEM = "\x8b\x20\x20\x20\x89\n";
static const char arrow_down1[] PROGMEM = "\xbe\x90\x8e\x8c\xbe\n";

bool rhruiz_render_oled(void) {
    layer_state_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _FN1:
            oled_write_P(arrow_up, false);
            oled_write_P(arrow_up, true);
            break;

        case _FN2:
            oled_write_P(arrow_down0, false);
            oled_write_P(arrow_down1, false);
            oled_write_P(PSTR("\x8b\x20\x8f\x20\x89\n"), true);
            oled_write_P(arrow_down1, true);
            break;

        case _AUG:
            oled_write_P(arrow_up, false);
            oled_write_P(arrow_down0, true);
            oled_write_P(arrow_down1, true);
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

        case _NUM:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_P(_spacer, false);
                oled_write_P(lc[layer][i], false);
                oled_write_char('\n', false);
            }
            break;

        default:
            for (uint8_t i = 0; i < 4; i++) {
                oled_write_char('\n', false);
            }

            break;
    }

    return false;
}
