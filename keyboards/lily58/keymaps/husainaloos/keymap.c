#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define _QWERTY 0
#define _L1 1
#define _L2 2
#define _WIN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  	[_QWERTY] = LAYOUT(
		KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_BSPC,
		KC_TAB,		KC_Q,		LT(_WIN,KC_W),	KC_E,		KC_R,		KC_T,		KC_Y,		ALL_T(KC_U),	KC_I,		KC_O,		KC_P,		KC_MINS,
		KC_GRV,		SFT_T(KC_A),	ALT_T(KC_S),	GUI_T(KC_D),	CTL_T(KC_F),	KC_G,		KC_H,		CTL_T(KC_J),	GUI_T(KC_K),	ALT_T(KC_L),	SFT_T(KC_SCLN),	KC_QUOT,
		KC_ENT,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		_______,	_______,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_BSLASH,
		_______,	_______,	MO(_L1),	KC_SPC,		LSFT_T(KC_ENT),	MO(_L2),	_______,	_______
		),
	[_L1]	  = LAYOUT(
		KC_F12,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
		_______,	_______,	_______,	KC_MS_UP,	_______,	_______,	KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,	_______,	_______,
		_______,	G(KC_A),	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	_______,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,	_______,	_______,
		QK_BOOT,	G(KC_Z),	G(KC_X),	G(KC_C),	G(KC_V),	KC_VOLD,	_______,	_______,	KC_VOLU,	KC_BTN1,	KC_BTN2,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
		),
	[_L2]	  = LAYOUT(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	KC_LCBR,	_______,	_______,	KC_RCBR,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_EQL,		KC_LPRN,	_______,	_______,	KC_RPRN,	KC_PLUS,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	KC_LBRC,	_______,	_______,	_______,	_______,	KC_RBRC,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
		),
	[_WIN]	  = LAYOUT(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	LCA(KC_D),	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	LCA(KC_LEFT),	LCA(KC_C),	LCA(KC_RIGHT),	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	LCA(KC_ENT),	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
		)
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
        case SFT_T(KC_ENT):
		// Force the dual-role key press to be handled as a modifier if any
		// other key was pressed while the mod-tap key is held down.
		return true;
        default:
		// Do not force the mod-tap key press to be handled as a modifier
		// if any other key was pressed while the mod-tap key is held down.
		return false;
	}
}

layer_state_t layer_state_set_user(layer_state_t state)
{
	return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	if (!is_keyboard_left())
		return OLED_ROTATION_270;
	return OLED_ROTATION_0;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
void set_timelog(void);
const char *read_timelog(void);

char layer_state_str[24];

const char *read_layer_indicator(void)
{
	switch (get_highest_layer(layer_state)) {
	case _QWERTY:
		snprintf(layer_state_str, sizeof(layer_state_str), "QWERT");
		break;
	case _L1:
		snprintf(layer_state_str, sizeof(layer_state_str), "L1");
		break;
	case _L2:
		snprintf(layer_state_str, sizeof(layer_state_str), "L2");
		break;
	case _WIN:
		snprintf(layer_state_str, sizeof(layer_state_str), "WIN");
		break;
	default:
		snprintf(layer_state_str, sizeof(layer_state_str), "UNKNWN");
	}

	return layer_state_str;
}

bool oled_task_user(void)
{
	if (is_keyboard_master()) {
		oled_write_ln(read_layer_indicator(), false);
		oled_write_ln(read_timelog(), false);
	} else {
		oled_write(read_logo(), false);
	}
	return false;
}
#endif				// OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t * record)
{
	if (record->event.pressed) {
		set_timelog();
	}
	return true;
}

/* Local Variables: */
/* eval: (c-set-style "linux") */
/* eval: (indent-tabs-mode 1) */
/* compile-command: "qmk flash --keyboard lily58/rev1 --keymap husainaloos" */
/* End: */
