#pragma once

#include "../settings/combo_setting.h"

// 콤보 목록 나열
enum combos {
	#define COMBO_X(NAME, COMBOS, ...) NAME,
		COMBO_LIST
	#undef COMBO_X
};

// 콤보 키 배열 정의
#define COMBO_X(NAME, WORK_KEY, ...) const uint16_t PROGMEM COMBO_##NAME[] = {__VA_ARGS__, COMBO_END};
	COMBO_LIST
#undef COMBO_X

// 콤보 동작키 매핑
combo_t key_combos[] = {
	#define COMBO_X(NAME, WORK_KEY, ...) [NAME] = COMBO(COMBO_##NAME, WORK_KEY),
		COMBO_LIST
	#undef COMBO_X
};