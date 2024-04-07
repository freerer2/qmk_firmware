#include QMK_KEYBOARD_H
#include "lazybones.h"

// 콤보 목록 나열
enum combos {
	#define COMBO_X(NAME, WORK_KEY, ...) NAME,
		COMBO_LIST
	#undef COMBO_X
};

// 콤보 키 배열 정의
#define COMBO_X(NAME, WORK_KEY, ...) const uint16_t PROGMEM COMBO_##NAME[] = {__VA_ARGS__, COMBO_END};
	COMBO_LIST
#undef COMBO_X

// 콤보 동작키 매핑
combo_t key_combos[] = {
	#define COMBO_X(NAME, WORK_KEY, ...) [NAME] = COMBO(uint16_t PROGMEM COMBO_##NAME, WORK_KEY),
		COMBO_LIST
	#undef COMBO_X
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
	TD_DOUBLE_TAP,
	TD_DOUBLE_HOLD,
} td_state_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {return TD_SINGLE_TAP;}
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// 유저키코드 추가
enum my_keycodes {
	ECLIPSE,
	BROWSER = SAFE_RANGE,
	NEXACRO,
	STEP_INTO,
	STEP_OVER,
	STEP_OUT,
	RESUME,
};


// 오버라이드 추가
enum shifts {
	#define OVERRIDE_X(NAME, MOD, ORI, CHG) NAME,
		OVERRIDE_LIST
	#undef OVERRIDE_X
};

// 레이어추가
enum layers {
	#define LAYER_X(LAYER, STRING) U_##LAYER,
		LAYER_LIST
	#undef LAYER_X
};

// 더블탭레이어 키코드 추가 
enum {
    U_TD_BOOT,
    U_TD_COMM_SCRL,
    U_TD_BTN2_SCRL,
	#define LAYER_X(LAYER, STRING) U_TD_##LAYER,
		LAYER_LIST
	#undef LAYER_X
};

// 레이어 정의
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	#define LAYER_X(LAYER, STRING) [U_##LAYER] = U_LAYER_VA_ARGS(MAPPING, LAYER_##LAYER),
		LAYER_LIST
	#undef LAYER_X
};

// 더블탭 레이어 함수
#define LAYER_X(LAYER, STRING) \
	void u_td_fn_##LAYER(tap_dance_state_t *state, void *user_data) { \
		if (state->count == 2) { \
			default_layer_set((layer_state_t)1 << U_##LAYER); \
		} \
	}
	LAYER_LIST
#undef LAYER_X

// 더블탭 실행함수
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		reset_keyboard();
	}
};

static td_state_t drg_state;
void u_td_fn_commscrl_finish(tap_dance_state_t *state, void *user_data) {
	drg_state = cur_dance(state);
	switch (drg_state) {
		case TD_SINGLE_TAP:
			register_code(KC_SLSH);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(true);
			#endif
			layer_on(U_MOUSE);
			break;
		case TD_DOUBLE_TAP:
			tap_code(KC_SLSH);
			tap_code(KC_SLSH);
		default:
			break;
    }
}

void u_td_fn_commscrl_reset(tap_dance_state_t *state, void *user_data) {
	switch (drg_state) {
		case TD_SINGLE_TAP:
			unregister_code(KC_SLSH);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(false);
			#endif
			layer_off(U_MOUSE);
			break;
		case TD_DOUBLE_TAP:
		default:
			break;
    }
	drg_state = TD_NONE;
}

void u_td_fn_btn2scrl_finish(tap_dance_state_t *state, void *user_data) {
	drg_state = cur_dance(state);
	switch (drg_state) {
		case TD_SINGLE_TAP:
			register_code(KC_BTN2);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(true);
			#endif
			break;
		case TD_DOUBLE_TAP:
			#ifndef POINTING_DEVICE_ENABLE
				register_code(KC_BTN3);
			#endif
			break;
		default:
			break;
    }
}

void u_td_fn_btn2scrl_reset(tap_dance_state_t *state, void *user_data) {
	switch (drg_state) {
		case TD_SINGLE_TAP:
			unregister_code(KC_BTN2);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(false);
			#endif
			break;
		case TD_DOUBLE_TAP:
			#ifndef POINTING_DEVICE_ENABLE
				unregister_code(KC_BTN3);
			#endif
		default:
			break;
    }
	drg_state = TD_NONE;
}

// 더블탭 실행 액션 추가
tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [U_TD_COMM_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_commscrl_finish, u_td_fn_commscrl_reset),
    [U_TD_BTN2_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_btn2scrl_finish, u_td_fn_btn2scrl_reset),
	#define LAYER_X(LAYER, STRING) [U_TD_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_##LAYER),
	LAYER_LIST
	#undef LAYER_X
};

//오버라이드
#define OVERRIDE_X(NAME, MOD, ORI, CHG) const key_override_t OVERRIDE_##NAME = ko_make_basic(MOD, ORI, CHG);
	OVERRIDE_LIST
#undef OVERRIDE_X

const key_override_t **key_overrides = (const key_override_t *[]){
#define OVERRIDE_X(NAME, MOD, ORI, CHG) &OVERRIDE_##NAME,
	OVERRIDE_LIST
#undef OVERRIDE_X
NULL
};

//유저키코드
static bool is_eclipse = false;
static bool is_browser = false;
static bool is_nexaro = false;
// 유저키코드 처리
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		
	case ECLIPSE:
		if (record->event.pressed) {
			is_eclipse = true;
			is_browser = false;
			is_nexaro = false;
		}
		return false;
		
	case BROWSER:
		if (record->event.pressed) {
			is_eclipse = false;
			is_browser = true;
			is_nexaro = false;
		}
		return false;
		
	case NEXACRO:
		if (record->event.pressed) {
			is_eclipse = false;
			is_browser = false;
			is_nexaro = true;
		}
		return false;
		
    case STEP_INTO:
		if(is_eclipse){
			if (record->event.pressed) {
				register_code(KC_F5);
			} else {
				unregister_code(KC_F5);
			}
		} else if (is_browser || is_nexaro){
			if (record->event.pressed) {
				register_code(KC_F11);
			} else {
				unregister_code(KC_F11);
			}
		}
		return false;
		
    case STEP_OVER:
		if(is_eclipse){
			if (record->event.pressed) {
				register_code(KC_F6);
			} else {
				unregister_code(KC_F6);
			}
		} else if (is_browser || is_nexaro){
			if (record->event.pressed) {
				register_code(KC_F10);
			} else {
				unregister_code(KC_F10);
			}
		}
		return false;
		
    case STEP_OUT:
		if(is_eclipse){
			if (record->event.pressed) {
				register_code(KC_F7);
			} else {
				unregister_code(KC_F7);
			}
		} else if (is_browser || is_nexaro){
			if (record->event.pressed) {
				register_code(KC_LSFT);
				register_code(KC_F11);
			} else {
				unregister_code(KC_F11);
				unregister_code(KC_LSFT);
			}
		}
		return false;
		
    case RESUME:
		if(is_eclipse || is_browser){
			if (record->event.pressed) {
				register_code(KC_F8);
			} else {
				unregister_code(KC_F8);
			}
		} else if (is_nexaro){
			if (record->event.pressed) {
				register_code(KC_F5);
			} else {
				unregister_code(KC_F5);
			}
		}
		return false;
    }
    return true;
};

//유저 키 실시간처리
void matrix_scan_user(void) {
	//TODO : 상태값 같은걸 실시간으로 처리 가능함
}

//탭 시간간격
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A): case LALT_T(KC_S): case LALT_T(KC_L): case LGUI_T(KC_QUOT):
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}