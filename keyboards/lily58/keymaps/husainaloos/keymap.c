#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

enum layer_number {
  _QWERTY = 0,
  _L1,
  _NAVIG,
  _WINCT,
  _ADJUST,
  _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ESCAPE|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    | ENT   |------+------+------+------+------+------|
 * |ADJUST|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \ Shft \-----------------------------------------'
 *                   | GUI  | ALT  | L1   | /Space  /       \Backsp\  | CTRL | ALT  | MEH  |
 *                   |      |      |      |/       /         \      \ | ENTR |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,      KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,      KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,           KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  _______,     KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,           KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  MO(_ADJUST), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    _______, KC_ENT,          KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                KC_LGUI, KC_LALT, MO(_L1), KC_SPC,  RSFT_T(KC_BSPC), RCTL_T(KC_ENT), KC_RALT, KC_MEH
),
/* L1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  {   |  }   |  F6  |                    |  F7  |  F8  |  =   |  +   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | NAVIG|      |  (   |  )   |WINCT |-------.    ,-------| LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | MOUSE|  |   |  [   |  ]   |      |-------|    |-------|      |PG_DWN|PG_UP |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_L1] = LAYOUT(
  KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______,    _______, KC_LCBR, KC_RCBR, KC_F6,                     KC_F7,   KC_F8,   KC_EQL,  KC_PLUS, _______, _______,
  _______, TO(_NAVIG), _______, KC_LPRN, KC_RPRN, MO(_WINCT),                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, TO(_MOUSE), KC_PIPE, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______
),
/* NAVIG
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      |BUT_L |BUT_R |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | ACL0 | ACL1 | ACL2 |      |-------.    ,-------| M_L  | M_D  | M_UP | M_RT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |QWERTY|      |W_LEFT|W_UP  |W_DOWN|W_RIGH|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAVIG] = LAYOUT(
  XXXXXXX,     _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX,     XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  XXXXXXX,     XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  TO(_QWERTY), XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______,_______
),
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| ENTER |    |       |------+------+------+------+------+------|
 * |QWERTY| UNDO | CUT  | COPY | PASTE|      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MOUSE] = LAYOUT(
  _______,     _______, _______, _______, _______,  _______,                   _______, _______, _______, _______, _______, _______,
  _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  TO(_QWERTY), KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, KC_ENT,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______,  _______, _______, _______, _______, _______,_______
),
/* WINCT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |CENTER|FULL  |FULL-V|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |H-THIR|H-TWOT|H-HALF|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |      |-------|    |-------|      |VHALFU|VHALFD|      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_WINCT] = LAYOUT(
  _______,     _______, _______, _______, _______,  _______,                   _______, _______,    _______,      _______,      _______, _______,
  _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                   XXXXXXX, LCA(KC_C),  LCA(KC_ENT),  MEH(KC_UP),   XXXXXXX, XXXXXXX,
  _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                   XXXXXXX, LCA(KC_D),  LCA(KC_T),    LCA(KC_LEFT), XXXXXXX, XXXXXXX,
  TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______, XXXXXXX, LCA(KC_UP), LCA(KC_DOWN), XXXXXXX,      XXXXXXX, XXXXXXX,
                                 _______, _______,  _______, _______, _______, _______, _______,     _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |DM_REC|DM_STP|DM_PLY|      |      |                    |      |      |      |      |      |RESET |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | SLEEP| WAKE |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|MUTE  |V_DOWN|V_UP  |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |POWER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, DM_REC1, DM_RSTP, DM_PLY1, XXXXXXX, XXXXXXX,                   XXXXXXX,    XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, RESET,
  XXXXXXX, KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,    XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, KC_SYSTEM_POWER,
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
    return OLED_ROTATION_270;
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
    snprintf(layer_state_str, sizeof(layer_state_str), "QWERT");
    break;
  case _L1:
    snprintf(layer_state_str, sizeof(layer_state_str), "L1");
    break;
  case _NAVIG:
    snprintf(layer_state_str, sizeof(layer_state_str), "NAVIG");
    break;
  case _MOUSE:
    snprintf(layer_state_str, sizeof(layer_state_str), "MOUSE");
    break;
  case _WINCT:
    snprintf(layer_state_str, sizeof(layer_state_str), "WINCT");
    break;
  case _ADJUST:
    snprintf(layer_state_str, sizeof(layer_state_str), "ADJUST");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "UNKNWN");
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
