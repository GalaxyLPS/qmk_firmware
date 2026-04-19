#include QMK_KEYBOARD_H
#include "keymap_german.h"



#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))


// ==================== LAYER DEFINITION ====================
enum layer_names {
    _BASE = 0,
    _SPECIAL_CHARS,
    _SYMBOL,
    _NAV,
    _FUNCTION,
    _ADJUST,
    _LAYER_COUNT
};

// ==================== CUSTOM KEYCODES ====================
enum custom_keycodes {
    RGB_NXT,
    RGB_PRV
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK,

    a_GRAVE,
    a_ACUTE,
    a_CIRCUMFLEX,
    a_TILDE,
    A_GRAVE,
    A_ACUTE,
    A_CIRCUMFLEX,
    A_TILDE,

    ae,
    AE,

    c_CEDILLA,
    C_CEDILLA,

    e_GRAVE,
    e_ACUTE,
    e_CIRCUMFLEX,
    E_GRAVE,
    E_ACUTE,
    E_CIRCUMFLEX,

    i_GRAVE,
    i_ACUTE,
    i_CIRCUMFLEX,
    I_GRAVE,
    I_ACUTE,
    I_CIRCUMFLEX,
    I_TILDE,

    o_GRAVE,
    o_ACUTE,
    o_CIRCUMFLEX,
    o_TILDE,
    O_GRAVE,
    O_ACUTE,
    O_CIRCUMFLEX,
    O_TILDE,

    u_GRAVE,
    u_ACUTE,
    u_CIRCUMFLEX,
    U_GRAVE,
    U_ACUTE,
    U_CIRCUMFLEX,

    SHARP_s,
    SHARP_S,
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍


    [a_GRAVE] = 0x00E0, // à
    [a_ACUTE] = 0x00E1, // á
    [a_CIRCUMFLEX] = 0x00E2, // â
    [a_TILDE] = 0x00E3, // ã
    [A_GRAVE] = 0x00C0, // À
    [A_ACUTE] = 0x00C1, // Á
    [A_CIRCUMFLEX] = 0x00C2, // Â
    [A_TILDE] = 0x00C3, // Ã

    [ae] = 0x00E6, // æ
    [AE] = 0x00C6, // Æ


    [c_CEDILLA] = 0x00E7, // ç
    [C_CEDILLA] = 0x00C7, // Ç

    [e_GRAVE] = 0x00E8, // à
    [e_ACUTE] = 0x00E9, // é
    [e_CIRCUMFLEX] = 0x00EA, // ê
    [E_GRAVE] = 0x00C8, // È
    [E_ACUTE] = 0x00C9, // É
    [E_CIRCUMFLEX] = 0x00CA, // Ê

    [i_GRAVE] = 0x00EC, // ì
    [i_ACUTE] = 0x00ED, // í
    [i_CIRCUMFLEX] = 0x00EE, // î
    [I_GRAVE] = 0x00CC, // Ì
    [I_ACUTE] = 0x00CD, // Í
    [I_CIRCUMFLEX] = 0x00CE, // Î


    [o_GRAVE] = 0x00F2, // ò
    [o_ACUTE] = 0x00F3, // ó
    [o_CIRCUMFLEX] = 0x00F4, // ô
    [o_TILDE] = 0x00F5, // õ
    [O_GRAVE] = 0x00D2, // Ò
    [O_ACUTE] = 0x00D3, // Ó
    [O_CIRCUMFLEX] = 0x00D4, // Ô
    [O_TILDE] = 0x00D5, // Õ


    [u_GRAVE] = 0x00F9, // ù
    [u_ACUTE] = 0x00FA, // ú
    [u_CIRCUMFLEX] = 0x00FB, // û
    [U_GRAVE] = 0x00D9, // Ù
    [U_ACUTE] = 0x00DA, // Ú
    [U_CIRCUMFLEX] = 0x00DB, // Û

    [SHARP_s] = 0x00DF, // ß
    [SHARP_S] = 0x1E9E, // ẞ
};


