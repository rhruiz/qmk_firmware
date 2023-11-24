#pragma once
#include "quantum.h"

layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void keyboard_post_init_keymap(void);
void matrix_init_keymap(void);
void matrix_scan_keymap(void);
void housekeeping_task_keymap(void);
void caps_word_set_keymap(bool active);
void suspend_power_down_keymap(void);
void suspend_wakeup_init_keymap(void);
#ifdef OLED_ENABLE
bool oled_task_keymap(void);
#endif
