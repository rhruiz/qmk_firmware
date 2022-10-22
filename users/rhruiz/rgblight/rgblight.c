#include "quantum.h"

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

