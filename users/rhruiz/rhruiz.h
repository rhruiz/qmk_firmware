#pragma once
#include "quantum.h"
#include "layouts/keys.h"
#include "layouts/wrappers.h"

#ifdef SPLIT_KEYBOARD
#    include "transactions.h"
#endif

#ifdef AUDIO_ENABLE
#    include "audio/songs.h"
#endif

#ifdef OLED_ENABLE
#    include "oled/oled.h"
#endif

#ifndef BASE_LAYERS
#    define BASE_LAYERS _BL
#endif

typedef enum rhruiz_layers { _BL, _COLEMAK, _CODH, _ISRT, _NORMAN, _APTV3, _SEMI, _GAME, _NUM, _FN1, _FN2, _GAMEFN1, _CFG, _FUNC } rhruiz_layers;

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
    NV_COPY,
    NV_PSTE,
    KC_CCCP,
    KC_FARW,
    KC_ARRW,
    KC_PDIR,
    NEW_SAFE_RANGE
} rhruiz_keycodes;

layer_state_t layer_state_set_keymap(layer_state_t state);
bool          process_record_keymap(uint16_t keycode, keyrecord_t *record);
void          keyboard_post_init_keymap(void);
void          matrix_init_keymap(void);

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

typedef struct _rhruiz_runtime_state {
    size_t nav_keys_index;
    bool is_window_switcher_active;
    size_t base_layer;
    uint16_t copy_paste_timer;
#ifdef SPLIT_KEYBOARD
    bool needs_runtime_state_sync;
#   ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#   endif
#endif
} rhruiz_runtime_state;
