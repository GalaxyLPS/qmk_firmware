#include QMK_KEYBOARD_H
#include "keymap_german.h"
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif
// ==================== LAYER DEFINITION ====================
enum layer_names {
    _BASE = 0,
    _UPPER,
    _SYMBOL,
    _NAV,
    _CONTROL,
    _ALT,
    _FUNCTION,
    _ADJUST,
    _LAYER_COUNT
};

// ==================== CUSTOM KEYCODES ====================
enum custom_keycodes {
    RGB_NXT,
    RGB_PRV
};

// ==================== RGB KONFIGURATION ====================
const HSV layer_colors[] = {
    [_BASE]    = {170, 255, 150},  // Blau
    [_UPPER]   = {30,  255, 150},  // Gold
    [_SYMBOL]  = {213, 255, 150},  // Lila
    [_NAV]     = {85,  255, 150},  // Grün
    [_CONTROL] = {0,   200, 200},  // Orange
    [_ALT]     = {180, 255, 150},  // Türkis
    [_FUNCTION]= {240, 255, 150},  // Pink
    [_ADJUST]  = {0,   255, 200}   // Rot
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_DEFAULT_MODE);
    rgblight_sethsv_noeeprom(layer_colors[_BASE].h, layer_colors[_BASE].s, layer_colors[_BASE].v);

    if (!host_keyboard_led_state().num_lock) {
        tap_code(KC_NUM_LOCK);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    rgblight_sethsv_noeeprom(layer_colors[layer].h, layer_colors[layer].s, layer_colors[layer].v);
    return state;
}

// ==================== TASTENBELEGUNG ====================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer (Noted Layout) */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_J,    DE_Z,    DE_Y,    KC_U,    KC_A,    KC_Q,                         KC_P,    KC_B,    KC_M,    KC_L,    KC_F,    DE_SS,
        MO(_UPPER), KC_C,    KC_S,    KC_I,    KC_E,    KC_O,                         KC_D,    KC_T,    KC_N,    KC_R,    KC_H,    MO(_UPPER),
        MO(_SYMBOL), KC_V,    KC_X,    DE_UDIA, DE_ADIA, DE_ODIA,                      KC_W,    KC_G,    KC_COMM, KC_DOT,  KC_K,    MO(_SYMBOL),


                                 MO(_NAV), MO(_CONTROL), KC_SPC,                                         KC_ENT,  MO(_ALT), OSL(_ADJUST)
    ),

    /* Upper Layer (Shifted Keys) */
    [_UPPER] = LAYOUT_split_3x6_3(
        LSFT(KC_J), LSFT(DE_Z), LSFT(DE_Y), LSFT(KC_U), LSFT(KC_A), LSFT(KC_Q),    LSFT(KC_P), LSFT(KC_B), LSFT(KC_M), LSFT(KC_L), LSFT(KC_F), LSFT(DE_SS),

        _______,    LSFT(KC_C), LSFT(KC_S), LSFT(KC_I), LSFT(KC_E), LSFT(KC_O),    LSFT(KC_D), LSFT(KC_T), LSFT(KC_N), LSFT(KC_R), LSFT(KC_H), _______,


        _______,    LSFT(KC_V), LSFT(KC_X), LSFT(DE_UDIA), LSFT(DE_ADIA), LSFT(DE_ODIA), LSFT(KC_W), LSFT(KC_G), KC_SCLN, KC_COLN, LSFT(KC_K), _______,


        _______, KC_LCTL, LSFT(KC_SPC),                         LSFT(KC_ENT), _______, _______
    ),

    /* Symbol Layer */
    [_SYMBOL] = LAYOUT_split_3x6_3(
        _______, DE_EURO, DE_CIRC, DE_LBRC, DE_RBRC, DE_UNDS,                      DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR, DE_AT,
        KC_LSFT, ALGR(DE_SS), DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                      DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, _______,
        _______, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV,                        DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, KC_RSFT,
        _______, KC_LCTL, _______,                                                    _______, KC_LALT, _______
    ),

    /* Navigation Layer */
    [_NAV] = LAYOUT_split_3x6_3(
        _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,                        KC_LGUI, _______, _______, _______, _______, _______,
        KC_PSCR, _______, KC_P4,   KC_P5,   KC_P6,   KC_DEL,                       KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT,
        KC_LSFT, _______, KC_P1,   KC_P2,   KC_P3,   KC_NUM,                      KC_END, _______, _______, _______, _______, _______,
        _______, KC_LCTL, KC_TAB,                                                 KC_ESC,  KC_LALT,  _______
    ),

    /* Control Layer */
    [_CONTROL] = LAYOUT_split_3x6_3(
        C(KC_J), C(DE_Z), C(DE_Y), C(KC_U), C(KC_A), C(KC_Q),                     C(KC_P), C(KC_B), C(KC_M), C(KC_L), C(KC_F), C(DE_SS),
        KC_LSFT, C(KC_C), C(KC_S), C(KC_I), C(KC_E), C(KC_O),                     C(KC_D), C(KC_T), C(KC_N), C(KC_R), C(KC_H), KC_RSFT,
        _______, C(KC_V), C(KC_X), C(DE_UDIA), C(DE_ADIA), C(DE_ODIA),              C(KC_W), C(KC_G), C(KC_COMM), C(KC_DOT), C(KC_K), _______,
        _______, KC_LCTL, _______,                                                     _______, _______, _______
    ),

    /* Alt Layer */
    [_ALT] = LAYOUT_split_3x6_3(
        A(KC_J), A(DE_Z), A(DE_Y), A(KC_U), A(KC_A), A(KC_Q),                     A(KC_P), A(KC_B), A(KC_M), A(KC_L), A(KC_F), A(DE_SS),
        KC_LSFT, A(KC_C), A(KC_S), A(KC_I), A(KC_E), A(KC_O),                     A(KC_D), A(KC_T), A(KC_N), A(KC_R), A(KC_H), KC_RSFT,
        _______, A(KC_V), A(KC_X), A(DE_UDIA), A(DE_ADIA), A(DE_ODIA),              A(KC_W), A(KC_G), A(KC_COMM), A(KC_DOT), A(KC_K), OSL(_FUNCTION),
        _______, KC_LCTL, _______,                                                 _______, _______, _______
    ),

    /* Function Layer (RGB Control + Media) */
    [_FUNCTION] = LAYOUT_split_3x6_3(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______,                     _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, _______,                     _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                                                 _______, _______, _______
    ),

    /* Adjust Layer (One-Shot für RGB/Media) */
    [_ADJUST] = LAYOUT_split_3x6_3(
        QK_BOOT, QK_RBT, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        UG_TOGG, UG_NEXT, UG_HUEU, UG_SATD, UG_VALU, UG_SPDU,                     _______, _______, _______, _______, _______, _______,
        _______, UG_PREV, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,                     _______, _______, _______, _______, _______, _______,
        _______,_______, _______,                                                     _______, _______, _______
    )
};

// ==================== ENCODER ====================
#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _ADJUST:
            if (clockwise) {
                rgblight_increase_hue_noeeprom();
            } else {
                rgblight_decrease_hue_noeeprom();
            }
            break;
        case _CONTROL:
            if (clockwise) {
                tap_code16(C(KC_RGHT));  // Strg + →
            } else {
                tap_code16(C(KC_LEFT));  // Strg + ←
            }
            break;
        default:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
    }
    return true;
}
#endif

// ==================== KEYCODE HANDLING ====================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case RGB_NXT:
                rgblight_step_noeeprom();
                return false;
            case RGB_PRV:
                rgblight_step_reverse_noeeprom();
                return false;


        }
    }
    return true;
}
