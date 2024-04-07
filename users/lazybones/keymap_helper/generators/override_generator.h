#pragma once

#include "../settings/override_setting.h"

// 오버라이드 목록 나열
// enum overrides {
// 	#define OVERRIDE_X(NAME, MOD, ORI, CHG) NAME,
// 		OVERRIDE_LIST
// 	#undef OVERRIDE_X
// };

// 오버라이드 동작 정의
#define OVERRIDE_X(NAME, MOD, ORI, CHG) const key_override_t OVERRIDE_##NAME = ko_make_basic(MOD, ORI, CHG);
	OVERRIDE_LIST
#undef OVERRIDE_X

// 오버라이드 전역 정의
const key_override_t **key_overrides = (const key_override_t *[]){
	#define OVERRIDE_X(NAME, MOD, ORI, CHG) &OVERRIDE_##NAME,
		OVERRIDE_LIST
	#undef OVERRIDE_X
	NULL
};