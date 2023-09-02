#include "oled.h"
#include "rhruiz.h"

#ifdef OLED_ROTATE_ENABLE
#include "users/rhruiz/oled/rotate.c"
#else
#include "users/rhruiz/oled/no_rotate.c"
#endif

__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
#ifdef OLED_ROTATE_ENABLE
    return OLED_ROTATION_270;
#else
    return rotation;
#endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return oled_init_keymap(rotation); }

__attribute__((weak)) bool oled_task_user(void) {
    return rhruiz_render_oled();
}
