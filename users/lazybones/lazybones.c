#include QMK_KEYBOARD_H
#include "lazybones.h"

// 더블탭 실행함수
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		reset_keyboard();
	}
};

void u_td_fn_slsh_finish(tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case TD_SINGLE_TAP:
			register_code(KC_SLSH);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(true);
			#endif
			layer_on(U_SCROL);
			break;
		case TD_DOUBLE_TAP:
			tap_code(KC_SLSH);
			tap_code(KC_SLSH);
		default:
			break;
    }
}

void u_td_fn_slsh_reset(tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case TD_SINGLE_TAP:
			unregister_code(KC_SLSH);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(false);
			#endif
			layer_off(U_SCROL);
			break;
		case TD_DOUBLE_TAP:
		default:
			break;
    }
	td_state = TD_NONE;
}

void u_td_fn_btn2scrl_finish(tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
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
	switch (td_state) {
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
	td_state = TD_NONE;
}

// 더블탭 실행 액션 추가
tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [U_TD_SLSH_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_slsh_finish, u_td_fn_slsh_reset),
    [U_TD_BTN2_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_btn2scrl_finish, u_td_fn_btn2scrl_reset),
};

//유저키코드
static bool is_eclipse = false;
static bool is_browser = false;
static bool is_nexaro = false;

// 유저키코드 처리
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case A_A_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.16, 0.25);}return false;
	case A_B_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.33, 0.25);}return false;
	case A_C_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.5, 0.25);}return false;
	case A_D_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.66, 0.25);}return false;
	case A_E_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.83, 0.25);}return false;
	case A_A_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.16, 0.5);}return false;
	case A_B_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.33, 0.5);}return false;
	case A_C_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.5, 0.5);}return false;
	case A_D_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.66, 0.5);}return false;
	case A_E_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.83, 0.5);}return false;
	case A_A_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.16, 0.75);}return false;
	case A_B_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.33, 0.75);}return false;
	case A_C_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.5, 0.75);}return false;
	case A_D_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.66, 0.75);}return false;
	case A_E_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.83, 0.75);}return false;
	
	case B_A_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.09, 0.25);}return false;
	case B_A_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.09, 0.5);}return false;
	case B_A_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.09, 0.75);}return false;
	case B_B_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.18, 0.25);}return false;
	case B_B_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.18, 0.5);}return false;
	case B_B_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.18, 0.75);}return false;
	case B_C_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0, 0.25);}return false;
	case B_C_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0, 0.5);}return false;
	case B_C_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0, 0.75);}return false;
	case B_D_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.36, 0.25);}return false;
	case B_D_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.36, 0.5);}return false;
	case B_D_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.36, 0.75);}return false;
	case B_E_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.45, 0.25);}return false;
	case B_E_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.45, 0.5);}return false;
	case B_E_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.45, 0.75);}return false;
	case B_F_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.54, 0.25);}return false;
	case B_F_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.54, 0.5);}return false;
	case B_F_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.54, 0.75);}return false;
	case B_G_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.63, 0.25);}return false;
	case B_G_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.63, 0.5);}return false;
	case B_G_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.63, 0.75);}return false;
	case B_H_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.72, 0.25);}return false;
	case B_H_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.72, 0.5);}return false;
	case B_H_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.72, 0.75);}return false;
	case B_I_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.81, 0.25);}return false;
	case B_I_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.81, 0.5);}return false;
	case B_I_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.81, 0.75);}return false;
	case B_J_A: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.9, 0.25);}return false;
	case B_J_B: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.9, 0.5);}return false;
	case B_J_C: if(record->event.pressed){digitizer_in_range_on(); digitizer_set_position(0.9, 0.75);}return false;

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
		case TD(U_TD_BTN2_SCRL): /*case TD(U_TD_SLSH_SCRL):*/
			return TAPPING_TERM - 50;
		case LCTL_T(KC_D): case LSFT_T(KC_F): 
		case LSFT_T(KC_J): case LCTL_T(KC_K): 
            return TAPPING_TERM;
        case LGUI_T(KC_A): case LALT_T(KC_S):
		case LALT_T(KC_L): case LGUI_T(KC_QUOT):
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
