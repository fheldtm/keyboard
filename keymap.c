// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _MAC,
    _LOWER,
    _WIN,
    _WIN_LOWER,
};

enum custom_keycodes {
    KC_MAC = QK_USER,
    KC_LOWER,
    KC_WIN,
    KC_WIN_LOWER
};

// double keycode.(Custom Shifting)
// enum td_keycodes {
//     CSFT_Q, CSFT_W, CSFT_E, CSFT_R, CSFT_T,
//     CSFT_O, CSFT_P
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * MAC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LGUI |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MAC  |    |  WIN  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTRL| LAlt | LCTR |SPACE | /RAISE  /       \LOWER \  |ENTER | RGUI | RAlt | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MAC] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSLS,
  KC_LGUI,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MAC,      KC_WIN, KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
               KC_LCTL, KC_LALT, KC_LCTL, KC_SPC, MO(_LOWER),      MO(_LOWER), KC_ENT,  KC_RGUI, KC_RALT,  KC_RCTL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   \  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         _______, _______, _______, _______,  _______, _______,
  KC_LGUI, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  KC_LSFT, KC_UNDS, KC_EQL,  KC_MINS, KC_PLUS, _______, _______,       _______, _______, _______, _______, _______,  _______, _______,
                     KC_LCTL, KC_LALT, KC_LCTL, KC_SPC, _______,       _______,  KC_ENT, KC_RGUI, KC_RALT, KC_RCTL
),

/*
 * WIN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MAC  |    |  WIN  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SPACE | /RAISE  /       \LOWER \  |ENTER | RGUI | RAlt | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_WIN] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MAC,     KC_WIN, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
               KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,MO(_WIN_LOWER),MO(_WIN_LOWER),KC_ENT, KC_RALT, KC_RCTL, KC_RCTL
),

/* WIN_LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCRTL|   (  |   )  |   {  |   }  |   %  |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|   )  |   \  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_WIN_LOWER] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         _______, _______, _______, _______,  _______, _______,
  KC_LCTL, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  KC_LSFT, KC_UNDS, KC_EQL,  KC_MINS, KC_PLUS, _______, _______,       _______, _______, _______, _______, _______,  _______, _______,
                    KC_LCTL, KC_LALT, KC_LCTL, KC_SPC, _______,       _______,  KC_ENT, KC_RALT, KC_RCTL, KC_RCTL
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
        case KC_WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
    }
    return true;
};

/**
 * COMBO
 */
enum combo_events {
    ESC_COMBO,

    BRACKET_COMBO_1,
    BRACKET_COMBO_2,
    BRACKET_COMBO_3,

    F11_COMBO,
    F12_COMBO,

    CIRCLE_NUMBER_COMBO_1,
    CIRCLE_NUMBER_COMBO_2,
    CIRCLE_NUMBER_COMBO_3,
    CIRCLE_NUMBER_COMBO_4,
    CIRCLE_NUMBER_COMBO_5,
    CIRCLE_NUMBER_COMBO_6,
    CIRCLE_NUMBER_COMBO_7,
    CIRCLE_NUMBER_COMBO_8,
    CIRCLE_NUMBER_COMBO_9,
};

const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM bracket_combo_1[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM bracket_combo_2[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM bracket_combo_3[] = {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM f11_combo[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM f12_combo[] = {KC_F2, KC_F3, COMBO_END};

combo_t key_combos[] = {
    [ESC_COMBO] = COMBO_ACTION(esc_combo),

    [BRACKET_COMBO_1] = COMBO_ACTION(bracket_combo_1),
    [BRACKET_COMBO_2] = COMBO_ACTION(bracket_combo_2),
    [BRACKET_COMBO_3] = COMBO_ACTION(bracket_combo_3),

    [F11_COMBO] = COMBO_ACTION(f11_combo),
    [F12_COMBO] = COMBO_ACTION(f12_combo),
};
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case ESC_COMBO:
            if (pressed) {
                tap_code16(KC_ESC);
            }
            break;

        case BRACKET_COMBO_1:
            if (pressed) {
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
                tap_code16(KC_LEFT);
            }
            break;
        case BRACKET_COMBO_2:
            if (pressed) {
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
                tap_code16(KC_LEFT);
            }
            break;
        case BRACKET_COMBO_3:
            if (pressed) {
                tap_code16(KC_LBRC);
                tap_code16(KC_RBRC);
                tap_code16(KC_LEFT);
            }
            break;

        case F11_COMBO:
            if (pressed) {
                tap_code16(KC_F11);
            }
            break;
        case F12_COMBO:
            if (pressed) {
                tap_code16(KC_F12);
            }
            break;
    }
};

// Tap Dance
// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // double keycode.(Custom Shifting)
//     [CSFT_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LSFT(KC_Q)),
//     [CSFT_W] = ACTION_TAP_DANCE_DOUBLE(KC_W, LSFT(KC_W)),
//     [CSFT_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, LSFT(KC_E)),
//     [CSFT_R] = ACTION_TAP_DANCE_DOUBLE(KC_R, LSFT(KC_R)),
//     [CSFT_T] = ACTION_TAP_DANCE_DOUBLE(KC_T, LSFT(KC_T)),
//     [CSFT_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, LSFT(KC_O)),
//     [CSFT_P] = ACTION_TAP_DANCE_DOUBLE(KC_P, LSFT(KC_P))
// };