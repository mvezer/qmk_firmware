// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "action_layer.h"
#include "caps_word.h"
#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H
#include "print.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _NUM,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_CLMK_DH PDF(_COLEMAK_DH)
#define LGUI_a LGUI_T(KC_A)
#define LALT_r LALT_T(KC_R)
#define LCTL_s LCTL_T(KC_S)
#define LSFT_t LSFT_T(KC_T)
#define RSFT_n RSFT_T(KC_N)
#define RCTL_e RCTL_T(KC_E)
#define RALT_t RALT_T(KC_I)
#define RGUI_o RGUI_T(KC_O)
#define TRNS KC_TRNS
#define ALEFT RALT(KC_LEFT)
#define ADOWN RALT(KC_DOWN)
#define AUP RALT(KC_UP)
#define ARIGHT RALT(KC_RIGHT)
#define NAV_SPC LT(_NAV,KC_SPC)
#define SYM_TAB LT(_SYM,KC_TAB)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | CLMK  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   !  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | Caps |Space |  Tab | /  NUM  /       \  NUM \ |Enter |Bkspc |      |      |
 *            |      | word |/NAV  |/SYM  |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                     KC_6,   KC_7,   KC_8,       KC_9,   KC_0,       KC_GRV,
  KC_ESC,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                     KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_BSPC,
  KC_TAB,   KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                     KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B, KC_MUTE,     KC_CLMK_DH,  KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_EXLM,
             KC_NO,   CW_TOGG, NAV_SPC, SYM_TAB, MO(_NUM),        MO(_NUM), KC_ENT,  KC_BSPC,  KC_NO, KC_NO
),
/*
 * COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   '  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   [  |   ]  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |   ;  |
 * |------+------+------+------+------+------|  Mute |    | QWRTY |------+------+------+------+------+------|
 * |   \  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |   -  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | Caps |Space |  Tab | /  NUM  /       \  NUM \ |Enter |Bkspc |      |      |
 *            |      | word |/NAV  |/SYM  |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK_DH] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_EQUAL,
  KC_QUOTE, KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                               KC_J,   KC_L,   KC_U,   KC_Y,   KC_LBRC,KC_RBRC,
  KC_ESC,   LGUI_a, LALT_r, LCTL_s, LSFT_t, KC_G,                               KC_M,   RSFT_n, RCTL_e, RALT_t, RGUI_o, KC_SCLN,
  KC_BSLS,  KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_MUTE,      KC_QWERTY,  KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,KC_MINUS,
             KC_NO,   CW_TOGG, NAV_SPC, SYM_TAB, MO(_NUM),        MO(_NUM),     KC_ENT,  KC_BSPC,  KC_NO, KC_NO
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   %  |   {  |   }  |   ~  |   =  |   @  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   !  |   (  |   )  |   *  |   %  |   ^  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   [  |   ]  |   -  |   +  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
  KC_F12,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                      KC_F6,      KC_F7,                  KC_F8,                  KC_F9,          KC_F10,     KC_F11,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                      KC_PERC,    KC_LEFT_CURLY_BRACE,    KC_RIGHT_CURLY_BRACE,   KC_TILDE,       KC_EQUAL,   KC_AT,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                      KC_EXCLAIM, KC_LEFT_PAREN,          KC_RIGHT_PAREN,         KC_ASTERISK,    KC_PERCENT, KC_CIRCUMFLEX,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, TRNS,       TRNS,    KC_PLUS,    KC_LEFT_BRACKET,        KC_RIGHT_BRACKET,       KC_MINS,        KC_PLUS,    KC_BACKSLASH,
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
/* NAV
 * ,----------------------------------------.                     ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |ALeft |ADown | AUp  |ARight|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | Home | PgDn | PgUp | End  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  KC_F12,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                      KC_F6,  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                      KC_NO,  ALEFT,      ADOWN,      AUP,        ARIGHT,     KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                      KC_NO,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TRNS,       TRNS,   KC_NO,  KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // [_ADJUST] = LAYOUT(
  // XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // QK_BOOT  , XXXXXXX,KC_QWERTY,KC_CLMK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  // XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  // )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_PRVWD:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 }
//             }
//             break;
//         case KC_NXTWD:
//              if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 }
//             }
//             break;
//         case KC_LSTRT:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                      //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_code(KC_HOME);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_code(KC_HOME);
//                 }
//             }
//             break;
//         case KC_LEND:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_code(KC_END);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_code(KC_END);
//                 }
//             }
//             break;
//     }
//     return true;
// }

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

void print_status_narrow(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("CLMK"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        default:
            oled_write_ln_P(PSTR("-----"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_ln_P(PSTR("[   ]"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("[NAV]"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("[SYM]"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("[NUM]"), false);
            break;
        default:
            oled_write_ln_P(PSTR("[???]"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("CAPS"), is_caps_word_on());
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return true;
}

#endif
