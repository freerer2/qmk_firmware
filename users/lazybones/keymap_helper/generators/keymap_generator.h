#pragma once

#include "../settings/keymap_layer_setting.h"

// 레이어 목록 나열
enum layers {
	#define LAYER_X(LAYER, STRING) U_##LAYER,
		LAYER_LIST
	#undef LAYER_X
};

// 레이어 선언 매크로 함수
#define U_LAYER_VA_ARGS(mapping, ...) mapping(__VA_ARGS__)

// 매핑 변수 레이어 레이아웃 대입
#define MAPPING LAYOUT_lazybones

// 레이어 정의
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	#define LAYER_X(LAYER, STRING) [U_##LAYER] = U_LAYER_VA_ARGS(MAPPING, LAYER_##LAYER),
		LAYER_LIST
	#undef LAYER_X
};