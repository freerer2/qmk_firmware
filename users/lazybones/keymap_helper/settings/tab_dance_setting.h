#pragma once

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
	TD_DOUBLE_TAP,
	TD_DOUBLE_HOLD,
	TD_TRIPPLE_TAP,
	TD_TRIPPLE_HOLD,
} td_state_t;

static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {return TD_SINGLE_TAP;}
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) {return TD_DOUBLE_TAP;}
        else return TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (!state->pressed) {return TD_TRIPPLE_TAP;}
        else return TD_TRIPPLE_HOLD;
    } else return TD_UNKNOWN;
}