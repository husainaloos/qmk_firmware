#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

enum layer_number {
  _QWERTY = 0,
  _L2,
  _ARROW,
  _NAVIG,
  _MOUSE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ADJUST|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Backsp|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| ARROW |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \ Shft \-----------------------------------------'
 *                   | LAlt | GUI  | L2   | /Space  /       \ESCAPE\  | CTRL | ALT  | ENT  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  MO(_ADJUST), KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,      KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_BSPC,     KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  _______,     KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_ARROW), _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  KC_LALT, KC_LGUI, TT(_L2), KC_SPC, RSFT_T(KC_ESC), KC_RCTL, KC_RALT, KC_ENT
),
/* L2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |GUITAB|  F6  |                    |  F7  |  F8  |   [  |  ]   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  &   |      |      | BSPC |   %  |-------.    ,-------|      | ENT  |   (  |  )   |  =   |      |
 * |------+------+------+------+------+------| NAVIG |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |   {  |  }   |      |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_L2] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, LGUI(KC_TAB), KC_F6,                        KC_F7,   KC_F8,   KC_LBRC, KC_RBRC, KC_PLUS, _______,
  _______, KC_AMPR, _______, _______, KC_BSPC,      KC_PERC,                      _______, KC_ENT,  KC_LPRN, KC_RPRN, KC_EQUAL,_______,
  _______, _______, _______, _______, _______,      _______, TO(_NAVIG), _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_BSLS,
                             _______, _______,      _______, _______,    _______, _______, _______, _______
),
/* ARROW
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QWERTY|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_ARROW] = LAYOUT(
  TO(_QWERTY), _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______,_______
),
/* NAVIG
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QWERTY|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      |W_UP  |      |      |                    |      |BUT_L |BUT_R |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | ACL0 | ACL1 | ACL2 |      |-------.    ,-------| M_L  | M_D  | M_UP | M_RT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |W_DOWN|      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAVIG] = LAYOUT(
  TO(_QWERTY), _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX,     XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, _______,
  XXXXXXX,     XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX,     XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______,_______
),
/* MOUSE //TBD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QWERTY|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      |W_UP  |      |      |                    |      |BUT_L |BUT_R |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | ACL0 | ACL1 | ACL2 |      |-------.    ,-------| M_L  | M_D  | M_UP | M_RT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |W_DOWN|      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MOUSE] = LAYOUT(
  TO(_QWERTY), _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX,     XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, _______,
  XXXXXXX,     XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX,     XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______,_______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | SLEEP| WAKE |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|MUTE  |V_DOWN|V_UP  |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,    XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,    XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______,    _______,           XXXXXXX
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_left())
    return OLED_ROTATION_180;
  return OLED_ROTATION_0;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
void set_timelog(void);
const char *read_timelog(void);

char layer_state_str[24];

const char *read_layer_indicator(void) {
  switch (get_highest_layer(layer_state))
  {
  case _QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default (%d)", get_highest_layer(layer_state));
    break;
  case _L2:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: L2 (%d)", get_highest_layer(layer_state));
    break;
  case _ARROW:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ARROW (%d)", get_highest_layer(layer_state));
    break;
  case _NAVIG:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: NAVIG (%d)", get_highest_layer(layer_state));
    break;
  case _ADJUST:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST (%d)", get_highest_layer(layer_state));
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: UNKNOWN-%d", get_highest_layer(layer_state));
  }

  return layer_state_str;
}
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_indicator(), false);
    oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_timelog();
  }
  return true;
}
