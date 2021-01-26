#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7305
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         Enjoy
#define DESCRIPTION     Pro Micro driven 40% with a joystick

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { D1, C6, B4, B3, B1, E6, D4, D0 }
#define MATRIX_COL_PINS { D2, D3, D7, B5, F6, F7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set to 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#define PREVENT_STUCK_MODIFIERS
#define TAP_CODE_DELAY 100

/* key combination for command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* number of backlight levels */
#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#define BACKLIGHT_ON_STATE 1

#define JOYSTICK_BUTTON_COUNT 1
#define JOYSTICK_AXES_COUNT 2

#endif