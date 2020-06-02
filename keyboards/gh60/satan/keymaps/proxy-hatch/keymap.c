#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  BL, // BASE_LAYER,             // 0
  FL, // FUNCTIONS_LAYER,        // 1
  KL  // KEYBOARD_CONFIG_LAYER   // 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Overlay 1: Default Layer
 * ,-----------------------------------------------------------.
 * |Esc/~|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|BSPC |
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
 * |-----------------------------------------------------------|
 * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Return  |
 * |-----------------------------------------------------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|Fn2|   up     |
 * |-----------------------------------------------------------|
 * |Ctrl|Gui |Alt |      Space             |Alt | <- | dn | -> |
 * `-----------------------------------------------------------'
 KC_GESC: Esc/
 */
  [BL] = LAYOUT_60_ansi(
    KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_UP, \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(FL), KC_LEFT, KC_DOWN, KC_RGHT
  ),

/* Overlay 1: Mouse/Func Layer
	 * WH_UDLR: Mouse Wheel Up/Down/Left/Right
	 * BRID/U: Brightness Up/Down
	 * MNXT: Media Next Track
	 * MPRV: Media Previous Track
	 */
  [FL] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
    _______, KC_SLEP, KC_WH_U, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, \
    _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______, KC_STOP, KC_MPRV, KC_MPLY, KC_MNXT,          _______, \
    _______,          _______, _______, KC_CALC, _______, _______, _______, _______, _______,  OSL(KL),  OSL(KL),          KC_PGUP, \
    KC_PSCR, KC_SLCK, KC_PAUS,                             KC_INS,                            _______, KC_HOME, KC_PGDN, KC_END
  ),

  /* Overlay 2: Keyboard Config Layer
  This layer is meant to all one shot functions: https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
   * CG_TOGG: MAGIC_TOGGLE_CTL_GUI - Toggle Control and GUI swap on both sides
   * BL_STEP: Cycle through backlight levels https://docs.qmk.fm/#/feature_backlight
   * EEP_RST: Reinitializes the keyboard’s EEPROM (persistent memory)
   * RESET: Put the keyboard into bootloader mode for flashing
   * DEBUG: Toggle debug mode

   */
  [KL] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
    _______, _______, _______, EEP_RST,   RESET, _______, _______, _______, _______, _______, BL_STEP, BL_DEC,  BL_INC,  BL_TOGG, \
    _______, _______, _______,   DEBUG, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, \
    LCG_SWP, LCG_NRM, _______,                            _______,                            _______, _______, _______, _______
  )






  /* Keymap _FL: Function Layer
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
