BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
RAW_ENABLE = yes
OLED_ENABLE = no
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes
MAGIC_ENABLE = no
GRAVE_ESC_ENABLE = no

BOOTLOADER = qmk-dfu
SPLIT_TRANSPORT = mirror

OPT_DEFS += -DPRO_MICRO
COMBO_ENABLE=no

OS_DETECTION_ENABLE ?= yes
ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
    DEFERRED_EXEC_ENABLE = yes
endif

ifeq ($(strip $(THUMBSTICK_ENABLE)), yes)
    POINTING_DEVICE_ENABLE = yes
    OPT_DEFS += -DTHUMBSTICK_ENABLE
	SRC += analog.c
	SRC += thumbstick.c
endif
