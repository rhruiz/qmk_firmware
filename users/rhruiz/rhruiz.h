#pragma once
#include "quantum.h"
#include "keymap_callbacks/keymap_callbacks.h"
#include "layouts/keys.h"
#include "layouts/wrappers.h"

#if defined(RGBLIGHT_ENABLE)
#include "rgblight/rgblight.h"
#endif

#if defined(OS_DETECTION_ENABLE)
#include "os_detection.h"
#endif

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

typedef enum rhruiz_layers { _BL, _COLEMAK, _CODH, _GAME, _NUM, _FN1, _FN2, _GAMEFN1, _AUG, _CFG, _FUNC } rhruiz_layers;

typedef enum custom_keycodes {
    // macro keys
    KC_MAKE = QK_USER,
    KC_EPIP,
    KC_FARW,
    KC_ARRW,
    KC_PDIR,
    KC_TQUO,
    KC_CCCP,
    // config keys
    KC_LAYO,
    KC_LAY0,
    KC_LAY1,
    KC_NOS,
    // window switcher
    KC_CTAB,
    // os independent nav keys
    NV_START,
    NV_NWIN = NV_START, // next window
    NV_SCTP, // scroll to bottom
    NV_SCBT, // scroll to top
    NV_EOL,
    NV_BOL,
    NV_WLFT, // word left
    NV_WRGH, // word right
    NV_BCK,
    NV_FWD,
    NV_TAN, // next tab
    NV_TAP, // previous tab
    NV_MICT,  // mission control
    NV_COPY,
    NV_PSTE,
    NV_SCSH, // screenshot
    NV_WSCH, // window screenshot
    NV_WSWT, // window switcher key
    NV_END = NV_WSWT,
    USER_SAFE_RANGE
} rhruiz_keycodes;

typedef struct _rhruiz_runtime_state {
    uint8_t nav_keys_index;
#ifdef OS_DETECTION_ENABLE
    os_variant_t host_os;
#endif
    bool is_window_switcher_active;
    uint8_t base_layer;
    uint16_t copy_paste_timer;
#ifdef BLINK_LED_PIN
    uint16_t blink_repeat_timer;
    uint8_t  blink_times_remaining;
    uint16_t blink_dur;
#endif
#ifdef SPLIT_KEYBOARD
    bool needs_runtime_state_sync;
#   ifdef CAPS_WORD_ENABLE
    bool caps_word_enabled;
#   endif
#endif
} rhruiz_runtime_state;

bool process_record_nav(uint16_t keycode, keyrecord_t *record, rhruiz_runtime_state *runtime_state);
bool process_record_macros(uint16_t keycode, keyrecord_t *record);
layer_state_t default_layer_state_set_user_nav(layer_state_t state, rhruiz_runtime_state *runtime_state);
void reset_runtime_state(void);
#ifdef BLINK_LED_PIN
void blink_led(uint16_t duration_ms, uint8_t times);
void blink_led_task(void);
#endif

#define NUM_NAV_KEYS_OSES 2

#ifdef TAP_DANCE_ENABLE
// tap dances
enum {
    TD_RSHIFT_NUM,
};

#    define TD_SNU TD(TD_RSHIFT_NUM)
#else
#    define TD_SNU KC_RSFT
#endif
