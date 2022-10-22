#pragma once

/* underglow control */
void rhruiz_rgblight_reset(void);
#ifdef RGBLIGHT_ENABLE
void rhruiz_change_leds_to(uint16_t, uint8_t);
#    ifndef RGBLIGHT_LAYERS
typedef struct {
    uint16_t hue;
    uint8_t  sat;
} hue_sat_pair;
#    endif
#endif
