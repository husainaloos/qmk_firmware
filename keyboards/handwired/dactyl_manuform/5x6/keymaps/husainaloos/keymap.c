#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _L1 1
#define _L2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_5x6(
		KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,   KC_6,	KC_7,		KC_8,		KC_9,		KC_0,		KC_BSPC,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,	KC_Y,	KC_U,		KC_I,		KC_O,		KC_P,		KC_MINS,
		KC_GRV,		SFT_T(KC_A),	ALT_T(KC_S),	GUI_T(KC_D),	CTL_T(KC_F),	KC_G,	KC_H,	CTL_T(KC_J),	GUI_T(KC_K),	ALT_T(KC_L),	SFT_T(KC_SCLN),	KC_QUOT,
		KC_ENT,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,	KC_N,	KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_BSLASH,
		_______,	_______,	KC_PLUS,	KC_EQL,
		MO(_L1),	KC_SPC,		LSFT_T(KC_ENT),	MO(_L2),
		KC_RCTL,	KC_LALT,	GUI_T(KC_TAB),	LCA_T(KC_TAB),
		TO(_L1),	KC_HYPR,	KC_ESC,		KC_LALT
		),
	[_L1] = LAYOUT_5x6(
		KC_F12,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
		_______,	_______,	LCA(KC_LEFT),	KC_MS_UP,	LCA(KC_RIGHT),	_______,	KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,	LCA(KC_D),	_______,
		_______,	G(KC_A),	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	_______,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,	_______,	_______,
		QK_BOOT,	G(KC_Z),	G(KC_X),	G(KC_C),	G(KC_V),	KC_VOLD,	KC_VOLU,	KC_BTN1,	KC_BTN2,	_______,	LCA(KC_ENT),	_______,
		_______,	LCA(KC_C),	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		TO(_QWERTY),	_______,	_______,	_______
		),
	[_L2] = LAYOUT_5x6(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	KC_AMPR,	KC_ASTR,	_______,	KC_LCBR,	KC_RCBR,	KC_7,		KC_8,		KC_9,		_______,	_______,
		_______,	KC_EQL,		KC_DLR,		KC_PERC,	KC_CIRC,	KC_LPRN,	KC_RPRN,	KC_4,		KC_5,		KC_6,		KC_PLUS,	_______,
		_______,	_______,	KC_EXLM,	KC_AT,		KC_HASH,	KC_LBRC,	KC_RBRC,	KC_1,		KC_2,		KC_3,		_______,	_______,
		_______,	_______,	_______,	_______,
		KC_0,		_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______
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

/* Local Variables: */
/* eval: (c-set-style "linux") */
/* eval: (indent-tabs-mode 1) */
/* compile-command: "qmk compile --keyboard handwired/dactyl_manuform/5x6 --keymap husainaloos" */
/* End: */
