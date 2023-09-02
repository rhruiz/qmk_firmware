#include "quantum.h"
#include "rhruiz.h"

#define _rhI(x) __rhI(x)
#define __rhI(x) #x
#ifdef __clang__
#define lambda(return_type, function_body) \
    ^ return_type function_body
#else
#define lambda(return_type, function_body) \
({ \
      return_type __fn__ function_body \
          __fn__; \
})
#endif

bool shifted(uint8_t mods) {
    return mods & MOD_MASK_SHIFT;
}

void without_mods(
#ifdef __clang__
        void (^block)(uint8_t)
#else
        void block(uint8_t)
#endif
) {
    uint8_t mods = mod_config(get_mods());
    clear_mods();
#ifndef NO_ACTION_ONESHOT
    mods |= mod_config(get_oneshot_mods());
    clear_oneshot_mods();
#endif
    block(mods);
    set_mods(mods);
}

void send_make_args(bool should_flash, bool parallel) {
    if (should_flash) {
        SEND_STRING("qmk flash");
    } else {
        SEND_STRING("qmk compile");
    }

    SEND_STRING(" -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
#    if defined(CONVERTER_ENABLED)
    SEND_STRING(" -e CONVERT_TO=" CONVERTER_TARGET);
#    endif

    if (parallel) {
        SEND_STRING(" -j 8");
    }
#ifdef OLED_ENABLE

    SEND_STRING(" -e OLED_ENABLE=yes");
#    ifdef OLED_ROTATE_ENABLE
    SEND_STRING(" -e OLED_ROTATE_ENABLE=yes");
#    endif
#endif
}

void send_make(bool should_flash, bool parallel) {
#ifndef BOOTLOADER_CATERINA
#    ifdef RAW_ENABLE
    if (should_flash) {
        send_make_args(false, parallel);
        SEND_STRING(" && VID=" _rhI(VENDOR_ID) " PID=" _rhI(PRODUCT_ID));
        SEND_STRING(" ~/dev/keyboard/hid_send/hid_send bootloader && ");
    }
#    endif
#endif
    send_make_args(should_flash, parallel);
}

bool process_record_macros(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TQUO:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case KC_ARRW:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                   if (shifted(mods)) {
                       SEND_STRING("<- ");
                   } else {
                       SEND_STRING("->");
                   }
                }));
            }
            break;

        case KC_FARW:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                    if (shifted(mods)) {
                        SEND_STRING("<>");
                    } else {
                        SEND_STRING("=> ");
                    }
                }));
            }
            break;

        case KC_EPIP:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                    if (shifted(mods)) {
                        SEND_STRING(" { || }" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                    } else {
                        SEND_STRING("|> ");
                    }
                }));
            }
            break;

        case KC_PDIR:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t _mods) {
                    SEND_STRING("../");
                }));
            }
            break;

        case KC_MAKE:
            if (record->event.pressed) {
                without_mods(lambda (void, (uint8_t mods) {
                    bool should_flash = shifted(mods);
                    bool parallel = mods & MOD_MASK_CTRL;

                    send_make(should_flash, parallel);

                    SEND_STRING(SS_TAP(X_ENTER));
                }));
            }
            break;

        default:
            return true;
    }

    return false;
}
