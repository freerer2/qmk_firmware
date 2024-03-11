#include QMK_KEYBOARD_H
#include "freerer2.h"

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

// 콤보추가
enum combos {
#define COMBO_X(NAME, COMBOS, ...) NAME,
COMBO_LIST
#undef COMBO_X
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

// 더블탭레이어 함수 추가 
enum {
    U_TD_BOOT,
#define LAYER_X(LAYER, STRING) U_TD_U_##LAYER,
LAYER_LIST
#undef LAYER_X
};

// 레이어
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define LAYER_X(LAYER, STRING) [U_##LAYER] = U_LAYER_VA_ARGS(MAPPING, LAYER_##LAYER),
LAYER_LIST
#undef LAYER_X
};

// 더블탭레이어 함수
#define LAYER_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
LAYER_LIST
#undef LAYER_X

// 키보드 리부트 함수 추가
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

// 더블탬 레이어 함수 실핼 액션 추가
tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define LAYER_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
LAYER_LIST
#undef LAYER_X
};

// 콤보
#define COMBO_X(NAME, COMBOS, ...) const uint16_t PROGMEM COMBO_##NAME[] = {__VA_ARGS__, COMBO_END};
COMBO_LIST
#undef COMBO_X

combo_t key_combos[] = {
#define COMBO_X(NAME, COMBOS, ...) [NAME] = COMBO(COMBO_##NAME, COMBOS),
COMBO_LIST
#undef COMBO_X
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