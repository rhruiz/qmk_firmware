SRC += rhruiz.c get_tapping_term.c nav_keys.c macros.c rgblight/rgblight.c \
	   base_layers.c blink_led.c keymap_callbacks/keymap_callbacks.c \
	   runtime_state.c

GRAVE_ESC_ENABLE=no
SPACE_CADET_ENABLE=no

ifeq ($(strip $(RAW_ENABLE)), yes)
    SRC += raw_hid/raw_hid.c
endif

ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
	SRC += users/rhruiz/split.c
endif

ifeq ($(strip $(OLED_ROTATE_ENABLE)), yes)
	OPT_DEFS += -DOLED_ROTATE_ENABLE -DRHRUIZ_OLED_FONT_H="\"users/rhruiz/oled/font_rotated.c\""
else
	OPT_DEFS += -DRHRUIZ_OLED_FONT_H="\"users/rhruiz/oled/glcdfont.c\""
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled/oled.c
endif

ifeq ($(strip $(RGBLIGHT_LAYERS)), yes)
	OPT_DEFS += -DRGBLIGHT_LAYERS -DRGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
endif

ifeq ($(strip $(LOCK_LAYERS)), yes)
	OPT_DEFS += -DLOCK_LAYERS
endif

ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
    DEFERRED_EXEC_ENABLE = yes
endif