// ==================== TASTENBELEGUNG ====================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer (Noted Layout) */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_J,    DE_Z,    DE_Y,    KC_U,    KC_A,    KC_Q,                         KC_P,    KC_B,    KC_M,    KC_L,    KC_F,    MO(_SPECIAL_CHARS),
        _______, MT(MOD_LGUI, KC_C), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_I), MT(MOD_LCTL, KC_E),   KC_O,                         KC_D,    MT(MOD_LCTL, KC_T),    MT(MOD_LSFT, KC_N),    MT(MOD_LALT, KC_R),    MT(MOD_LGUI, KC_H),    _______,
        MO(_SYMBOL), KC_V,    KC_X,    DE_UDIA, DE_ADIA, DE_ODIA,                      KC_W,    KC_G,    KC_COMM, KC_DOT,  KC_K,    MO(_SYMBOL),


                                 _______, MO(_NAV), KC_SPC,                                         KC_ENT,  MO(_NAV), OSL(_ADJUST)
    ),

    [_SPECIAL_CHARS] = LAYOUT_split_3x6_3(
        UM(SNEK),    UP(SHARP_s, SHARP_S),    UP(a_GRAVE, A_GRAVE),    UP(a_CIRCUMFLEX, A_CIRCUMFLEX),   UP(a_ACUTE, A_ACUTE),    UP(a_TILDE, A_TILDE),         UP(o_GRAVE, o_GRAVE),    UP(o_CIRCUMFLEX, O_CIRCUMFLEX),   UP(o_ACUTE, O_ACUTE),    UP(o_TILDE, O_TILDE),    _______,    _______,
        KC_LSFT,    UP(c_CEDILLA, C_CEDILLA),    UP(e_GRAVE, E_GRAVE),    UP(e_CIRCUMFLEX, E_CIRCUMFLEX),   UP(e_ACUTE, E_ACUTE),    _______,          UP(u_GRAVE, U_GRAVE),    UP(u_CIRCUMFLEX, U_CIRCUMFLEX),   UP(u_ACUTE, U_ACUTE),   _______,    _______,    KC_LSFT,
        _______,    UP(ae, AE),    UP(i_GRAVE, I_GRAVE),    UP(i_CIRCUMFLEX, I_CIRCUMFLEX),   UP(i_ACUTE, I_ACUTE),    _______,          _______,    _______,    _______,    _______,    _______,    _______,
                                     _______, _______, _______,                               _______,  _______, _______
    ),

    /* Symbol Layer */
    [_SYMBOL] = LAYOUT_split_3x6_3(
        _______, DE_EURO, DE_CIRC, DE_LBRC, DE_RBRC, DE_UNDS,                      DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR, DE_AT,
        KC_LSFT, ALGR(DE_SS), DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                  DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, KC_RSFT,
        _______, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV,                        DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
        _______, KC_LCTL, _______,                                                    _______, KC_LALT, _______
    ),

    /* Navigation Layer */
    [_NAV] = LAYOUT_split_3x6_3(
        KC_PSCR, _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,                        KC_LGUI,   _______,  _______,  _______,   _______,   _______,
        KC_LSFT, _______, KC_P4,   KC_P5,   KC_P6,   KC_DEL,                       KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT,
        _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_HOME,                      KC_END, _______, KC_PGDN, KC_PGUP, _______, _______,
        KC_LCTL, _______, KC_TAB,                                                 KC_ESC,  _______,  _______
    ),

    /* Function Layer */
    [_FUNCTION] = LAYOUT_split_3x6_3(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, _______,					_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU,
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, _______,					 _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, _______,					 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, 						_______, _______, _______
        ),

    /* Adjust Layer (One-Shot für RGB/Media) */
    [_ADJUST] = LAYOUT_split_3x6_3(
        QK_BOOT, QK_RBT, _______, _______, _______, _______,				 	KC_NUM, _______, _______, _______, _______, _______,
        UG_TOGG, UG_NEXT, UG_HUEU, UG_SATD, UG_VALU, UG_SPDU, 					_______, _______, _______, _______, _______, _______,
        _______, UG_PREV, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,					_______, _______, _______, _______, _______, _______,
        _______, _______, _______,												 _______, _______, _______
        )
    };

// ==================== ENCODER ====================
#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        default:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
    }
    return false;
}
#endif

void keyboard_post_init_user(void) {
    if (!host_keyboard_led_state().num_lock) {
        tap_code(KC_NUM_LOCK);
    }
}