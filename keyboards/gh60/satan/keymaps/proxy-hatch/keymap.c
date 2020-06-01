#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  BASE_LAYER,
  FUNCTIONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default Layer
 * ,-----------------------------------------------------------.
 * |Esc/~|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
 * |-----------------------------------------------------------|
 * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Return  |
 * |-----------------------------------------------------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|Fn2|Shift     |
 * |-----------------------------------------------------------|
 * |Ctrl|Gui |Alt |      Space             |Alt |Fn4 |Fn4 |Fn1 |
 * `-----------------------------------------------------------'
 KC_GESC:
 */
  [BASE_LAYER] = LAYOUT_60_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(FUNCTIONS), KC_RCTL
  ),


/* Overlay 1: Mouse/Func mode
	 * WH_UDLR: Mouse Wheel Up/Down/Left/Right
	 * BRID/U: Brightness Up/Down
	 * MNXT: Media Next Track
	 * MPRV: Media Previous Track
	 */
  [FUNCTIONS] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
    _______, KC_SLEP, KC_WH_U, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, \
    _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______, KC_STOP, KC_MPRV, KC_MPLY, KC_MNXT,          _______, \
    _______,          _______, KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, \
    KC_PSCR, KC_SLCK, KC_PAUS,                             KC_INS,                            _______, KC_HOME, KC_PGDN, KC_END
  )

/*
[FUNCTIONS] = LAYOUT_60_ansi(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, BSPC, \
        TAB, TRNS,TRNS,TRNS,TRNS,TRNS,WH_L,WH_D,WH_U,WH_R,TRNS,TRNS,TRNS,TRNS, \
        LCTL,TRNS,ACL0,ACL1,ACL2,TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,TRNS,     ENT,  \
        LSFT,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,BTN1,BTN4,BTN5,TRNS,          RSFT, \
        LCTL,LGUI,LALT,          BTN1,                    TRNS,TRNS,TRNS,RCTL),



  /'*' Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | ` |   |   |   |   |   |   |   |   |   |   |   |   | Reset |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|  BL |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   '*'/
  [_FL] = LAYOUT_60_ansi(
    KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  )
*/
};
