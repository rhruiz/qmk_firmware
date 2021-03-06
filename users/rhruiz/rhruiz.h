#pragma once
#include "quantum.h"
#include "layouts/wrappers.h"

#ifdef AUDIO_ENABLE
#    include "audio/songs.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#    include "oled/oled.h"
#endif

enum rhruiz_layers { _BL, _GAME, _NUM, _KEY_OVERRIDE, _FN1, _FN2, _GAMEFN1, _CFG };

enum custom_keycodes { KC_MAKE = SAFE_RANGE, KC_EPIP, KC_CTAB, NEW_SAFE_RANGE };

/* mission control */
#define MISCTRL LCTL(KC_UP)

/* tap to esc, hold to ctrl */
#define CTRLESC LCTL_T(KC_ESC)

/* space or fn */
#define SPCFN1 LT(_FN1, KC_SPC)
#define SPCFN2 LT(_FN2, KC_SPC)

/* backspace or fn */
#define BKSFN1 LT(_FN1, KC_BSPC)
#define BKSFN2 LT(_FN2, KC_BSPC)

/* arrow cluster */
#define CLLEFT MT(MOD_RGUI, KC_LEFT)
#define CLDOWN MT(MOD_RCTL, KC_DOWN)
#define CLUP MT(MOD_RSFT, KC_UP)
#define CLRIGHT LT(_FN1, KC_RIGHT)

void          rhruiz_update_layer_colors(layer_state_t state);
layer_state_t rhruiz_layer_state_set_user(layer_state_t state);
bool          rhruiz_is_layer_indicator_led(uint8_t index);
void          rhruiz_disable_promicro_leds(void);
bool          rhruiz_process_record(uint16_t keycode, keyrecord_t *record);
void          keyboard_post_init_keymap(void);
void          matrix_init_keymap(void);

#ifdef TAP_DANCE_ENABLE
// tap dances
enum {
    TD_RSHIFT_NUM,
};

#    define KC_TDSNU TD(TD_RSHIFT_NUM)
#else
#    define KC_TDSNU KC_RSFT
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
