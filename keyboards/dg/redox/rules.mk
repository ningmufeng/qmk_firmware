# MCU name
MCU = atmega32u4

# Bootloader selection
#   Atmel DFU    atmel-dfu
#   Pro Micro    caterina
#   QMK DFU      qmk-dfu
BOOTLOADER = caterina

# Build Options
BOOTMAGIC_ENABLE = no   # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes   # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
CONSOLE_ENABLE = no     # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE = no   # Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
NKRO_ENABLE = yes       # USB Nkey Rollover. See <https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work> if doesn't work.
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no        # MIDI support
UNICODE_ENABLE = no     # Unicode
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no       # Audio output on port C6
FAUXCLICKY_ENABLE = no  # Use buzzer to emulate clicky switches
RGBLIGHT_ENABLE = yes   # Enable WS2812 RGB underlight. 
SPLIT_KEYBOARD = yes
