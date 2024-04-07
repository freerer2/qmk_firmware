`rules.mk`
-
```make
KEY_OVERRIDE_ENABLE = yes
```
---

`lazybones.h`
-
```h
	//오버라이드 조합키 정의(이름, 조합할 모드키, 조합할 키코드, 작동 키코드)
	#define OVERRIDE_LIST \
	OVERRIDE_X(WINLT,	MOD_MASK_SHIFT, 	U_WINLT, 	U_WINFLT) \
	OVERRIDE_X(WINUP,	MOD_MASK_SHIFT, 	U_WINUP, 	U_WINFUP) \
	OVERRIDE_X(WINDN,	MOD_MASK_SHIFT, 	U_WINDN, 	U_WINFDN) \
	OVERRIDE_X(WINRT,	MOD_MASK_SHIFT, 	U_WINRT, 	U_WINFRT) \
	OVERRIDE_X(MSLT,	MOD_MASK_SHIFT, 	KC_MS_L, 	KC_WH_L) \
	OVERRIDE_X(MSUP,	MOD_MASK_SHIFT, 	KC_MS_U, 	KC_WH_U) \
	OVERRIDE_X(MSDN,	MOD_MASK_SHIFT, 	KC_MS_D, 	KC_WH_D) \
	OVERRIDE_X(MSRT,	MOD_MASK_SHIFT, 	KC_MS_R, 	KC_WH_R)
```
---

`lazybones.c`
-
```c
// 오버라이드 목록 나열
enum shifts {
	#define OVERRIDE_X(NAME, MOD, ORI, CHG) NAME,
		OVERRIDE_LIST
	#undef OVERRIDE_X
};

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
```