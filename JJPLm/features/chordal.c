const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                            '*', '*',  '*', 'R'
    );

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_S):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

//bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case LT(1,KC_S):
//            // Immediately select the hold action when another key is pressed.
//            return true;
//        default:
//            // Do not select the hold action when another key is pressed.
//            return false;
//    }
//}