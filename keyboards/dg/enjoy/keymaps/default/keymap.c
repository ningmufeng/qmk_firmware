#include "enjoy.h"
#include "analog.h"
#include "pointing_device.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT, 
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_CAPS, KC_UP,   KC_RSFT, 
    KC_LCTL, KC_LGUI,          KC_LALT,          KC_SPC,           MO(1),   MO(2),   KC_LEFT, KC_DOWN, KC_RGHT, 
    KC_BTN1),

  [1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, 
    KC_CAPS, KC_INS,  KC_HOME, KC_PGUP, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT,          KC_TRNS, 
    KC_TRNS,          KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_BTN1),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
    BL_BRTG, BL_DEC,  BL_INC,  BL_ON,   BL_OFF,  BL_TOGG, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,          KC_TRNS, 
    KC_TRNS,          KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_WH_D, KC_WH_U, KC_TRNS, 
    KC_TRNS, KC_TRNS,          KC_TRNS,          RESET,            KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, 
    KC_BTN1)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {}
  return MACRO_NONE;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 2); PORTB &= ~(1 << 2);
  } else {
    DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
  }
}

/*** Joystick ***/
uint8_t xPin  = F5;
uint8_t yPin  = F4;

uint16_t originAxisValue = 512;
uint16_t maxAxisValue = 1023;
uint16_t minAxisValue = 0;
uint16_t lastCursor = 0;

uint8_t precisionSpeed = 1;
uint8_t maxCursorSpeed = 2;
uint8_t speedRegulator = 20;  // Lower Values Create Faster Movement
uint8_t cursorTimeout = 10;

int8_t xPolarity = 1;
int8_t yPolarity = 1;

int16_t axisCoordinate(uint8_t pin) {
  int8_t  direction;
  int16_t distanceFromOrigin;
  int16_t range;

  int16_t position = analogReadPin(pin);

  if (originAxisValue == position) {
    return 0;
  } else if (originAxisValue > position) {
    distanceFromOrigin = originAxisValue - position;
    range              = originAxisValue - minAxisValue;
    direction          = 1;
  } else {
    distanceFromOrigin = position - originAxisValue;
    range              = maxAxisValue - originAxisValue;
    direction          = -1;
  }

  float   percent    = (float)distanceFromOrigin / range;
  int16_t coordinate = (int16_t)(percent * 100);
  if (coordinate < 0) {
    return 0;
  } else if (coordinate > 100) {
    return 100 * direction;
  } else {
    return coordinate * direction;
  }
}

int8_t axisToMouseComponent(uint8_t pin, int8_t polarity) {
  int coordinate = axisCoordinate(pin);
  if (coordinate == 0) {
    return 0;
  } else {
    float percent = (float)coordinate / 100;
    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
      return percent * precisionSpeed * polarity * (abs(coordinate) / speedRegulator);
    } else {
      return percent * maxCursorSpeed * polarity * (abs(coordinate) / speedRegulator);
    }
  }
}

void pointing_device_task(void) {
  report_mouse_t report = pointing_device_get_report();

  if (timer_elapsed(lastCursor) > cursorTimeout) {
    lastCursor = timer_read();
    report.x   = axisToMouseComponent(xPin, xPolarity);
    report.y   = axisToMouseComponent(yPin, yPolarity);
  }

  pointing_device_set_report(report);
  pointing_device_send();
}
