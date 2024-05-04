#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layer_names {
    _NOTED,         // default layer, default german alphabet
    _NOTED_UPPER,   // layer for upper case letters
    _NOTED_CONTROL, // layer for changing default layer, and going to deeper layers
    _NOTED_ALT,
    _NOTED_SPECIAL_CHARS, // special chars layer for programming, email etc. etc.
    _NOTED_NAVIGATION,    // navigation layer
    _NOTED_ONESHOT,       // layer for controlling media, and other lesser used stuff
};
/*
unicode has to be enabled on the keyboard and the operating system

enum unicode_names {
    DE_LAE,
    DE_LOE,
    DE_LUE,
    DE_UOE,
    DE_UAE,
    DE_UUE,
    DE_SSS,
    DE_USS,
};

const uint32_t PROGMEM unicode_map[] = {
    [DE_LAE] = 0x00E4, // ä
    [DE_LOE] = 0x00F6, // ö
    [DE_LUE] = 0x00FC, // ü
    [DE_UOE] = 0x00D6, // Ö
    [DE_UAE] = 0x00C4, // Ä
    [DE_UUE] = 0x00DC, // Ü
    [DE_SSS] = 0x00DF, // ß
    [DE_USS] = 0x1E9E, // ẞ
};
*/

// SHIFT, STRG, ALT, SUPER,

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NOTED] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_J, DE_Z, DE_Y, KC_U, KC_A, KC_Q, /* | */ KC_P, KC_B, KC_M, KC_L, KC_F, DE_SS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        MO(_NOTED_UPPER), KC_C, KC_S, KC_I, KC_E, KC_O, /* | */ KC_D, KC_T, KC_N, KC_R, KC_H, MO(_NOTED_UPPER),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        MO(_NOTED_SPECIAL_CHARS), KC_V, KC_X, DE_UDIA, DE_ADIA, DE_ODIA, /* | */ KC_W, KC_G, KC_COMM, KC_DOT, KC_K, MO(_NOTED_SPECIAL_CHARS),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        MO(_NOTED_NAVIGATION), MO(_NOTED_CONTROL), KC_SPC, /* | */ KC_ENT, MO(_NOTED_ALT), OSL(_NOTED_ONESHOT)
        //`--------------------------'  `--------------------------'
        ),
    [_NOTED_UPPER] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        S(KC_J), S(DE_Z), S(DE_Y), S(KC_U), S(KC_A), S(KC_Q), /* | */ S(KC_P), S(KC_B), S(KC_M), S(KC_L), S(KC_F), S(DE_SS),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|ß
        KC_TRNS, S(KC_C), S(KC_S), S(KC_I), S(KC_E), /* | */ S(KC_O), S(KC_D), S(KC_T), S(KC_N), S(KC_R), S(KC_H), KC_TRNS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, S(KC_V), S(KC_X), S(DE_UDIA), S(DE_ADIA), S(DE_ODIA), /* | */ S(KC_W), S(KC_G), S(KC_COMM), S(KC_DOT), S(KC_K), KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LCTL, S(KC_SPC), /* | */ S(KC_ENT), KC_LALT, KC_NO

        //`--------------------------'  `--------------------------'
        ),
    [_NOTED_SPECIAL_CHARS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, DE_EURO, DE_CIRC, DE_LBRC, DE_RBRC, DE_UNDS, /* | */ DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR, DE_AT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, ALGR(DE_SS), DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, /* | */ DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, KC_F18,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TRNS, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV, /* | */ DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_TRNS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LCTL, KC_LSFT, /* | */ KC_NO, KC_LALT, KC_NO
        //`--------------------------'  `--------------------------'
        ),
    [_NOTED_NAVIGATION] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_P0, /* | */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_PSCR, KC_NO, KC_P4, KC_P5, KC_P6, KC_DEL, /* | */ KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO, /* | */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_LALT,  KC_TAB, /* | */ KC_ESC, KC_END, KC_NO
        //`--------------------------'  `--------------------------'
        ),
    [_NOTED_CONTROL] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        C(KC_J), C(DE_Z), C(DE_Y), C(KC_U), C(KC_A), C(KC_Q), /* | */ C(KC_P), C(KC_B), C(KC_M), C(KC_L), C(KC_F), C(DE_SS),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|ß
        KC_LSFT, C(KC_C), C(KC_S), C(KC_I), C(KC_E), /* | */ C(KC_O), C(KC_D), C(KC_T), C(KC_N), C(KC_R), C(KC_H), KC_LSFT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, C(KC_V), C(KC_X), C(DE_UDIA), C(DE_ADIA), C(DE_ODIA), /* | */ C(KC_W), C(KC_G), C(KC_COMM), C(KC_DOT), C(KC_K), KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_NO, KC_TRNS, S(KC_TAB), /* | */ C(KC_ENT), KC_LALT, KC_NO
        //`--------------------------'  `--------------------------'
),
    [_NOTED_ALT] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        A(KC_J), A(DE_Z), A(DE_Y), A(KC_U), A(KC_A), A(KC_Q), /* | */ A(KC_P), A(KC_B), A(KC_M), A(KC_L), A(KC_F), A(DE_SS),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|ß
        KC_LSFT, A(KC_C), A(KC_S), A(KC_I), A(KC_E), /* | */ A(KC_O), A(KC_D), A(KC_T), A(KC_N), A(KC_R), A(KC_H), KC_LSFT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, A(KC_V), A(KC_X), A(DE_UDIA), A(DE_ADIA), A(DE_ODIA), /* | */ A(KC_W), A(KC_G), A(KC_COMM), A(KC_DOT), A(KC_K), KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LCTL, KC_NO, /* | */ KC_NO, KC_TRNS, KC_NO
        //`--------------------------'  `--------------------------'
        ),
    [_NOTED_ONESHOT] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NUM, RGB_TOG, QK_BOOT, QK_REBOOT, QK_BACKLIGHT_TOGGLE, KC_NO, /* | */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* | */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* | */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_NO, KC_NO, KC_NO, /* | */ KC_NO, KC_NO, KC_NO
        //`--------------------------'  `--------------------------'
        )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

void numlock_on(void) {
    led_t led_state = host_keyboard_led_state();
    bool  b         = led_state.num_lock;
    if (!b) {
        register_code(KC_NUM_LOCK);
        unregister_code(KC_NUM_LOCK);
    }
}

void keyboard_post_init_user() {
    numlock_on();
    debug_enable = true;
    debug_matrix=true;

}