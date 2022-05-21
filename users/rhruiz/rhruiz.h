#pragma once
#include "quantum.h"
#include "layouts/keys.h"
#include "layouts/wrappers.h"

#ifdef AUDIO_ENABLE
#    include "audio/songs.h"
#endif

#ifdef OLED_ENABLE
#    include "oled/oled.h"
#endif

typedef enum rhruiz_layers { _BL, _ALT_BL, _COLEMAK, _CODH, _ISRT, _NORMAN, _GAME, _NUM, _ALT_NUM, _KEY_OVERRIDE, _FN1, _FN2, _GAMEFN1, _ALT_FN1, _ALT_FN2, _CFG, _ALT_CFG } rhruiz_layers;

enum custom_keycodes {
    KC_MAKE = SAFE_RANGE,
    KC_EPIP,
    KC_CTAB,
    KC_LAYO,
    KC_NOS,
    NV_NWIN,
    NV_SCTP,
    NV_SCBT,
    NV_EOL,
    NV_BOL,
    NV_WLFT,
    NV_WRGH,
    NV_BCK,
    NV_FWD,
    NV_TAN,
    NV_TAP,
    NV_MICT,
    NEW_SAFE_RANGE
} rhruiz_keycodes;

void          rhruiz_update_layer_colors(layer_state_t state);
layer_state_t rhruiz_layer_state_set_user(layer_state_t state);
bool          rhruiz_is_layer_indicator_led(uint8_t index);
void          rhruiz_disable_promicro_leds(void);
bool          rhruiz_process_record(uint16_t keycode, keyrecord_t *record);
void          keyboard_post_init_keymap(void);
void          matrix_init_keymap(void);
void          rhruiz_next_default_layer(void);

#ifdef TAP_DANCE_ENABLE
// tap dances
enum {
    TD_RSHIFT_NUM,
};

#    define TD_SNU TD(TD_RSHIFT_NUM)
#else
#    define TD_SNU KC_RSFT
#endif

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
