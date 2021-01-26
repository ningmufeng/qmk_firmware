#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7304
#define DEVICE_VER      0x0002
#define MANUFACTURER    Leo Deng
#define PRODUCT         Plancky
#define DESCRIPTION     Pro Micro driven 40% ortholinear layout keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D7, E6, B3 }
#define MATRIX_COL_PINS { D2, C6, D4, D0, D1, B6, B2, F4, F5, F6, F7, B1 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* number of backlight levels */
#define BACKLIGHT_PIN B5
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#define BACKLIGHT_ON_STATE 1

#endif