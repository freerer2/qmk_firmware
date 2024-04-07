`rules.mk`
-
```make
COMBO_ENABLE = yes
```
---

`config.h`
-
```h
#define COMBO_TERM 50		//콤보 텀 50
#define EXTRA_SHORT_COMBOS	//콤보조합 최대 6키까지
```
---

`lazybones.h`
-
```h
//콤보 정의(이름, 작동키, 콤보키)
#define COMBO_LIST \
COMBO_X(left_thumb,		KC_ESC,		LT(U_NAV,KC_SPC),	LT(U_FUN,KC_TAB)) \
COMBO_X(mouse_thumb,	KC_BTN3,	KC_BTN1,			KC_BTN2) \
COMBO_X(right_thumb,	KC_DEL,		LT(U_SYM,KC_ENT),	LT(U_NUM,KC_BSPC)) \
COMBO_X(XC,				KC_UNDS,	KC_X,				KC_C) \
COMBO_X(SD,				S(KC_SPC),	LALT_T(KC_S),		LCTL_T(KC_D)) \
COMBO_X(KL,				KC_CAPS,	LCTL_T(KC_K),		LALT_T(KC_L))
```
---

`lazybones.c`
-
```c
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
```
---