#include QMK_KEYBOARD_H
#include "print.h"

#define QWERTY 0 // Base qwerty
#define NUMPAD 1 // NumPad layer for QWERTY
#define PROGRAM 2 // Program layer for QWERTY

#define LAYER1 3 // NEO-like layers
#define LAYER2 4
#define LAYER3 5
#define LAYER4 6
#define LAYER5 7
#define LAYER6 8


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_NUBS,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                   KC_HOME,
                           KC_BSPC,KC_DEL ,KC_END ,

    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, DF(NUMPAD), MO(PROGRAM),
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),

[NUMPAD] = LAYOUT(
           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
                   _______,KC_INS ,_______,_______,
			   _______,_______,
                                   _______,
                           _______,_______,_______,

    _______,KC_MPRV,KC_MPLY,KC_MNXT,KC__MUTE,KC__VOLDOWN,KC__VOLUP, DF(QWERTY), MO(PROGRAM),
	_______,KC_NLCK,KC_PEQL,KC_PEQL,KC_PAST,_______,
	_______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PMNS,_______,
	_______,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
	_______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PENT,_______,
		_______,_______,KC_PDOT,KC_PENT,
           _______,_______,
           _______,
           _______,_______,KC_P0
    ),

[PROGRAM] = LAYOUT(
           _______,_______,DF(LAYER1),_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
                   _______,_______,_______,_______,
			   _______,_______,
                                   _______,
                           _______,_______,_______,

    RESET,KC_MPRV,KC_MPLY,KC_MNXT,KC__MUTE,KC__VOLDOWN,KC__VOLUP,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,
           _______,_______,
           _______,
           _______,_______,_______
    ),

[LAYER1] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_GRV, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_X   ,KC_V   ,KC_L   ,KC_C   ,KC_W   ,
           MO(LAYER3),KC_U ,KC_I  ,KC_A   ,KC_E   ,KC_O   ,
           LM(LAYER2,MOD_LSFT), UC(0xFC), UC(0xF6), UC(0xE4), KC_P, KC_Z,
                   LSFT(KC_6) ,MO(LAYER4),KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                   KC_HOME,
                           KC_BSPC,KC_DEL ,KC_END ,

    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_RALT, MO(LAYER4),
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	 KC_K, KC_H, KC_G, KC_F, KC_Q, MO(LAYER3),
	KC_S, KC_N, KC_R, KC_T, KC_D, KC_Y,
	 KC_B, KC_M, KC_COMM, KC_DOT, KC_J, LM(LAYER2,MOD_LSFT),
		KC_UP  ,KC_DOWN,UC(0xDF),KC_QUOT,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),

[LAYER2] = LAYOUT(
           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           UC(0x327), UC(0xB0), UC(0xA7),UC(0x2113),UC(0xBB),UC(0xAB),
           _______,   _______,  _______, _______,   _______, _______,
           MO(LAYER5),_______,  _______, _______,   _______, _______,
           KC_CAPS,   UC(0xDC), UC(0xD6),UC(0xC4),  _______, _______,
                      UC(0x30C),XXXXXXX, _______,   _______,
			   _______,_______,
                                   _______,
                           _______,_______,_______,

    _______,_______,_______,_______,_______,_______,_______,_______,XXXXXXX,
	KC_DLR, UC(0x20AC), UC(0x201E), UC(0x201C), UC(0x201D),UC(0x2014),
	 _______,_______,_______,_______,_______, MO(LAYER5),
	 _______,_______,_______,_______,_______,_______,
	 _______,_______, UC(0x2013), UC(0x2022),_______, KC_CAPS,
		_______,_______,UC(0x1E9E),KC_GRAVE,
           _______,_______,
           _______,
           _______,_______,_______
    ),

[LAYER3] = LAYOUT(
           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           UC(0x30A), UC(0xB9), UC(0xB2), UC(0xB3), UC(0x203A), UC(0x2039),
           KC_TAB, UC(0x2026), KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,
           XXXXXXX, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR,
           MO(LAYER5), KC_HASH, KC_DLR, KC_PIPE, KC_TILD, KC_GRV,
                   XXXXXXX ,MO(LAYER6),KC_LEFT,KC_RGHT,
			   _______,_______,
                                   _______,
                           _______,_______,_______,

    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, _______, MO(LAYER6),
	UC(0xA2), UC(0xA5), UC(0x201A), UC(0x2018), UC(0x2019), XXXXXXX,
	 KC_EXLM, KC_LT, KC_GT, KC_EQL, KC_AMPR, XXXXXXX,
	 KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT,
	 KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, MO(LAYER5),
		KC_UP  ,KC_DOWN, UC(0x17F),UC(0x338),
           _______,_______,
           _______,
           _______,_______,_______
    ),

[LAYER4] = LAYOUT(
           _______,_______,_______,DF(QWERTY),UC_M_WI,UC_M_MA,UC_M_LN,UC_M_WC,_______,
           UC(0x308),_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
                   UC(0x307),_______,_______,_______,
			   _______,_______,
                                   _______,
                           _______,_______,_______,

    RESET,KC_MPRV,KC_MPLY,KC_MNXT,KC__MUTE,KC__VOLDOWN,KC__VOLUP,_______,_______,
	_______,_______,_______,KC_PSLS,KC_PAST,KC_PMNS,
	_______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,_______,
	_______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PDOT,_______,
	_______,KC_KP_1,KC_KP_2,KC_KP_3,_______,_______,
		_______,_______,_______,UC(0x30B),
           _______,_______,
           _______,
           _______,_______,KC_KP_0
    ),

[LAYER5] = LAYOUT(
           _______,_______,_______,DF(QWERTY),UC_M_WI,UC_M_MA,UC_M_LN,UC_M_WC,_______,
           UC(0x308),_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
                   UC(0x307),_______,_______,_______,
			   _______,_______,
                                   _______,
                           _______,_______,_______,

    RESET,KC_MPRV,KC_MPLY,KC_MNXT,KC__MUTE,KC__VOLDOWN,KC__VOLUP,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
		_______,_______,_______,UC(0x30B),
           _______,_______,
           _______,
           _______,_______,_______
    )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  printf("layer_state_set_user running\n");
  switch (get_highest_layer(state)) {
    case NUMPAD:
      writePin(C3, 0);
      break;
    default:
      writePin(C3, 1);
      break;
  }
  return state;
}

void led_set_user(uint8_t usb_led) {
  
}

bool led_update_user(led_t led_state) {
  writePin(C4, !led_state.scroll_lock);
  writePin(C5, !led_state.num_lock);
  writePin(C1, !led_state.caps_lock);
  return false;
}