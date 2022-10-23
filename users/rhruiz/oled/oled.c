#include "oled.h"
#include "rhruiz.h"

extern rhruiz_runtime_state runtime_state;

#ifdef OLED_ROTATE
#include "users/rhruiz/oled/rotate.c"
#else
#include "users/rhruiz/oled/no_rotate.c"
#endif

__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
#ifdef OLED_ROTATE
    return OLED_ROTATION_270;
#else
    return rotation;
#endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return oled_init_keymap(rotation); }

void rhruiz_oled_activity(void) { runtime_state.oled_timer = timer_read(); }

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed(runtime_state.oled_timer) > OLED_TIMEOUT) {
            oled_off();
            return false;
        } else {
            oled_on();
        }
    }

    return rhruiz_render_oled();
}

void suspend_power_down_user(void) { oled_off(); }

void suspend_wakeup_init_user(void) { oled_on(); }
