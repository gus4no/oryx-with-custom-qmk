#include QMK_KEYBOARD_H
#include "version.h"
#include "features/chordal.c"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           MT(MOD_LSFT, KC_R),LT(1, KC_S),    MT(MOD_LGUI, KC_T),KC_G,                                           KC_M,           MT(MOD_RGUI, KC_N),LT(1, KC_E),    MT(MOD_RSFT, KC_I),KC_O,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           MT(MOD_LALT, KC_X),KC_C,           MEH_T(KC_D),    KC_V,                                           KC_K,           MEH_T(KC_H),    KC_COMMA,       MT(MOD_RCTL, KC_DOT),KC_SLASH,       KC_TRANSPARENT, 
                                                    MT(MOD_LGUI, KC_ENTER),OSM(MOD_LSFT),                                  KC_BSPC,        LT(2, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_PAGE_UP,     KC_UP,          KC_PGDN,        KC_MEDIA_NEXT_TRACK,                                KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TAB,         MT(MOD_LSFT, KC_LEFT),KC_DOWN,        MT(MOD_RGUI, KC_RIGHT),KC_MEDIA_PLAY_PAUSE,                                KC_RBRC,        MT(MOD_RGUI, KC_4),KC_5,           MT(MOD_RSFT, KC_6),KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_BSLS,        KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,                                KC_DOT,         MT(MOD_RALT, KC_1),KC_2,           MT(MOD_RCTL, KC_3),KC_EQUAL,       KC_TRANSPARENT, 
                                                    MT(MOD_LGUI, KC_SPACE),KC_ENTER,                                       KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_MODE_FORWARD,KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(KC_LBRC),  KC_MS_WH_DOWN,  RGUI(KC_RBRC),  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TOGGLE_LAYER_COLOR,KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_PAGE_UP, KC_UP, KC_PGDN, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_7, KC_8, KC_9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, KC_ESCAPE),
    COMBO(combo2, KC_ESCAPE),
    COMBO(combo3, KC_ESCAPE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A:
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_ENTER):
            return TAPPING_TERM -50;
        case KC_O:
            return TAPPING_TERM + 50;
        case MEH_T(KC_H):
            return TAPPING_TERM + 50;
        case LT(2,KC_SPACE):
            return TAPPING_TERM + 15;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {0,0,0}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {0,0,0}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {0,0,0}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {0,0,0}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {24,255,255}, {0,0,0}, {24,255,255}, {24,255,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {0,0,0}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {0,0,0}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {0,0,0}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {0,0,0}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {221,222,255}, {0,0,0}, {221,222,255}, {221,222,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


