#pragma once
#include "quantum.h"
#include "runtime_state.h"
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
#    define BASE_LAYERS _QWER
#endif

#define FIRST_NON_BASE_LAYER _FN1

bool process_record_nav(uint16_t keycode, keyrecord_t *record);
bool process_record_macros(uint16_t keycode, keyrecord_t *record);
layer_state_t default_layer_state_set_user_nav(layer_state_t state);
void default_layer_by_index(uint8_t index);
void next_default_layer(void);
uint8_t default_layer_index(void);
#ifdef BLINK_LED_PIN
void blink_led(uint16_t duration_ms, uint8_t times);
void blink_led_task(void);
void blink_led_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);
#endif

#define NUM_NAV_KEYS_OSES 2

#ifdef SPLIT_KEYBOARD
#    include "split.h"
#endif
